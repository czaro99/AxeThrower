#include "Animation.h"

Animation::Animation(std::vector<sf::Texture> textures, float time)
{
	this->textures = textures;
	this->time = time;
	this->currentId = 0;
	this->clock = 0.f;
}

Animation::~Animation()
{

}

void Animation::reset()
{
	isAnimationFinished = false;
	this->clock = 0;
}

void Animation::update(float deltaTime)
{
	clock += deltaTime;
	if (clock > time) {
		clock = 0;
		++currentId;
		if (currentId > textures.size() - 1) {
			currentId = 0;
			isAnimationFinished = true;
		}
			
	}
	
	
}

sf::Texture &Animation::getCurrentTexture()
{
	return textures.at(currentId);
}

