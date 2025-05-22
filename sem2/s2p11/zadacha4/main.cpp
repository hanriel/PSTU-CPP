///
// ### Задача 4
// 1. Создать адаптер контейнера.
// 2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для
// пользовательского типа перегрузить необходимые операции.
// 3. Добавить элементы в соответствии с заданием
// 4. Удалить элементы в соответствии с заданием.
// 5. Выполнить задание варианта для полученного контейнера.
// 6. Выполнение всех заданий оформить в виде глобальных функций.

// - Адаптер контейнера - стек.

// Задание 3
// Найти максимальный элемент и добавить его в конец контейнера

// Задание 4 
// Найти элемент с заданным ключом и удалить его из контейнера

// Задание 5
// К каждому элементу добавить среднее арифметическое элементов контейнера
///

#include "Money.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef stack<Money> St; // стек
typedef vector<Money> Vec; // вектор

// Функция для создания и заполнения стека
St make_stack(int n) {
    St s;
    Money m;
    for(int i = 0; i < n; i++) {
        cout << "Enter money " << i+1 << " (rub kop): ";
        cin >> m;
        s.push(m);
    }
    return s;
}

// Функция для печати стека
void print_stack(St s) {
    cout << "Stack contents (top to bottom):" << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

// Копирует стек в вектор
Vec copy_stack_to_vector(St s) {
    Vec v;
    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    // Вектор будет в обратном порядке, так как стек LIFO
    reverse(v.begin(), v.end());
    return v;
}

// Копирует вектор в стек
St copy_vector_to_stack(Vec v) {
    St s;
    for(auto it = v.rbegin(); it != v.rend(); ++it) {
        s.push(*it);
    }
    return s;
}

// Находит максимальный элемент в стеке
Money find_max(St s) {
    if(s.empty()) throw runtime_error("Stack is empty");
    
    Money max_val = s.top();
    while(!s.empty()) {
        if(s.top() > max_val) {
            max_val = s.top();
        }
        s.pop();
    }
    return max_val;
}

// Добавляет максимальный элемент в конец стека
void add_max_to_end(St& s) {
    if(s.empty()) return;
    
    Money max_val = find_max(s);
    s.push(max_val);
}

// Удаляет первый найденный элемент с заданным ключом
bool remove_by_key(St& s, const Money& key) {
    Vec v = copy_stack_to_vector(s);
    auto it = find(v.begin(), v.end(), key);
    
    if(it != v.end()) {
        v.erase(it);
        s = copy_vector_to_stack(v);
        return true;
    }
    return false;
}

// Вычисляет среднее арифметическое элементов стека
Money calculate_average(St s) {
    if(s.empty()) throw runtime_error("Stack is empty");
    
    Vec v = copy_stack_to_vector(s);
    Money sum = accumulate(v.begin(), v.end(), Money());
    return sum / v.size();
}

// Добавляет среднее арифметическое к каждому элементу
void add_average_to_elements(St& s) {
    if(s.empty()) return;
    
    Money avg = calculate_average(s);
    Vec v = copy_stack_to_vector(s);
    
    for(auto& m : v) {
        m = m + avg;
    }
    
    s = copy_vector_to_stack(v);
}

int main() {
    try {
        Money t;
        St s;
        int n;
        
        // 1. Создание и заполнение стека
        cout << "Enter stack size: ";
        cin >> n;
        s = make_stack(n);
        
        cout << "\nOriginal stack:" << endl;
        print_stack(s);
        
        // 2. Добавление максимального элемента в конец
        add_max_to_end(s);
        cout << "After adding max to end:" << endl;
        print_stack(s);
        
        // 3. Удаление элемента по ключу
        Money key;
        cout << "Enter money value to remove (rub kop): ";
        cin >> key;
        if(remove_by_key(s, key)) {
            cout << "Element removed. New stack:" << endl;
            print_stack(s);
        } else {
            cout << "Element not found." << endl;
        }
        
        // 4. Добавление среднего к каждому элементу
        add_average_to_elements(s);
        cout << "After adding average to elements:" << endl;
        print_stack(s);
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}