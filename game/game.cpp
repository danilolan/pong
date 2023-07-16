#include <iostream>
#include "game.h"

#include <SFML/Graphics.hpp>

Game::Game(int width, int height, std::string title){
    this->width = width;
    this->height = height;
    this->title = title;
};

void Game::run(){
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
};