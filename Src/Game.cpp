#include "Headers/Game.h"

void Game::setValue(int i, int j, int val) {
        box[i][j] = val;
}
void Game::displayGAame(int i, int j) {
        std::cout << box[i][j] << std::endl;
}


void Game::displayGBame() {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                std::cout << box[i][j] << "\t";
            }
            std::cout << std::endl;
        }
}

void Game::startGBame() {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if ((i % 2 != 0) && (j % 2 != 0)) {
                    box[i][j] = -1;
                }
                else if ((i + j) > 1 && (i + j) < 19) {
                    box[i][j] = 1;

                }
                else {
                    box[i][j] = 0;
                }
            }
        }
    }

int Game::sendStat(int i, int j) {
        return box[i][j];
    }

void Game::bombPlace(sf::Vector2i point) {
        int x = point.x;
        int y = point.y;
        box[x][y] = -1;
    }

void Game::enemyBombPlace(sf::Vector2i point) {
        int x = point.x;
        int y = point.y;
        box[x][y] = -1;
    }

sf::Vector2i Game::explosion(sf::Vector2i point, sf::Vector2i player1, sf::Vector2i player2) {
    int x = point.x;
    int y = point.y;
    sf::Vector2i stat(0, 0);
    box[x][y] = 0;
    if (x == player1.x && y == player1.y)
        stat.x = 1;
    if (x == player2.x && y == player2.y)
        stat.y = 1;



    if (x > 0) {
        if (box[x - 1][y] == 1) {
            box[x - 1][y] = 0;
        }
        if ((x - 1) == player1.x && y == player1.y)
            stat.x = 1;
        if ((x - 1) == player2.x && y == player2.y)
            stat.y = 1;

    }
    if (x < 10) {
        if (box[x + 1][y] == 1) {
            box[x + 1][y] = 0;
        }
        if ((x + 1) == player1.x && y == player1.y)
            stat.x = 1;
        if ((x + 1) == player2.x && y == player2.y)
            stat.y = 1;
    }
    if (y > 0) {
        if (box[x][y - 1] == 1) {
            box[x][y - 1] = 0;
        }
        if (x == player1.x && (y - 1) == player1.y)
            stat.x = 1;
        if (x == player2.x && (y - 1) == player2.y)
            stat.y = 1;
    }
    if (y < 10) {
        if (box[x][y + 1] == 1) {
            box[x][y + 1] = 0;
        }
        if (x == player1.x && y + 1 == player1.y)
            stat.x = 1;
        if (x == player2.x && y + 1 == player2.y)
            stat.y = 1;
    }
    return stat;
}



        /*if (x > 0) {
            if (box[x - 1][y] == 1) {
                box[x - 1][y] = 0;
            }
            if ((x - 1) == player1.x && y == player1.y)
                stat.x = 1;
            if ((x - 1) == player2.x && y == player2.y)
                stat.y = 1;

        }
        if (x < 10) {
            if (box[x + 1][y] == 1) {
                box[x + 1][y] = 0;
            }
            if ((x + 1) == player1.x && y == player1.y)
                stat.x = 1;
            if ((x + 1) == player2.x && y == player2.y)
                stat.y = 1;
        }
        if (y > 0) {
            if (box[x][y - 1] == 1) {
                box[x][y - 1] = 0;
            }
            if (x == player1.x && (y-1) == player1.y)
                stat.x = 1;
            if (x == player2.x && (y-1) == player2.y)
                stat.y = 1;
        }
        if (y < 10) {
            if (box[x][y + 1] == 1) {
                box[x][y + 1] = 0;
            }
            if (x == player1.x && y+1 == player1.y)
                stat.x = 1;
            if (x == player2.x && y+1 == player2.y)
                stat.y = 1;
        }
        return stat;
    }*/





/*void Game::enemyExplosion(sf::Vector2i point) {
        int x = point.x;
        int y = point.y;
        box[x][y] = 0;
        if (x > 0) {
            if (box[x - 1][y] == 1) {
                box[x - 1][y] = 0;
            }
        }
        if (x < 10) {
            if (box[x + 1][y] == 1) {
                box[x + 1][y] = 0;
            }
        }
        if (y > 0) {
            if (box[x][y - 1] == 1) {
                box[x][y - 1] = 0;
            }
        }
        if (y < 10) {
            if (box[x][y + 1] == 1) {
                box[x][y + 1] = 0;
            }
        }
    }*/