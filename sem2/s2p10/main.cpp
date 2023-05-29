//
// Created by hanriel on 5/29/23.
//

/// Создать класс Money для работы с денежными суммами. Число должно быть
//представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть
//числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
//- вычитание дробного числа из суммы
//- операции сравнения (==, !=).
//Задание:
//- Удалить все записи равные заданному значению.
//- Уменьшить все записи с заданным значением на 1 рубль 50 копеек. Значение
//интервала не должно быть меньше 0 рублей 0 копеек.
//- Добавить K записей после элемента с заданным значением.


#include "Money.h"
#include "file_work.h"

int main() {
    Money m;
    int k, c;
    char filename[30];
    do {
        cout << "\n0. Exit";
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete record from file";
        cout << "\n4. Add record to file";
        cout << "\n5. Change value of record";
        cin >> c;
        switch (c) {
            case 1:
                cout << "\nEnter file name: ";
                cin >> filename;
                k = make_file(filename);
                break;
            case 2:
                cout << "\nEnter file name: ";
                cin >> filename;
                k = print_file(filename); // call function print_file
                if (k == 0) cout << "\nFile emply"; // if file is empty
                if (k < 0) cout << "\nCant read file"; // if cant open file
                break;
            case 3:
                cout << "\nEnter file name: ";
                cin >> filename;
                cout << "\nEnter value: ";
                cin >> k;
                k = delete_record(filename, k);
                if (k < 0) cout << "\nCant read file";
                break;
            case 4:
                cout << "\nEnter file name: ";
                cin >> filename;
                cout << "\nEnter value: ";
                cin >> k;
                cout << "\nEnter Money: ";
                cin >> m;
                k = add_record(filename, k, m);
                if (k < 0) cout << "\nCant read file";
                if(k==0) k = add_end(filename, m);
                break;
            case 5:
                cout << "\nEnter file name: ";
                cin >> filename;
                cout << "\nEnter value: ";
                cin >> k;
                cout << "\nEnter Money: ";
                cin >> m;
                k = change_record(filename, k, m);
                if (k < 0) cout << "\nCant read file";
                if (k == 0) cout << "\nRecord not found";
                break;
            default:
                cout << "\nWrong choice";
                break;
        }
    } while (c != 0);
    return 0;
}