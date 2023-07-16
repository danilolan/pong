#include <iostream>
#include "game.h"
#include "./player/player.h"

#include <SFML/Graphics.hpp>

Game::Game(int width, int height, std::string title){
    this->width = width;
    this->height = height;
    this->title = title;
};

void Game::run(){
    sf::RenderWindow window(sf::VideoMode(width, height), title);

    Player player(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(10, 10, 10));

        player.update();
        player.render();

        window.display();
    }
};