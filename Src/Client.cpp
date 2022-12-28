#include "Headers/Client.h"

Client::Client(std::string s) {
    ipAddress = s;
    port = 54000;
    ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &data);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);
    int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
}

void Client::update(infoHolder buf,infoHolder& refbuf) {
   
    recv(sock, (char*)&refbuf, sizeof(infoHolder), 0);
    send(sock, (char*)&buf, sizeof(infoHolder), 0);
    
}
Client::~Client() {
    closesocket(sock);
    WSACleanup();
}
