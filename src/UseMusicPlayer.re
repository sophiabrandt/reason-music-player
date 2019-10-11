let useMusicPlayer = () => {
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);

  let isPlaying = state.isPlaying;

  let trackList = state.tracks;

  let currentTrackIndex = state.currentTrackIndex;

  let currentTrackName =
    switch (state.currentTrackIndex) {
    | None => ""
    | Some(idx) => state.tracks[idx].name
    };

  let togglePlay = () => MusicPlayer.TogglePlay |> dispatch;

  let playTrack = index =>
    switch (state.currentTrackIndex) {
    | None => MusicPlayer.PlayTrack(index) |> dispatch
    | Some(idx) =>
      index === idx ? togglePlay() : MusicPlayer.PlayTrack(index) |> dispatch
    };

  let playPreviousTrack = _ =>
    switch (state.currentTrackIndex) {
    | None => ()
    | Some(idx) =>
      togglePlay();
      idx === 0 ? playTrack(idx) : playTrack(idx - 1);
    };

  let playNextTrack = _ => {
    let trackListEnd = Array.length(trackList) - 1;
    switch (state.currentTrackIndex) {
    | None => ()
    | Some(idx) =>
      togglePlay();
      idx === trackListEnd ? playTrack(idx) : playTrack(idx + 1);
    };
  };

  (
    isPlaying,
    trackList,
    currentTrackIndex,
    currentTrackName,
    togglePlay,
    playTrack,
    playPreviousTrack,
    playNextTrack,
  );
};
