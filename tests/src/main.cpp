#include <iostream>
#include "stos_tablica.hh"
#include "stackList.hh"
#include "socketConnection.hh"

using namespace std;

int main(int argc, char *argv[])
{
    char send[] = "Collere";
    char received[] = "Collere";
    char end = 'q';
    int socketDescriptor;
    socketConnection serverConn;

    serverConn.fill_socket_connection();
    socketDescriptor = serverConn.create_socket();
    serverConn.server_read(send);

    return 0;
}