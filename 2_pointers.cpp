#include <iostream>
using namespace std;

int main() {

    // 1. Dereference: obtain the object to which the pointer points
    string s("hello world");
    string *sp = &s; // sp holds the address of s
    // & means the "address-of"

    cout << sp << endl;
    cout << *sp << endl;

    // 2. Void pointers: a special pointer type that can hold an address of any object
    double db1 = 3.14;
    void *pv = &db1;
    // you should avoid this for easier debugging

    // 3. Avoid uninitialized pointers
    // results in run-time error when we attempt to dereference the uninitialized pointers

    // 4. References: another name for the variable
    int ival = 1024, ival2 = 2048;

    int *pi = &ival, *pi2 = &ival2;
    pi = pi2;
    // *pi = 2048, *pi2 = 2048
    cout << ival << endl;

    int &ri = ival, &ri2 = ival2;
    ri = ri2;
    // ri = 2048, ri2 = 2048, ival = 2048
    cout << ival << endl;

    // 5. Pointer to pointer
    int ival3 = 1024;
    int *pi3 = &ival3;
    int **ppi = &pi3;

    // 6. Access array
    int ia[] = {0, 2, 4, 6, 8};
    int *ip = ia; // ip points to ia[0]
    ip = &ia[4];  // ip points to ia[4]

    // 7. Subscripts and pointers
    // We can use subscripts like dereference arithmatic calculation
    // p[1] = *(p+1)

    // 8. Point to the end of array
    // We can use 
    // int *p = arr;
    // int *p2 = p + arr_size
    // p2 points to the element one passed the end, but can not dereference.

    // 9. const pointer: if and only if use to point a const object

    return 0;
};
