#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

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

    // Перегруженные операции
    Money &operator=(const Money &);
    Money operator+(const Money&) const;
    Money operator/(int) const;
    bool operator<(const Money&) const;
    bool operator==(const Money&) const;
    bool operator!=(const Money&) const;
    friend Money operator-(const Money &lhs, const Money &rhs);

    // Функции ввода-вывода
    friend istream &operator>>(istream &in, Money &m);
    friend ostream &operator<<(ostream &out, const Money &m);
};

// Адаптер стека с дополнительной функциональностью
typedef stack<Money, vector<Money>> MoneyStack;

// Функции для работы со стеком
MoneyStack makeStack(int n);
void printStack(MoneyStack s);
void addMaxToEnd(MoneyStack& s);
bool removeByValue(MoneyStack& s, const Money& key);
Money calculateAverage(MoneyStack s);
void addAverageToElements(MoneyStack& s);