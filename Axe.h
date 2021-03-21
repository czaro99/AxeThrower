#pragma once
#include "Entity.h"
class Axe: public Entity
{





public:
	Axe(sf::Texture& texture, float x, float y);
	~Axe();
	void setDirection(sf::Vector2f& direction);
	virtual void move(sf::Vector2f direction, const float& deltaTime) override;
	virtual void update(const float& deltaTime) override;
	virtual void render(sf::RenderTarget* target) override;
};

