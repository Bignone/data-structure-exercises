#include <iostream>

using namespace std;

int dobleOfVarAsValue(int var)
{
    return var * 2;
}

void dobleOfVarAsPointer(int * pointer)
{
    *pointer *= 2;
}

int main()
{
    int one = 1;
    int two = 2;

    int doubleOne;
    int doubleTwo;

    int * pointerOne = &one;
    int * pointerTwo = &two;

    cout << "Operations with vars as values" << endl;
    doubleOne = dobleOfVarAsValue(one);
    cout << "Result of " << one << " * 2 = " << doubleOne << endl;
    doubleTwo = dobleOfVarAsValue(two);
    cout << "Result of " << two << " * 2 = " << doubleTwo << endl;

    cout << "Operations with vars as pointers" << endl;
    cout << "Result of " << one << " * 2 = ";
    dobleOfVarAsPointer(pointerOne);
    cout << *pointerOne << endl;
    cout << "Result of " << two << " * 2 = ";
    dobleOfVarAsPointer(pointerTwo);
    cout << *pointerTwo << endl;

    return 0;
}
