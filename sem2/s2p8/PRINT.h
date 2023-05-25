//
// Created by hanriel on 5/24/23.
//
#pragma once

#include <iostream>
#include "OBJECT.h"

using namespace std;

#ifndef PNUPU_CPP_PRINT_H
#define PNUPU_CPP_PRINT_H


class PRINT : public Object {
protected:
    string name;
    string author;
public:
    PRINT();

    ~PRINT() override;

    void Show() override;

    void Input() override;

    PRINT(const string &, const string &);

    PRINT(const PRINT &);

    //селекторы
    string Get_name() { return name; }
    string Get_author() { return author; }

    //модификаторы
    void Set_name(string);
    void Set_author(string);

    PRINT &operator=(const PRINT &);//перегрузка операции присваивания
};


#endif //PNUPU_CPP_PRINT_H
