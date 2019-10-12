type musicTrack = {
  name: string,
  file: string,
};

type musicTracks = array(musicTrack);

type playing =
  | Playing(int)
  | NotPlaying;

type state = {
  tracks: musicTracks,
  playing,
  audioPlayer: JsAudio.audio,
};
