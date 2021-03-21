#pragma once
#include "Entity.h"
class Enemy : public Entity
{
private:
	
	float temp=0;
	

public:

	Enemy(sf::Texture& texture, float x, float y);
	~Enemy();
	

	virtual void move(sf::Vector2f direction, const float& deltaTime) override;
	virtual void update(const float& deltaTime) override;
	virtual void render(sf::RenderTarget* target) override;
};

