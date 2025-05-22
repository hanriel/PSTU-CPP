#include "Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    try {
        // Создаем вектор из 5 элементов Money
        cout << "Enter 5 money values (format 'rub kop' for each):" << endl;
        Vector<Money> vec(5);
        
        cout << "\nOriginal vector: ";
        vec.Print();

        // Задание 3: Найти максимальный элемент и добавить его в конец
        vec.AddMaxToEnd();
        cout << "\nAfter adding max to end: ";
        vec.Print();

        // Задание 4: Найти и удалить элемент
        Money key;
        cout << "\nEnter money value to remove (format 'rub kop'): ";
        cin >> key;
        if (vec.Remove(key)) {
            cout << "Element removed. New vector: ";
            vec.Print();
        } else {
            cout << "Element not found." << endl;
        }

        // Задание 5: Добавить среднее к каждому элементу
        vec.AddAverageToElements();
        cout << "\nAfter adding average to elements: ";
        vec.Print();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}