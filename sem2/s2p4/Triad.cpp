#include "Triad.h"

using namespace std;

// Constructors and destructor
Triad::Triad() {
    first = 0;
    second = 0;
    third = 0;
}

Triad::Triad(int f, int s, int t) {
    first = f;
    second = s;
    third = t;
}

Triad::Triad(const Triad &triad) {
    first = triad.first;
    second = triad.second;
    third = triad.third;
}

Triad::~Triad() = default;

// Setters
void Triad::setFirst(int f) { first = f; }

void Triad::setSecond(int s) { second = s; }

void Triad::setThird(int t) { third = t; }

// Getters
int Triad::getFirst() const { return first; }

int Triad::getSecond() const { return second; }

int Triad::getThird() const { return third; }

Triad &Triad::operator=(const Triad &t) {
    if (&t == this) return *this;
    first = t.first;
    second = t.second;
    third = t.third;
    return *this;
}

bool Triad::operator<(const Triad &t) const {
    return this->first == t.first ? this->second == t.second ? this->third < t.third :
                                    this->second < t.second :
           this->first < t.first;
}

bool Triad::operator==(const Triad &t) const {
    return this->first == t.first
           && this->second == t.second
           && this->third == t.third;
}

istream &operator>>(istream &in, Triad &c) {
    cout << "FIRST: ";
    in >> c.first;
    cout << "SECOND: ";
    in >> c.second;
    cout << "THIRD: ";
    in >> c.third;
    return in;
}

ostream &operator<<(ostream &out, Triad &c) {
    out << "\nFIRST : " << c.first;
    out << "\nSECOND : " << c.second;
    out << "\nTHIRD : " << c.third;
    out << "\n";
    return out;
}

