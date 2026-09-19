# Snek Ate the Doot

A tiny snake/nibblet clone to learn C++ and Raylib. I applied to an Unreal 5 job with no C++ or Unreal experience, and was not expecting to get a call back.  After a couple of interviews I needed to write a tech test and realized I needed to learn C++ :)  I wrote this snake clone from scratch with no tutorial except for what was in the Raylib docs.

## Overview

- main.cpp runs a basic game loop: It updates the state of the currently running scene, the draws it to the screen, and on and on.
  
- The scene system let me manage the few scenes I needed without much overhead.  Each update the game checks if the current scene wants to load a new scene, and if it does the current scene gets cleaned up, then the next scene is initialized and loaded.
  
- As the position I was applying for was a UI programming role, I spent time polishing the main menu with music, sfx and simple feedback inspired by arcade games of the 80s

## Setup and running

### Prerequisites

You need:

- [CMake](https://cmake.org/download/) 3.0 or newer
- A C++ compiler and build toolchain
  - Windows: MinGW-w64 is recommended for the linker settings in this project
  - macOS: Xcode Command Line Tools
  - Linux: GCC or Clang, Make, and the OpenGL/X11 development packages required by raylib

raylib is included in `libs/raylib`, so it is built as part of this project; you do not need to install raylib separately.

### Clone the repository

```bash
git clone https://github.com/dsabatier/snek-cpp.git
cd snek-cpp
```

### Build
```
cmake -S . -B build
cmake --build build
```

### Play

Run SNEK or SNEK.exe
