#pragma once

#include <iostream>

using namespace std;

class Triad {
public:

    int first;
    int second;
    int third;

    Triad();

    Triad(int, int, int);

    Triad(const Triad &);

    virtual ~Triad();

    // Getters
    int getFirst() const;

    int getSecond() const;

    int getThird() const;

    // Setters
    void setFirst(int);

    void setSecond(int);

    void setThird(int);

    // Overloads
    Triad &operator=(const Triad &);

    bool operator<(const Triad &) const;

    bool operator==(const Triad &) const;

    // Global IN/OUT
    friend istream &operator>>(istream &in, Triad &c);

    friend ostream &operator<<(ostream &in, Triad &c);
};


