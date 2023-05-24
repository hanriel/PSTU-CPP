// Сформировать двумерный массив. Добавить в него столбец с заданным номером;

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n, m, col;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    int **arr = new int *[n]; // Создание двумерного массива
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    cout << "Введите номер колонки которую нужно добавить: ";
    cin >> col;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) { // добавление дополнительной колонки
            if (j == col) { // заполнение значения новой колонки
                cout << "Введите значение для строки " << i + 1 << " колонки " << j + 1 << ": ";
                cin >> arr[i][j];
            } else if (j < col) { // копирование значений существующей колонки
                cout << "Введите значение для строки " << i + 1 << " колонки " << j + 1 << ": ";
                cin >> arr[i][j];
            } else {
                arr[i][j] = 0; // Заполнение колонки нулями
            }
        }
    }

    cout << "Обновленный массив:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Высвобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
