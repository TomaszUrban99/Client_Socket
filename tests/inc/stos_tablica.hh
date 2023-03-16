#ifndef STOS_TABLICA
#define STOS_TABLICA

#include <iostream>

/*!
    Template of class StackArray.
    Class realise the concept of stack, which implementation
    is based on an array.

    Attributes of StackArray class:
        T *arrayStack- pointer to an array of elements of type T
        int _stackSize- number of elements on the stack
*/
template <class T>
class StackArray
{
    T *arrayStack;
    int _stackSize = 0;

public:
    /*!
        StackArray()- constructor of instance of
        class made from template StackArray.
    */
    StackArray()
    {
        arrayStack = (T *)malloc(0 * sizeof(T));
    }
    /*!
        ~StackArray()- destructor of instance of
        class made from template StackArray.
    */
    ~StackArray()
    {
        free(arrayStack);
    }

    /* stackSize()- return number of elements on the stack */
    int stackSize();

    /* empty()- check whether the stack is empty */
    bool empty();

    void push(T newElement);
    T pop();

    void printStack();
};

/*!
    int stackSize()- method returning number of elements put on
    the stack

    \retval int _stackSize- number of elements on the stack
*/
template <class T>
int StackArray<T>::stackSize()
{
    return _stackSize;
}

/*!
    bool empty()- function for checking whether stack is empty
    \retval bool true- given stack is empty
    \retval bool false- given stack is not empty
*/
template <class T>
bool StackArray<T>::empty()
{
    if (_stackSize)
        return false;
    return true;
}

/*!
    void push(T newElement)- move given element to the
    top of a stack

    Function puts the given element of type T on the
    top of given stack. First- allocate memory for an array
    one size larger than the current array (tmpStack).

    \arg T newElement- element to be put on the top
    of the stack

    \retval none- function does not return

*/
template <class T>
void StackArray<T>::push(T newElement)
{
    T *tmpArray = new T(_stackSize + 1);
    tmpArray[_stackSize] = newElement;

    for (int i = 0; i < _stackSize; ++i)
        tmpArray[i] = arrayStack[i];

    free(arrayStack);
    arrayStack = tmpArray;
    _stackSize++; // change the attribute
}

/*!
    pop()- function to get the top element from the stack
    \retval T- element from the top of the stack
*/
template <class T>
T StackArray<T>::pop()
{
    T tmp = arrayStack[_stackSize - 1];

    if (_stackSize > 0)
    {
        _stackSize--;
        T *tmpArray = new T(_stackSize);

        for (int i = 0; i < _stackSize; ++i)
            tmpArray[i] = arrayStack[i];

        free(arrayStack);
        arrayStack = tmpArray;
    }
    else
    {
        std::cout << "Stack is empty" << std::endl;
    }

    return tmp;
}

/*!
    void printStack()- function for returning the elements
    from the stack.
*/
template <class T>
void StackArray<T>::printStack()
{
    for (int i = _stackSize - 1; i >= 0; --i)
        printf("%d %s", arrayStack[i], " ");

    printf("%s", "\n");
}

#endif