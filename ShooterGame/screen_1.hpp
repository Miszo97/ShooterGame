#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class screen_1 : public cScreen
{
private:
    bool Running = true;
    sf::Texture  array_of_body_textuers [1];
    sf::Texture shoot_rifle[3];
    sf::Texture bullet_texture;
    sf::Texture enemy_texture;
    sf::Music music;
    sf::Clock clock;
    sf::Time enemy_spawn = sf::seconds(1);
    Map map;
    sf::Font font;
    sf::Text elapsed_time;
    sf::Text hp_text;
    sf::Time savedTime = sf::seconds(0);
    sf::Time elapsed;
    
    public:
    
    screen_1(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
    
    array_of_body_textuers[0].loadFromFile(resourcePath() + "/images/survivor.png");
    
    sf::Texture shoot_rifle[3];
    
    
    shoot_rifle[0].loadFromFile(resourcePath() + "/shoot/survivor-shoot_rifle_0.png");
    shoot_rifle[1].loadFromFile(resourcePath() + "/shoot/survivor-shoot_rifle_1.png");
    shoot_rifle[2].loadFromFile(resourcePath() + "/shoot/survivor-shoot_rifle_2.png");
    
    
    bullet_texture.loadFromFile(resourcePath() + "/images/bullet.png");
    enemy_texture.loadFromFile(resourcePath() + "/images/enemy_texture.png");
    
   
    
    // Open it from an audio file
    if (!music.openFromFile(resourcePath() + "gun_sound.wav"))
    {
        // error...
    }
    

    map.player.loadSprites(array_of_body_textuers, shoot_rifle);

    map.createEnemy(enemy_texture);
    //map.createEnemy(enemy_texture);
    
    
    
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
   
    elapsed_time.setFont(font);
    elapsed_time.setPosition(20, 15);
    hp_text.setFont(font);
    hp_text.setPosition(700, 15);
}

int screen_1::Run(sf::RenderWindow &App)
{
    
    clock.restart();
    
    
    
    while (Running)
    {
        sf::Event event;
        //Verifying events
        while (App.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                savedTime += clock.getElapsedTime();
                return (0);
            }
            
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(App);
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
        
        elapsed = clock.getElapsedTime();
        elapsed_time.setString(std::to_string(static_cast<int>(floor(elapsed.asSeconds()+savedTime.asSeconds()))));
        
        if (elapsed.asSeconds() + savedTime.asSeconds() > enemy_spawn.asSeconds()) {
            map.createEnemy(enemy_texture);
            enemy_spawn += sf::seconds(1);
        }
        
        
        
        
        
        App.clear(sf::Color(123,164,98));
        
        sf::Vector2i localPosition = sf::Mouse::getPosition(App);
        map.player.updateRotation(localPosition);
        map.player.UpdatePossision();
        
        
        if (!(map.Enemys.empty())) {
            for (auto a = map.Enemys.begin(); a != map.Enemys.end(); ++a){
                if (a->abilityToAtack() == true) {
                    map.player.reduceHP(10);
                    std::cout<<"true";
                    if(map.player.hp == 0) return 2;
                }
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
            for (auto a = map.Bullets.begin(); a != map.Bullets.end(); ++a) App.draw(*a);
        }
        
        if (!(map.Enemys.empty())) {
            for (auto a = map.Enemys.begin(); a != map.Enemys.end(); ++a) App.draw(*a);
        }
        
        
        hp_text.setString(std::to_string(map.player.hp));
        
        App.draw(map.player);
        
        App.draw(elapsed_time);
        App.draw(hp_text);
        
        
        
        
        // Update the window
        App.display();

    }
    
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
