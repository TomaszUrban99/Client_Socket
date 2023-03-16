#ifndef SOCKET_CONNECTION_HH
#define SOCKET_CONNECTION_HH

/* Libraries for socket operation */

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

constexpr int PORTNUMBER = 8080;
constexpr int ALLOWED_REPETITIONS = 10;

constexpr int SOCKET_CREATION_FAILED = 1;
constexpr int BIND_FAILED = 2;
constexpr int LISTEN_FAILED = 3;
constexpr int ACCEPT_FAILED = 4;

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
class socketConnection
{
    struct sockaddr_in address;
    int socket_descriptor;
    int address_len;

public:
    /*!
        socketConnection &fill_socket_connection()- method
        which makes server listening on the given port

        Function:
            1. create socket on which server will be listening to,
            socket descriptor returned by the function socket would
            be stored on the field socket_descriptor
            2. bind the port number and socket
            3. listen for incoming messagess

        Return:
        \retval socketConnection&- reference to the object of class
        socket connection
    */
    socketConnection &fill_socket_connection();

    /*
        int create_socket()- function, which accepts connection
        request sent on given port number
    */
    int create_socket();

    /*
        int server_read()- function for reading incoming
        messages
    */
    int server_read(char server_buffer[]);

    /*
        int server_send()- function for sending messages
        to the connected clients
    */
    int server_send(char *character_to_send[]);
};

#endif