#include <iostream>

const int len = 3;

int matrixSum(int n, int **a) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j) sum += a[i][j];
    return sum;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));
    int **matrix = new int *[len];
    for (int i = 0; i < len; ++i)
        matrix[i] = new int[len];

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            matrix[i][j] = rand();

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int s = matrixSum(len, matrix);

    std::cout << s;

    return 0;
}