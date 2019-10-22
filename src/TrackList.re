open ReactUtils;

[@react.component]
let make = () => {
  let (
    playing,
    trackList,
    _currentTrackName,
    _pauseTrack,
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
            <div className="columns is-vcentered">
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
              <div className="song-title column"> {s(track.name)} </div>
            </div>
          </div>,
        trackList,
      )
      |> React.array
    }
  </>;
};
