open ReactUtils;

[@react.component]
let make = () => {
  let (
    playing,
    trackList,
    _currentTrackName,
    _togglePlay,
    playTrack,
    _playPreviousTrack,
    _playNextTrack,
  ) =
    UseMusicPlayer.useMusicPlayer();

  <>
    {
      Array.mapi(
        (index, track: SharedTypes.musicTrack) =>
          <div className="box" key={index |> string_of_int}>
            <button className="button" onClick={_ => playTrack(index)}>
              {
                switch (playing) {
                | Playing(idx) =>
                  idx === index ?
                    <i className="fas fa-pause" /> :
                    <i className="fas fa-play" />
                | NotPlaying => <i className="fas fa-play" />
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
