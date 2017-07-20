//
//  Player.hpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Entity.hpp"




class Player : public Entity{
    
    
    int counter = 0;
    int amount_of_frames = 1;
    
public:
    
    Player();
    
    float rotation;
    
    bool isGoingForward, isGoingBackward, isGoingLeft, isGoingRight;
    
    void loadSprites(sf::Texture *, sf::Texture *);
    
    sf::Sprite body_sprites [5];
    sf::Sprite riffle_shoot_sprites[3];
    
    
    void Shoot();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void UpdatePossision();
    void updateRotation(sf::Vector2i);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
};

#endif /* Player_hpp */
