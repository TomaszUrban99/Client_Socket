#ifndef FILE_TRANSFER_CLIENT_HH
#define FILE_TRANSFER_CLIENT_HH

#include <iostream>
#include <fstream>

#include "stackList.hh"
#include "socketConnection.hh"

constexpr int FILE_OPEN_FAILED = 101;

constexpr int CORRECT_SENT_FILE_SIZE = 10;
constexpr int CORRECT_SENT_PACKET_NUMBER = 12;

class fileTransferClient
{
    int _fileSize;
    int _packetSize;
    int _lastPacketSize;
    int _packetNumber;

    stackList<char *> _packetList;
    char *_outputFileName;
    std::ofstream _outputFile;

public:
    fileTransferClient(char *fileName)
    {
        _outputFileName = fileName;
    }

    void openFile();

    void putOnList(char *newPacket, int packet_number);

    void receiveFileInformation(socketConnection_client &Connection);

    void receiveFile(socketConnection_client &Connection);

    void writeToFile();
};

#endif