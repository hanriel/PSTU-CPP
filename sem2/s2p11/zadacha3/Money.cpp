#include "Money.h"
#include <iomanip>

Money::Money() {
    rub = 0;
    cheers = 0;
}

Money::Money(long r, int c) {
    rub = (r * 100 + c) / 100;
    cheers = c;
    cheers = (r * 100 + c) % 100;
}

Money::Money(const Money &m) {
    rub = m.rub;
    cheers = m.cheers;
}

Money::~Money() = default;

long Money::getRub() const { return rub; }

int Money::getCheers() const { return cheers; }

void Money::setRub(long r) { rub = r; }

void Money::setCheers(int c) { cheers = c; }

// перегрузка операции присваивания
Money &Money::operator=(const Money &m) {
    if (&m == this) return *this;
    rub = m.rub;
    cheers = m.cheers;
    return *this;
}

// перегрузка глобальной функции-операции ввода
istream &operator>>(istream &in, Money &m) {
    cout << "rub?";
    in >> m.rub;
    cout << "cheers?";
    in >> m.cheers;
    return in;
}

// перегрузка глобальной функции-операции вывода
ostream &operator<<(ostream &out, const Money &m) {
    return (out << m.rub << "," << setfill('0') << setw(2) << m.cheers) << "rub";
}

Money Money::operator+(const Money &money) const {
    Money obj(rub + money.rub, cheers + money.cheers);
    return obj;
}

Money Money::operator-(const Money &money) const {
    Money obj(rub - money.rub, cheers - money.cheers);
    return obj;
}

Money Money::operator/(const Money &money) const {
    Money obj(rub / money.rub, cheers / money.cheers);
    return obj;
}

Money Money::operator/(const int &num) const {
    Money obj(rub / num, cheers / num);
    return obj;
}

bool Money::operator>(const Money &money) const {
    if (rub > money.rub) return true;
    if (rub == money.rub && cheers > money.cheers) return true;
    return false;
}

bool Money::operator<(const Money &money) const {
    if (rub < money.rub) return true;
    if (rub == money.rub && cheers < money.cheers) return true;
    return false;
}

bool Money::operator==(const Money &other) const {
    return (this->rub == other.rub && this->cheers == other.cheers);
}

bool Money::operator!=(const Money &other) const {
    return !(*this == other);
}
