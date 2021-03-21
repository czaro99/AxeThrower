#include "Entity.h"



Entity::Entity()
{
	

}

Entity::~Entity()
{
}

bool Entity::intersect(Entity* e)
{
	return this->sprite.getGlobalBounds().intersects(e->sprite.getGlobalBounds());
}

void Entity::setMovementSpeed(float ms)
{
	this->movementSpeed = ms;
}

void Entity::move(sf::Vector2f direction, const float& deltaTime)
{
	
}

void Entity::update(const float& deltaTime)
{
        
}

void Entity::render(sf::RenderTarget* target)
{
	
}
