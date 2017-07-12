//
//  Bullet.cpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Bullet.hpp"
#include <cmath>
#include <iostream>

Bullet::Bullet(sf::Vector2f pl_pos, sf::Vector2i _mousePosition){

    mousePosition = _mousePosition;
    possision = pl_pos;
    bullet_sprite.setPosition(pl_pos);
    sf::IntRect Rect =  bullet_sprite.getTextureRect();
    bullet_sprite.setOrigin(Rect.width/2, Rect.height/2);
    bullet_sprite.scale(0.025,0.025);

}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const    {
    
    
        target.draw(bullet_sprite ,states);
        
    
}

void Bullet::loadBulletSprite(const sf::Texture & tex){

    bullet_sprite.setTexture(tex);
    

}


void Bullet::updateRotation(float p_r){
    
    
    rotation = p_r;
    bullet_sprite.setRotation(p_r);
    
}


void Bullet::UpdatePossision(){
    
    
    float a = fabs(possision.x - mousePosition.x);
    float b = fabs(possision.y - mousePosition.y);
    
    
    
    if (mousePosition.y<possision.y && mousePosition.x < possision.x)
    {
        
        if (a>b)
            
            bullet_sprite.move(-a/b, -1);
        
        else
            
            bullet_sprite.move(-1 , -b/a);
        
        
    } else
        
        if (mousePosition.y<possision.y && mousePosition.x > possision.x)
        {
            if (a>b)
                
                bullet_sprite.move(a/b, -1);
            
            else
                
                bullet_sprite.move(1 , -b/a);
            
            
        } else
            
            if (mousePosition.y>possision.y && mousePosition.x > possision.x)
            {
                if (a>b)
                    
                    bullet_sprite.move(a/b, 1);
                
                else
                    
                    bullet_sprite.move(1 , b/a);
                
                
                
            } else
                
                if (mousePosition.y>possision.y && mousePosition.x < possision.x)
                {
                    if (a>b)
                        
                        bullet_sprite.move(-a/b, 1);
                    
                    else
                        
                        bullet_sprite.move(-1 , b/a);
                    
                    
                }
    
    
    

    
    
}


