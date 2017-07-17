//
//  Enemy.cpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Enemy.hpp"
#include <math.h>
#include <iostream>


Enemy::Enemy(sf::Vector2f pos) {
    
    sf::IntRect Rect =  sprite.getTextureRect();
    sprite.setOrigin(Rect.width/2, Rect.height/2);
    sprite.scale(0.25,0.25);
    possision = pos;
    hp = 20;

    
    
}


void Enemy::loadEnemySprite(const sf::Texture & enemy_texture){
    
    
    sprite.setTexture(enemy_texture);
    
    
    
}

void Enemy::UpdatePossision(sf::Vector2f p_p){
   
    p_p.x -= 25;
    p_p.y -= 25;
    
    float offset_x = 0;
    float offset_y = 0;
    float ratio = 0;
    
    if (fabs(p_p.x - possision.x)< 5) {
        possision = p_p;
        
    } else
        
    {
    
    float a = fabs(possision.x - p_p.x);
    float b = fabs(possision.y - p_p.y);
    
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
    
    
    if (p_p.y<possision.y && p_p.x < possision.x)
    {
        
        
        
        offset_y*=-1;
        offset_x*=-1;
        
        
    } else
        
        if (p_p.y<possision.y && p_p.x > possision.x)
        {
            
            offset_y*=-1;
            
            
        }
    
        else
            
            if (p_p.y>possision.y && p_p.x < possision.x)
            {
                
                offset_x*=-1;
                
                
            }
    
    possision.x += offset_x;
    possision.y += offset_y;
        
    }
    
    sprite.setPosition(possision);
    
//    std::cout<<"Offset_x: "<<offset_x<<" Offset_y: "<<offset_y<<" Ratio: "<<ratio<<std::endl;
//    std::cout<<sprite.getPosition().x<<" "<<sprite.getPosition().y<<std::endl;
//    std::cout<<p_p.x<<" "<<p_p.y<<" "<<possision.x<<" "<<possision.y<<std::endl;
    

}




void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const    {
    
        target.draw(sprite);
    
}
