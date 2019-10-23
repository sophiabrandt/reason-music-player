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
  playing: NotPlaying,
  audioPlayer: JsAudio.(make("")),
};

type action =
  | PauseTrack
  | PlayTrack(int);

let withPauseTrack = state: SharedTypes.state => {
  ...state,
  playing: NotPlaying,
};

let withPlayTrack = (state: SharedTypes.state, index) => {
  ...state,
  playing: Playing(index),
  audioPlayer: JsAudio.(make(state.tracks[index].file)),
};

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  | PauseTrack => withPauseTrack(state)
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
      switch (state.playing) {
      | Playing(_idx) => JsAudio.(state.audioPlayer |> play)
      | NotPlaying => JsAudio.(state.audioPlayer |> pause)
      };
      None;
    },
    [|state.playing|],
  );

  <MusicPlayerProvider value=(state, dispatch)>
    children
  </MusicPlayerProvider>;
};
