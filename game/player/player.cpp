#include "player.h"
#include <iostream>

Player::Player(sf::RenderWindow& window): 
    window(window)
{
    this->size = sf::Vector2f(30.f, 200.f);

    sf::RectangleShape shape(size);
    shape.setFillColor(sf::Color(220, 220, 220));
    this->shape = shape;

    this->speed = 0.1;
};

void Player::update(){
    sf::Vector2f beforePosition = position;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        position.y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y -= speed;
    }

    if(this->colisions()){
        position = beforePosition;
    }

    shape.setPosition(position);
}

void Player::render(){
    window.draw(shape);
}

bool Player::colisions(){
    //bounderies
    if(position.y < 0) return true;
    if(position.y + size.y > 1000) return true;

    return false;
}