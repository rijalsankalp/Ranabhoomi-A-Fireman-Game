#pragma once

#include <SFML/Network.hpp>
#include <SFML/Graphics/Text.hpp>
#include "connection.h"
#include "Clientgamemode.h"
//#include "InfoHolder.h"
#include <SFML\Graphics\RectangleShape.hpp>
class Ippage
{
public:
    Ippage(unsigned int width, unsigned int height);
    void render();
    void run();
    void handlePlayerInput(sf::Keyboard::Key& key, bool isPressed);
    void processEvents();
    void onPressEnter();
   // void moveUp(bool goUp);
private:
    ResourceHolder <sf::Font, Fonts::ID> fonts;
    sf::RenderWindow mWindow2;
    sf::RectangleShape inputBox;
    sf::String playerInput;
    sf::Text playerText, enter;
    //sf::Texture ipTexture;
    //sf::RectangleShape ipImage;
    bool isPressedReturn;
    unsigned width, height;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

