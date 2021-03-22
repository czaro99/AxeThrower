#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "Enemy.h"
#include "Axe.h"
#include "Animation.h"


class Game
{
private:
	

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::Texture playerTexture;
	sf::Texture playerTexture_l;
	sf::Texture enemyTexture;
	sf::Texture axeTexture;
	sf::Texture backgroundTexture;
	
	

	sf::Sprite background;

	sf::Clock deltaTimeClock;
	float deltaTime;
	float x_pos;
	float y_pos;

	Player* player;
	std::vector<Enemy*> enemies;
	std::vector<Axe*> axes;
	std::vector<Entity*> removed;
	
	void initVariables();
	void initPlayer();
	void initEnemy();
	void initWindow();
	void initAxe(Player& player);
	bool axeCreate{true};

public:

	Game();
	~Game();

	const bool getWindowIsOpen() const;

	

	void pollEvents();
	void updateDeltaTime();
	void update();
	void render();

};

