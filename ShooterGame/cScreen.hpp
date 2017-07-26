//
//  cScreen.hpp
//  ShooterGame
//
//  Created by Miszo on 22.07.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef cScreen_hpp
#define cScreen_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>


class cScreen
{
    public :
    virtual int Run (sf::RenderWindow &App) = 0;
};


#endif
