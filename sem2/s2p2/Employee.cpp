#include "Employee.h"
#include <iostream>
#include <string>

// Конструктор без параметров
Employee::Employee() {
    fio = "";
    post = "";
    salary = 0;
    cout << "====Конструктор без параметров====" << endl;
}

// Конструктор c параметрами
Employee::Employee(string _fio, string _post, double _salary) {
    fio = _fio;
    post = _post;
    salary = _salary;
    cout << "===Конструктор c параметрами===" << endl;
}

// Конструктор копирования
Employee::Employee(const Employee &e) {
    fio = e.fio;
    post = e.post;
    salary = e.salary;
    cout << "===Конструктор копирования===" << endl;
}

// Деструктор
Employee::~Employee() {
    cout << "Деструктор для класса: " << this << endl;
}

// Селекторы
string Employee::getFIO() { return fio; }

string Employee::getPost() { return post; }

double Employee::getSalary() { return salary; }

// Модификаторы
void Employee::setFIO(string _fio) { fio = _fio; }

void Employee::setPost(string _post) { post = _post; }

void Employee::setSalary(double _salary) { salary = _salary; }

// Метод для просмотра атрибутов
void Employee::show() {
    cout << "" << fio << endl;
    cout << "" << post << endl;
    cout << "" << salary << endl;
}
