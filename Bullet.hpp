//
//  Bullet.hpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "Element.hpp"
#include <SFML/Graphics.hpp>


class Bullet : public Element {
    
    float rotation;
    sf::Vector2i mousePosition;
    
public:
    Bullet(sf::Vector2f, sf::Vector2i);
    void UpdatePossision();
    void updateRotation(float);
    
    
    
    sf::Sprite bullet_sprite;
    sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(50,50));
    

    void loadBulletSprite(const sf::Texture &);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
};

#endif /* Bullet_hpp */


