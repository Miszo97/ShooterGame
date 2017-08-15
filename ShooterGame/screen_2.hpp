#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class screen_2 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
    sf::Text & score_;
public:
    screen_2(sf::Text&);
    virtual int Run(sf::RenderWindow &App);
};

screen_2::screen_2(sf::Text & score) : score_(score)
{
    playing = false;
}

int screen_2::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    
    sf::Font Font;
    sf::Text Menu1;
    sf::Text Menu2;
    sf::Text Menu3;
    int menu = 0;
    
    if (!Texture.loadFromFile(resourcePath() + "background.png"))
    {
        std::cerr << "Error loading presentation.gif" << std::endl;
        return (-1);
    }
    Sprite.setTexture(Texture);
    Sprite.setColor(sf::Color(255, 255, 255));
    
    if (!Font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    
    
    Menu1.setFont(Font);
    Menu1.setCharacterSize(40);
    Menu1.setString("Game over");
    Menu1.setPosition({ 280.f, 160.f });
    
    Menu2.setFont(Font);
    Menu2.setCharacterSize(40);
    Menu2.setString("Your result: " + score_.getString());
    Menu2.setPosition({ 280.f, 220.f });
    
    Menu3.setFont(Font);
    Menu3.setCharacterSize(40);
    Menu3.setString("Play Again");
    Menu3.setPosition({ 280.f, 280.f });
    Menu3.setColor(sf::Color(255, 0, 0, 255));
    
    
    
    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                        case sf::Keyboard::Return:
                        if (menu == 0)
                        {
                            //Let's get play !
                            playing = true;
                            return (1);
                        }
                        
                        break;
                    default:
                        break;
                }
            }
        }
        
        
        
        
        //Clearing screen
        App.clear(sf::Color::White);
        //Drawing
        App.draw(Sprite);
        
        
            App.draw(Menu3);
        
            App.draw(Menu1);
    
            App.draw(Menu2);
        
        App.display();
    }
    
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
