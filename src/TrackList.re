open ReactUtils;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);
  <>
    {
      Array.map(
        track =>
          <div className="box">
            <div className="song-title"> {s(track.SharedTypes.name)} </div>
          </div>,
        state.tracks,
      )
      |> React.array
    }
  </>;
};
