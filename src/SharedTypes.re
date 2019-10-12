type musicTrack = {
  name: string,
  file: string,
};

type musicTracks = array(musicTrack);

type playing =
  | Playing(option(int))
  | NotPlaying;

type state = {
  tracks: musicTracks,
  playing,
  audioPlayer: JsAudio.audio,
};
