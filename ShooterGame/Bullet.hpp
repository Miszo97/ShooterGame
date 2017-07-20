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
    float ratio;
    float offset_x;
    float offset_y;
    
    sf::Vector2i mousePosition;
   
    int speed = 15;
    
public:
    Bullet(sf::Vector2f, sf::Vector2i);
    ~Bullet();
    void UpdatePossision();
    void updateRotation(float);
    void setInitialPos(float) noexcept;
    
    
    
    sf::Sprite sprite;
    sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(50,50));
    

    void loadBulletSprite(const sf::Texture &);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
};

#endif /* Bullet_hpp */


