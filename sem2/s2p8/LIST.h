//
// Created by hanriel on 5/25/23.
//

#ifndef PSTU_CPP_LIST_H
#define PSTU_CPP_LIST_H


#include "OBJECT.h"

class List {

protected:
    int size;
    Object **begin;
    int current;
public:
    explicit List(int);

    ~List();

    void Add();
    void Add(Object *);

    void Del();

    void Show();

    int operator()() const;

    virtual void HandleEvent(const TEvent&e);
};

#endif //PSTU_CPP_LIST_H
