#include "socketConnection.hh"

socketConnection_client &socketConnection_client::clientConnect(char ip_address[])
{
    if ((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() failed");
        exit(SOCKET_CREATION_FAILED);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORTNUMBER);

    std::cout << ip_address << std::endl;

    if (inet_pton(address.sin_family, ip_address, &address.sin_addr) <= 0)
    {
        perror("Invalid address\n");
        exit(INVALID_ADDRESS);
    }

    if (connect(socket_descriptor,
                (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Connection failed\n");
        exit(CONNECTION_FAILED);
    }

    return *this;
}

int socketConnection_client::client_read(char server_buffer[], int size)
{
    int read_bytes = read(socket_descriptor, server_buffer, size);
    return read_bytes;
}

int socketConnection_client::client_read()
{
    int read_bytes = 0;
    read(socket_descriptor, &read_bytes, sizeof(read_bytes));
    return ntohl(read_bytes);
}

int socketConnection_client::client_send(int number_to_send)
{
    int read_bytes = htonl(number_to_send);
    return send(socket_descriptor, &read_bytes, sizeof(read_bytes), 0);
}

int socketConnection_client::client_send(char character_to_send[])
{
    return send(socket_descriptor, character_to_send,
                strlen(character_to_send), 0);
}