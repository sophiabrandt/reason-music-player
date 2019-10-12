open ReactUtils;

[@react.component]
let make = () => {
  let (
    playing,
    _trackList,
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
            switch (playing) {
            | Playing(Some(_idx)) => false
            | _ => true
            }
          }>
          <i className="fas fa-step-backward" />
        </button>
        <button
          className="button has-text-light has-background-grey-dark"
          onClick={_ => togglePlay()}
          disabled={
            switch (playing) {
            | Playing(Some(_idx)) => false
            | _ => true
            }
          }>
          {
            switch (playing) {
            | Playing(Some(_idx)) => <i className="fas fa-pause" />
            | _ => <i className="fas fa-play" />
            }
          }
        </button>
        <button
          className="button has-text-light has-background-grey-dark"
          onClick=playNextTrack
          disabled={
            switch (playing) {
            | Playing(Some(_idx)) => false
            | _ => true
            }
          }>
          <i className="fas fa-step-forward" />
        </button>
      </div>
    </div>
  </>;
};
