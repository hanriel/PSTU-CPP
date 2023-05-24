//
// Created by hanriel on 5/24/23.
//
#pragma once

#include <iostream>
#include "PRINT.h"

using namespace std;

#ifndef PNUPU_CPP_BOOK_H
#define PNUPU_CPP_BOOK_H


class BOOK : public PRINT {
    int pages;
    string izdat;
    //group;
public:
    BOOK();

    void Show();

    void Input();

    BOOK(string, int, int, int);

    BOOK(const BOOK &);

    int Get_pages() const { return pages; }

    string Get_izdat() { return izdat; }

    void Set_pages(int);

    void Set_izdat(string);

    BOOK &operator=(const BOOK &);
};


#endif //PNUPU_CPP_BOOK_H
