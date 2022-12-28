#include "Headers/Server.h"

Server::Server() {
        ver = MAKEWORD(2, 2);

        int wsOk = WSAStartup(ver, &wsData);
        listening = socket(AF_INET, SOCK_STREAM, 0);
        hint.sin_family = AF_INET;
        hint.sin_port = htons(54000);
        hint.sin_addr.S_un.S_addr = INADDR_ANY;
        bind(listening, (sockaddr*)&hint, sizeof(hint));

        listen(listening, SOMAXCONN);
 }


void Server::runServer() {
        int clientSize = sizeof(enemy);
        clientSocket = accept(listening, (sockaddr*)&enemy, &clientSize);


        closesocket(listening);
    }

  
infoHolder Server::update(infoHolder myobj) {
        send(clientSocket, (char*)&myobj, sizeof(infoHolder), 0);
        recv(clientSocket, (char*)&myobj, sizeof(infoHolder), 0);
        return myobj;
 }
Server::~Server() {
    closesocket(clientSocket);
    WSACleanup();
}

