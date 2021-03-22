#pragma once
#include <vector>
#include "Entity.h"
class Animation
{
private:
	std::vector<sf::Texture> textures;
	float time;
	float clock;
	int currentId;
	
public:
	bool isAnimationFinished;
	Animation(std::vector<sf::Texture> textures, float time);
	~Animation();
	void reset();
	void update(float deltaTime);
	sf::Texture &getCurrentTexture();
};

