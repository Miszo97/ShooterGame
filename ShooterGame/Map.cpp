//
//  Map.cpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//




#include "Map.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include <iostream>

Map::Map(){
    
    
    
}

void Map::createBullet(sf::Texture& bull_tex, float P_r, sf::Vector2i _mouseposision){
    
    
    Bullet b(player.possision, _mouseposision);
    b.setInitialPos(P_r);
    b.sprite.setTexture(bull_tex);
    b.sprite.setRotation(P_r);
    Bullets.push_back(b);
    
}


void Map::createEnemy(sf::Texture& enemy_tex){
    
    Enemy e(sf::Vector2f(40,40));
    e.loadEnemySprite(enemy_tex);
    Enemys.push_back(std::move(e));
    
}

void Map::Player_Enemy_Coll() noexcept{

    
    if (!(Enemys.empty())) {
        for (auto a = Enemys.begin(); a != Enemys.end(); ++a){
            
            
           
                if(check_for_collsion_EE(*a, player)){
                    
                    player.reduceHP(10);
                    if (player.hp ==0) {
                        std::cout<<"He is dead";
                    }
                    
                    
                       
                    
                    
                    
                    
                    
                    
                }
                
            }
            
        }
        
        
    

}



void Map::Bullet_Enemy_Coll() {

if (!(Bullets.empty()) && !(Enemys.empty())) {
    for (auto a = Bullets.begin(); a != Bullets.end(); ++a){
        
        
        for (auto b = Enemys.begin(); b != Enemys.end(); ++b) {
            if(check_for_collsion_EE(*a, *b)){
                
                b->reduceHP(10);
                if (b->hp ==0) {
                    Enemys.erase(b);
                }
                
                Bullets.erase(a);
                --a;
                
                break;
                
                
                
                
            }
            
        }
        
    }
    
    
}
    
}

