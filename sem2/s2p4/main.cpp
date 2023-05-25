/*
Базовый класс:
    ТРОЙКА_ЧИСЕЛ (TRIAD)
    Первое_число (first) - int
    Второе_число (second) – int
    Третье_число (third) - int
Определить методы изменения полей и сравнения триады.
Создать производный класс TIME с полями часы, минуты и секунды. Определить
полный набор операций сравнения временных промежутков.
*/

#include <iostream>
#include "Triad.h"
#include "mytime.h"

using namespace std;

//Функция принимает объект базового класса как параметр
void f1(Triad &t) {
    t.setFirst(0);
}

//Функция возвращает объект базового класса
Triad f2() {
    TIME t(12, 30, 0);
    return t;
}

int main() {
    // Работа с классом TRIAD
    Triad a;
    cin >> a;
    cout << a;

    Triad b(12, 30, 45);
    cout << b;
    a = b;
    cout << a;

    // Работа с классом TIME
    TIME t;
    cin >> t;
    cout << t;

    // Принцип подстановки
    f1(t);
    a = f2();
    cout << a;

    return 0;
}
