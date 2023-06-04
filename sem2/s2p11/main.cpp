/// Задача 1
// 1. Контейнер - двунапрвленная очередь
// 2. Тип элементов - int
// Задача 2
// Тип элементов Money (см. лабораторную работу №3).
// Задача 3
// Параметризированный класс – Вектор (см. лабораторную работу №7)
// Задача 4
// Адаптер контейнера - стек.
// Задача 5
// Параметризированный класс – Вектор
// Адаптер контейнера - стек.
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

using namespace std;

typedef queue<int> Que;

Que make_queue(int n) {
    Que v;//пустая очередь
    for (int i = 0; i < n; i++) {
        int a = rand() % 100 - 50;
        v.push(a);//добавляем а в конец очереди
    }
    return v;//возвращаем очередь как результат работы функции
}

//функция для печати очереди
void print_queue(Que &v) {
    while (!v.empty()) {
        std::cout << v.front() << " ";
        v.pop();
    }
    std::cout << std::endl;
}

//Функция для нахождения максимального элемента контейнера и добавления его в конец контейнера
int max_element(Que &v) {
    int max = v.front();
    while (!v.empty()) {
        if (v.front() > max) {
            max = v.front();
        }
        v.pop();
    }
    v.push(max);
    return max;
}

//Функция для нахождения элемента с заданным ключом и удаления его из контейнера
int find_element(Que &v, int key) {
    while (!v.empty()) {
        if (v.front() == key) {
            v.pop();
            return key;
        }
        v.pop();
    }
    return -1;
}

//Функция для добалвления к каждому элементу в контейнере среднего арифметического контейнера
int add_average(Que &v) {
    int sum = 0;
    while (!v.empty()) {
        sum += v.front();
        v.pop();
    }
    return sum / v.size();
}

int main() {
    try {
        queue<int> v;//вектор
        auto vi = v.front(); //итератор
        int n;
        cout << "N?";
        cin >> n;
        v = make_queue(n);//формирование вектора
        print_queue(v);//печать вектора

        max_element(v);//печать максимальный элемент
        print_queue(v);//печать вектора
    }
    catch (int) {
        cout << "Error!";
    }

    return 0;
}