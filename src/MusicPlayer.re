let initialState: SharedTypes.state = {
  audioPlayer: "audio",
  tracks: [|
    {name: "Lost Chameleon - Genesis", file: "LostChameleon"},
    {name: "The Hipsta - Shaken Soda", file: "Rock"},
    {name: "Tobu - Such Fun", file: "Tobu"},
  |],
  currentTrackIndex: None,
  isPlaying: false,
};

type action =
  | TogglePlay
  | PlayTrack(int);

let withTogglePlay = state: SharedTypes.state => {
  ...state,
  isPlaying: !state.SharedTypes.isPlaying,
};

let withPlayTrack = (state: SharedTypes.state, index: int) => {
  ...state,
  currentTrackIndex: Some(index),
  isPlaying: true,
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

  <MusicPlayerProvider value=(state, dispatch)>
    children
  </MusicPlayerProvider>;
};
