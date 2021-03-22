#include "Game.h"


void Game::initVariables()
{
    this->window = nullptr;
    srand(time(NULL));
   
    playerTexture.loadFromFile("assets/knight.png");
   
    playerTexture_l.loadFromFile("assets/knight_left.png");
    enemyTexture.loadFromFile("assets/enemy1.png");
    axeTexture.loadFromFile("assets/axe.png");
    backgroundTexture.loadFromFile("assets/background.png");
    background.setTexture(backgroundTexture);
    
    
    
    
 
}


void Game::initPlayer()
{
  
    player = new Player(playerTexture, (window->getSize().x) / 2.0, (window->getSize().y) / 2.0);
    
    
}
void Game::initEnemy()
{
    x_pos = rand() % window->getSize().x;
    y_pos = rand() % window->getSize().y;
    enemies.push_back(new Enemy(enemyTexture, x_pos, y_pos));
   
}
void Game::initAxe(Player& player)
{
    Axe* a = new Axe(axeTexture, player.sprite.getPosition().x, player.sprite.getPosition().y);
    sf::Vector2f* v = new sf::Vector2f(sf::Mouse::getPosition(*window).x-(player.sprite.getPosition().x), sf::Mouse::getPosition(*window).y - (player.sprite.getPosition().y));
    float length = sqrt(v->x * v->x + v->y * v->y);
    *v /= length;
    a->setDirection(*v);
    axes.push_back(a);
    
}


void Game::initWindow()
{
    this->videoMode.height = 768;
    this->videoMode.width = 1024;
    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);

}

Game::Game()
{
    initVariables();

    initWindow();
    
    initPlayer();

   
  

}

Game::~Game()
{
    delete window;
    delete player;
    for (auto e : enemies)
        delete e;
    for (auto a : axes)
        delete a;
    for (auto r : removed)
        delete r;
   
}

const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}



void Game::pollEvents()
{
    while (window->pollEvent(event)) {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;      
            

        }

        

    }

    
}

void Game::updateDeltaTime()
{
    deltaTime = deltaTimeClock.restart().asSeconds();
}


void Game::update()
{
    pollEvents();

    while(enemies.size()<7)
        initEnemy();
   
   
    player->update(deltaTime, playerTexture, playerTexture_l);

    for(auto enemy: enemies)
    enemy->update(deltaTime);

    for (auto a : axes)
        a->update(deltaTime);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && axeCreate) {
        axeCreate = false;
        
        initAxe(*player);
        
    }
    else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        
        axeCreate = true;
    }

    for (auto e : enemies)
        if (player->intersect(e)) {
            std::cout << "bam\n";
            sf::Vector2f* v = new sf::Vector2f(e->sprite.getPosition().x - (player->sprite.getPosition().x), e->sprite.getPosition().y - (player->sprite.getPosition().y));
            float length = sqrt(v->x * v->x + v->y * v->y);
            *v /= length/1.5f;
            player->sprite.setPosition(player->sprite.getPosition()-*v);
           
           
        }
            


    
    for (auto a : axes)
        for (auto e : enemies)
            if (a->intersect(e)) {
                removed.push_back(a);
                removed.push_back(e);           
            }

    for (auto r : removed) {
        auto it_a = std::find(axes.begin(), axes.end(), r);
        auto it_e = std::find(enemies.begin(), enemies.end(), r);
        
        if (it_a != axes.end())
        {
            axes.erase(it_a);
        }
        if (it_e != enemies.end())
        {
            enemies.erase(it_e);
        }
     }
            


}

void Game::render()
{
    window->clear(sf::Color::Black);
    window->draw(background);
    player->render(window);
    for (auto enemy : enemies)
    enemy->render(window);
    for (auto a : axes)
        a->render(window);
    window->display();
}
