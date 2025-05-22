///
//### Задача 3
//1. Создать параметризированный класс Вектор, используя в качестве контейнера ассоциативный контейнер.
//2. Заполнить его элементами.
//3. Найти максимальный элемент и добавить его в конец контейнера.
//4. Найти элемент с заданным ключом и удалить его из контейнера.
//5. К каждому элементу добавить среднее арифметическое элементов контейнера.
//6. Выполнение всех заданий оформить в виде методов параметризированного класса.
///

#include "Money.h"
#include "Container.h"
#include <iostream>
using namespace std;

int main() {
    try {
        int n;
        cout << "Enter container size: ";
        cin >> n;

        // 1. Создание и заполнение контейнера
        Container<Money> v(n);
        cout << "\nOriginal container:" << endl;
        v.Print();

        // 2. Добавление максимального элемента в конец
        v.AddMaxToEnd();
        cout << "After adding max to end:" << endl;
        v.Print();

        // 3. Удаление элемента по ключу
        int key;
        cout << "Enter key to remove: ";
        cin >> key;
        v.RemoveByKey(key);
        cout << "After removing element with key " << key << ":" << endl;
        v.Print();

        // 4. Добавление среднего к каждому элементу
        v.AddAverageToElements();
        cout << "After adding average to elements:" << endl;
        v.Print();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
