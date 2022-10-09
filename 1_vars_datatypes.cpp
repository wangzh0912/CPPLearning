#include <iostream>
#include <string.h>
#include <vector>

int main() {
    // 1. Variable definition
    // <data type> <identifier>
    char a;
    int radius;
    
    // 2. Definition and declaration
    extern int test; // declares but does not define i

    // 3. Initialization
    int b(23);  // direct initialize 
    int c = 45; // copy initialize
    std::cout << b << c << std::endl;

    // 4. const qualifier
    // objects not modifiable
    const int d = 56;
    // d = 78; error

    // 5. Reference
    // making an alternative name for an object
    int ival = 1024;
    int &ref_val = ival;
    std::cout << ref_val << " " << &ref_val << std::endl;

    // 6. Give alias to datatypes and data
    // datatype
    typedef float bond_price;
    bond_price p1, p2;
    // data
    enum month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    month curr_month = Jan;

    // 7. Namespace
    // using namespace
    
    // 8. String
    std::string line;
    //getline(std::cin, line);
    line.empty();
    line.size();

    // convert string to c-string
    const char *cstr = line.c_str();

    // 9. Vector
    using std::vector;
    vector<int> ivec(10);
    vector<std::string> svec;
    // v.empty()
    // v.size()
    // v.push_back()

    // 10. Iterator
    vector<int>::iterator iter;
    vector<int>::iterator iter_b = ivec.begin();
    vector<int>::iterator iter_e = ivec.end(); // return one element after the last element
    *iter_b = 0; // assign 0 to ivec[0]
    // use index
    for (vector<int>::size_type ix=0; ix!=ivec.size(); ++ix) {
        ivec[ix] = 0;
        std::cout << ivec[ix] << " ";
    };
    std::cout << std::endl;
    // use iterator
    for (vector<int>::iterator iter=ivec.begin(); iter!=ivec.end(); ++iter) {
        *iter = 1;
        std::cout << *iter << " ";
    };
    std::cout << std::endl;
    // const iterator to not modify the element
    for (vector<int>::const_iterator iter=ivec.begin(); iter!=ivec.end(); ++iter) {
        std::cout << *iter << " ";
    };
    
    // 11. Conditional operator
    int i = 10, j = 20;
    int max_val = i > j ? i : j; // if ... then i else j

    // 12. Array
    // initialize
    char ca1[] = {'C', '+', '+', '\0'};
    char ca2[] = "C++";
    // no direct array copy or assignment
    const size_t array_size = 7;
    int ia1[] = {1, 2, 3, 4, 5, 6, 7};
    int ia2[array_size];
    for (size_t ix=0; ix!=array_size; ++ix)
        ia2[ix] = ia1[ix];
    // defining: using const number as size

};

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex(int=0, int=0);
    ~Complex();
};