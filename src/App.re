open ReactUtils;

[@react.component]
let make = () =>
  <div className="section is-fullheignt">
    <div className="container">
      <h1 className="is-size-2 has-text-centered is-capitalized">
        {s("Reason Music Player")}
      </h1>
      <br />
      <div className="column is-4 is-offset-4">
        <MusicPlayer> <TrackList /> <PlayerControls /> </MusicPlayer>
      </div>
    </div>
  </div>;
