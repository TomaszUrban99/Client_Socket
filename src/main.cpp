#include <iostream>
#include "stos_tablica.hh"
#include "stackList.hh"
#include "socketConnection.hh"

using namespace std;

int main(int argc, char *argv[])
{
    char send[] = "Collere";
    char received[] = "Collere";
    char ip_address[] = "127.0.0.1";
    char end = 'q';
    int socketDescriptor;
    socketConnection_client serverConn;

    serverConn.clientConnect(ip_address);
    serverConn.client_send(send);

    return 0;
}