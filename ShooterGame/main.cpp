
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <iostream>

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    

    sf::Texture  array_of_body_textuers [5];
    
    
        array_of_body_textuers[0].loadFromFile(resourcePath() + "/images/survivor.png");
    
    
    sf::Texture bullet_texture;
    bullet_texture.loadFromFile(resourcePath() + "/images/bullet.png");
    
    sf::Texture enemy_texture;
    enemy_texture.loadFromFile(resourcePath() + "/images/survivor.png");
    
    Map map;
    map.player.loadSpritesBody(array_of_body_textuers);
    
    
    map.createEnemy(enemy_texture);
    

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    

   


    
    // Start the game loop
    while (window.isOpen())
    {
        // Starting sf::Clock
        sf::Clock clock;
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
          
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                map.createBullet(bullet_texture, map.player.rotation, localPosition);
            
            }
            
            
            
            
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                map.createEnemy(enemy_texture);
            }
            
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                // left key is pressed: move our character
                map.player.moveLeft();
                //std::cout<<"Left button has been clicked!";
                map.player.isGoingLeft = true;
            } else {
                map.player.isGoingLeft = false;
            }
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                
                map.player.moveRight();
                
                map.player.isGoingRight = true;
                
            } else {
                map.player.isGoingRight = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                
                map.player.moveUp();
                
                map.player.isGoingForward = true;
                
                
                
            } else{
                map.player.isGoingForward = false;
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                
                map.player.moveDown();
                map.player.isGoingBackward = true;
                
                
            } else {
                map.player.isGoingBackward = false;
            }
            
            
            
        }


        // Clear screen
        window.clear();
        
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        map.player.updateRotation(localPosition);
        map.player.UpdatePossision();
        
        if (!(map.Enemys.empty())) {
            for (auto a = map.Enemys.begin(); a != map.Enemys.end(); ++a) a->UpdatePossision(map.player.possision);
        }
        
        
        if (!(map.Bullets.empty())) {
            for (auto a = map.Bullets.begin(); a != map.Bullets.end(); ++a) a->UpdatePossision();
        }
        
        map.Bullet_Enemy_Coll();
        
                
        
        
        if (!(map.Bullets.empty())) {
            for (auto a = map.Bullets.begin(); a != map.Bullets.end(); ++a) window.draw(*a);
        }
        
        if (!(map.Enemys.empty())) {
            for (auto a = map.Enemys.begin(); a != map.Enemys.end(); ++a) window.draw(*a);
        }
        

        window.draw(map.player);
        
        
        
        

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
