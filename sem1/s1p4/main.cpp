#include <iostream>

int main() {

    setlocale(LC_ALL, "rus");
    srand(time(nullptr));
    const int N = 100;

    //Ини. массив для значений
    int a[N];

    //Длинна массива
    std::cout << "Укажите длинну массива LEN (не более 100): ";
    int len;
    std::cin >> len;

    //1) Заполняем массив значниями
    for (int i = 0; i < len; i++) a[i] = rand();

    //2) Печатаем массив на экран
    for (int i = 0; i < len; i++) printf("%d: %d \n", i, a[i]);

    //3) Удалить первое вхождение элемента
    std::cout << "Что удалить?: ";
    int del;
    std::cin >> del;

    for (int i = 0; i < len; ++i) {
        if (a[i] == del) {
            for (int j = i; j < len; ++j) a[j] = a[j + 1];
            break;
        }
    }
    --len;

    //4) Сдвинуть массив на K элементов вправо
    std::cout << "Сдвинуть массив на К: ";
    int k;
    std::cin >> k;

    for (int i = len + k; i >= k; i--) a[i] = a[i - k];
    len += k;

    //5) Печатаем массив на экран
    for (int i = 0; i < len; i++) printf("%d: %d \n", i, a[i]);


    system("pause");
}