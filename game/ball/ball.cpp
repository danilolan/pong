#include "./ball.h"
#include "../player/player.h"
#include <cmath>
#include <random>

bool rectangleCircleCollision(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangleSize, const sf::Vector2f& circlePosition, float circleRadius);
float generateRandomFloat(float min, float max);

Ball::Ball(sf::RenderWindow& window) :
    window(window) 
{
    this->speed = sf::Vector2f(0.02f, 0.05f);
    this->radius = 5.f;
    this->speedAcc = 0.005f;

    sf::CircleShape shape(this->radius);
    shape.setFillColor(sf::Color(220, 220, 220));
    this->shape = shape;
    this->position = sf::Vector2f(500.f, 500.f);
};

void Ball::update(Player& playerLeft, Player& playerRight){
    sf::Vector2f beforePosition = position;
    
    this->colisions(playerLeft, playerRight);
    
    position = position + speed;

    this->shape.setPosition(position);
};

void Ball::render(){
    this->window.draw(shape);
};

bool Ball::colisions(Player& playerLeft, Player& playerRight){
    if(position.y <= 0) speed.y = std::abs(speed.y);
    if(position.y + radius * 2 >= 1000) speed.y *= -1;

    std::cout << generateRandomFloat(-0.05f, 0.05f) << std::endl;

    if(rectangleCircleCollision(playerLeft.position, playerLeft.size, position, radius)){
        speed.x = std::abs(speed.x) + speedAcc;
        speed.y = generateRandomFloat(-0.1f, 0.1f);
    }

    if(rectangleCircleCollision(playerRight.position, playerRight.size, position, radius)){
        speed.x = (speed.x * (-1.f)) - speedAcc;
        speed.y = generateRandomFloat(-0.1f, 0.1f);
    }

    if(position.x > 1300) reset();
    if(position.x < -300) reset();

};

void Ball::reset(){
    speed = sf::Vector2f(0.02f, 0.05f);
    position = sf::Vector2f(500.f, 500.f);
}

bool rectangleCircleCollision(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangleSize, const sf::Vector2f& circlePosition, float circleRadius) {

    sf::Vector2f rectangleCenter = { rectanglePosition.x + rectangleSize.x / 2.0f, rectanglePosition.y + rectangleSize.y / 2.0f };

    float distanceX = std::abs(rectangleCenter.x - circlePosition.x);
    float distanceY = std::abs(rectangleCenter.y - circlePosition.y);

    if (distanceX > (rectangleSize.x / 2.0f + circleRadius)) {
        return false;
    }
    if (distanceY > (rectangleSize.y / 2.0f + circleRadius)) {
        return false;
    }
    
    if (distanceX <= rectangleSize.x / 2.0f) {
        return true;
    }
    if (distanceY <= rectangleSize.y / 2.0f) {
        return true;
    }

    float cornerDistance = std::pow(distanceX - rectangleSize.x / 2.0f, 2) + std::pow(distanceY - rectangleSize.y / 2.0f, 2);
    
    return cornerDistance <= std::pow(circleRadius, 2);
}

float generateRandomFloat(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(gen);
}