type musicTrack = {
  name: string,
  file: string,
};

type musicTracks = array(musicTrack);

type state = {
  tracks: musicTracks,
  currentTrackIndex: option(int),
  isPlaying: bool,
  audioPlayer: JsAudio.audio,
};
