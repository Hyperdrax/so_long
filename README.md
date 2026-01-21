This project has been created as part of the 42 curriculum by flhensel.

## Description

This project, is a basic 2D game called "so_long." The goal of the game is to navigate a player character through maps, collect coins and bringing them to your chest. 

The game serves as an introduction to game development concepts and graphics programming within the context of the C programming language.

## Instructions

### Build
- Install required X11 dev packages (on Debian/Ubuntu: `sudo apt install libx11-dev libxext-dev libbsd-dev`) if not already present.
- From the project root: `make` (or `make re` to rebuild all).

### Run
- Launch with a `.ber` map: `./so_long maps/map1.ber`
- Controls: `W/A/S/D` or arrow keys to move; `ESC` or window close (X) to quit.

### Notes
- Map files must use the `.ber` extension and pass validation (rectangular, walled borders, 1 player, 1 exit, at least 1 collectable, all reachable).

## Resources

Dependencies:
- https://github.com/42Paris/minilibx-linux
- https://github.com/Hyperdrax/get_next_line
- https://github.com/Hyperdrax/libft

Usage and Documentation for MiniLibX:
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

Game Assets:
- https://711studios.itch.io/15-pixel-art-textures
- https://merchant-shade.itch.io/16x16-mixed-rpg-icons
- https://pixelfrog-assets.itch.io/tiny-swords

Tutorials:
- https://www.youtube.com/watch?v=RwgKqA9j3JE

### Ai usage
AI assisted with understanding, repetitive tasks (texture loading, error handling), and debugging. All code was verified for correctness and understanding by me.