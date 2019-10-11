[@bs.module "./bensound-summer.mp3"] external summer: string = "default";
[@bs.module "./bensound-ukulele.mp3"] external ukulele: string = "default";
[@bs.module "./bensound-creativeminds.mp3"]
external creativeminds: string = "default";

let initialState: SharedTypes.state = {
  tracks: [|
    {name: "Benjamin Tissot - Summer", file: summer},
    {name: "Benjamin Tissot - Ukulele", file: ukulele},
    {name: "Benjamin Tissot - Creative Minds", file: creativeminds},
  |],
  currentTrackIndex: None,
  isPlaying: false,
  audioPlayer: JsAudio.make(""),
};

type action =
  | TogglePlay
  | PlayTrack(int);

let withTogglePlay = state: SharedTypes.state => {
  ...state,
  isPlaying: !state.SharedTypes.isPlaying,
};

let withPlayTrack = (state: SharedTypes.state, index: int) => {
  let newState = {
    ...state,
    currentTrackIndex: Some(index),
    isPlaying: true,
    audioPlayer: JsAudio.(make(state.tracks[index].file)),
  };
  Js.log(newState.isPlaying);
  newState;
};

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  | TogglePlay => withTogglePlay(state)
  | PlayTrack(index) => withPlayTrack(state, index)
  };

let musicPlayerContext = React.createContext((initialState, ignore));
let musicPlayerContextProvider = React.Context.provider(musicPlayerContext);

module MusicPlayerProvider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
  let make = React.Context.provider(musicPlayerContext);
};

[@react.component]
let make = (~children) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect1(
    () => {
      switch (state.currentTrackIndex) {
      | None => ()
      | Some(_idx) =>
        state.isPlaying ?
          JsAudio.(state.audioPlayer |> play) :
          JsAudio.(state.audioPlayer |> pause)
      };
      None;
    },
    [|state|],
  );

  <MusicPlayerProvider value=(state, dispatch)>
    children
  </MusicPlayerProvider>;
};
