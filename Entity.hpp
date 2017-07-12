//
//  Entity.hpp
//  ShooterGame
//
//  Created by Miszo on 09.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Element.hpp"

class Entity : public Element{
    
protected:
    
    
    
public:
    
    double time_step;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    void reduceHP(int);
    
    
    
    
    
    
    
};

#endif /* Entity_hpp */
