#include <iostream>
#include <math.h>

int main() {
    setlocale(LC_ALL, "rus");
    long double sum, an, n;
    an = 1.0;
    sum = 0;
    n = 1.0;

    while (an > 1E-4) {
        an = 10 / (n + 1);
        sum = sum + an;
        printf("N: %2.0f An: %12.8f SUM: %12.8f\n", n, an, sum);
        n = n + 1.0;
    }

    system("pause");
}

