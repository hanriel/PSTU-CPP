#pragma once

#include <iostream>

using namespace std;

template<class T>
class Array;

template<class T>
ostream &operator<<(ostream &out, const Array<T> &a);

template<class T>
istream &operator>>(istream &in, Array<T> &a);

// Множество
template<class T>
class Array {
public:
    Array(int s, T k);

    Array(const Array<T> &a);

    ~Array();

    Array &operator=(const Array<T> &a);     //оператор присваивания
    T &operator[](int index); //операция доступа по индексу
    Array operator+(T k);

    int operator()(); //операция, возвращающая длину множества
    friend ostream &operator
    <<<>(
    ostream &out,
    const Array<T> &a
    );

    friend istream &operator>><>(istream &in, Array<T> &a);

private:
    int size;//размер множества
    T *data;//укзатель на динамический массив значений множества
};

template<class T>
Array<T>::Array(int s, T k) {
    size = s;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
}

template<class T>
Array<T>::Array(const Array<T> &a) {
    size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

template<class T>
Array<T>::~Array() {
    delete[]data;
    data = 0;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &a) {
    if (this == &a)return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    return *this;
}

template<class T>
T &Array<T>::operator[](int index) {
    if (index < size) return data[index];
    else cout << "\nError! Index>size";
}

template<class T>
int Array<T>::operator()() {
    return size;
}

template<class T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

template<class T>
istream &operator>>(istream &in, Array<T> &a) {
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}

template<class T>
Array<T> Array<T>::operator+(const T k) {
    Array<T> temp(size, k);
    for (int i = 0; i < size; ++i)
        temp.data[i] = data[i] + k;
    return temp;
}