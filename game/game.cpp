#include <iostream>
#include "game.h"
#include "./player/player.h"
#include "./ball/ball.h"

#include <SFML/Graphics.hpp>

Game::Game(int width, int height, std::string title){
    this->width = width;
    this->height = height;
    this->title = title;
};

void Game::run(){
    sf::RenderWindow window(sf::VideoMode(width, height), title);

    Player playerLeft(window, sf::Keyboard::W, sf::Keyboard::S, 0.f);
    Player playerRight(window, sf::Keyboard::Up, sf::Keyboard::Down, 970.f, true);
    Ball ball(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(10, 10, 10));

        playerLeft.update(ball.position);
        playerLeft.render();

        playerRight.update(ball.position);
        playerRight.render();

        ball.update(playerLeft, playerRight);
        ball.render();

        window.display();
    }
};