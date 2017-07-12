//
//  Map.cpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//




#include "Map.hpp"
#include "Bullet.hpp"

Map::Map(){
    
    
    
}

void Map::createBullet(sf::Texture& bull_tex, float P_r, sf::Vector2i _mouseposision){
    
    
    Bullet b(player.possision, _mouseposision);
    b.bullet_sprite.setTexture(bull_tex);
    b.bullet_sprite.setRotation(P_r);
    Bullets.push_back(b);
    
}
