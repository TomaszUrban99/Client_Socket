#include "fileTransferClient.hh"

void fileTransferClient::openFile()
{
    _outputFile.open(_outputFileName,
                     std::ofstream::binary | std::ofstream::out);

    if (_outputFile.fail())
    {
        perror("Failed to open file()");
        exit(FILE_OPEN_FAILED);
    }
}

void fileTransferClient::putOnList(char *newPacket, int packetNumber)
{
    _packetList.push(newPacket, packetNumber);
}

void fileTransferClient::receiveFileInformation(socketConnection_client &Connection)
{
    /* Get the file size */
    _fileSize = Connection.client_read();

    std::cout << "file size:" << _fileSize << std::endl;
    /* If correct, send the answer */
    Connection.client_send(CORRECT_SENT_FILE_SIZE);

    /* Get the number of packets */
    _packetNumber = Connection.client_read();
    /* If correct, send the answer */
    Connection.client_send(CORRECT_SENT_PACKET_NUMBER);

    /* Get the information about packets size */
    _packetSize = Connection.client_read();

    _lastPacketSize = Connection.client_read();

    /*
        Return the file size counted on the base of number of packets
        and each packet's size
    */
    Connection.client_send((_packetNumber - 1) * _packetSize + _lastPacketSize);
}

void fileTransferClient::receiveFile(socketConnection_client &Connection)
{
    /* Packets iterator */
    int j = 1;

    /* Receive file information */
    receiveFileInformation(Connection);

    while (j <= _packetNumber)
    {
        int bytes_received = 0;
        int bytes_one = 0;

        int current_packet_number = Connection.client_read();
        int packet_size;

        if (current_packet_number != _packetNumber)
            packet_size = _packetSize;
        else
            packet_size = _lastPacketSize;

        std::cout << "Numer pakietu: " << current_packet_number << std::endl;

        char *received = new char[packet_size];

        while (bytes_received < packet_size)
        {
            bytes_one = Connection.client_read(received, packet_size - bytes_received);

            if (bytes_one < 1)
            {
                perror("Failed to read data()");
                exit(1);
            }

            bytes_received = bytes_received + bytes_one;
            received = received + bytes_one;
        }
        j++;

        std::cout << "Received bytes: " << bytes_received << std::endl;
        received = received - bytes_received;
        _packetList.push(received, current_packet_number);
    }
}

void fileTransferClient::writeToFile()
{
    /*
        Open file to transfer

        Method checks, whether the stream to file has
        been corretly oppened
    */
    openFile();

    for (int i = 0; i < _packetNumber; ++i)
    {
        if (i != (_packetNumber - 1))
        {
            char *packet = _packetList.pop();
            _outputFile.write(packet, _packetSize);
        }

        else
            _outputFile.write(_packetList.pop(), _lastPacketSize);
    }
}