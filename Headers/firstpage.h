#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include<SFML/Audio.hpp>
#include"Src/ResourceHolder.cpp"

namespace Fonts
{
    enum  ID { homeFont, fontNumber };
}

class firstpage {
public:
    firstpage(unsigned int width, unsigned int height);
    void run();

private:
    //void about();
    void moveUp(bool goUp);
    void render();
    void handlePlayerInput(sf::Keyboard::Key& key, bool isPressed);
    void update();
    void processEvents();
    void onPressEnter();
private:
    sf::Text home[3];
    sf::Text aboutText;
    std::string aboutTextString;
    ResourceHolder<sf::Font, Fonts::ID> fonts;
    int selectedItem;
    bool isPressedUp, isPressedDown, isPressedReturn, enterAbout;
    unsigned width, height;
    //sf::Texture homeTexture;
    //sf::RectangleShape firstimage;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::RenderWindow firstwindow;
};

