#ifndef TEST1
#define TEST1

/*
    Test1
    test1.cpp- program for checking the functionality of push()
    and pop() methods for the implementation of stack idea based
    on an array

    test1.cpp source file includes the check of stackArray template
    for the followinng types:
        -> int
        -> double
        -> float
        -> char

    Test schedule
        -> open the file with data
        -> read the data from the file
        -> push the data on the stack
        -> check the size
        -> pop the data from stack
        -> check whether element from the stack
        is the same as this read from input
*/

#include <iostream>
#include <fstream>
#include "stos_tablica.hh"
#include "stackList.hh"
#include "socketConnection.hh"
#include "fileTransferClient.hh"

constexpr char path[] = "../tests_data/test_data.txt";
constexpr int buffer_size = 100;

int main()
{
    char *buffer = new char(buffer_size);
    std::ifstream testDataStream(path, std::ifstream::in);

    /*if (testDataStream.fail())
    {
        perror("Failed to open file with data for tests");
        return -1;
    }*/

    testDataStream.getline(buffer, buffer_size);

    /*
        Declare socketConnection_client object to
        enable handle connection to server
    */
    socketConnection_client serverConn;

    /* Connect to given ip_address */
    serverConn.clientConnect(buffer);

    delete[] buffer;

    buffer = new char(buffer_size);

    testDataStream.getline(buffer, buffer_size);

    fileTransferClient Transfer(buffer);

    Transfer.receiveFile(serverConn);
    Transfer.writeToFile();

    return 0;
}

#endif