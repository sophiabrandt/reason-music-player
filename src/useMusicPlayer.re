let useMusicPlayer = () => {
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);
  let isPlaying = state.isPlaying;

  let trackList = state.tracks;

  let currentTrackIndex = state.currentTrackIndex;

  let togglePlay = () => MusicPlayer.TogglePlay |> dispatch;

  let playTrack = index =>
    switch (state.currentTrackIndex) {
    | None => MusicPlayer.PlayTrack(index) |> dispatch
    | Some(idx) =>
      index === idx ? togglePlay() : MusicPlayer.PlayTrack(index) |> dispatch
    };

  let playPreviousTrack = _ =>
    switch (state.currentTrackIndex) {
    | None => MusicPlayer.PlayTrack(0) |> dispatch
    | Some(idx) => playTrack(idx - 1)
    };

  let playNextTrack = _ =>
    switch (state.currentTrackIndex) {
    | None => MusicPlayer.PlayTrack(0) |> dispatch
    | Some(idx) => playTrack(idx + 1)
    };

  (
    isPlaying,
    trackList,
    currentTrackIndex,
    togglePlay,
    playTrack,
    playPreviousTrack,
    playNextTrack,
  );
};
