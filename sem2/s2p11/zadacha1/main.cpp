/// Задача 1
// 1. Контейнер - двунапрвленная очередь
// 2. Тип элементов - int
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
    Que v; //пустая очередь
    for (int i = 0; i < n; i++) {
        int a = rand() % 100 - 50;
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
int max_element(Que &v) {
    Que tmp = v;
    int max = tmp.front();
    while (!tmp.empty()) {
        if (tmp.front() > max) {
            max = tmp.front();
        }
        tmp.pop();
    }
    return max;
}

//Функция для нахождения элемента с заданным ключом и удаления его из контейнера
int find_element(Que &v, int key) {
    Que tmp = v;
    while (!tmp.empty()) {
        if (tmp.front() == key) {
            tmp.pop();
            return key;
        }
        tmp.pop();
    }
    return -1;
}

//Функция для нахождения среднего арифметического контейнера
int get_average(Que &v) {
    Que tmp = v;
    int sum = 0;
    while (!tmp.empty()) {
        sum += tmp.front();
        tmp.pop();
    }
    return sum / v.size();
}

// Добавить среднее арифметическое к каждому элементу контейнера
int add_average(Que &v) {
    Que tmp;
    int avg = get_average(v);
    while (!v.empty()) {
        tmp.push(v.front() + avg);
        v.pop();
    }
    v = tmp;
    return 0;
}

int main() {
    try {
        queue<int> v;//вектор
        auto vi = v.front(); //итератор
        int n;
        cout << "N?";
        cin >> n;
        v = make_queue(n);//формирование вектора
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