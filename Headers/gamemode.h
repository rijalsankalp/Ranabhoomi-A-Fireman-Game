#pragma once
#include <iostream>
#include"Game.h"
#include"Server.h"
#include"Client.h"
#include "InfoHolder.h"

using namespace std;
class gamemode
{
public:
	sf::Vector2i posToArr(float x, float y);
	void run();
};


