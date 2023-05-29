#include "Array.h"

Array::Array(int s) {
//если текущий размер больше максимального, то генерируется исключение
    if (s > MAX_SIZE) throw 1;
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++)
        beg[i] = 0;
}

Array::Array(const Array &v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}

Array::~Array() {
    delete[]beg;
}

Array::Array(int s, const int *mas) {
//если текущий размер больше максимального, то генерируется исключение
    if (s > MAX_SIZE) throw 1;
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = mas[i];
}

const Array &Array::operator=(const Array &v) {
    if (this == &v)return *this;
    delete[]beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
    return *this;
}

ostream &operator<<(ostream &out, const Array &v) {
    if (v.size == 0) out << "Empty\n";
    else {
        for (int i = 0; i < v.size; i++)
            out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, Array &v) {
    for (int i = 0; i < v.size; i++) {
        cout << ">";
        in >> v.beg[i];
    }
    return in;
}

int Array::operator[](int i) {
    if (i < 0)throw 2;//если индекс отрицательный, то генерируется исключение
//если индекс больше размер вектора, то генерируется исключениеif(i>=size) throw error("Array length more than MAXSIZE\n");
    return beg[i];
}

Array Array::operator+(int a) {
//если при добавлении элемента размер вектора станет больше максимального,
//то генерируется исключение
    if (size + 1 == MAX_SIZE) throw 4;
    Array temp(size + 1, beg);
    temp.beg[size] = a;
    return temp;
}

Array Array::operator--() {
//если вектор пустой, то удалить элемент нельзи и генерируется исключение
    if (size == 0) throw 5;
    if (size == 1)//если в вектор один элемент
    {
        size = 0;
        delete[]beg;
        beg = nullptr;
        return *this;
    };
    Array temp(size, beg);
    delete[]beg;
    size--;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = temp.beg[i];
    return *this;
}
