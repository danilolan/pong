#include "player.h"
#include <iostream>

Player::Player(sf::RenderWindow& window, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, float posX, bool isBot): 
    window(window)
{
    this->downKey = downKey;
    this->upKey = upKey;

    this->size = sf::Vector2f(30.f, 200.f);
    this->position = sf::Vector2f(posX, 0.f);

    this->isBot = isBot;

    sf::RectangleShape shape(size);
    shape.setFillColor(sf::Color(220, 220, 220));
    this->shape = shape;

    this->speed = 0.1;
};

void Player::update(sf::Vector2f ballPosition){
    sf::Vector2f beforePosition = position;

    if(isBot){
        position.y = ballPosition.y - (size.y / 2);
    }
    else {
        if (sf::Keyboard::isKeyPressed(this->downKey))
        {
            position.y += speed;
        }
        if (sf::Keyboard::isKeyPressed(this->upKey))
        {
            position.y -= speed;
        }
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