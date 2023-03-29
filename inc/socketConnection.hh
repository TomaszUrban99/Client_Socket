#ifndef SOCKET_CONNECTION_HH
#define SOCKET_CONNECTION_HH

/* Libraries for socket operation */

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

constexpr int PORTNUMBER = 8080;
constexpr int ALLOWED_REPETITIONS = 10;

constexpr int SOCKET_CREATION_FAILED = 1;
constexpr int INVALID_ADDRESS = 2;
constexpr int CONNECTION_FAILED = 3;

/*!
    Class socketConnection- representing the idea of connection
    as a server.

    Attributes:
        ->struct sockaddr_in address- structure for storing
        information about connection to be established by the server
        ->int socket_descriptor- socket descriptor through which
        the connection would be established
        ->int address_len- size of address attribute
*/
class socketConnection_client
{
    struct sockaddr_in address;
    int socket_descriptor;
    int address_len;

public:
    /*

    */
    socketConnection_client &clientConnect(char ip_Adress[]);

    /*
        int server_read()- function for reading incoming
        messages
    */
    int client_read();

    int client_read(char server_buffer[], int size);

    int client_send(int number_to_send);
    /*
        int server_send()- function for sending messages
        to the connected clients
    */
    int client_send(char character_to_send[]);
};

#endif