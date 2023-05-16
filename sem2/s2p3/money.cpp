#include "money.h"
#include <iomanip>

Money::Money() {
    rub = 0; cheers = 0;
}

Money::Money(long r, int c) {
    rub = (r * 100 + c) / 100; cheers = c;
    cheers = (r * 100 + c) % 100;
}

Money::Money(const Money& m) {
    rub = m.rub; cheers = m.cheers;
}

Money::~Money() {}

long Money::getRub() { return rub; }
int Money::getCheers() { return cheers; }
void Money::setRub(long r) { rub = r;  }
void Money::setCheers(long c) { cheers = c; }

// перегрузка операции присваивания
Money& Money::operator=(const Money &m) {
    if(&m==this) return *this;
    rub = m.rub;
    cheers = m.cheers;
    return *this;
}

// перегрузка операций сравнения
bool operator==(const Money& lhs, const Money& rhs) {
    return lhs.rub == rhs.rub && lhs.cheers == rhs.cheers;
}

bool operator!=(const Money& lhs, const Money& rhs) {
    return !(lhs.rub != rhs.rub || lhs.cheers != rhs.cheers);
}

// перегрузка операции вычитания
Money operator-(const Money& lhs, const Money& rhs) {
    Money obj(lhs.rub - rhs.rub, lhs.cheers - rhs.cheers);
    return obj;
}

// перегрузка глобальной функции-операции ввода
istream& operator>>(istream&in, Money&m) {
    cout<<"rub?"; in>>m.rub;
    cout<<"cheers?"; in>>m.cheers;
    return in;
}
// перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream&out, const Money&m) {
    return (out<<m.rub<<","<< setfill('0') << setw(2) << m.cheers) << "rub";
}