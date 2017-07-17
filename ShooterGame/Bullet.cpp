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
    sprite.setPosition(pl_pos);
    sf::IntRect Rect =  sprite.getTextureRect();
    sprite.setOrigin(Rect.width/2, Rect.height/2);
    sprite.scale(0.025,0.025);
    
    
    ratio = 0;
    float a = fabs(possision.x - mousePosition.x);
    float b = fabs(possision.y - mousePosition.y);
    
    if (a>b) {
        
        ratio = a/b;
        
        offset_x = sqrt((speed*speed) / (1 + (1/(ratio*ratio))));
        offset_y = sqrt((speed*speed)/(ratio*ratio +1));
        
        
        
        
    } else if (b>a) {
        
        ratio = b/a;
        
        offset_y = sqrt((speed*speed) / (1 + (1/(ratio*ratio))));
        offset_x = sqrt((speed*speed)/(ratio*ratio +1));
        
    } else {
        
        offset_y = speed;
        offset_x = speed;
        
    }
    
    
    if (mousePosition.y<possision.y && mousePosition.x < possision.x)
    {
        
        
            
        offset_y*=-1;
        offset_x*=-1;
        
        
    } else
        
        if (mousePosition.y<possision.y && mousePosition.x > possision.x)
        {
            
            offset_y*=-1;
            
            
        }
    
        else
                
                if (mousePosition.y>possision.y && mousePosition.x < possision.x)
                {
                    
                    offset_x*=-1;
                    
                    
                }
    

}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const    {
    
    
        target.draw(sprite ,states);
        
    
}

void Bullet::loadBulletSprite(const sf::Texture & tex){

    sprite.setTexture(tex);
    

}


void Bullet::updateRotation(float p_r){
    
    
    rotation = p_r;
    sprite.setRotation(p_r);
    
}


void Bullet::UpdatePossision(){
    
    
    possision.x += offset_x;
    possision.y += offset_y;
    
    sprite.setPosition(possision);
    
   
    
    
    //std::cout<<"Offset_x: "<<offset_x<<" Offset_y: "<<offset_y<<" Ratio: "<<ratio<<std::endl;
    
    
    
    
    

    
    
}


