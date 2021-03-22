#include "Player.h"



Player::Player(sf::Texture& texture, float x, float y)
{
    sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(sf::Vector2f(0.07f, 0.07f));
    sprite.setOrigin(sf::Vector2f(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2));
	movementSpeed = 100.f;

    std::vector<sf::Texture> walkTextures;
    std::vector<sf::Texture> throwTextures;
    sf::Texture tex0;
    tex0.loadFromFile("assets/knight_walk_right/walk000.png");
    walkTextures.push_back(tex0);

    sf::Texture tex1;
    tex1.loadFromFile("assets/knight_walk_right/walk001.png");
    walkTextures.push_back(tex1);

    sf::Texture tex2;
    tex2.loadFromFile("assets/knight_walk_right/walk002.png");
    walkTextures.push_back(tex2);

    sf::Texture tex3;
    tex3.loadFromFile("assets/knight_walk_right/walk003.png");
    walkTextures.push_back(tex3);

    sf::Texture tex4;
    tex4.loadFromFile("assets/knight_walk_right/walk004.png");
    walkTextures.push_back(tex4);

    sf::Texture tex5;
    tex5.loadFromFile("assets/knight_walk_right/walk005.png");
    walkTextures.push_back(tex5);

    sf::Texture tex6;
    tex6.loadFromFile("assets/knight_walk_right/walk006.png");
    walkTextures.push_back(tex6);

    sf::Texture t0;
    t0.loadFromFile("assets/throwTextures/_ATTACK_000.png");
    throwTextures.push_back(t0);
    sf::Texture t1;
    t1.loadFromFile("assets/throwTextures/_ATTACK_001.png");
    throwTextures.push_back(t1);
    sf::Texture t2;
    t2.loadFromFile("assets/throwTextures/_ATTACK_002.png");
    throwTextures.push_back(t2);
    sf::Texture t3;
    t3.loadFromFile("assets/throwTextures/_ATTACK_003.png");
    throwTextures.push_back(t3);
    sf::Texture t4;
    t4.loadFromFile("assets/throwTextures/_ATTACK_004.png");
    throwTextures.push_back(t4);
    sf::Texture t5;
    t5.loadFromFile("assets/throwTextures/_ATTACK_005.png");
    throwTextures.push_back(t5);
    sf::Texture t6;
    t6.loadFromFile("assets/throwTextures/_ATTACK_006.png");
    throwTextures.push_back(t6);



    walking = new Animation(walkTextures, 0.1f);
    throwing = new Animation(throwTextures, 0.1f);
  
    
}


Player::~Player()
{
}

void Player::move(sf::Vector2f direction, const float& deltaTime)
{
    
    sprite.move(direction*movementSpeed*deltaTime);
}

void Player::update(const float& deltaTime)
{
}

void Player::update(const float& deltaTime, sf::Texture& texture_r, sf::Texture& texture_l)
{
    bool isMoving= false;
    bool isAttacking= false;
   

    direction.x = direction.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        isMoving = true;
        right = false;
        direction.x = -1.f;
        
      
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        isMoving = true;
        right = true;
        direction.x = 1.f;
        
       
    }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            isMoving = true;
            direction.y = 1.f;
          
    }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            isMoving = true;
            direction.y = -1.f;
          
    }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            isAttacking = true;

        if (!(animation == throwing && animation != nullptr ? !animation->isAnimationFinished : false)) {
            if (isAttacking) {
                if (animation == nullptr || animation == walking) {
                    animation = throwing;
                    animation->reset();
                }

            }
            else if (isMoving) {
                if (animation == nullptr) {
                    animation = walking;
                    animation->reset();
                }

            }
            

            else {
                animation = nullptr;
                sprite.setTexture(texture_r);
            }
        }
        
            
        
    
    move(direction, deltaTime);
   
    if (animation != nullptr) {
        animation->update(deltaTime);
    }
        

}

void Player::render(sf::RenderTarget* target)
{
    if (animation != nullptr) {
      sprite.setTexture(animation->getCurrentTexture());
      sprite.setOrigin(sf::Vector2f(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2));
      sprite.setScale((right ? 0.07f :-0.07f), 0.07f);
    }
	target->draw(sprite);
}
