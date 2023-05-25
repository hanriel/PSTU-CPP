//
// Created by hanriel on 5/24/23.
//

#ifndef PSTU_CPP_OBJECT_H
#define PSTU_CPP_OBJECT_H

#include "EVENT.h"

class Object {
public:
    Object();

    virtual void Show() = 0;

    virtual void Input() = 0;

    virtual ~Object();

    virtual void HandleEvent(const TEvent &e)=0;
};

#endif //PSTU_CPP_OBJECT_H
