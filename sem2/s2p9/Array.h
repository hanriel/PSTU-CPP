#pragma once

#include <iostream>

using namespace std;

const int MAX_SIZE = 30;              //максимальный размер вектора
class Array {
    int size;                       //текущий размер
    int *beg;                       //указатель на начало динамического массива
public:
    //конструктор без параметров
    Array() {
        size = 0;
        beg = nullptr;
    }

    explicit Array(int s);          //конструктор с параметром
    Array(int s, const int *mas);    //конструктор с параметром
    Array(const Array &v);           //конструктор копирования
    ~Array();                       //деструктор
    const Array &operator=(const Array &v);//операция присваивания
    int operator[](int i);          //доступ по индексу
    Array operator+(int a);         //добавление элемента
    Array operator--();             //удаление элемента
    //дружественные функции ввода-вывода
    friend ostream &operator<<(ostream &out, const Array &v);

    friend istream &operator>>(istream &in, Array &v);
};