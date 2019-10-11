type audio;
[@bs.new] external make: string => audio = "Audio";
[@bs.send] external play: audio => unit = "play";
[@bs.send] external pause: audio => unit = "pause";
