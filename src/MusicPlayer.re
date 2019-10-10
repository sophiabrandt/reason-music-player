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
  | DoSomething;

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  | DoSomething => state
  };

let musicPlayerContext = React.createContext((initialState, ignore));

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
