#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H
class Player{
    public:
        Player(sf::RenderWindow& window, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, float posX);
        void update();
        void render();
        sf::Vector2f position;
        sf::Vector2f size;
        
    private:
        sf::RenderWindow& window;
        sf::RectangleShape shape;
        sf::Keyboard::Key upKey;
        sf::Keyboard::Key downKey;

        float speed;

        bool colisions();
};

#endif // !PLAYER_H