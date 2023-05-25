#include <iostream>
#include <string>
#include "Employee.h"

// Функция для возврата объекта как результата
Employee makeEmployee() {
    string fio;
    string post;
    double salary;

    cout << "Введите ФИО: ";
    cin >> fio;
    cout << "Введите Должность: ";
    cin >> post;
    cout << "Введите Зарплату: ";
    cin >> salary;

    Employee e(fio, post, salary);
    return e;
}

// Функция для передачи объекта как параметра
void printEmployee(Employee e) {
    e.show();
}

int main() {
    setlocale(LC_ALL, "rus");

    Employee e1;
    e1.show();

    Employee e2("Федосеев Данил Александрович", "Преподаватель", 20000);
    e2.show();

    Employee e3 = e2;
    e3.setFIO("Гибадуллин Дамир Рустамович");
    e3.setPost("Преподаватель");
    e3.setSalary(25000);

    printEmployee(e3);

    e1 = makeEmployee();
    e1.show();

    return 0;
}