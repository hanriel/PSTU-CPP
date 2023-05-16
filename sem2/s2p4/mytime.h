#pragma once

#include "triad.h"
#include <iostream>
using namespace std;

// Class TIME is based on class Triad
class TIME : public Triad {
public:
    using Triad::Triad;
};

std::ostream& operator << (std::ostream &out, const TIME &t) {
    return out << t.first << ':' << t.second << ':' << t.third;
}