#pragma once

#include <iostream>

using namespace std;


class Iterator {
    friend class Array;                     //дружественный класс
public:
    Iterator() { elem = nullptr; }               //конструктор без параметров
    Iterator(const Iterator &it) { elem = it.elem; }//конструктор копирования
    //перегруженные операции сравнения
    bool operator==(const Iterator &it) { return elem == it.elem; }

    bool operator!=(const Iterator &it) { return elem != it.elem; };

    void operator++() { ++elem; };            //перегруженная операция инкремент
    void operator--() { --elem; }              //перегруженная операция декремент
    int &operator*() const { return *elem; }  //перегруженная операция разыменования
private:
    int *elem;                               //указатель на элемент типа int
};

// Множество
class Array {
public:
    explicit Array(int s, int k = 0);

    Array(const Array &a);

    ~Array();

    Array &operator=(const Array &a);     //оператор присваивания
    int &operator[](int index); //операция доступа по индексу
    int operator()(); //операция, возвращающая длину вектора
    friend ostream &operator<<(ostream &out, const Array &a); //перегруженные операции ввода-вывода
    friend istream &operator>>(istream &in, Array &a);

    Iterator first() { return beg; }//возвращает указатель на первый элемент
    Iterator last() { return end; }//возвращает указатель на элемент следующий за
private:
    int size;//размер вектора
    int *data;//укзатель на динамический массив значений вектора
    Iterator beg;//указатель на первый элемент вектора
    Iterator end;//указатель на элемент следующий за последним
};