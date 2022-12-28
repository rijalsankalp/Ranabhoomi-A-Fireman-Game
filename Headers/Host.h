#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics/Text.hpp>
#include "connection.h"
#include <SFML\Graphics\RectangleShape.hpp>
#include "gamemode.h"
class Host
{
public:
    Host(unsigned int width, unsigned int height);
    void render();
    void run();
    void handlePlayerInput(sf::Keyboard::Key& key, bool isPressed);
    void processEvents();
 private:
    ResourceHolder <sf::Font, Fonts::ID> fonts;
    sf::RenderWindow mWindow2;
    sf::RectangleShape inputBox;
    sf::Text  enter, IpShow;
    int selectedItem;
    //sf::Texture ipTexture;
    //sf::RectangleShape ipImage;
    bool isPressedReturn;
    unsigned width, height;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

