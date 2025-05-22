///
// ### Задача 5
// 1. Создать параметризированный класс, используя в качестве контейнера адаптер
// контейнера.
// 2. Заполнить его элементами.
// 3. Добавить элементы в соответствии с заданием
// 4. Удалить элементы в соответствии с заданием.
// 5. Выполнить задание варианта для полученного контейнера.
// 6. Выполнение всех заданий оформить в виде методов параметризированного
// класса.

// - Параметризированный класс – Вектор
// - Адаптер контейнера - стек.

// Задание 3
// Найти максимальный элемент и добавить его в конец контейнера

// Задание 4 
// Найти элемент с заданным ключом и удалить его из контейнера

// Задание 5
// К каждому элементу добавить среднее арифметическое элементов контейнера
///

#include "Money.h"
#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
    try {
        // 1. Создание вектора
        int size;
        cout << "Enter vector size: ";
        cin >> size;
        
        Vector<Money> vec(size);
        cout << "\nOriginal vector:\n";
        vec.Print();

        // 2. Добавление максимального элемента в конец
        vec.AddMaxToEnd();
        cout << "\nAfter adding max to end:\n";
        vec.Print();

        // 3. Удаление элемента по ключу
        Money key;
        cout << "\nEnter money value to remove (format 'rub kop'): ";
        cin >> key;
        vec.Remove(key);
        cout << "After removing element:\n";
        vec.Print();

        // 4. Добавление среднего к каждому элементу
        vec.AddAverageToElements();
        cout << "\nAfter adding average to elements:\n";
        vec.Print();

        // 5. Добавление нового элемента
        Money newElement;
        cout << "\nEnter new money value to add: ";
        cin >> newElement;
        vec.Add(newElement);
        cout << "After adding new element:\n";
        vec.Print();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}