#include "socketConnection.hh"

socketConnection &socketConnection::fill_socket_connection()
{
    if ((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() failed");
        exit(SOCKET_CREATION_FAILED);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORTNUMBER);
    address_len = sizeof(address);

    if (bind(socket_descriptor,
             (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind() failed");
        exit(BIND_FAILED);
    }

    if (listen(socket_descriptor, ALLOWED_REPETITIONS) < 0)
    {
        perror("listen() failed");
        exit(LISTEN_FAILED);
    }

    return *this;
}

int socketConnection::create_socket()
{
    int new_socket = accept(socket_descriptor,
                            (struct sockaddr *)&address, (socklen_t *)&address_len);

    std::cout << new_socket << std::endl;
    if (new_socket < 0)
    {
        perror("accept() failed");
        exit(ACCEPT_FAILED);
    }

    return new_socket;
}

int socketConnection::server_read(char server_buffer[])
{
    read(socket_descriptor,
         server_buffer, sizeof(*server_buffer) / sizeof(char));

    return 0;
}