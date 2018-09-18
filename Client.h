#ifndef TIC_TAC_TOE_CLIENT_H
#define TIC_TAC_TOE_CLIENT_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

class Client {
private:
    int client;
    uint16_t portNum;
    bool isExit;
    size_t bufsize;
    char buffer[1024];
    string ip;
    struct sockaddr_in server_addr;
    socklen_t size;

public:
    Client();
    int startClient();
};


#endif //TIC_TAC_TOE_CLIENT_H
