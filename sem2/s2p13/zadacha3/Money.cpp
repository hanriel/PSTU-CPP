#include "Money.h"
#include <iomanip>
#include <stdexcept>

Money::Money() : rub(0), cheers(0) {}

Money::Money(long r, int c) : rub(r), cheers(c) {
    // Нормализация копеек
    if (cheers >= 100 || cheers < 0) {
        rub += cheers / 100;
        cheers %= 100;
    }
    if (cheers < 0) {
        rub--;
        cheers += 100;
    }
}

Money::Money(const Money &m) : rub(m.rub), cheers(m.cheers) {}

Money::~Money() {}

long Money::getRub() { return rub; }
int Money::getCheers() { return cheers; }

void Money::setRub(long r) { rub = r; }
void Money::setCheers(int c) { 
    cheers = c;
    // Нормализация при установке
    if (cheers >= 100 || cheers < 0) {
        rub += cheers / 100;
        cheers %= 100;
    }
    if (cheers < 0) {
        rub--;
        cheers += 100;
    }
}

Money &Money::operator=(const Money &m) {
    if (&m == this) return *this;
    rub = m.rub;
    cheers = m.cheers;
    return *this;
}

bool Money::operator==(const Money& other) const {
    return rub == other.rub && cheers == other.cheers;
}

bool Money::operator!=(const Money &other) {
    return !(*this == other);
}

Money operator-(const Money &lhs, const Money &rhs) {
    long totalRub = lhs.rub - rhs.rub;
    int totalCheers = lhs.cheers - rhs.cheers;
    return Money(totalRub, totalCheers);
}

istream &operator>>(istream &in, Money &m) {
    cout << "rub? ";
    in >> m.rub;
    cout << "cheers? ";
    in >> m.cheers;
    
    // Нормализация при вводе
    if (m.cheers >= 100 || m.cheers < 0) {
        m.rub += m.cheers / 100;
        m.cheers %= 100;
    }
    if (m.cheers < 0) {
        m.rub--;
        m.cheers += 100;
    }
    
    return in;
}

ostream &operator<<(ostream &out, const Money &m) {
    return out << m.rub << "," << setfill('0') << setw(2) << m.cheers << "rub";
}

Money Money::operator+(const Money& money) const {
    long totalRub = rub + money.rub;
    int totalCheers = cheers + money.cheers;
    return Money(totalRub, totalCheers);
}

Money Money::operator/(int num) const {
    if (num == 0) throw runtime_error("Division by zero");
    long totalKop = rub * 100 + cheers;
    totalKop /= num;
    return Money(totalKop / 100, totalKop % 100);
}

bool Money::operator<(const Money& money) const {
    if (rub != money.rub) return rub < money.rub;
    return cheers < money.cheers;
}