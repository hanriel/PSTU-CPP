#include "Array.h"
Array::Array(int s,int k) {
    size=s;
    data=new int[size];
    for(int i=0;i<size;i++)
        data[i]=k;
}
//конструктор копирования
Array::Array(const Array&a) {
    size=a.size;
    data=new int[size];
    for(int i=0;i<size;i++)
        data[i]=a.data[i];
}
//деструктор
Array::~Array() {
    delete[]data;
    data=0;
}
//операция присваивания
Array&Array::operator=(const Array&a) {
    if(this==&a)return *this;
    size=a.size;
    if (data!=0) delete[]data;
    data=new int[size];
    for(int i=0;i<size;i++)
        data[i]=a.data[i];
    return *this;
}
//операция доступа по индексу
int&Array::operator[](int index) {
    if (index<size) return data[index];
    else cout<<"\nError! Index>size";
}
//операция для получения длины вектора
int Array::operator ()() {
    return len();
}
//операции для ввода-выода
ostream&operator<<(ostream&out,const Array&a) {
    for(int i=0;i<a.len();++i)
        out<<a.data[i]<<" ";
    return out;
}
istream&operator>>(istream&in,Array&a) {
    for(int i=0;i<a.len();++i)
        in>>a.data[i];
    return in;
}
