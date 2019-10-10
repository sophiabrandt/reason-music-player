open ReactUtils;

type action =
  | DoSomething;

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  | DoSomething => state
  };

[@react.component]
let make = () => {
  let initialState = React.useContext(MusicPlayerContext.musicPlayerContext);
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <>
    {
      Array.map(
        track =>
          <div className="box">
            <div className="song-title"> {s(track.SharedTypes.name)} </div>
          </div>,
        state.tracks,
      )
      |> React.array
    }
  </>;
};
