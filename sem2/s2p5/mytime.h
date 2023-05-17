#pragma once

#include "Triad.h"
#include <iostream>
using namespace std;

// Class TIME is based on class Triad
class TIME : public Triad {
public:
    using Triad::Triad;

    bool operator==(const Triad &);
    bool operator!=(const Triad &);
    friend ostream &operator<<(ostream &, const TIME &);
    friend istream &operator>>(istream &, TIME &);
};


