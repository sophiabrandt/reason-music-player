let useMusicPlayer = () => {
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);

  let playing = state.playing;

  let trackList = state.tracks;

  let currentTrackName =
    switch (playing) {
    | Playing(Some(idx)) => state.tracks[idx].name
    | _ => "Please choose a track to play"
    };

  let togglePlay = () => MusicPlayer.TogglePlay |> dispatch;

  let playTrack = index =>
    switch (playing) {
    | Playing(Some(idx)) =>
      index === idx ? togglePlay() : MusicPlayer.PlayTrack(index) |> dispatch
    | _ => MusicPlayer.PlayTrack(index) |> dispatch
    };

  let playPreviousTrack = _ => {
    togglePlay();
    switch (playing) {
    | Playing(Some(idx)) => idx === 0 ? playTrack(idx) : playTrack(idx - 1)
    | _ => ()
    };
  };

  let playNextTrack = _ => {
    let trackListEnd = Array.length(trackList) - 1;
    togglePlay();
    switch (playing) {
    | Playing(Some(idx)) =>
      idx === trackListEnd ? playTrack(idx) : playTrack(idx + 1)
    | _ => ()
    };
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
