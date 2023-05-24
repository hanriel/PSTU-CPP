//
// Created by hanriel on 5/24/23.
//

#include "PRINT.h"

PRINT::PRINT() {
    name = "";
    author = "";
}

//деструктор
PRINT::~PRINT() = default;

//констрктор с параметрами
PRINT::PRINT(const string &N, const string &A) {
    name = N;
    author = A;
}

//конструктор копирования
PRINT::PRINT(const PRINT &car) {
    name = car.name;
    author = car.author;
}

//селекторы
void PRINT::Set_name(string N) {
    name = N;
}

void PRINT::Set_author(string A) {
    author = A;
}

//оператор присваивания
PRINT &PRINT::operator=(const PRINT &c) {
    if (&c == this)return *this;
    name = c.name;
    author = c.author;
    return *this;
}

//метод для просмотра атрибутов
void PRINT::Show() {
    cout << "\nNAME : " << name;
    cout << "\nAUTHOR : " << author;
    cout << "\n";
}

//метод для ввода значений атрибутов
void PRINT::Input() {
    cout << "\nName:";
    cin >> name;
    cout << "\nAuthor:";
    cin >> author;
}