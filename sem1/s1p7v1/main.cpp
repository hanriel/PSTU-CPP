#include <iostream>

struct frict {
    int a;
    int b;
};

int NOD(int x, int y) {
    if (y == 0) return x;
    return NOD(y, x % y);
}

double sum_des(float a, float b) {
    return a + b;
}
double sum_des(float a, double b) {
    return a + b;
}
double sum_des(double a, float b) {
    return a + b;
}
double sum_des(double a, double b) {
    return a + b;
}

frict sum_f(int a, int b, int c, int d) {
    frict dr;
    dr.a = a * d + c * b;
    dr.b = b * d;
    return dr;
}
frict sum_f(frict a, frict b) {
    frict dr;
    dr.a = a.a * b.b + b.a * a.b;
    dr.b = a.b * b.b;
    return dr;
}

int main() {
    float a_1, b_1;
    int a, b, c, d;
    setlocale(LC_ALL, "rus");

    std::cout << "Введите первую десятичную дробь: ";
    std::cin >> a_1;

    std::cout << "Введите вторую десятичную дробь: ";
    std::cin >> b_1;

    std::cout << "Сумма: " << sum_des(a_1, b_1) << std::endl;

    std::cout << "Введите числиель и знаменатель первой дроби через Enter: ";
    std::cin >> a >> b;

    std::cout << "Введите числиель и знаменатель второй дроби через Enter: ";
    std::cin >> c >> d;

    frict f = sum_f(a, b, c, d);
    int nod = NOD(f.a, f.b);

    std::cout << "Сумма: " << f.a/nod << "/" << f.b/nod;
}