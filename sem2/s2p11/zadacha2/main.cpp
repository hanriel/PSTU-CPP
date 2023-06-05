// Задача 2
// Тип элементов Money (см. лабораторную работу №3).
// Задание 3
// Найти максимальный элемент и добавить его в конец контейнера
// Задание 4
// Найти элемент с заданным ключом и удалить его из контейнера
// Задание 5
// К каждому элементу добавить среднее арифметическое элементов контейнера
/// \return

#include <iostream>
#include <queue>
#include <cstdlib>
#include "Money.h"

using namespace std;

typedef queue<Money> Que;

Que make_queue(int n) {
    Que v; //пустая очередь
    for (int i = 0; i < n; i++) {
        Money a(rand() % 100 - 50, rand() % 100 - 50);
        v.push(a); //добавляем а в конец очереди
    }
    return v; //возвращаем очередь как результат работы функции
}

//функция для печати очереди
void print_queue(Que &v) {
    Que tmp = v;
    while (!tmp.empty()) {
        std::cout << tmp.front() << " ";
        tmp.pop();
    }
    std::cout << std::endl;
}

//Функция для нахождения максимального элемента контейнера и добавления его в конец контейнера
Money max_element(Que &v) {
    Que tmp = v;
    Money max = tmp.front();
    while (!tmp.empty()) {
        if (tmp.front() > max) {
            max = tmp.front();
        }
        tmp.pop();
    }
    return max;
}

//Функция для нахождения элемента с заданным ключом и удаления его из контейнера
void find_element(Que &v, Money key) {
    Que tmp = v;
    while (!tmp.empty()) {
        if (tmp.front() == key) {
            tmp.pop();
        }
        tmp.pop();
    }
}

//Функция для нахождения среднего арифметического контейнера
Money get_average(Que &v) {
    Que tmp = v;
    Money sum;
    while (!tmp.empty()) {
        sum.setRub(sum.getRub() + tmp.front().getRub());
        sum.setCheers(sum.getCheers() + tmp.front().getCheers());
        tmp.pop();
    }
    return sum / v.size();
}

// Добавить среднее арифметическое к каждому элементу контейнера
int add_average(Que &v) {
    Que tmp;
    Money avg = get_average(v);
    while (!v.empty()) {
        tmp.push(v.front() + avg);
        v.pop();
    }
    v = tmp;
    return 0;
}

int main() {
    try {
        queue<Money> v;//вектор
        auto vi = v.front(); //итератор
        int n;
        cout << "N?";
        cin >> n;
        v = make_queue(n); //формирование вектора
        cout << "Вектор: ";
        print_queue(v);//печать вектора

        cout << "Max: " << max_element(v) << endl;
        cout << "Average: " << get_average(v) << endl;
        add_average(v);
        cout << "Вектор: ";
        print_queue(v);//печать вектора
    }
    catch (int) {
        cout << "Error!";
    }

    return 0;
}