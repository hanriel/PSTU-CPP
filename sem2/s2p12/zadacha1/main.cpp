///
// ### Задача 1.
// 1. Создать ассоциативный контейнер - set
// 2. Заполнить его элементами стандартного типа (int).
// 3. Найти максимальный элемент и добавить его в конец контейнера.
// 4. Найти элемент с заданным ключом и удалить его из контейнера.
// 5. К каждому элементу добавить среднее арифметическое элементов контейнера.
// 6. Выполнение всех заданий оформить в виде глобальных функций.
///

#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

typedef set<int> TSet;

// Функция для заполнения множества
TSet make_set(int n) {
    TSet s;
    int a;
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> a;
        s.insert(a);
    }
    return s;
}

// Функция для печати множества
void print_set(const TSet& s) {
    cout << "Set contents: ";
    for(const auto& item : s) {
        cout << item << " ";
    }
    cout << endl;
}

// Функция для нахождения максимального элемента
int find_max(const TSet& s) {
    if(s.empty()) throw runtime_error("Set is empty");
    return *s.rbegin(); // последний элемент в set - максимальный
}

// Функция для добавления максимального элемента в конец
void add_max_to_end(TSet& s) {
    if(s.empty()) return;
    s.insert(find_max(s));
}

// Функция для удаления элемента по ключу
bool remove_by_key(TSet& s, int key) {
    return s.erase(key) > 0;
}

// Функция для вычисления среднего арифметического
double calculate_average(const TSet& s) {
    if(s.empty()) throw runtime_error("Set is empty");
    double sum = accumulate(s.begin(), s.end(), 0.0);
    return sum / s.size();
}

// Функция для добавления среднего к каждому элементу
void add_average_to_elements(TSet& s) {
    if(s.empty()) return;
    
    double avg = calculate_average(s);
    TSet new_set;
    
    for(const auto& item : s) {
        new_set.insert(item + avg);
    }
    
    s = new_set;
}

int main() {
    try {
        int n;
        cout << "Enter set size: ";
        cin >> n;
        
        // 1. Создание и заполнение множества
        TSet my_set = make_set(n);
        cout << "\nOriginal set:\n";
        print_set(my_set);
        
        // 2. Добавление максимального элемента в конец
        add_max_to_end(my_set);
        cout << "\nAfter adding max to end:\n";
        print_set(my_set);
        
        // 3. Удаление элемента по ключу
        int key;
        cout << "\nEnter element to remove: ";
        cin >> key;
        if(remove_by_key(my_set, key)) {
            cout << "Element removed. New set:\n";
            print_set(my_set);
        } else {
            cout << "Element not found.\n";
        }
        
        // 4. Добавление среднего к каждому элементу
        add_average_to_elements(my_set);
        cout << "\nAfter adding average to elements:\n";
        print_set(my_set);
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}