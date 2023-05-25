//
// Created by hanriel on 5/24/23.
//
#pragma once

#include <iostream>
#include "PRINT.h"

using namespace std;

#ifndef PSTU_CPP_BOOK_H
#define PSTU_CPP_BOOK_H


class BOOK : public PRINT {
    int pages;
    string publisher;
public:
    BOOK();

    void Show() override;

    void Input() override;

    BOOK(const BOOK &);

    BOOK(const string &, const string &, int, const string &);

    ~BOOK() override;

    int getPages() const { return pages; }

    string getPublisher() { return publisher; }

    void setPages(int);

    void setPublisher(string);

    BOOK &operator=(const BOOK &);
};


#endif //PSTU_CPP_BOOK_H
