#include "Headers/Ippage.h"

Ippage::Ippage(unsigned int width, unsigned int height)
    :fonts(Fonts::fontNumber),
    isPressedReturn(false),
    mWindow2(sf::VideoMode(width, height), "Ranabhoomi", sf::Style::Default),
    width(width), height(height)
{
    buffer.loadFromFile("Media/Audio/keyPressSound.wav");
    sound.setBuffer(buffer);
    fonts.load(Fonts::homeFont, "Media/Fonts/gunplay rg.ttf");
    for (int i = 0; i < 2; i++)
    enter.setString("Please Enter host's IP:");
    enter.setFont(fonts.get(Fonts::homeFont));
    playerText.setPosition(0, enter.getCharacterSize());
    playerText.setFont(fonts.get(Fonts::homeFont));
    inputBox.setSize(sf::Vector2f(500, 50));
    inputBox.setOutlineThickness(2.f);
    inputBox.setFillColor(sf::Color(167, 150, 150));
    inputBox.setOrigin((mWindow2.getSize().x / 2.f) + (inputBox.getSize().x / 2.f), mWindow2.getSize().y / 2.f);
    inputBox.setPosition(mWindow2.getSize().x, mWindow2.getSize().y);
    enter.setPosition(inputBox.getOrigin().x - (inputBox.getSize().x * (4.f / 5.f)), inputBox.getOrigin().y - 100);
    playerText.setPosition(inputBox.getOrigin().x - (inputBox.getSize().x * (4.f / 5.f)), inputBox.getOrigin().y);
    playerText.setFillColor(sf::Color::Black);
    //ipTexture.loadFromFile("Media/Textures/firstpage.jpg");
    //ipImage.setSize(sf::Vector2f(width, height));
    //ipImage.setPosition(0, 0);
    //ipImage.setTexture(&ipTexture);
}
void Ippage::render() {
    mWindow2.clear(sf::Color::Black);
    //mWindow2.draw(ipImage);
    mWindow2.draw(inputBox);
    mWindow2.draw(enter);
    mWindow2.draw(playerText);
    mWindow2.display();
}


void Ippage::handlePlayerInput(sf::Keyboard::Key& key, bool isPressed) {
    switch (key) {
    case sf::Keyboard::Return:
        sound.play();
        onPressEnter();
        break;
    
    case sf::Keyboard::Escape:
        sound.play();
        mWindow2.close();
        connection connect(1024, 720);
        connect.run();
        break;
    }
}
void Ippage::onPressEnter()
{
    if (!playerInput.isEmpty())
    {
        mWindow2.close();
        Clientgamemode mode;
        mode.run(playerInput);
    }
    else
        enter.setString("You must Enter the IP:");
}
void Ippage::run() {
    while (mWindow2.isOpen())
    {
        processEvents();
        render();
    }
}
void Ippage::processEvents() {
    sf::Event event = {};
    while (mWindow2.pollEvent(event))
    {
        switch (event.type) {
       case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::TextEntered:
            if ((event.text.unicode >= 48 && event.text.unicode <= 57) || (event.text.unicode == 46))
            {
                sound.play();
                playerInput += event.text.unicode;
                playerText.setString(playerInput);
            }
            else if (event.text.unicode == 8 && !playerInput.isEmpty())
            {
                sound.play();
                playerInput.erase(playerInput.getSize() - 1, 1);
                playerText.setString(playerInput);
            }
            break;
        case sf::Event::Closed:
            mWindow2.close();
            break;
        }
    }
}
