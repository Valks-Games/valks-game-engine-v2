## Setup
Visual Studio 2019 or G++ is recommended, it is untested on other development environments.

Start by cloning the repository with `git clone --recursive https://github.com/valkyrienyanko/valks-game-engine-v2.git` (or your fork if you want to edit).

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

This project uses premake5. To build for windows, `cd scripts` and run `vs2019.bat` and then open parent dir with visual studio 2019. Run from inside VS. For linux, `cd scripts`, `chmod +x linux.sh` then `./linux.sh` to build make files, then `cd ..` and `make` to build. `cd bin` and `./engine` to run.
