#include "Array.h"

#include "Array.h"

Array::Array(int s, int k) {
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
    beg.elem = &data[0];
    end.elem = &data[size];
}

//конструктор копирования
Array::Array(const Array &a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
}

//деструктор
Array::~Array() {
    delete[]data;
    data = 0;
}

//операция присваивания
Array &Array::operator=(const Array &a) {
    if (this == &a)return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
    return *this;
}

//операция доступа по индексу
int &Array::operator[](int index) {
    if (index < size) return data[index];
    else cout << "\nError! Index>size";
}

//операция для получения длины множества
int Array::operator()() {
    return size;
}

//операции для ввода-вывода
ostream &operator<<(ostream &out, const Array &a) {
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

istream &operator>>(istream &in, Array &a) {
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}

//операция для добавления константы
Array Array::operator+(const int k)//+k
{
    Array temp(size);
    for (int i=0;i<size;++i)
        temp.data[i]+=data[i]+k;
    return temp;
}
