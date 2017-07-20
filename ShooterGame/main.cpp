
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <iostream>
#include <math.h>

int main(int, char const**)
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);

    
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    

    sf::Texture  array_of_body_textuers [1];
    
    array_of_body_textuers[0].loadFromFile(resourcePath() + "/images/survivor.png");
    
    sf::Texture shoot_rifle[3];
    
    
    shoot_rifle[0].loadFromFile(resourcePath() + "/shoot/survivor-shoot_rifle_0.png");
    shoot_rifle[1].loadFromFile(resourcePath() + "/shoot/survivor-shoot_rifle_1.png");
    shoot_rifle[2].loadFromFile(resourcePath() + "/shoot/survivor-shoot_rifle_2.png");
    
    sf::Texture bullet_texture;
    bullet_texture.loadFromFile(resourcePath() + "/images/bullet.png");
    
    sf::Texture enemy_texture;
    enemy_texture.loadFromFile(resourcePath() + "/images/enemy_texture.png");
    
    // Declare a new music
    sf::Music music;
    // Open it from an audio file
    if (!music.openFromFile(resourcePath() + "gun_sound.wav"))
    {
        // error...
    }
    
    sf::Clock clock;
    sf::Time enemy_spawn = sf::seconds(1);
    
    Map map;
    map.player.loadSprites(array_of_body_textuers, shoot_rifle);
    
    
    
    
    

    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    sf::Text text;
    text.setFont(font);
    text.setPosition(700, 30);
    
    

   


    
    // Start the game loop
    while (window.isOpen())
    {
        
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
          
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                map.createBullet(bullet_texture, map.player.rotation, localPosition);
                map.player.Shoot();
                music.play();
            }
            
            
            
            
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                map.createEnemy(enemy_texture);
            }
            
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                
                map.player.moveLeft();
               
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
        sf::Time elapsed = clock.getElapsedTime();
        text.setString(std::to_string(floor(elapsed.asSeconds())));
        if (elapsed.asSeconds() > enemy_spawn.asSeconds()) {
            map.createEnemy(enemy_texture);
            enemy_spawn += sf::seconds(1);
        }
        
        //std::cout<<clock.getElapsedTime().asSeconds()<<std::endl;
        
        
        // Clear screen
        window.clear(sf::Color(123,164,98));
        
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        map.player.updateRotation(localPosition);
        map.player.UpdatePossision();
        
        
        if (!(map.Enemys.empty())) {
            for (auto a = map.Enemys.begin(); a != map.Enemys.end(); ++a){
                a->UpdatePossision(map.player.possision);
                a->updateRotation(map.player.possision);
            }
        }
        
        
        if (!(map.Bullets.empty())) {
            for (auto a = map.Bullets.begin(); a != map.Bullets.end();) {
                
                if(a->possision.x > 800 || a->possision.x < 0) map.Bullets.erase(a);
                    else
                {
                    a->UpdatePossision();

                    ++a;
                }
            }
        }
        
        map.Bullet_Enemy_Coll();
        
                
        
        
        if (!(map.Bullets.empty())) {
            for (auto a = map.Bullets.begin(); a != map.Bullets.end(); ++a) window.draw(*a);
        }
        
        if (!(map.Enemys.empty())) {
            for (auto a = map.Enemys.begin(); a != map.Enemys.end(); ++a) window.draw(*a);
        }
        
        
        
        
        window.draw(map.player);
        window.draw(text);
        
        
        

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
