#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture, float x, float y)
{
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	movementSpeed = 50.f;	
	
	
}

Enemy::~Enemy()
{
}



void Enemy::move(sf::Vector2f direction, const float& deltaTime)
{
	sprite.move(movementSpeed * direction * deltaTime);
}

void Enemy::update(const float& deltaTime)
{
	temp += deltaTime;
	if (temp > 2) {
		angle = rand() % 360;
		temp = 0;
	}
		
	direction.x = cos(angle / 360 * 2 * 3.14159265);
	direction.y = sin(angle / 360 * 2 * 3.14159265);
	move(direction, deltaTime);
	

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(sprite);
	
}
