#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

template<class T>
class Vector {
    vector<T> data;
public:
    Vector() = default;
    Vector(int n);
    
    void Print() const;
    void Add(const T& element);
    void Remove(const T& key);
    T Max() const;
    void AddMaxToEnd();
    T Average() const;
    void AddAverageToElements();
};

template<class T>
Vector<T>::Vector(int n) {
    for (int i = 0; i < n; i++) {
        T element;
        cout << "Enter element " << i+1 << ": ";
        cin >> element;
        data.push_back(element);
    }
}

template<class T>
void Vector<T>::Print() const {
    cout << "Vector contents: ";
    for (const auto& item : data) {
        cout << item << " ";
    }
    cout << endl;
}

template<class T>
void Vector<T>::Add(const T& element) {
    data.push_back(element);
}

template<class T>
void Vector<T>::Remove(const T& key) {
    auto it = find(data.begin(), data.end(), key);
    if (it != data.end()) {
        data.erase(it);
    }
}

template<class T>
T Vector<T>::Max() const {
    if (data.empty()) throw runtime_error("Vector is empty");
    return *max_element(data.begin(), data.end());
}

template<class T>
void Vector<T>::AddMaxToEnd() {
    if (!data.empty()) {
        data.push_back(Max());
    }
}

template<class T>
T Vector<T>::Average() const {
    if (data.empty()) throw runtime_error("Vector is empty");
    T sum = accumulate(data.begin(), data.end(), T());
    return sum / data.size();
}

template<class T>
void Vector<T>::AddAverageToElements() {
    if (data.empty()) return;
    T avg = Average();
    for (auto& item : data) {
        item = item + avg;
    }
}