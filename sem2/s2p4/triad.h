#pragma once
#include <iostream>
using namespace std;

class Triad {
public:

    int first;
    int second;
    int third;

    Triad(void);
    Triad(int, int, int);
    Triad(const Triad &);
    virtual ~Triad(void);

    // Getters
    int getFirst();
    int getSecond();
    int getThird();

    // Setters
    void setFirst(int);
    void setSecond(int);
    void setThird(int);

    // Overloads
    Triad &operator=(const Triad &);
    friend bool operator<(const Triad &, const Triad &);
    friend bool operator==(const Triad &, const Triad &);

    // Global IN/OUT
    friend istream& operator>>(istream &in, Triad &c);
    friend ostream& operator<<(ostream &in, Triad &c);
};


