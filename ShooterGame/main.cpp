
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <iostream>
#include <math.h>
//#include "screens.hpp"
#include "cScreen.cpp"
#include "screen_0.hpp"
#include "screen_1.hpp"
#include "screen_2.hpp"

int main(int, char const**)
{
    
    //Applications variables
    std::vector<cScreen*> Screens;
    int screen = 0;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);

    
    screen_0 s0;
    Screens.push_back(&s0);
    
    screen_1 s1;
    Screens.push_back(&s1);
    
    screen_2 s2;
    Screens.push_back(&s2);
    
    
    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }


   

    return EXIT_SUCCESS;
}
