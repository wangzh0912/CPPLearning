// 1. Class Definitions
// - class members
// - public: accessible to all code
// - private: accessible to other class members
// - protected: use in inheritance

// 2. Constructors
// - Same name with the name of class
// - No return type
// - Maybe overloaded
// - constructor initializer
// - const member and reference member require initializer

// 3. Friends: allow non-member functions access the private members of a class
// in header file
// 4. static member: associated with class not the object

// date.h
class date {
private:
    long jDate;

    // 4. static member
    static int count;

public:
    date() : jDate(0) {};
    friend bool operator==(const date& d1, const date& d2);
    // use friend so we can access jDate in d1 and d2

    // 5. copy constructor
    date(const date&);

    // 6. this
    // this is the address of the current object
    date& operator=(const date& dt) {
        if (this == &dt)
            return *this;
        jDate = dt.jDate;
        return *this;
    }

    // 7. const member functon: CANNOT CHANGE the OBJECT
    int year() const {
        if (jDate == 0)
            return 0;
        // some stuff here
        int y;
        return y;
    }
}
// date.cpp


