#pragma once
//#include <SFML/Graphics.hpp>
#include<iostream>
#include"InfoHolder.h"
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Client
{
public:
    Client(string s);
    void update(infoHolder buf,infoHolder& refbuf);
    ~Client();
private:

    WSADATA data;
    WORD ver;
    string ipAddress;
    int port;
    SOCKET sock;
    SOCKET clientSocket;
    sockaddr_in hint;
    sockaddr_in enemy;

};

