//
// Created by hanriel on 5/24/23.
//

#ifndef PNUPU_CPP_OBJECT_H
#define PNUPU_CPP_OBJECT_H

class Object {
public:
    Object();

    virtual void Show() = 0;

    virtual void Input() = 0;

    virtual ~Object();
};

#endif //PNUPU_CPP_OBJECT_H
