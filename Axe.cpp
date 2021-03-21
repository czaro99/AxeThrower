#include "Axe.h"

Axe::Axe(sf::Texture& texture, float x, float y)
{
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(sf::Vector2f(0.07f, 0.07f));
	movementSpeed = 300.f;
}

Axe::~Axe()
{
}

void Axe::setDirection(sf::Vector2f& direction)
{
	this->direction = direction;
}

void Axe::move(sf::Vector2f direction, const float& deltaTime)
{
	sprite.move(direction * deltaTime * movementSpeed);
}

void Axe::update(const float& deltaTime)
{
	move(direction, deltaTime);
	sprite.setOrigin(sf::Vector2f(sprite.getTextureRect().width/2, sprite.getTextureRect().height/2));
	sprite.rotate(8.60);
}

void Axe::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
