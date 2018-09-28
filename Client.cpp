#include "Client.h"

Client::Client() : client(socket(AF_INET, SOCK_STREAM, 0)), portNum(1502), isExit(false), bufsize(1), buffer(), ip("127.0.0.1") {

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


    cout << "\n\n=> Enter Ctrl-C to end the connection\n" << endl;
    do {
        do {
            cout << "Player: ";
            cin >> buffer;
            send(client, buffer, bufsize, 0);
        } while (! send(client, buffer, bufsize, 0));

        do {
            cout << "Wait for server..." << endl;
            recv(client, buffer, bufsize, 0);
            cout << "Server: " << buffer << " " << endl;
        } while (! recv(client, buffer, bufsize, 0));

    } while (!isExit);

    cout << "\n=> Connection terminated.\nGoodbye...\n";
    close(client);

    return 0;
}


//int main(){
//
//    Client client = Client();
//
//    return 0;
//}