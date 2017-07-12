//
//  Map.hpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <vector>

class Map {

public:
    
    
    Map();
    std::vector<Enemy> Enemys;
    std::vector<Bullet> Bullets;
    
    Player player;
    
    void createEnemy();
    void createBullet(sf::Texture&, float, sf::Vector2i);
    void UpdateElements();
    
    template <typename T1, typename T2>
    bool check_for_collsion_EE(T1& object1,T2& object2){
        
        
        if(object1.sprite.getGlobalBounds().intersects(object2.sprite.getGlobalBounds())){
            
            return true;
            
        } else return false;
    }



};

#endif /* Map_hpp */
