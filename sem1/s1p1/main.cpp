#include <iostream>
#inclide <cmath>

int main()
{
    setlocale(LC_ALL, "rus");
    char a = 100;

    // FLOAT
    // Обьявляем переменые
    float b_1 = 0.001f;

    // Шаг 1: a + b
    float step1_1 = b_1 + a;
    // Шаг 2: (a + b)^4
    float step1_2 = powf(step1_1, 4);
    // Шаг 3: a^4 + 4 * a^3 * b
    float step1_3 = powf(a, 4) + 4 * powf(a, 3) * b_1;
    //Шаг 4: (a + b)^4 - (a^4 + 4 * a^3 * b)
    float chislitel_1 = step1_2 - step1_3;
    //Шаг 5: 6*b^2*b^2
    float step1_4 = 6 * powf(a, 2) * powf(b_1, 2);
    //Шаг 6: 4a*b^3
    float step1_5 = 4 * a * powf(b_1, 3);
    //Шаг 7: b^4
    float step1_6 = powf(b_1, 4);
    //Шаг 8:
    float znamenatel_1 = step1_4 + step1_5 + step1_6;
    //Результат:
    float result_1 = chislitel_1 / znamenatel_1;
    printf("FLOAT: %f\n", result_1);

    // DOUBLE
    // Обьявляем переменые
    double b_2 = 0.001;

    // Шаг 1: a + b
    double step2_1 = b_2 + a;
    // Шаг 2: (a + b)^4
    double step2_2 = pow(step2_1, 4);
    // Шаг 3: a^4 + 4 * a^3 * b
    double step2_3 = pow(a, 4) + 4 * pow(a, 3) * b_2;
    //Шаг 4: (a + b)^4 - (a^4 + 4 * a^3 * b)
    double chislitel_2 = step2_2 - step2_3;
    //Шаг 5: 6*b^2*b^2
    double step2_4 = 6 * pow(a, 2) * pow(b_2, 2);
    //Шаг 6: 4a*b^3
    double step2_5 = 4 * a * pow(b_2, 3);
    //Шаг 7: b^4
    double step2_6 = pow(b_2, 4);
    //Шаг 8:
    double znamenatel_2 = step2_4 + step2_5 + step2_6;
    //Результат:
    double result_2 = chislitel_2 / znamenatel_2;
    printf("DOUBLE: %f\n", result_2);

    int m, n, r1;
    bool r2, r3;
    m = 1;
    n = 1;
    r1 = ++n * ++m;
    r2 = m++ < n;
    r3 = n++ > m;
    printf("%d, %d, %d", r1, r2, r3);

    system("pause");
}
