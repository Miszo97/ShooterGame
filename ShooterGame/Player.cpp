//
//  Player.cpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
#include <cmath>

Player::Player(){
    
    possision = sf::Vector2f(400,300);
    time_step= 0.016;
    velocity = sf::Vector2f(0,0);
    acceleration = sf::Vector2f(0,0);
    
    
    
    
    
    
}




void Player::loadSprites(sf::Texture * body_texture_ptr, sf::Texture * rifle_shoot_ptr){
    
    for (int i =0 ; i<1 ; i++) {
        
        body_sprites[i].setTexture(body_texture_ptr[i]);
        body_sprites[i].setPosition(possision);
        body_sprites[i].scale(0.25, 0.25);
        sf::IntRect Rect =  body_sprites[i].getTextureRect();
        body_sprites[i].setOrigin(Rect.width/2, Rect.height/2);
       
    }
    
    for (int i =0 ; i<3 ; i++) {
        
        riffle_shoot_sprites[i].setTexture(body_texture_ptr[i]);
        riffle_shoot_sprites[i].setPosition(possision);
        riffle_shoot_sprites[i].scale(0.25, 0.25);
        sf::IntRect Rect =  riffle_shoot_sprites[i].getTextureRect();
        riffle_shoot_sprites[i].setOrigin(Rect.width/2, Rect.height/2);
        
    }

}




void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const    {
    
    
        
        target.draw(body_sprites[0] ,states);
        
    
}


void Player::Shoot(){
 
    ;
    
}


void Player::UpdatePossision(){
    
    for (int i =0 ; i<1 ; i++) {
        
        
        if (!isGoingForward  && velocity.y < 0){
        
        
            velocity.y -= velocity.y/2;
            
        }
        if (!isGoingBackward  && velocity.y > 0){
            
            
            velocity.y -= velocity.y/2;
            
        }
        if (!isGoingLeft  && velocity.x < 0){
            
            
            velocity.x -= velocity.x/2;
            
        }
        if (!isGoingRight  && velocity.x > 0){
            
            
            velocity.x -= velocity.x/2;
            
        }
        
        sf::Vector2f current_possition = possision + sf::Vector2f(velocity.x * time_step, velocity.y * time_step);
        velocity.x = velocity.x + acceleration.x * time_step;
        velocity.y = velocity.y + acceleration.y * time_step;
        possision = current_possition;
        body_sprites[i].setPosition(possision);
        
        
    }
    
    
    
}


void Player::updateRotation(sf::Vector2i localPosition){


   
    double a = 0;
    double b = 0;
    
    
    
    if (localPosition.y<possision.y && localPosition.x < possision.x)
    {
        
        a = fabs(localPosition.x - possision.x);
        b = fabs(localPosition.y - possision.y);
        
        rotation = atan(a/b) * 180 / 3.14159265 * -1;
        //std::cout<<"a/b "<<a/b<<" "<<rotation<<std::endl;
    } else
        
        if (localPosition.y<possision.y && localPosition.x > possision.x)
        {
            a = fabs(localPosition.x - possision.x);
            b = fabs(localPosition.y - possision.y);
            
            rotation = atan(a/b) * 180 / 3.14159265;
           // std::cout<<"a/b "<<a/b<<" "<<rotation<<std::endl;
            
            
        } else
            
            if (localPosition.y>possision.y && localPosition.x > possision.x)
            {
                a = fabs(localPosition.x - possision.x);
                b = fabs(localPosition.y - possision.y);
                
                rotation = (atan(b/a) * 180 / 3.14159265) + 90;
                //std::cout<<"b/a "<<a/b<<" "<<rotation<<std::endl;
                
                
                
            } else
                
                if (localPosition.y>possision.y && localPosition.x < possision.x)
                {
                    a = fabs(localPosition.x - possision.x);
                    b = fabs(localPosition.y - possision.y);
                    
                    rotation = (atan(b/a) * 180 / 3.14159265 * -1) -90;
                    //std::cout<<"b/a "<<a/b<<" "<<rotation<<std::endl;
                    
                    
                }
    
    
    
    
    //std::cout<<atan(1) * 180 / 3.14159265;
    
    body_sprites[0].setRotation(rotation);

}







void Player::moveUp(){
    
    if (velocity.y != -100)
        
    velocity.y = -100;

}
void Player::moveDown(){
    
    if (velocity.y != 100)
    velocity.y = 100;

}
void Player::moveLeft(){
    
    if (velocity.x != -100)
    velocity.x = -100;
}
void Player::moveRight(){
    
    if (velocity.x != 100)

    velocity.x = 100;
}


