#pragma once
#include <SFML/Graphics.hpp>
#include"Game.h"
#include"Server.h"
#include"Client.h"
#include"InfoHolder.h"

using namespace std;
class Clientgamemode
{
public:

	sf::Vector2i posToArr(float x, float y);
	void run(string s);
};












