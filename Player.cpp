#include "Player.h"



Player::Player(sf::Texture& texture, float x, float y)
{
    sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(sf::Vector2f(0.07f, 0.07f));
	movementSpeed = 100.f;
    canMove = true;
    
}


Player::~Player()
{
}

void Player::move(sf::Vector2f direction, const float& deltaTime)
{
    if(canMove)
    sprite.move(direction*movementSpeed*deltaTime);
}

void Player::update(const float& deltaTime)
{
}

void Player::update(const float& deltaTime, sf::Texture& texture_r, sf::Texture& texture_l)
{
    direction.x = direction.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction.x = -1.f;
        sprite.setTexture(texture_l);
       // canMove = true;
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction.x = 1.f;
        sprite.setTexture(texture_r);
       // canMove = true;
    }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction.y = 1.f;
           // canMove = true;
    }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction.y = -1.f;
           // canMove = true;
    }
        
    
    move(direction, deltaTime);
    

        

}

void Player::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
