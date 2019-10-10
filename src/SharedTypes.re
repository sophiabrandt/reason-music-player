type musicTrack = {
  name: string,
  file: string,
};

type musicTracks = array(musicTrack);

type state = {
  audioPlayer: string,
  tracks: musicTracks,
  currentTrackIndex: option(int),
  isPlaying: bool,
};

