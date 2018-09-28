

#include "GameServer.h"


GameServer::GameServer() : client(socket(AF_INET, SOCK_STREAM, 0)), portNum(1502), isExit(false), bufsize(1024), buffer(), game(3){

    startServer();
}

int GameServer::startServer() {

    if (client < 0) {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }
    cout << "\n=> Socket server has been created..." << endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    if ((bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0) {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }

    size = sizeof(server_addr);
    cout << "=> Waiting for players to join..." << endl;
    listen(client, 1);

    server = accept(client,(struct sockaddr *)&server_addr,&size);

    // first check if it is valid or not
    if (server < 0) {
        cout << "=> Error on accepting..." << endl;
    }

    serverOnline();

    close(client);

    return 0;
}



void GameServer::serverOnline() {

    while (server > 0) {
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);
        cout << "=> Connected with player #" << endl;

        cout << "\n=> Enter Ctrl-C to end the connection\n" << endl;
        cout << "Client: ";
        do {
            cout << "Wait for player..." << endl;
            do {
                recv(server, buffer, bufsize, 0);
                cout << "Client: " << buffer << " " << endl;
            } while (!recv(server, buffer, bufsize, 0));

            do {
                cout << "Server: ";
                cin >> buffer;
                send(server, buffer, bufsize, 0);
            } while (!send(server, buffer, bufsize, 0));

        } while (!isExit);

        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
        isExit = false;
        exit(1);
    }
}


//int main(){
//
//    GameServer gameServer = GameServer();
//    return 0;
//}