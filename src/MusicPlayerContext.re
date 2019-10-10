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

let musicPlayerContext: React.Context.t(SharedTypes.state) =
  React.createContext(initialState);

module MusicPlayerProvider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
  let make = React.Context.provider(musicPlayerContext);
};
