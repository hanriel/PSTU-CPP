#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

template<class T>
class Container {
    map<int, T> v;
    int len;
public:
    Container(void);
    Container(int n);
    void Print();
    ~Container(void);

    // Новые методы для выполнения задания
    T Max() const;
    void AddMaxToEnd();
    void RemoveByKey(int key);
    T Average() const;
    void AddAverageToElements();
};

template <class T>
Container<T>::Container() {
    len = 0;
}

template <class T>
Container<T>::~Container(void) {}

template <class T>
Container<T>::Container(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[i] = a;
    }
    len = v.size();
}

template <class T>
void Container<T>::Print() {
    for (const auto& pair : v) {
        cout << pair.first << " - " << pair.second << endl;
    }
    cout << endl;
}

// Нахождение максимального элемента
template <class T>
T Container<T>::Max() const {
    if (v.empty()) throw runtime_error("Container is empty");

    auto max_it = max_element(v.begin(), v.end(),
        [](const pair<int, T>& a, const pair<int, T>& b) {
            return a.second < b.second;
        });

    return max_it->second;
}

// Добавление максимального элемента в конец
template <class T>
void Container<T>::AddMaxToEnd() {
    if (v.empty()) return;

    T max_val = Max();
    int new_key = v.rbegin()->first + 1;
    v[new_key] = max_val;
    len++;
}

// Удаление элемента по ключу
template <class T>
void Container<T>::RemoveByKey(int key) {
    auto it = v.find(key);
    if (it != v.end()) {
        v.erase(it);
        len--;
    }
}

// Вычисление среднего арифметического
template <class T>
T Container<T>::Average() const {
    if (v.empty()) throw runtime_error("Container is empty");

    T sum;
    for (const auto& pair : v) {
        sum = sum + pair.second;
    }

    return sum / len;
}

// Добавление среднего к каждому элементу
template <class T>
void Container<T>::AddAverageToElements() {
    if (v.empty()) return;

    T avg = Average();
    for (auto& pair : v) {
        pair.second = pair.second + avg;
    }
}