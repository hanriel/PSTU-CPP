#include "mytime.h"
#include <iostream>


bool TIME::operator==(const TIME &other) {
    return (
        this->first == other.first &&
        this->second == other.second &&
        this->third == other.third
    );
}

bool TIME::operator!=(const TIME &other) { return !(*this == other); }

ostream &operator<<(std::ostream &out, const TIME &t) {
    return out << t.first << ':' << t.second << ':' << t.third;
}

istream &operator>>(istream &in, TIME &t) {
    cout << "Hours: "; in >> t.first;
    cout << "Minutes: "; in >> t.second;
    cout << "Minutes: "; in >> t.third;
    return in;
}

void TIME::Show() {
    cout<<"\nHOU : "<<first;
    cout<<"\nMIN : "<<second;
    cout<<"\nSEC : "<<third;
    cout<<"\n";
}