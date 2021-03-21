#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:

public:

	bool canMove;

	Player(sf::Texture& texture, float x, float y);
	~Player();
	void update(const float& deltaTime, sf::Texture& texture_r, sf::Texture& texture_l);
	virtual void move(sf::Vector2f direction, const float& deltaTime) override;
	virtual void update(const float& deltaTime) override;
	virtual void render(sf::RenderTarget* target) override;
};

