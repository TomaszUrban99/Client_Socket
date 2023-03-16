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
#include <string>
#include "stos_tablica.hh"

constexpr char path[] = "../tests/tests_data/test1_data.txt";

int main()
{
    StackArray<int> stack_int;
    StackArray<float> stack_float;
    StackArray<double> stack_double;
    StackArray<char> stack_char;

    /* Opening the file */
    std::ifstream fileHandle;
    fileHandle.open(path);
    if (!fileHandle.is_open())
    {
        return -1;
    }

    /* Integers */
    int intVar;
    fileHandle >> intVar;
    if (!fileHandle.is_open())
    {
        return -1;
    }

    stack_int.push(intVar);
    if (stack_int.stackSize() != 1)
        return -1;

    /* Check the pop function */
    if (stack_int.pop() != intVar)
        return -1;

    /* Double */
    double doubleVar;
    fileHandle >> doubleVar;
    if (fileHandle.fail())
        return -1;
    stack_double.push(doubleVar);
    if (stack_double.stackSize() != 1)
        return -1;

    /* Check the pop function */
    if (stack_double.pop() != doubleVar)
        return -1;

    /* Float */
    float floatVar;
    fileHandle >> floatVar;
    if (fileHandle.fail())
        return -1;
    stack_float.push(floatVar);
    if (stack_float.stackSize() != 1)
        return -1;

    /* Check the pop function */
    if (stack_float.pop() != floatVar)
        return -1;

    /* Char */
    char charVar;
    fileHandle >> charVar;
    if (fileHandle.fail())
        return -1;
    stack_char.push(charVar);
    if (stack_char.stackSize() != 1)
        return -1;

    /* Check the pop function */
    if (stack_char.pop() != charVar)
        return -1;

    return 0;
}

#endif