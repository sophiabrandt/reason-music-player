let useMusicPlayer = () => {
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);

  let playing = state.playing;

  let trackList = state.tracks;

  let currentTrackName =
    switch (playing) {
    | Playing(idx) => state.tracks[idx].name
    | _ => "Please choose a track to play"
    };

  let togglePlay = () => MusicPlayer.TogglePlay |> dispatch;

  let playTrack = index =>
    switch (playing) {
    | Playing(idx) =>
      index === idx ?
        togglePlay() :
        {
          JsAudio.(state.audioPlayer |> pause);
          MusicPlayer.PlayTrack(index) |> dispatch;
        }
    | _ => MusicPlayer.PlayTrack(index) |> dispatch
    };

  let trackListLength = Array.length(trackList);

  let playPreviousTrack = _ =>
    switch (playing) {
    | Playing(idx) =>
      ((idx - 1) mod trackListLength + trackListLength)
      mod trackListLength
      |> playTrack
    | _ => ()
    };

  let playNextTrack = _ =>
    switch (playing) {
    | Playing(idx) => (idx + 1) mod trackListLength |> playTrack
    | _ => ()
    };

  (
    playing,
    trackList,
    currentTrackName,
    togglePlay,
    playTrack,
    playPreviousTrack,
    playNextTrack,
  );
};
