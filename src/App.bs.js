// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as TrackList$ReasonMusicPlayer from "./TrackList.bs.js";
import * as MusicPlayer$ReasonMusicPlayer from "./MusicPlayer.bs.js";
import * as PlayerControls$ReasonMusicPlayer from "./PlayerControls.bs.js";

function App(Props) {
  return React.createElement("div", {
              className: "section is-fullheignt"
            }, React.createElement("div", {
                  className: "container"
                }, React.createElement("div", {
                      className: "column is-6 is-offset-4"
                    }, React.createElement("h1", {
                          className: "is-size-2 has-text-centered"
                        }, "Reason Music Player"), React.createElement("br", undefined), React.createElement(MusicPlayer$ReasonMusicPlayer.make, {
                          children: null
                        }, React.createElement(TrackList$ReasonMusicPlayer.make, { }), React.createElement(PlayerControls$ReasonMusicPlayer.make, { })))));
}

var make = App;

export {
  make ,
  
}
/* react Not a pure module */
