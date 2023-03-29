#include <iostream>
#include <fstream>
#include "stos_tablica.hh"
#include "stackList.hh"
#include "socketConnection.hh"
#include "fileTransferClient.hh"

constexpr int INPUT_ARGUMENTS = 3;

using namespace std;

int main(int argc, char *argv[])
{

    if (argc < INPUT_ARGUMENTS)
    {
        perror("Incorrect number of input arguments.");
        return -1;
    }

    /*
        Declare socketConnection_client object to
        enable handle connection to server
    */
    socketConnection_client serverConn;

    /* Connect to given ip_address */
    serverConn.clientConnect(argv[1]);

    fileTransferClient Transfer(argv[2]);

    Transfer.receiveFile(serverConn);
    Transfer.writeToFile();

    return 0;
}