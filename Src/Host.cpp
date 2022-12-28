#include "Headers/Host.h"

Host::Host(unsigned int width, unsigned int height)
    :fonts(Fonts::fontNumber),
    isPressedReturn(false),
    mWindow2(sf::VideoMode(width, height), "Ranabhumi", sf::Style::Default),
    width(width), height(height), selectedItem(0)
{
    buffer.loadFromFile("Media/Audio/keyPressSound.wav");
    sound.setBuffer(buffer);
    fonts.load(Fonts::homeFont, "Media/Fonts/gunplay rg.ttf");
    IpShow.setString("Your IP is :" + sf::IpAddress::getLocalAddress().toString());
    IpShow.setPosition(0, 0);
    IpShow.setFont(fonts.get(Fonts::homeFont));
    IpShow.setFillColor(sf::Color::Green);
    enter.setString("Waiting for client. Pleas wait .......");
    enter.setPosition(0, 50);
    enter.setFont(fonts.get(Fonts::homeFont));
    enter.setFillColor(sf::Color::Red);
    //ipTexture.loadFromFile("Media/Textures/firstpage.jpg");
    //ipImage.setSize(sf::Vector2f(width, height));
    //ipImage.setPosition(0, 0);
    //ipImage.setTexture(&ipTexture);
}
void Host::render() {
    mWindow2.clear(sf::Color::Black);
    //mWindow2.draw(ipImage);
    mWindow2.draw(IpShow);
    mWindow2.draw(enter);
  
    mWindow2.display();
}


void Host::handlePlayerInput(sf::Keyboard::Key& key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::Enter:
             {
            mWindow2.close();
            gamemode mode;
            mode.run();
           }
       case sf::Keyboard::Escape:
        sound.play();
        mWindow2.close();
        connection connect(1024, 720);
        connect.run();
        break;
    }
} 

void Host::run() {
    while (mWindow2.isOpen())
    {
        processEvents();
        render();
    }
}
void Host::processEvents() {
    sf::Event event = {};
    while (mWindow2.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
           
        case sf::Event::Closed:
            mWindow2.close();
            break;
        }
    }
}
