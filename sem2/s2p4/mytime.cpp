#include "mytime.h"
#include <iostream>


bool TIME::operator==(const Triad &other) {
    return (
            this->first == other.first &&
            this->second == other.second &&
            this->third == other.third
    );
}

bool TIME::operator!=(const Triad &other) { return !(*this == other); }

ostream &operator<<(std::ostream &out, const TIME &t) {
    return out << t.first << ':' << t.second << ':' << t.third;
}

istream &operator>>(istream &in, TIME &t) {
    cout << "Hours: ";
    in >> t.first;
    cout << "Minutes: ";
    in >> t.second;
    cout << "Seconds: ";
    in >> t.third;
    return in;
}