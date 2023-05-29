//
// Created by hanriel on 5/25/23.
//

/// Класс- контейнер МНОЖЕСТВО с элементами типа int.
//Реализовать операции:
//[] – доступа по индексу;
//!= - проверка на неравенство;
//< число – принадлежность числа множеству;
//+ n – переход вправо к элементу с номером n .

#include "Array.h"

using namespace std;

int main() {
    try {
        Array x(2);
        Array y;

        cout << x;
        cout << "Номер элемента: ";
        int i;
        cin >> i;
        cout << x[i] << endl;

        y = x + 3;
        cout << y;

        --x;
        cout << x;
        --x;
        cout << x;
        --x;
    } catch (int) {
        cout << "Ошибка" << endl;
    }
    return 0;
}