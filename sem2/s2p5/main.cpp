#include "Object.h"
#include "Triad.h"
#include "mytime.h"
#include "Vector.h"


int main() {
    Vector v(5); // Вектор из 5 элементов

    Triad a;
    cin >> a;

    TIME b;
    cin >> b;

    Object *p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);

    cout << v;
    return 0;

   // TODO Отчет 5 лаба
}