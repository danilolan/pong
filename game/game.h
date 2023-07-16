#include <iostream>

#ifndef GAME_H
#define GAME_H

class Game {
    public:
        Game(int width, int height, std::string title);
        void run();
    private:
        int width;
        int height;
        std::string title;
};
#endif // Game