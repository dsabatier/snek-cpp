# Snek Ate the Doot

A tiny snake/nibblet clone to learn C++ and Raylib. I applied to an Unreal 5 job with no C++ or Unreal experience, and was not expecting to get a call back.  After a couple of interviews I needed to write a tech test and realized I needed to learn C++ :)  I wrote this snake clone from scratch with no tutorial except for what was in the Raylib docs.

## Overview

- main.cpp runs a basic game loop: It updates the state of the currently running scene, the draws it to the screen, and on and on.
- 
- The scene system let me manage the few scenes I needed without much overhead.  Each update the game checks if the current scene wants to load a new scene, and if it does the current scene gets cleaned up, then the next scene is initialized and loaded.
- 
- As the position I was applying for was a UI programming role, I spent time polishing the main menu with music, sfx and simple feedback inspired by arcade games of the 80s
