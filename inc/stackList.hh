#ifndef STACK_LIST_HH
#define STACK_LIST_HH

#include <memory>
#include <iostream>
#include <fstream>
#include "stackNode.hh"

template <class T>
class stackList
{
    /* Pointer to the head of the stack */
    std::shared_ptr<stackNode<T>> _head;
    /* Pointer to the bottom of the stack */
    std::shared_ptr<stackNode<T>> _tail;
    /* Number of elements on the stack */
    int _stackSize = 0;

public:
    /* CONSTRUCTORS AND DESTRUCTOR */
    stackList<T>()
    {
        _head = nullptr;
        _tail = nullptr;
    }
    ~stackList<T>()
    {
    }

    /* ACCESS TO ATTRIBUTES */
    T &top();
    std::shared_ptr<stackNode<T>> getHead();
    T top() const { return _head->getElement(); }

    /* TOOLS FOR THE STACK */
    void push(T newElem);
    void push(T newElem, int newElemNumber);
    T pop();
};

/*!
    top()- return the element from the top node
*/
template <typename T>
T &stackList<T>::top()
{
    return _head->getElement();
}

/*!
    push()- method for putting element on the top of the stack

    \arg T newElem- element to put on the top of the stack

    Function:
        1. Create a new instance of stackNode class, which will
        be pointed by std::shared_ptr<> newNodePtr
        2. Set the current head of the stack (_head) as the next node
        after new node.
        3. Set new head of stack- newly created node.
        4. If stack was empty, before push(), then set the tail to the
        new node of the stack.
        5. Increment value of attribute _stackSize;

    \retval void method- no return value
*/
template <typename T>
void stackList<T>::push(T newElem)
{
    std::shared_ptr<stackNode<T>> newNodePtr(new stackNode<T>(newElem));

    newNodePtr->setNext(_head);
    _head = newNodePtr;

    if (_stackSize == 0)
        _tail = newNodePtr;

    _stackSize++;
}

template <typename T>
void stackList<T>::push(T newElem, int newNodeNumber) // 1 + 2
{
    std::shared_ptr<stackNode<T>> newNodePtr(new stackNode<T>(newElem, newNodeNumber)); // 5
    std::shared_ptr<stackNode<T>> tmpNode = _head; // 3

    if (tmpNode == NULL) // 3
    {
        _head = newNodePtr;
        newNodePtr->setNext(NULL); 
        _tail = newNodePtr;
    }
    else
    {
        while (tmpNode->getNext() != NULL && tmpNode->getNext()->getNodeNumber() < newNodeNumber) // 7 * (1 + 2 + 3 + 4 + ... (n-1)) = 
        { // 7 * n*(1 + n-1)/2 = n^2 * 7/2
            tmpNode = tmpNode->getNext();
        }

        if (tmpNode == _head && tmpNode->getNodeNumber() > newNodeNumber) // 8 * (n-1)
        {
            newNodePtr->setNext(_head);
            _head = newNodePtr;
        }
        else if (tmpNode->getNext() == NULL)
        {
            tmpNode->setNext(newNodePtr);
            newNodePtr->setNext(NULL);
        }
        else
        {
            newNodePtr->setNext(tmpNode->getNext());
            tmpNode->setNext(newNodePtr);
        }
    }
}

template <typename T>
T stackList<T>::pop()
{
    T elementNode = top();
    _head = _head->getNext();

    return elementNode;
}

/*!
    getHead()- get the pointer to the top node of the stack
*/
template <typename T>
std::shared_ptr<stackNode<T>> stackList<T>::getHead()
{
    return _head;
}

/* OVERLOADED OPERATORS */
template <typename T>
std::ostream &operator<<(std::ostream &out, stackList<T> &list)
{
    std::shared_ptr<stackNode<T>> tmpPtr = list.getHead();
    while (tmpPtr != NULL)
    {
        std::cout << tmpPtr->getElement() << std::endl;
        tmpPtr = tmpPtr->getNext();
    }

    return out;
}
#endif