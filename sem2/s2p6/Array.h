#pragma once
#include <iostream>

using namespace std;

class Array {
public:
    explicit Array(int s, int k=0);
    Array(const Array &a);
    ~Array();
    //оператор присваивания
    Array&operator=(const Array&a);
    //операция доступа по индексу
    int&operator[](int index);
    //операция, возвращающая длину вектора
    int operator()();
    //перегруженные операции ввода-вывода
    friend ostream& operator<<(ostream& out, const Array&a);
    friend istream& operator>>(istream& in, Array&a);
private:
    int size;//размер вектора
    int *data;//укзатель на динамический массив значений вектора
};