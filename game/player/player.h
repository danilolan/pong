#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H
class Player{
    public:
        Player(sf::RenderWindow& window);
        void update();
        void render();
    private:
        sf::RenderWindow& window;
        sf::Vector2f position;
        sf::RectangleShape shape;
        sf::Vector2f size;
        float speed;

        bool colisions();
};

#endif // !PLAYER_H