#pragma once

#include <vector>
#include <iostream>

using namespace std;

//шаблон класса
template<class T>
class Vector {
    vector<T> v;//последовательный контейнер для хранения элементов вектора
    int len;
public:
    Vector(void);//конструктор без параметра
    Vector(int n);//конструктор с параметром
    void Print();//печать
    ~Vector(void);//деструктор

    T Average();//вычисление среднего арифметического
    void Add(T el, int pos);//добавление элемента el на позицию pos
};

//конструктор без параметра
template<class T>
Vector<T>::Vector() {
    len = 0;
}

//деструктор
template<class T>
Vector<T>::~Vector(void) {}

//конструктор с параметром
template<class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    len = v.size();
}

//печать
template<class T>
void Vector<T>::Print() {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

