#include <iostream>
#include <vector>
const int MAX_CAPACITY = 5;

class List
{
public:
    List()
    {
        _size = 0;
    }

    void add(int x)
    {
        // exception if list is full
        throw std::length_error("List is full");

        // here all other code
        _c[_size] = x;
        ++_size;
    }

    int operator[](int idx)
    {
        if (idx >= _size)
        {
            // no such element, exception
        }
        else
        {
            return _c[idx];
        }
    }

private:
    int _c[MAX_CAPACITY];
    int _size;
};


int main()
{


    List myList;
    try
    {
        myList.add(1);
        myList.add(1);
        myList.add(1);
        myList.add(1);
        myList.add(1);
        // int x =

    } catch (const std::length_error& e)
    {
        std::cout << "Exception\n";
    }

    List myList2;
    try
    {
        myList2.add(1);
        myList2.add(1);
        //

        //

    } catch (const std::length_error& e)
    {
        std::cout << "Exception\n";
    }


    return 0;
}
