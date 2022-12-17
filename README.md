
# so_long

Welcome to so_long, a 2D game written in C!

## Requirements

-   A C compiler (such as GCC)
-   in Linux, Libraries: libXext, libX11 ,
    to install these dependencies, run:
    
`sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`

-   in mac, compiling flags are: -framework OpenGL -framework AppKit

## Installation

1.  Clone the repository to your local machine:

Copy code

`git clone https://github.com/hu8813/so_long.git` 

2.  Navigate to the repository directory:

Copy code

`cd so_long` 

3.  Compile the game using the Makefile:

Copy code

`make` 

This will create an executable file called `so_long`.

## Running the game

To start the game, simply run the executable ait a path to map file as parameter:

Copy code

`./so_long maps/map.ber` 

## Controls

-   Use the W A S D keys to move the player character
-   Press the ESC or click (X) to exit
