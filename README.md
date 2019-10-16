<!-- PROJECT SHIELDS -->

[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/sophiabrandt/reason-music-player">
    <img src="logo.png" alt="Logo">
  </a>

  <h3 align="center">Reason Music Player</h3>

  <p align="center">
    A simple music player built with ReasonReact and useContext
    <br />
    <a href="https://github.com/sophiabrandt/reason-music-player"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://sophiabrandt.github.io/reason-music-player/">View Demo</a>
    ·
    <a href="https://github.com/sophiabrandt/reason-music-player/issues">Report Bug</a>
    ·
    <a href="https://github.com/sophiabrandt/reason-music-player/issues">Request Feature</a>
  </p>
</p>

<!-- TABLE OF CONTENTS -->

## Table of Contents

- [About the Project](#about-the-project)
  - [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)
- [Acknowledgements](#acknowledgements)

<!-- ABOUT THE PROJECT -->

## About The Project

> A ReasonReact music player with the React Context API

This is a port of the James King's blog post **[How to Use the useContext Hook in React][upmostly]** to ReasonReact.

**☞ [View Demo][demo]**

### Built With

- [ReasonML](https://reasonml.github.io/)
- [ReasonReact](https://reasonml.github.io/reason-react/)
- [Bulma](https://bulma.io)

<!-- GETTING STARTED -->

## Getting Started

To get a local copy up and running follow these steps:

### Prerequisites

You need [Node.js](https://nodejs.org/en/) with npm or yarn.

- npm

```sh
npm install npm@latest -g
```

- yarn

```sh
npm install yarn -g
```

Install [Bucklescript and Reason](https://reasonml.github.io/docs/en/installation):

```sh
npm install -g bs-platform --unsafe-perm
```
or

```sh
yarn global add bs-platform --unsafe-perm
```

(I use [pnpm](https://pnpm.js.org/) for installing local packages, that's why you'll find a `pnpm-lock.yml` file in this repository.)

For **editor support**, check the [Reason Docs](https://reasonml.github.io/docs/en/editor-plugins).  
For Vim, you can check my blog post about [ReasonML Development With Vim](https://www.rockyourcode.com/reason-ml-development-with-vim).

### Installation

1. Clone the repo

```sh
git clone https://github.com/sophiabrandt/reason-music-player.git
```

(Alternatively, use [degit](https://github.com/Rich-Harris/degit): `npx degit sophiabrandt/reason-music-player reason-music-player`).

3. Install NPM packages

```sh
cd reason-music-player && npm install
```

<!-- USAGE EXAMPLES -->

## Usage

Run the project locally under `http://localhost:3000` via:

```sh
npm run start
```

Create a production build:

```sh
npm run build
```

<!-- ROADMAP -->

## Roadmap

See the [open issues](https://github.com/sophiabrandt/reason-music-player/issues) for a list of proposed features (and known issues).

<!-- CONTRIBUTING -->

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE` for more information.

<!-- CONTACT -->

## Contact

Sophia Brandt - [@hisophiabrandt](https://twitter.com/hisophiabrandt)

Project Link: [https://github.com/sophiabrandt/reason-music-player](https://github.com/sophiabrandt/reason-music-player)

<!-- ACKNOWLEDGEMENTS -->

## Acknowledgements

- [How to Use the useContext Hook in React][upmostly]
- [Bensound][bensound]
- [Img Shields](https://shields.io)
- [Choose an Open Source License](https://choosealicense.com)
- [Best-README-Template](https://github.com/othneildrew/Best-README-Template/blob/master/README.md)

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/sophiabrandt/reason-music-player.svg?style=flat-square
[contributors-url]: https://github.com/sophiabrandt/reason-music-player/graphs/contributors
[issues-shield]: https://img.shields.io/github/issues/sophiabrandt/reason-music-player.svg?style=flat-square
[issues-url]: https://github.com/sophiabrandt/reason-music-player/issues
[license-shield]: https://img.shields.io/github/license/sophiabrandt/reason-music-player.svg?style=flat-square
[license-url]: https://github.com/sophiabrandt/reason-music-player/blob/master/LICENSE.txt
[upmostly]: https://upmostly.com/tutorials/how-to-use-the-usecontext-hook-in-react
[bensound]: https://www.bensound.com/
[demo]: https://sophiabrandt.github.io/reason-music-player/
