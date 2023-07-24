#include <SFML/Graphics.hpp>
#include "../player/player.h"

#ifndef BALL_H
#define BALL_H

class Ball{
    public:
        Ball(sf::RenderWindow& window);
        sf::Vector2f position;

        void update(Player& playerLeft, Player& playerRight);
        void render();
        void reset();
    private:
        sf::RenderWindow& window;
        sf::CircleShape shape;
        float radius;
        float speedAcc;

        sf::Vector2f speed;

        void colisions(Player& playerLeft, Player& playerRight);
};

#endif // !BALL_H