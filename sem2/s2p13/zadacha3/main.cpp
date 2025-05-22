///
// ### Задача 3
// 1. Создать ассоциативный контейнер - множество.
// 2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
// 3. Найти максимальный элемент и добавить его в конец контейнера (использовать алгоритмы replace_if(), replace_copy(), replace_copy_if(), fill()).
// 4. Найти элемент с заданным ключом и удалить его из контейнера (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
// 5. К каждому элементу добавить среднее арифметическое элементов контейнера.
// 6. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы find(), find_if(), count(), count_if()).
// 7. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()) .
// 8. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.
///

#include "Money.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main() {
    try {
        // 1. Создание множества
        set<Money> moneySet;
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        
        for (int i = 0; i < n; ++i) {
            Money m;
            cin >> m;
            moneySet.insert(m);
        }
        
        // Вывод исходного множества
        cout << "\nOriginal set:" << endl;
        for_each(moneySet.begin(), moneySet.end(), [](const Money& m) {
            cout << m << endl;
        });
        
        // 2. Нахождение максимального элемента и добавление его в конец
        if (!moneySet.empty()) {
            auto maxIt = max_element(moneySet.begin(), moneySet.end());
            Money maxMoney = *maxIt;
            
            // Для множества нужно удалить и вставить снова, так как порядок фиксирован
            moneySet.erase(maxIt);
            moneySet.insert(maxMoney);
            
            cout << "\nAfter adding max to end:" << endl;
            for_each(moneySet.begin(), moneySet.end(), [](const Money& m) {
                cout << m << endl;
            });
        }
        
        // 3. Удаление элемента по ключу
        Money key;
        cout << "\nEnter money value to remove: ";
        cin >> key;
        
        size_t removed = moneySet.erase(key);
        if (removed > 0) {
            cout << "Element removed. New set:" << endl;
            for_each(moneySet.begin(), moneySet.end(), [](const Money& m) {
                cout << m << endl;
            });
        } else {
            cout << "Element not found!" << endl;
        }
        
        // 4. Добавление среднего арифметического к каждому элементу
        if (!moneySet.empty()) {
            // Вычисление среднего
            Money sum = accumulate(moneySet.begin(), moneySet.end(), Money());
            Money avg = sum / moneySet.size();
            
            // Создаем новое множество с измененными значениями
            set<Money> newSet;
            transform(moneySet.begin(), moneySet.end(), 
                     inserter(newSet, newSet.begin()),
                     [avg](const Money& m) { return m + avg; });
            
            moneySet = newSet;
            
            cout << "\nAfter adding average to elements:" << endl;
            for_each(moneySet.begin(), moneySet.end(), [](const Money& m) {
                cout << m << endl;
            });
        }
        
        // 5. Поиск элемента
        cout << "\nEnter money value to search: ";
        cin >> key;
        auto found = moneySet.find(key);
        if (found != moneySet.end()) {
            cout << "Element found: " << *found << endl;
        } else {
            cout << "Element not found!" << endl;
        }
        
        // 6. Подсчет элементов с заданным значением
        cout << "\nEnter money value to count: ";
        cin >> key;
        size_t cnt = moneySet.count(key);
        cout << "Found " << cnt << " elements" << endl;
        
        // 7. Дополнительная операция: умножение каждого элемента на 2
        cout << "\nAfter multiplying each element by 2:" << endl;
        set<Money> doubledSet;
        transform(moneySet.begin(), moneySet.end(),
                 inserter(doubledSet, doubledSet.begin()),
                 [](const Money& m) { return m + m; }); // m + m = 2*m
                 
        for_each(doubledSet.begin(), doubledSet.end(), [](const Money& m) {
            cout << m << endl;
        });
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
