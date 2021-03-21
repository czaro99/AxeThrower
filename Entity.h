#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cstdlib>
#include <cmath>
class Entity
{
private:
	



protected:
	
	float movementSpeed;
	float angle;

public:
	sf::Sprite sprite;
	sf::Vector2f direction;
	Entity();
	~Entity();
	bool intersect(Entity* e);
	void setMovementSpeed(float ms);
	virtual void move(sf::Vector2f direction, const float& deltaTime) = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget *target) = 0;

};

