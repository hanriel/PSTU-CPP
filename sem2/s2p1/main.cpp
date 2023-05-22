#include <iostream>
#include "point.h"

using namespace std;

point make_point(double x, double y) {
    point p;
    p.Init(x, y);
    return p;
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << "===Определение переменных A и B====" << endl;
    point A;
    point B;
    A.Init(3.0, 2.0);
    B.Read();
    A.Show();
    B.Show();
    cout << "A.Distance(" << B._x << ", " << B._y << ") = " << A.Distance(B._x, B._y) << endl;
    cout << "B.Distance(" << A._x << ", " << A._y << ") = " << B.Distance(A._x, A._y) << endl;

    cout << "\n=============Указатели=============" << endl;
    point *X = new point;
    X->Init(5, 6);
    X->Show();
    cout << "X.Distance(1, 1) = " << X->Distance(1, 1) << endl;

    cout << "Массивы" << endl;
    point mas[3];
    for (int i = 0; i < 3; i++)
        mas[i].Read();
    for (int i = 0; i < 3; i++)
        mas[i].Show();
    for (int i = 0; i < 3; i++)
        cout << "mas[" << i << "].Distance(0, 0) = " << mas[i].Distance(0, 0) << endl;

    cout << "\n=======Динамические массивы========" << endl;
    point *p_mas = new point[3];
    for (int i = 0; i < 3; i++)
        p_mas[i].Read();
    for (int i = 0; i < 3; i++)
        p_mas[i].Show();
    for (int i = 0; i < 3; i++)
        cout << "p_mas[" << i << "].Distance(0, 0) = " << mas[i].Distance(0, 0) << endl;

    cout << "\n====Вызов функции make_point()=====" << endl;
    double z, w;
    cout << "X: ";
    cin >> z;
    cout << "Y: ";
    cin >> w;
    point p = make_point(z, w);
    p.Show();

    return 0;
}
