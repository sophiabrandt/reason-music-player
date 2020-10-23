open ReactUtils;

[@react.component]
let make = () =>
  <div className="section is-fullheignt">
    <div className="container">
      <div className="column is-6 is-offset-3">
        <h1 className="is-size-2 has-text-centered">
          {s("Reason Music Player")}
        </h1>
        <br />
        <MusicPlayer> <TrackList /> <PlayerControls /> </MusicPlayer>
      </div>
    </div>
  </div>;
