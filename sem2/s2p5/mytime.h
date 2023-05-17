#pragma once

#include "Triad.h"
#include <iostream>
using namespace std;

// Class TIME is based on class Triad
class TIME : public Triad {
public:
    using Triad::Triad;
    void Show();//функция для просмотра атрибутов класса с помощью указателя
    bool operator==(const TIME &);
    bool operator!=(const TIME &);
    friend ostream &operator<<(ostream &, const TIME &);
    friend istream &operator>>(istream &, TIME &);
};


