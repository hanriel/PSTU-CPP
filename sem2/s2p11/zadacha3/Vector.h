#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class Vector {
    vector<T> v;
    int len;
public:
    Vector();
    Vector(int n);
    void Print();
    ~Vector();

    T Max(); // Найти максимальный элемент
    void AddMaxToEnd(); // Добавить максимальный элемент в конец
    bool Remove(const T& key); // Удалить элемент по ключу
    T Average(); // Вычислить среднее арифметическое
    void AddAverageToElements(); // Добавить среднее к каждому элементу
    void Add(const T& el, int pos); // Добавить элемент на позицию
};

template<class T>
Vector<T>::Vector() : len(0) {}

template<class T>
Vector<T>::~Vector() {}

template<class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    len = v.size();
}

template<class T>
void Vector<T>::Print() {
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;
}

template<class T>
T Vector<T>::Max() {
    if (v.empty()) throw runtime_error("Vector is empty");
    return *max_element(v.begin(), v.end());
}

template<class T>
void Vector<T>::AddMaxToEnd() {
    v.push_back(Max());
    len++;
}

template<class T>
bool Vector<T>::Remove(const T& key) {
    auto it = find(v.begin(), v.end(), key);
    if (it != v.end()) {
        v.erase(it);
        len--;
        return true;
    }
    return false;
}

template<class T>
T Vector<T>::Average() {
    if (v.empty()) throw runtime_error("Vector is empty");
    T sum;
    for (const auto& item : v) {
        sum = sum + item;
    }
    return sum / len;
}

template<class T>
void Vector<T>::AddAverageToElements() {
    T avg = Average();
    for (auto& item : v) {
        item = item + avg;
    }
}

template<class T>
void Vector<T>::Add(const T& el, int pos) {
    if (pos < 0 || pos > len) throw out_of_range("Invalid position");
    v.insert(v.begin() + pos, el);
    len++;
}