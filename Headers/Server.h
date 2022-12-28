#pragma once
#include <WS2tcpip.h>
#include"InfoHolder.h"
//#include <SFML/Graphics.hpp>
#pragma comment (lib, "ws2_32.lib")

using namespace std;
class Server
{

public:
    Server();
    ~Server();
    void runServer();
    infoHolder update(infoHolder myobj);
private:
    WSADATA wsData;
    WORD ver;
    SOCKET listening;
    SOCKET clientSocket;
    sockaddr_in hint;
    sockaddr_in enemy;
    
};

