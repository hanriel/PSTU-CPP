#include "Employee.h"
#include <iostream>
#include <string>

// Êîíñòðóêòîð áåç ïàðàìåòðîâ
Employee::Employee() {
	fio = "";
	post = "";
	salary = 0;
	cout << "====Êîíñòðóêòîð áåç ïàðàìåòðîâ====" << endl;
}

// Êîíñòðóêòîð c ïàðàìåòðàìè
Employee::Employee(string _fio, string _post, double _salary) {
	fio = _fio;
	post = _post;
	salary = _salary;
	cout << "===Êîíñòðóêòîð c ïàðàìåòðàìè===" << endl;
}

// Êîíñòðóêòîð êîïèðîâàíèÿ
Employee::Employee(const Employee &e) {
	fio = e.fio;
	post = e.post;
	salary = e.salary;
	cout << "===Êîíñòðóêòîð êîïèðîâàíèÿ===" << endl;
}

// Äåñòðóêòîð
Employee::~Employee() {
	cout << "Äåñòðóêòîð äëÿ îáúåêòà: " << this << endl;
}

// Ñåëåêòîðû
string Employee::getFIO() {	return fio; }
string Employee::getPost() { return post; }
double Employee::getSalary() { return salary; }

// Ìîäèôèêàòîðû
void Employee::setFIO(string _fio) { fio = _fio; }
void Employee::setPost(string _post) { post = _post; }
void Employee::setSalary(double _salary) { salary = _salary; }

//Ìåòîä äëÿ ïðîñìòðà àòðèáóòîâ
void Employee::show() {
	cout << "" << fio << endl;
	cout << "" << post << endl;
	cout << "" << salary << endl;
}
