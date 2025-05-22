///
// ### Задача 2.
// 1. Создать ассоциативный контейнер.
// 2. Заполнить его элементами пользовательского типа (Money). Для пользовательского типа перегрузить необходимые операции.
// 3. Найти максимальный элемент и добавить его в конец контейнера.
// 4. Найти элемент с заданным ключом и удалить его из контейнера.
// 5. К каждому элементу добавить среднее арифметическое элементов контейнера.
// 6. Выполнение всех заданий оформить в виде глобальных функций.
///


#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include "Money.h"

using namespace std;

typedef map<int, Money> TMap;
typedef TMap::iterator it;

// Функция для заполнения map
TMap make_map(int n) {
    TMap m;
    Money a;
    for (int i = 0; i < n; i++) {
        cout << "Enter money " << i + 1 << " (rub kop): ";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

// Функция для печати map
void print_map(const TMap& m) {
    cout << "Map contents:" << endl;
    for (const auto& pair : m) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

// Функция для нахождения максимального элемента
Money find_max(const TMap& m) {
    if (m.empty()) throw runtime_error("Map is empty");

    auto max_it = max_element(m.begin(), m.end(),
        [](const pair<int, Money>& a, const pair<int, Money>& b) {
            return a.second < b.second;
        });

    return max_it->second;
}

// Функция для добавления максимального элемента в конец
void add_max_to_end(TMap& m) {
    if (m.empty()) return;

    Money max_val = find_max(m);
    int new_key = m.rbegin()->first + 1; // следующий ключ
    m.insert(make_pair(new_key, max_val));
}

// Функция для удаления элемента по значению Money
bool remove_by_value(TMap& m, const Money& key) {
    auto it = find_if(m.begin(), m.end(),
        [&key](const auto& item) {
            return item.second == key;
        });

    if (it != m.end()) {
        m.erase(it);
        return true;
    }
    return false;
}

// Функция для вычисления среднего арифметического
Money calculate_average(const TMap& m) {
    if (m.empty()) throw runtime_error("Map is empty");

    Money sum;
    for (const auto& pair : m) {
        sum = sum + pair.second;
    }

    return sum / m.size();
}

// Функция для добавления среднего к каждому элементу
void add_average_to_elements(TMap& m) {
    if (m.empty()) return;

    Money avg = calculate_average(m);
    for (auto& pair : m) {
        pair.second = pair.second + avg;
    }
}

int main() {
    try {
        int n;
        cout << "Enter map size: ";
        cin >> n;

        // 1. Создание и заполнение map
        TMap money_map = make_map(n);
        cout << "\nOriginal map:" << endl;
        print_map(money_map);

        // 2. Добавление максимального элемента в конец
        add_max_to_end(money_map);
        cout << "\nAfter adding max to end:" << endl;
        print_map(money_map);

        // 3. Удаление элемента по значению
        Money key;
        cout << "\nEnter money value to remove (rub kop): ";
        cin >> key;
        if (remove_by_value(money_map, key)) {
            cout << "Element removed. New map:" << endl;
            print_map(money_map);
        }
        else {
            cout << "Element not found." << endl;
        }

        // 4. Добавление среднего к каждому элементу
        add_average_to_elements(money_map);
        cout << "\nAfter adding average to elements:" << endl;
        print_map(money_map);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}