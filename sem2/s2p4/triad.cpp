#include "triad.h"
using namespace std;

// Constructors and destructor
Triad::Triad(void) { first = 0; second = 0; third = 0; }
Triad::Triad(int f, int s, int t) { first = f; second = s; third = t; }
Triad::Triad(const Triad& triad) { first = triad.first; second = triad.second; third = triad.third; }
Triad::~Triad(void) { }

// Setters
void Triad::setFirst(int f) { first = f; }
void Triad::setSecond(int s) { second = s; }
void Triad::setThird(int t) { third = t; }

// Getters
int Triad::getFirst() { return first; }
int Triad::getSecond() { return second; }
int Triad::getThird() { return third; }

Triad &Triad::operator = (const Triad &t) {
    if(&t == this) return *this;
    first = t.first;
    second = t.second;
    third = t.third;
}

istream &operator >> (istream &in, Triad &c) {
    cout << "\nFirst: "; in>>c.first;
    cout << "\nSecond: "; in>>c.second;
    cout << "\nThird: "; in>>c.third;
    return in;
}

ostream &operator << (ostream &out, Triad &c) {
    out << "\nFIRST : " << c.first;
    out << "\nSECOND : " << c.second;
    out << "\nTHIRD : " << c.third;
    out << "\n";
    return out;
}

bool operator < (const Triad &lhs, const Triad &rhs) {
    return lhs.first == rhs.first ? lhs.second == rhs.second ?
            lhs.third < rhs.third :
            lhs.second < rhs.second :
            lhs.first < rhs.first;
}
 
bool operator == (const Triad &lhs, const Triad &rhs) {
    return lhs.first == rhs.first &&
        lhs.second == rhs.second &&
        lhs.third == rhs.third;
}
