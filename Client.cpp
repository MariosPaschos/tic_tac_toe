#include "Client.h"

Client::Client() : client(socket(AF_INET, SOCK_STREAM, 0)), portNum(1500), isExit(false), bufsize(1024), buffer(), ip("127.0.0.1") {

    startClient();
}

int Client::startClient() {

    if (client < 0) {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }
    cout << "\n=> Socket client has been created..." << endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        cout << "=> Connection to the server port number: " << portNum << endl;
    }
    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed...";


    cout << "\n\n=> Enter # to end the connection\n" << endl;
    do {
        cout << "Client: ";
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != '*');
        cout << endl;

    } while (!isExit);

    cout << "\n=> Connection terminated.\nGoodbye...\n";
    close(client);

    return 0;
}


int main(){

    Client client = Client();

    return 0;
}