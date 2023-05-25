#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n = 3, k = 10, j;
    double a = 0.1, b = 0.8, h = (b - a) / k, an, prev, SN, SE, eps = 0.0001, Y;

    //h шаг изменения функции

    for (double x = a; x <= b + h / 2.; x += h) {
        SN = 0.;
        for (int i = 1; i <= n; i++) {
            SN += pow(x, 4 * i + 1) / (4 * i + 1);
        }

        j = 1;
        an = 0.;
        prev = 1.;
        SE = 0.;
        while (fabs(prev - an) > eps) {
            prev = an;
            an = pow(x, 4 * j + 1) / (4 * j + 1);
            SE += an;
            j++;
        }

        Y = 0.25 * log((1. + x) / (1. - x)) + 0.5 * atan(x);

        cout << setprecision(2) << fixed << "X=" << x << setprecision(7)
             << "  SN=" << SN << "  SE=" << SE << "  Y=" << Y << "\n";
    }

    return 0;
}