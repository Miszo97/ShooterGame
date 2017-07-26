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
#include <random>

std::random_device rseed;
std::mt19937 rgen(rseed());
std::uniform_int_distribution<int> range(0,800);
std::uniform_int_distribution<int> range2(0,600);
std::uniform_int_distribution<int> side(1,4);


Enemy::Enemy(sf::Vector2f pos) {
    
    sf::IntRect Rect =  sprite.getTextureRect();
    sprite.setOrigin(Rect.width/2, Rect.height/2);
    sprite.scale(0.25,0.25);
    touched = false;
    
    hp = 20;
    
   //possision = sf::Vector2f(range(rgen), range2(rgen));
    
    
    
    
    switch (side(rgen)) {
    case 1:
        possision = possision = sf::Vector2f(0, range2(rgen));
    break;
        
    case 2:
        possision = possision = sf::Vector2f(range(rgen), 600);
        break;
        
    case 3:
        possision = possision = sf::Vector2f(800, range2(rgen));
        break;
        
    case 4:
        possision = possision = sf::Vector2f(range(rgen), 0);
        break;
        
    default:
        break;
        
    }

    
    
}


bool Enemy::abilityToAtack(){

    if(touched && clock.getElapsedTime().asSeconds() > atackAfter.asSeconds()){
    
        clock.restart();
        return true;
    
    
    }
    
    return false;



}

void Enemy::updateRotation(sf::Vector2f p_p) noexcept {
    
    double a = 0;
    double b = 0;
    
    
    
    if (p_p.y<possision.y && p_p.x < possision.x)
    {
        
        a = fabs(p_p.x - possision.x);
        b = fabs(p_p.y - possision.y);
        
        rotation = atan(a/b) * 180 / 3.14159265 * -1;
        //std::cout<<"a/b "<<a/b<<" "<<rotation<<std::endl;
    } else
        
        if (p_p.y<possision.y && p_p.x > possision.x)
        {
            a = fabs(p_p.x - possision.x);
            b = fabs(p_p.y - possision.y);
            
            rotation = atan(a/b) * 180 / 3.14159265;
            // std::cout<<"a/b "<<a/b<<" "<<rotation<<std::endl;
            
            
        } else
            
            if (p_p.y>possision.y && p_p.x > possision.x)
            {
                a = fabs(p_p.x - possision.x);
                b = fabs(p_p.y - possision.y);
                
                rotation = (atan(b/a) * 180 / 3.14159265) + 90;
                //std::cout<<"b/a "<<a/b<<" "<<rotation<<std::endl;
                
                
                
            } else
                
                if (p_p.y>possision.y && p_p.x < possision.x)
                {
                    a = fabs(p_p.x - possision.x);
                    b = fabs(p_p.y - possision.y);
                    
                    rotation = (atan(b/a) * 180 / 3.14159265 * -1) -90;
                    //std::cout<<"b/a "<<a/b<<" "<<rotation<<std::endl;
                    
                    
                }
    
    
    
    
    //std::cout<<atan(1) * 180 / 3.14159265;
    
    sprite.setRotation(rotation);
    
    
}

void Enemy::loadEnemySprite(const sf::Texture & enemy_texture){
    
    
    sprite.setTexture(enemy_texture);
    
    
    
}

sf::Sprite * Enemy::getSprite(){
    
    return &sprite;
    
}

void Enemy::UpdatePossision(sf::Vector2f p_p){
   
    //p_p.x -= 25;
   // p_p.y -= 25;
    
    float offset_x = 0;
    float offset_y = 0;
    float ratio = 0;
    
    if (fabs(p_p.x - possision.x)< 5) {
        
        touched = true;
        
    } else
        
    {
        
    touched = false;
        
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
    std::cout<<p_p.x<<" "<<p_p.y<<" "<<possision.x<<" "<<possision.y<<std::endl;
    

}




void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const    {
    
        target.draw(sprite);
    
}
