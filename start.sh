#!/bin/bash
g++ main.cpp game/game.cpp game/player/player.cpp game/ball/ball.cpp -o prog -lsfml-window -lsfml-system -lsfml-graphics
./prog