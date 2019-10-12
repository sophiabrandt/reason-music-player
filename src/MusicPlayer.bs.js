// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Caml_array from "bs-platform/lib/es6/caml_array.js";
import * as BensoundSummerMp3 from "./bensound-summer.mp3";
import * as BensoundUkuleleMp3 from "./bensound-ukulele.mp3";
import * as BensoundCreativemindsMp3 from "./bensound-creativeminds.mp3";

var summer = BensoundSummerMp3.default;

var ukulele = BensoundUkuleleMp3.default;

var creativeminds = BensoundCreativemindsMp3.default;

var initialState_000 = /* tracks : array */[
  /* record */[
    /* name */"Benjamin Tissot - Summer",
    /* file */summer
  ],
  /* record */[
    /* name */"Benjamin Tissot - Ukulele",
    /* file */ukulele
  ],
  /* record */[
    /* name */"Benjamin Tissot - Creative Minds",
    /* file */creativeminds
  ]
];

var initialState_002 = /* audioPlayer */new Audio("");

var initialState = /* record */[
  initialState_000,
  /* playing : NotPlaying */0,
  initialState_002
];

function withTogglePlay(state) {
  return /* record */[
          /* tracks */state[/* tracks */0],
          /* playing : NotPlaying */0,
          /* audioPlayer */state[/* audioPlayer */2]
        ];
}

function withPlayTrack(state, index) {
  return /* record */[
          /* tracks */state[/* tracks */0],
          /* playing : Playing */[index],
          /* audioPlayer */new Audio(Caml_array.caml_array_get(state[/* tracks */0], index)[/* file */1])
        ];
}

function reducer(state, action) {
  if (action) {
    return withPlayTrack(state, action[0]);
  } else {
    return withTogglePlay(state);
  }
}

var musicPlayerContext = React.createContext(/* tuple */[
      initialState,
      (function (prim) {
          return /* () */0;
        })
    ]);

var musicPlayerContextProvider = musicPlayerContext.Provider;

function makeProps(value, children, param) {
  return {
          value: value,
          children: children
        };
}

var make = musicPlayerContext.Provider;

var MusicPlayerProvider = /* module */[
  /* makeProps */makeProps,
  /* make */make
];

function MusicPlayer(Props) {
  var children = Props.children;
  var match = React.useReducer(reducer, initialState);
  var state = match[0];
  React.useEffect((function () {
          var match = state[/* playing */1];
          if (match) {
            if (match[0] !== undefined) {
              state[/* audioPlayer */2].play();
            } else {
              state[/* audioPlayer */2].pause();
            }
          } else {
            state[/* audioPlayer */2].pause();
          }
          return undefined;
        }), /* array */[state[/* playing */1]]);
  return React.createElement(make, makeProps(/* tuple */[
                  state,
                  match[1]
                ], children, /* () */0));
}

var make$1 = MusicPlayer;

export {
  summer ,
  ukulele ,
  creativeminds ,
  initialState ,
  withTogglePlay ,
  withPlayTrack ,
  reducer ,
  musicPlayerContext ,
  musicPlayerContextProvider ,
  MusicPlayerProvider ,
  make$1 as make,
  
}
/* summer Not a pure module */
