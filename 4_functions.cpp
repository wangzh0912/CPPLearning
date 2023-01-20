#include <iostream>
using namespace std;

// 1. Defining a function
// name, parameters, function body, return type
int add(int a, int b) {
    return a + b;
}

// 2. Return type
// Built-in
// Class
// Compound type: int& int*
// Void
// CAN NOT return a function of built-in array

// 3. Reference type
// 3.1 if non-reference, the arguments are copied
// if we want to change the argument or the argument is costly to copy,
// we may want to use reference parameters

// 3.2 if reference, the arguments are not copied
// const reference parameter: may not use the references to cahnge the arguments
// non-const reference may be bound only to non-const object of exactly the same type
void reference_type(int non_refer, int &refer) {
    non_refer ++;
    refer ++;
}

// 4. Pointer parameters
void pointer_args(int *a, int *b, const int *c) {
    int tmp = 1024;
    // 4.1 Changing pointers in the function will not change arguments
    a = &tmp;
    // 4.2 However, the function can assign through the pointer,
    // and change the value of the objects the pointer points
    *b = tmp;
    // 4.3 To prevent the change of the objects the pointer points,
    // use a const pointer parameter
    // *c = tmp; ERROR
}

// 5. Array Parameter
// 5.1 The three following expression is exactly the same
void array_param(int*);
void array_param(int[]);
void array_param(int[10]);  // this is equivalent to int[], the complier will not check the dimension

// 5.2 If we use reference to an array, the size is fixed
void array_param(int (&arr)[100]);

// 5.3 multidimensioned array
// the size of second array must be input

// 6. Return a reference
const string &short_string(const string &s1, const string &s2) {
    return s1.size() < s2.size() ? s1 : s2;
}
// NEVER return a reference to a local object
const string &short_string(const string &s1, const string &s2) {
    const string s("abc");
    return s;
    // This is NOT correct. Local variable s is on the stack.
}
// NEVER return a pointer to a local object
string* short_string2(const string &s1, const string &s2) {
    string s("abc");
    return &s;
    // This is NOT correct. Local variable s is on the stack.
}

// 7. Inline function
// expanded inline at each point in the program in which it is invoked
// should be defined in header files

// 8. Function overloading

// 9. Pointers to Functions
// 9.1 the function type is determined by return type and parameter list
typedef bool (*pf) (const string &, const string &);

// 9.2 using function pointer
bool str_compare(const string &str1, const string &str2) { return true; };
pf pf1 = str_compare;
// call the function
// pf1("hi", "bye");
// (*pf1)("hi", "bye");
// function pointer can be used to pass function to another function

int main() {
    // 1. Defining a function
    cout << add(1, 2) << endl;

    // 3. Reference type
    int non_refer = 1, refer = 1;
    reference_type(non_refer, refer);
    cout << non_refer << " " << refer << endl;

    // 4. Pointer parameters
    int a = 0, b = 0;
    int *pa = &a, *pb = &b;
    pointer_args(pa, pb, pb);
    cout << *pa << " " << *pb << endl;  



    return 0;
};
