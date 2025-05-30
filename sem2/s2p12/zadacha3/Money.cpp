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

Money::~Money() {}

long Money::getRub() { return rub; }

int Money::getCheers() { return cheers; }

void Money::setRub(long r) { rub = r; }

void Money::setCheers(int c) { cheers = c; }

// перегрузка операции присваивания
Money &Money::operator=(const Money &m) {
    if (&m == this) return *this;
    rub = m.rub;
    cheers = m.cheers;
    return *this;
}

// перегрузка операций сравнения
bool Money::operator==(const Money& other) const {
    return (this->rub == other.rub && this->cheers == other.cheers);
}

bool Money::operator!=(const Money &other) {
    return !(*this == other);
}

// перегрузка операции вычитания
Money operator-(const Money &lhs, const Money &rhs) {
    Money obj(lhs.rub - rhs.rub, lhs.cheers - rhs.cheers);
    return obj;
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

Money Money::operator+(const Money& money) const {
    long total_rub = rub + money.rub;
    int total_kop = cheers + money.cheers;

    // Корректировка если копеек больше 100
    if (total_kop >= 100) {
        total_rub += total_kop / 100;
        total_kop %= 100;
    }

    return Money(total_rub, total_kop);
}

Money Money::operator/(int num) const {
    if (num == 0) throw runtime_error("Division by zero");

    long total_kop = rub * 100 + cheers;
    total_kop /= num;

    return Money(total_kop / 100, total_kop % 100);
}

bool Money::operator<(const Money& money) const {
    if (rub < money.rub) return true;
    if (rub == money.rub && cheers < money.cheers) return true;
    return false;
}