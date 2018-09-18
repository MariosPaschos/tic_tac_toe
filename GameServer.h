#ifndef TIC_TAC_TOE_GAMESERVER_H
#define TIC_TAC_TOE_GAMESERVER_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;


class GameServer {

private:
    int client;
    uint16_t portNum;
    bool isExit;
    size_t bufsize;
    char buffer[1024];
    int server;
    struct sockaddr_in server_addr;
    socklen_t size;

public:
    GameServer();
    int startServer();

};


#endif //TIC_TAC_TOE_GAMESERVER_H
