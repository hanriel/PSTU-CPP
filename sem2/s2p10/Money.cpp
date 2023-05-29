#include "Money.h"
#include <iomanip>
#include <fstream>

using namespace std;

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

// перегрузка операций сравнения
bool Money::operator==(const Money &other) const {
    return (this->rub == other.rub && this->cheers == other.cheers);
}

bool Money::operator!=(const Money &other) const {
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

//дружественные функции для работы с файловыми потоками
fstream &operator>>(fstream &fin, Money &m) {
    fin >> m.rub;
    fin >> m.cheers;
    return fin;
}

fstream &operator<<(fstream &fout, const Money &m) {
    fout << m.rub << "\n" << m.cheers << "\n";
    return fout;
}