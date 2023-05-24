#include "Array7.h"
#include "Money.h"
#include <iostream>

using namespace std;

int main() {
    //инициализация, ввод и вывод значений вектора
    Array<int> A(5, 0);
    cin >> A;
    cout << A << endl;
    //инициализация и вывод значений вектора
    Array<int> B(10, 1);
    cout << B << endl;
    //операция присваивания
    B = A;
    cout << B << endl;
    //доступ по индексу
    cout << A[2] << endl;
    //получение длины вектора
    cout << "size=" << A() << endl;
    //операция сложения с константой
    B = A + 10;
    cout << B << endl;

    Money m;
    cin >> m;
    cout << m;

    int k;
    cout << "k?";
    cin >> k;
    Money p;
    //p = m + k; TODO Fix this
    cout << p;

    Money t;
    cin >> t;
    cout << t;
    Array<Money> A2(5, t);
    cin >> A2;
    cout << A2 << endl;
    Array<Money> B2(10, t);
    cout << B2 << endl;
    B2 = A2;
    cout << B2 << endl;
    cout << A2[2] << endl;
    cout << "size=" << A2() << endl;
    B2 = A2 + t;
    cout << B << endl;

    return 0;

    // TODO Отчет 7 лаба
}
