//
// Created by hanriel on 5/24/23.
//

#include "BOOK.h"

BOOK::BOOK() : PRINT() {
    pages = 0;
    izdat = "";
}

BOOK::~BOOK() = default;

BOOK::BOOK(const string& N, const string& A, int P, string I) : PRINT(N, A) {
    pages = P;
    izdat = I
}

BOOK::BOOK(const BOOK &L) {
    name = L.name;
    author= L.author;
    pages = L.pages;
    izdat = L.izdat;
}

void BOOK::Set_pages(int G) {
    pages = G;
}

void BOOK::Set_izdat(string G) {
    izdat = G;
}


BOOK &BOOK::operator=(const BOOK &l) {
    if (&l == this)return *this;
    mark = l.mark;
    power = l.power;
    cyl = l.cyl;
    return *this;
}

void BOOK::Show() {
    cout << "\nMARK : " << mark;
    cout << "\nCYL : " << cyl;
    cout << "\nPOWER : " << power;
    cout << "\nGRUZ : " << gruz;
    cout << "\n";
}

void BOOK::Input() {
    cout << "\nMark:";
    cin >> mark;
    cout << "\nPower:";
    cin >> power;
    cout << "\nCyl:";
    cin >> cyl;
    cout << "\nGRUZ : ";
    cin >> gruz;
}