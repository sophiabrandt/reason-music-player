let useMusicPlayer = () => {

  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);

  let playing = state.playing;

  let trackList = state.tracks;

  let currentTrackName =
    switch (playing) {
    | Playing(idx) => state.tracks[idx].name
    | NotPlaying => "Please choose a track to play"
    };

  let pauseTrack = () => MusicPlayer.PauseTrack |> dispatch;

  let playTrack = index =>
    switch (playing) {
    | Playing(idx) =>
      index === idx ?
        pauseTrack() :
        {
          JsAudio.(state.audioPlayer |> pause);
          MusicPlayer.PlayTrack(index) |> dispatch;
        }
    | NotPlaying => MusicPlayer.PlayTrack(index) |> dispatch
    };

  let trackListLength = Array.length(trackList);

  let playPreviousTrack = _ =>
    switch (playing) {
    | Playing(idx) =>
      ((idx - 1) mod trackListLength + trackListLength)
      mod trackListLength
      |> playTrack
    | NotPlaying => ()
    };

  let playNextTrack = _ =>
    switch (playing) {
    | Playing(idx) => (idx + 1) mod trackListLength |> playTrack
    | NotPlaying => ()
    };

  (
    playing,
    trackList,
    currentTrackName,
    pauseTrack,
    playTrack,
    playPreviousTrack,
    playNextTrack,
  );
};
