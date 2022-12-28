#include <iostream>
#include <fstream>
#include "Headers/firstpage.h"
#include "Headers/connection.h"

firstpage::firstpage(unsigned int width, unsigned int height)
    :fonts(Fonts::fontNumber),
    selectedItem(0),
    isPressedUp(false),
    isPressedDown(false),
    isPressedReturn(false),
    enterAbout(false),
    firstwindow(sf::VideoMode(width, height), "Ranabhoomi", sf::Style::Default),
    width(width),
    height(height)
{
    buffer.loadFromFile("Media/Audio/keyPressSound.wav");
    sound.setBuffer(buffer);
    fonts.load(Fonts::homeFont, "Media/Fonts/gunplay rg.ttf");
    for (auto& font : home)
        font.setFont(fonts.get(Fonts::homeFont));
    home[0].setString("Play");
    home[1].setString("About");
    home[2].setString("Exit");
    for (int i = 0; i < 3; i++)
        home[i].setPosition(width - (width / 2.f), (height / 2.f) + (height / 6.f * i));
   // homeTexture.loadFromFile("Media/Textures/firstpage.jpg");
   // firstimage.setSize(sf::Vector2f(width, height));
   // firstimage.setPosition(0, 0);
    //firstimage.setTexture(&homeTexture);
    aboutText.setFont(fonts.get(Fonts::homeFont));

   /* std::string detail;
    std::fstream aboutFile;
    aboutFile.open(("../about.txt"));
    if (aboutFile)
    {
        while (getline(aboutFile, detail))
        {
            aboutTextString.append(detail + "\n");
        }
    }*/
}
void firstpage::render() {
      
        firstwindow.clear(sf::Color::Black);
        //firstwindow.draw(firstimage);
        for (int i = 0; i < 3; i++) {
            home[i].setFillColor(i == selectedItem ? sf::Color::Red : sf::Color::Green);
            firstwindow.draw(home[i]);
        }
        firstwindow.display();
}

void firstpage::moveUp(const bool goUp = true) {
    if (goUp and selectedItem != 0)
        selectedItem--;
    else if (not goUp and selectedItem != 2)
        selectedItem++;
}
void firstpage::handlePlayerInput(sf::Keyboard::Key& key, bool isPressed) {
    switch (key) {
    case sf::Keyboard::Up:
        sound.play();
        isPressedUp = isPressed;
        break;
    case sf::Keyboard::Down:
        sound.play();
        isPressedDown = isPressed;
        break;
    case sf::Keyboard::Return:
        sound.play();
        isPressedReturn = isPressed;
        break;
    }
    update();
}

void firstpage::update() {
    if (isPressedUp)
        moveUp();
    if (isPressedDown)
        moveUp(false);
    if (isPressedReturn)
        onPressEnter();
}

void firstpage::onPressEnter() {
    switch (selectedItem)
    {
    case 1:
        //about();
        break;
    case 2:
        std::cout << "You're out of the battleground!" << std::endl;
        exit(0);
    case 0:
    {
    firstwindow.close();
    connection connect(1024, 720);
    connect.run();
    break;
    }
    }
}

/*void firstpage::about() {
    firstwindow.clear(sf::Color(255, 255, 255, 150));
    aboutText.setString(aboutTextString);
    aboutText.setFillColor(sf::Color::Black);
    aboutText.setCharacterSize(18);
    aboutText.setPosition(10, 50);
    firstwindow.draw(aboutText);
    firstwindow.display();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
{
    firstpage home(1024, 720);
    home.run();
}
}*/

void firstpage::run() {
    while (firstwindow.isOpen())
    {
        processEvents();
        render();
    }
}

void firstpage::processEvents() {
    sf::Event event = {};
    while (firstwindow.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break; 
        case sf::Event::Closed:
            firstwindow.close();
            break;
        }
    }
}

