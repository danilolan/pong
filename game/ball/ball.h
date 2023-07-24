#include <SFML/Graphics.hpp>
#include "../player/player.h"

#ifndef BALL_H
#define BALL_H

class Ball{
    public:
        Ball(sf::RenderWindow& window);

        void update(Player& playerLeft, Player& playerRight);
        void render();
    private:
        sf::RenderWindow& window;
        sf::CircleShape shape;
        float radius;
        sf::Vector2f position;

        sf::Vector2f speed;

        bool colisions(Player& playerLeft, Player& playerRight);
};

#endif // !BALL_H