#include "./ball.h"
#include "../player/player.h"
#include <cmath>

bool rectangleCircleCollision(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangleSize, const sf::Vector2f& circlePosition, float circleRadius);

Ball::Ball(sf::RenderWindow& window) :
    window(window) 
{
    this->speed = sf::Vector2f(0.02f, 0.05f);
    this->radius = 5.f;

    sf::CircleShape shape(this->radius);
    shape.setFillColor(sf::Color(220, 220, 220));
    this->shape = shape;
    this->shape.setPosition(sf::Vector2f(500.f, 500.f));
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

    std::cout << playerLeft.position.x << "\n";

    if(rectangleCircleCollision(playerLeft.position, playerLeft.size, position, radius))
        speed.x = std::abs(speed.x);

    if(rectangleCircleCollision(playerRight.position, playerRight.size, position, radius))
        speed.x *= -1.f;

};

bool rectangleCircleCollision(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangleSize, const sf::Vector2f& circlePosition, float circleRadius) {
    // Check for collision between a rectangle and a circle
    
    // Find the center point of the rectangle
    std::cout << rectanglePosition.x << std::endl;
    sf::Vector2f rectangleCenter = { rectanglePosition.x + rectangleSize.x / 2.0f, rectanglePosition.y + rectangleSize.y / 2.0f };
    
    // Calculate the distance between the circle's center and the rectangle's center
    float distanceX = std::abs(rectangleCenter.x - circlePosition.x);
    float distanceY = std::abs(rectangleCenter.y - circlePosition.y);
    
    // Check if the distance between the centers is greater than the sum of the radii
    if (distanceX > (rectangleSize.x / 2.0f + circleRadius)) {
        return false;
    }
    if (distanceY > (rectangleSize.y / 2.0f + circleRadius)) {
        return false;
    }
    
    // Check if the distance between the centers is less than or equal to the sum of the radii
    if (distanceX <= rectangleSize.x / 2.0f) {
        return true;
    }
    if (distanceY <= rectangleSize.y / 2.0f) {
        return true;
    }
    
    // Check collision at the corners of the rectangle
    float cornerDistance = std::pow(distanceX - rectangleSize.x / 2.0f, 2) + std::pow(distanceY - rectangleSize.y / 2.0f, 2);
    
    return cornerDistance <= std::pow(circleRadius, 2);
}