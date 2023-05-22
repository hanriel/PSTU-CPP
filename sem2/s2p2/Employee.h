#pragma once

#include <iostream>
#include <string>

using namespace std;

class Employee {

    string fio;
    string post;
    double salary;

public:
    Employee();

    Employee(string, string, double);

    Employee(const Employee &);

    ~Employee();

    string getFIO();

    void setFIO(string);

    string getPost();

    void setPost(string);

    double getSalary();

    void setSalary(double);

    void show();
};
