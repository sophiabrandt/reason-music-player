open ReactUtils;

[@react.component]
let make = () => {
  let (
    isPlaying,
    trackList,
    currentTrackIndex,
    togglePlay,
    playTrack,
    playPreviousTrack,
    playNextTrack,
  ) =
    UseMusicPlayer.useMusicPlayer();

  <>
    {
      Array.mapi(
        (index, track: SharedTypes.musicTrack) =>
          <div className="box" key={index |> string_of_int}>
            <button className="button" onClick={_ => playTrack(index)}>
              {
                switch (currentTrackIndex) {
                | None => <i className="fas fa-play" />
                | Some(idx) =>
                  idx === index && isPlaying ?
                    <i className="fas fa-pause" /> :
                    <i className="fas fa-play" />
                }
              }
            </button>
            <div className="song-title"> {s(track.SharedTypes.name)} </div>
          </div>,
        trackList,
      )
      |> React.array
    }
  </>;
};
