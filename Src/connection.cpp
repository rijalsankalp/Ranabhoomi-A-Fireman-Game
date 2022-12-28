#include "Headers/connection.h"


connection::connection(unsigned int width, unsigned int height)
    :fonts(Fonts::fontNumber),
    isPressedReturn(false),
    mWindow2(sf::VideoMode(width, height), "Ranabhumi", sf::Style::Default),
    width(width), height(height), selectedItem(0)
{
    buffer.loadFromFile("Media/Audio/keyPressSound.wav");
    sound.setBuffer(buffer);
    fonts.load(Fonts::homeFont, "Media/Fonts/gunplay rg.ttf");
    for (int i = 0; i < 2; i++)
        home[i].setFont(fonts.get(Fonts::homeFont));
    home[0].setString("Host");
    home[1].setString("Client");
    for (int i = 0; i < 2; i++)
        home[i].setPosition(width - (width / 2.f), (height / 2.f) + (height / 6.f * i));
    enter.setString("Please choose the mode");
    enter.setFont(fonts.get(Fonts::homeFont));
    enter.setPosition(375,250);
    enter.setFillColor(sf::Color::Green);
    
    //ipTexture.loadFromFile("Media/Textures/firstpage.jpg");
    //ipImage.setSize(sf::Vector2f(width, height));
    //ipImage.setPosition(0, 0);
    //ipImage.setTexture(&ipTexture);
}
void connection::render() {
    mWindow2.clear(sf::Color::Black);
    //mWindow2.draw(ipImage);
    mWindow2.draw(enter);
    for (int i = 0; i < 2; i++) {
        home[i].setFillColor(i == selectedItem ? sf::Color::Red : sf::Color::White);
        mWindow2.draw(home[i]);
    }

    mWindow2.display();
}
void connection::moveUp(const bool goUp = true) {
    if (goUp and selectedItem != 0)
        selectedItem--;
    else if (not goUp and selectedItem != 1)
        selectedItem++;
}

void connection::handlePlayerInput(sf::Keyboard::Key& key, bool isPressed) {
    switch (key) {
    case sf::Keyboard::Return:
        sound.play();
        onPressEnter();
        break;
    case sf::Keyboard::Up:
        sound.play();
        moveUp();
        break;
    case sf::Keyboard::Down:
        sound.play();
        moveUp(false);
        break;
    case sf::Keyboard::Escape:
        sound.play();
        mWindow2.close();
        firstpage home(1024, 720);
        home.run();
        break;
    }
}
void connection::onPressEnter()
{
  
    switch (selectedItem)
    {
    case 0:
       {
        mWindow2.close();
        Host host(1024, 720);
        host.run();
        break;
       }
        
    case 1:
        mWindow2.close();
        Ippage ip(1024, 720);
        ip.run();
        break;
    }
}
void connection::run() {
    while (mWindow2.isOpen())
    {
        processEvents();
        render();
    }
}
void connection::processEvents() {
    sf::Event event = {};
    while (mWindow2.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::Closed:
            mWindow2.close();
            break;
        }
    }
}