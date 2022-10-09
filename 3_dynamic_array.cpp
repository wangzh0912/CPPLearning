#include <iostream>
using namespace std;

int main() {
    // 1. Dynamic array using new and delete
    // memory leak: a dynamic array uses memory heap instead of memory stack
    // a heap does not auto-delete itself like the stack, and may cause a memory leak
    // Say if you point a pointer to a dynamic array A,
    // and you assign the pointer to another array B,
    // you cannot access to A anymore; A is called the memory leak

    int *pia = new int[10];
    delete [] pia; // delete the dynamic array
    pia = 0;       // set the pointer to null

    return 0;
};
