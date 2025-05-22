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
#include <stdexcept>

using namespace std;

typedef queue<int> Que;

// Создание очереди со случайными элементами
Que make_queue(int n) {
    if (n <= 0) {
        throw invalid_argument("Queue size must be positive");
    }
    
    Que v;
    for (int i = 0; i < n; i++) {
        int a = rand() % 100 - 50; // числа от -50 до 49
        v.push(a);
    }
    return v;
}

// Печать очереди без ее изменения
void print_queue(const Que &v) {
    Que tmp = v;
    while (!tmp.empty()) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

// Нахождение максимального элемента
int max_element(const Que &v) {
    if (v.empty()) {
        throw runtime_error("Queue is empty");
    }
    
    Que tmp = v;
    int max_val = tmp.front();
    tmp.pop();
    
    while (!tmp.empty()) {
        if (tmp.front() > max_val) {
            max_val = tmp.front();
        }
        tmp.pop();
    }
    return max_val;
}

// Удаление первого вхождения элемента
bool remove_first_occurrence(Que &v, int key) {
    Que tmp;
    bool found = false;
    
    while (!v.empty()) {
        int current = v.front();
        v.pop();
        
        if (!found && current == key) {
            found = true; // пропускаем первый найденный элемент
        } else {
            tmp.push(current); // сохраняем остальные элементы
        }
    }
    
    v = tmp; // восстанавливаем очередь
    return found;
}

// Вычисление среднего арифметического (с плавающей точкой)
double get_average(const Que &v) {
    if (v.empty()) {
        throw runtime_error("Queue is empty");
    }
    
    Que tmp = v;
    double sum = 0;
    int count = 0;
    
    while (!tmp.empty()) {
        sum += tmp.front();
        count++;
        tmp.pop();
    }
    
    return sum / count;
}

// Добавление среднего к каждому элементу
void add_average(Que &v) {
    if (v.empty()) return;
    
    double avg = get_average(v);
    Que tmp;
    
    while (!v.empty()) {
        tmp.push(v.front() + static_cast<int>(avg));
        v.pop();
    }
    
    v = tmp;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    try {
        int n;
        cout << "Введите размер очереди N: ";
        cin >> n;
        
        Que v = make_queue(n);
        cout << "Очередь: ";
        print_queue(v);

        cout << "Максимальный элемент: " << max_element(v) << endl;
        cout << "Среднее арифметическое: " << get_average(v) << endl;

        int key;
        cout << "Введите элемент для удаления: ";
        cin >> key;
        if (remove_first_occurrence(v, key)) {
            cout << "Элемент " << key << " удален. Новая очередь: ";
            print_queue(v);
        } else {
            cout << "Элемент " << key << " не найден." << endl;
        }

        add_average(v);
        cout << "Очередь после добавления среднего: ";
        print_queue(v);
    }
    catch (const exception &e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}