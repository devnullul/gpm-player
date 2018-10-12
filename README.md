Google Play Music Player
======

This is a "wrapper" (it's really just a super simplistic browser) for Google Play Music. As Google offers no official application for Linux and other current solutions rely on electron, this is a nice, low-resource alternative.

This application was "forked" from https://github.com/mintsuki/discord-player
Again, it's just a browser so all I did was replace URLs and strings.

### Build Dependencies

#### Debian & Ubuntu

On Debian and Ubuntu, discord-player depends on the following packages:

`build-essential qt5-qmake qtbase5-dev qt5-default qtwebengine5-dev`

#### Arch Linux

On Arch, it depends on qt5, which can be installed with:

`sudo pacman -S qt5`

Then install all selections.

#### Void

On Void, install the following:

`qt5-devel`

There are surely more I'm missing, please let me know if this is the case.

#### Fedora

First, install the dependencies:

`qt5-qtbase-devel qt5-qtwebengine qt5-qtwebengine-devel`

On Fedora, the `qmake` binary has a different name than on most distributions (why? no clue), so do the following before building:

`sudo ln -s /usr/bin/qmake-qt5 /usr/bin/qmake`

### Building

To configure the package, use the ./configure script:

    `./configure`

Or, if you want to specify a custom prefix:

    `./configure --prefix=/my/custom/path`

To build, just run:

    `make`

To install it run:

    `make install`

(or `sudo make install` if you need admin privileges)

##### Please support mintsuki, the person I more or less copied this from, link to his repository above!
