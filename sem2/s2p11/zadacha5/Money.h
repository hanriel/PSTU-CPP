#pragma once

#include <iostream>

using namespace std;

class Money {
    long rub;
    int cheers;

public:
    Money();

    Money(long, int);

    Money(const Money &);

    ~Money();

    long getRub() const;

    int getCheers() const;

    void setRub(long r);

    void setCheers(int c);

    //перегруженные операции
    Money &operator=(const Money &);

    Money operator+(const Money &) const;

    Money operator-(const Money &) const;

    Money operator/(const Money &) const;

    Money operator/(const int &) const;

    bool operator>(const Money &) const;

    bool operator<(const Money &) const;

    bool operator==(const Money &) const;

    bool operator!=(const Money &) const;

    //глобальные функции ввода-вывода
    friend istream &operator>>(istream &in, Money &m);

    friend ostream &operator<<(ostream &out, const Money &m);
};