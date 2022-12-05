// Program to demonstrate shallow and deep copy methods
#include <bits/stdc++.h>
using namespace std;

// In shallow copy, an object is created by simply copying the data of all variables of the original object. This works well if none of the variables of the object are defined in the heap section of memory. If some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location. This will lead to run-time errors due to creation of an ambiguity... a dangling pointer!
// class Example
// {
//     int length, *breadth, height;

// public:
//     void setter(int l, int b, int h)
//     {
//         length = l;
//         *(breadth) = b;
//         height = h;
//     }
//     void display()
//     {
//         cout << "This is shallow copying!" << endl
//              << &length << endl
//              << breadth << "\tNotice how the address remains the same! " << endl
//              << &height << endl;
//     }
// };
//-----------------------------------------------------------------------------------------------------------------------------------------------//
// In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object. In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.
class Example
{
    int length, *breadth, height;

public:
    Example()
    {
        breadth = new int; // allocates fresh memory resources
    }

    void setter(int l, int b, int h)
    {
        length = l;
        *breadth = b; // deep copy is needed to create replicas of objects whose variables are allocated in the heap section by DMA
        height = h;
    }

    void display()
    {
        cout << length << endl
             << breadth << "\tNotice how the address of DMA variables are unique!" << endl
             << height << endl;
    }

    Example(Example &sample)
    { // Copy constructor needs to be defined accordingly!
        length = sample.length;

        breadth = new int; // allocate new memory bytes
        *breadth = *(sample.breadth);

        height = sample.height;
    }

    ~Example()
    { // Destructor for freeing up the memory
        delete breadth;
    }
};

int main(int argc, char const *argv[])
{
    cout << "This is how you Deep Copy!\n"
         << endl;

    Example example1;
    example1.setter(1, 2, 3);
    example1.display();
    cout << endl;

    Example example2 = example1;
    example2.display();
    cout << endl;

    return 0;
}
