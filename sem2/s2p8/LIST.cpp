//
// Created by hanriel on 5/25/23.
//

#include <iostream>
#include "LIST.h"
#include "PRINT.h"
#include "BOOK.h"

void HandleEvent(const TEvent &e);

using namespace std;

//деструктор
List::~List() {
    delete[] begin;
    begin = nullptr;
}

//конструктор с параметрами
List::List(int n) {
    begin = new Object *[n];
    current = 0;
    size = n;
}

//добавление объекта, на который указывает указатель p в список
void List::Add() {
    Object *p;
//выбор из объектов двух возможных классов
    cout << "1.Car" << endl;
    cout << "2.Lorry" << endl;
    int y;
    cin >> y;
    if (y == 1)//добавление объекта класса PRINT
    {
        auto *a = new(PRINT);
        a->Input();//ввод значений атрибутов
        p = a;
        if (current < size) {
            begin[current] = p;//добавление в список
            current++;
        }
    } else if (y == 2) //добавление объекта класса Lorry
    {
        BOOK *b = new BOOK;
        b->Input();
        p = b;
        if (current < size) {
            begin[current] = p;
            current++;
        }
    } else return;
}

//просмотр списока
void List::Show() {
    if (current == 0)
        cout << "Empty" << endl;
    Object **p = begin;//указатель на указатель типа Object
    for (
            int i = 0;
            i < current;
            i++) {
        (*p)->Show();//вызов метода Show() (позднее связывание)
        p++;//передвигаем указатель на следующий объект
    }
}

//операция, которая возвращает размер списока
int List::operator()() const {
    return current;
}

//удаление элемента из списока, память не освобождается!
void List::Del() {
    if (current == 0)return;//пустой
    current--;
}

void List::Add(Object *p) {
    if (current < size) {
        begin[current] = p;
        current++;
    }
}

void List::HandleEvent(const TEvent &e) {
    if (e.what == evMessage) {
        Object **p = begin;
        for (int i = 0; i < current; i++) {
            (*p)->HandleEvent(e);//вызов метода (позднее связывание)
            p++;//передвигаем указатель на следующий объект
        }
    }
}