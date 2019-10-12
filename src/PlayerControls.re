open ReactUtils;

[@react.component]
let make = () => {
  let (
    playing,
    _trackList,
    currentTrackName,
    pauseTrack,
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
      <div className="buttons is-centered">
        <button
          className="button has-text-light has-background-grey-dark"
          onClick=playPreviousTrack
          disabled={
            switch (playing) {
            | Playing(_idx) => false
            | NotPlaying => true
            }
          }>
          <i className="fas fa-step-backward" />
        </button>
        <button
          className="button has-text-light has-background-grey-dark"
          onClick={_ => pauseTrack()}
          disabled={
            switch (playing) {
            | Playing(_idx) => false
            | NotPlaying => true
            }
          }>
          {
            switch (playing) {
            | Playing(_idx) => <i className="fas fa-pause" />
            | NotPlaying => <i className="fas fa-play" />
            }
          }
        </button>
        <button
          className="button has-text-light has-background-grey-dark"
          onClick=playNextTrack
          disabled={
            switch (playing) {
            | Playing(_idx) => false
            | NotPlaying => true
            }
          }>
          <i className="fas fa-step-forward" />
        </button>
      </div>
    </div>
  </>;
};
