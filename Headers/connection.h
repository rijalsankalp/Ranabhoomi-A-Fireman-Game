#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include "firstpage.h"
#include "Ippage.h"
#include "Host.h"

class connection
{
public:
    connection(unsigned int width, unsigned int height);
    void render();
    void run();
    void handlePlayerInput(sf::Keyboard::Key& key, bool isPressed);
    void processEvents();
    void onPressEnter();
    void moveUp(bool goUp);
private:
    sf::Text home[2];
    ResourceHolder <sf::Font, Fonts::ID> fonts;
    sf::RenderWindow mWindow2;
    sf::Text  enter;
    int selectedItem;
    //sf::Texture ipTexture;
    //sf::RectangleShape ipImage;
    bool isPressedReturn;
    unsigned width, height;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

