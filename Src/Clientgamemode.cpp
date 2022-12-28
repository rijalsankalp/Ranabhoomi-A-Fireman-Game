#include "Headers/Clientgamemode.h"
#include <fstream>
sf::Vector2i Clientgamemode:: posToArr(float x, float y) {
	int a, b;
	a = (x - 175) / 50;
	b = (y - 100) / 50;
	sf::Vector2i vec(a, b);
	return vec;

}
void Clientgamemode::run(string s)
{



	infoHolder thisInfo, enemyInfo;


	Client client(s);

	int thisPlayer = 1;
	int enemyPlayer = 0;

	//game object
	Game game;



	//declearation of veriables required that change often
	int bombTime[2] = { 0,0 };
	int boxValue;
	sf::Vector2i explodePlace[2];
	thisInfo.boom = 0;
	int totalbomb = 0, fromFiletotalbomb = 0;
	//int moveControl;
	sf::Vector2i isPlayerKilled;

	//game call
	game.startGBame();
	game.displayGBame();

	//player set position defination
	float playerX[2] = { 175.0f,675.0f };
	float playerY[2] = { 100.0f,600.0f };

	//bomb locations
	float bombX[2], bombY[2];

	//key press checker
	char pressedKey = 'N';

	//sfml clock definer 
	sf::Clock clock1, clock2;

	//All about bomb
	sf::Texture bombtex;
	bombtex.loadFromFile("Media/Textures/bomb.png");
	sf::IntRect bombRect1(0, 0, 32, 32);
	sf::IntRect bombRect2(0, 0, 32, 32);
	sf::Sprite sprite1(bombtex, bombRect1);
	sf::Sprite sprite2(bombtex, bombRect2);
	sprite1.setOrigin(16.0f, 16.0f);
	sprite2.setOrigin(16.0f, 16.0f);

	//All about fire (using sprite)
	sf::Texture fireTex;
	fireTex.loadFromFile("Media/Textures/fire.png");
	sf::IntRect fireRect(0, 0, 96, 96);
	sf::Sprite fireSprite1(fireTex, fireRect);
	sf::Sprite fireSprite2(fireTex, fireRect);
	fireSprite1.setOrigin(48.0f, 48.0f);
	fireSprite2.setOrigin(48.0f, 48.0f);


	//All about fence (sprite is not defined here)
	sf::RectangleShape fence(sf::Vector2f(50.0f, 50.0f));
	sf::Texture fenceTex;
	fenceTex.loadFromFile("Media/Textures/fence.png");
	fence.setTexture(&fenceTex);
	fence.setTextureRect(sf::IntRect(0, 0, 50, 50));
	fence.setOrigin(25.0f, 25.0f);


	//Window define and load;
	sf::RenderWindow window(sf::VideoMode(1000, 700), "RanaBhumi", sf::Style::Default);

	//baground
	sf::IntRect backgroundSize(0, 0, 1000, 700);
	sf::Texture back;
	back.loadFromFile("Media/Textures/background.png");
	sf::Sprite background(back, backgroundSize);


	//Rectangle image objs
	sf::RectangleShape player1(sf::Vector2f(32.0f, 32.0f));
	sf::RectangleShape player2(sf::Vector2f(32.0f, 32.0f));
	sf::RectangleShape bomb(sf::Vector2f(32.0f, 32.0f));


	//position sets
	player1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
	player2.setPosition(playerX[enemyPlayer], playerY[enemyPlayer]);
	thisInfo.al[0] = playerX[thisPlayer];
	thisInfo.al[1] = playerY[thisPlayer];

	//player Texture
	sf::Texture playerTex;
	playerTex.loadFromFile("Media/Textures/players.png");
	player1.setTexture(&playerTex);
	player2.setTexture(&playerTex);
	player1.setTextureRect(sf::IntRect(0, 0, 32, 32));
	player2.setTextureRect(sf::IntRect(32, 0, 32, 32));
	player1.setOrigin(16.0f, 16.0f);
	player2.setOrigin(16.0f, 16.0f);
	sf::Vector2i vec1 = posToArr(playerX[thisPlayer], playerY[thisPlayer]);
	sf::Vector2i vec2 = posToArr(playerX[enemyPlayer], playerY[enemyPlayer]);


	//Game Loop
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			pressedKey = 'A';
		}
		else if (pressedKey == 'A') {
			pressedKey = 'N';
			vec1 = posToArr(playerX[thisPlayer], playerY[thisPlayer]);
			if (((vec1.x - 1) >= 0) && (vec1.x <= 10)) {
				boxValue = game.sendStat(vec1.x - 1, vec1.y);
				if (boxValue == 0) {

					playerX[thisPlayer] -= 50.0f;
					player1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
				}
			}


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			pressedKey = 'W';
		}
		else if (pressedKey == 'W') {
			pressedKey = 'N';
			vec1 = posToArr(playerX[thisPlayer], playerY[thisPlayer]);
			if (((vec1.y - 1) >= 0) && (vec1.y <= 10)) {
				boxValue = game.sendStat(vec1.x, vec1.y - 1);
				if (boxValue == 0) {

					playerY[thisPlayer] -= 50.0f;
					player1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
				}
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			pressedKey = 'S';

		}
		else if (pressedKey == 'S') {
			pressedKey = 'N';
			vec1 = posToArr(playerX[thisPlayer], playerY[thisPlayer]);
			if ((vec1.y >= 0) && ((vec1.y + 1) <= 10)) {
				boxValue = game.sendStat(vec1.x, vec1.y + 1);
				if (boxValue == 0) {

					playerY[thisPlayer] += 50.0f;
					player1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
				}
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			pressedKey = 'D';
		}
		else if (pressedKey == 'D') {
			pressedKey = 'N';
			vec1 = posToArr(playerX[thisPlayer], playerY[thisPlayer]);
			if ((vec1.x >= 0) && ((vec1.x + 1) <= 10)) {
				boxValue = game.sendStat(vec1.x + 1, vec1.y);
				if (boxValue == 0) {

					playerX[thisPlayer] += 50.0f;
					player1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && bombTime[thisPlayer] == 0) {
			pressedKey = 'L';
			bombTime[thisPlayer] = 0;
		}
		else if (pressedKey == 'L') {
			totalbomb++;
			pressedKey = 'N';
			thisInfo.boom = 1;
			bombRect1.left = 0;
			bombTime[thisPlayer] = 20;
			sprite1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
			fireSprite1.setPosition(playerX[thisPlayer], playerY[thisPlayer]);
			bombX[thisPlayer] = playerX[thisPlayer];
			bombY[thisPlayer] = playerY[thisPlayer];
			game.bombPlace(posToArr(bombX[thisPlayer], bombY[thisPlayer]));

		}
		if (bombTime[thisPlayer] > 0) {
			if (clock1.getElapsedTime().asSeconds() > 2.0f / 12) {

				bombRect1.left += 32;
				bombTime[thisPlayer]--;


				sprite1.setTextureRect(bombRect1);
				clock1.restart();


			}
		}
		if (bombTime[enemyPlayer] > 8) {
			if (clock2.getElapsedTime().asSeconds() > 2.0f / 12) {

				bombRect2.left += 32;
				bombTime[enemyPlayer]--;


				sprite2.setTextureRect(bombRect2);
				clock2.restart();


			}
		}
		thisInfo.al[0] = playerX[thisPlayer];
		thisInfo.al[1] = playerY[thisPlayer];

		


		
			client.update(thisInfo,enemyInfo);
			thisInfo.boom = 0;
		
		playerX[enemyPlayer] = enemyInfo.al[0];
		//playerX[enemyPlayer] = enemyInfo.al[0];
		playerY[enemyPlayer] = enemyInfo.al[1];
	

		//enemy position set
		player2.setPosition(playerX[enemyPlayer], playerY[enemyPlayer]);

		//enemy bomb
		//enemyInfo.boom = 0;
		if (enemyInfo.boom == 1) {

			//pressedKey = 'N';
			totalbomb++;
			bombRect2.left = 0;
			bombTime[enemyPlayer] = 20;
			sprite2.setPosition(playerX[enemyPlayer], playerY[enemyPlayer]);
			fireSprite2.setPosition(playerX[enemyPlayer], playerY[enemyPlayer]);
			bombX[enemyPlayer] = playerX[enemyPlayer];
			bombY[enemyPlayer] = playerY[enemyPlayer];
			game.bombPlace(posToArr(bombX[enemyPlayer], bombY[enemyPlayer]));

		}


		window.clear(sf::Color::Cyan);
		window.draw(background);
		if (bombTime[thisPlayer] > 0) {
			window.draw(sprite1);
		}
		if (bombTime[enemyPlayer] > 0) {
			window.draw(sprite2);
		}

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				if (game.sendStat(i, j) == 1) {
					fence.setPosition(float((i * 50) + 175), float((j * 50) + 100));
					window.draw(fence);
				}
			}
		}
		window.draw(player1);
		window.draw(player2);
		if (bombTime[thisPlayer] == 9) {
			window.draw(fireSprite1);
			isPlayerKilled = game.explosion(posToArr(bombX[thisPlayer], bombY[thisPlayer]), posToArr(playerX[thisPlayer], playerY[thisPlayer]), posToArr(playerX[enemyPlayer], playerY[enemyPlayer]));

		}
		if (bombTime[enemyPlayer] == 9) {
			window.draw(fireSprite2);
			isPlayerKilled = game.explosion(posToArr(bombX[enemyPlayer], bombY[enemyPlayer]), posToArr(playerX[thisPlayer], playerY[thisPlayer]), posToArr(playerX[enemyPlayer], playerY[enemyPlayer]));

		}
		fstream file;
		file.open("Src/Data/record.txt", ios::out);
		file.write((char*)&totalbomb, sizeof(totalbomb));
		file.close();


		//fstream file;
		file.open("Src/Data/record.txt", ios::in);
		file.read((char*)&fromFiletotalbomb, sizeof(fromFiletotalbomb));
		file.close();


		if (isPlayerKilled.x == 1) {

			cout << endl << endl << "You died" << endl << endl << endl;
			cout << "\t" << "Total bomb ::" << fromFiletotalbomb << endl;
			window.close();

		}
		if (isPlayerKilled.y == 1) {

			cout << endl << endl << "You win" << endl << endl << endl;
			cout << "\t" << "Total bomb ::" << fromFiletotalbomb << endl;

			window.close();

		}

		window.display();

	}


}

