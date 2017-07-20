//
//  Enemy.hpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Enemy : public Entity {
    
    
    
    
    int speed = 1;
    float rotation;
    
    
    
    public:
    
    bool touched;
    void updateRotation(sf::Vector2f) noexcept;
    sf::Sprite sprite;
    Enemy(sf::Vector2f);
    void UpdatePossision(sf::Vector2f);
    void loadEnemySprite(const sf::Texture &);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    
    
};


#endif /* Enemy_hpp */
