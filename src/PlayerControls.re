open ReactUtils;

[@react.component]
let make = () => {
  let (
    isPlaying,
    _trackList,
    currentTrackIndex,
    currentTrackName,
    togglePlay,
    _playTrack,
    playPreviousTrack,
    playNextTrack,
  ) =
    UseMusicPlayer.useMusicPlayer();

  <>
    <div className="box controls has-background-grey-dark">
      <div className="current-track has-text-light">
        <marquee> {s(currentTrackName)} </marquee>
      </div>
      <div className="has-text-centered">
        <button
          className="button has-text-light has-background-grey-dark"
          onClick=playPreviousTrack
          disabled={
            switch (currentTrackIndex) {
            | None => true
            | Some(_idx) => false
            }
          }>
          <i className="fas fa-step-backward" />
        </button>
        <button
          className="button has-text-light has-background-grey-dark"
          onClick={_ => togglePlay()}
          disabled={
            switch (currentTrackIndex) {
            | None => true
            | Some(_idx) => false
            }
          }>
          {
            isPlaying ?
              <i className="fas fa-pause" /> : <i className="fa fa-play" />
          }
        </button>
        <button
          className="button has-text-light has-background-grey-dark"
          onClick=playNextTrack
          disabled={
            switch (currentTrackIndex) {
            | None => true
            | Some(_idx) => false
            }
          }>
          <i className="fas fa-step-forward" />
        </button>
      </div>
    </div>
  </>;
};
