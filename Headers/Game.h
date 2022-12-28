#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
class Game
{
    private:
        int a;
        int box[11][11];
    public:
        void setValue(int i, int j, int val);
        void displayGAame(int i, int j);
        void displayGBame();
        void startGBame();
        int sendStat(int i, int j);
        void bombPlace(sf::Vector2i point);
        void enemyBombPlace(sf::Vector2i point);
        sf::Vector2i explosion(sf::Vector2i point,sf::Vector2i player1,sf::Vector2i player2);
        //void enemyExplosion(sf::Vector2i point);
        
           
};

