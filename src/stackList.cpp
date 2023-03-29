#include "stackList.hh"

template <char>
std::ofstream &operator<<(std::ofstream &out, stackList<char> list)
{
    std::shared_ptr<stackNode<char>> tmpPtr = list.getHead();
    std::cout << "collere" << std::endl;
    while (tmpPtr != NULL)
    {
        std::cout << "Tusk" << std::endl;
        std::cout << tmpPtr->getElement() << std::endl;
        tmpPtr = tmpPtr->getNext();
    }

    return out;
}