//
// Created by hanriel on 5/24/23.
//

#include "BOOK.h"

BOOK::BOOK() : PRINT() {
    pages = 0;
    izdat = "";
}

BOOK::~BOOK() {}

BOOK::BOOK(const string& _name, const string& _author, int _pages, const string& _izdat) : PRINT(_name, _author) {
    pages = _pages;
    izdat = _izdat;
}

BOOK::BOOK(const BOOK &L) {
    name = L.name;
    author= L.author;
    pages = L.pages;
    izdat = L.izdat;
}

void BOOK::Set_pages(int G) { pages = G; }
void BOOK::Set_izdat(string G) { izdat = std::move(G); }


BOOK &BOOK::operator=(const BOOK &book) {
    if (&book == this) return *this;
    name = book.name;
    author= book.author;
    pages = book.pages;
    izdat = book.izdat;
    return *this;
}

void BOOK::Show() {
    cout << "\nNAME : " << name;
    cout << "\nAUTHOR : " << author;
    cout << "\nPAGES : " << pages;
    cout << "\nIZDATEL : " << izdat;
    cout << "\n";
}

void BOOK::Input() {
    cout << "\nName:";
    cin >> name;
    cout << "\nAuthor:";
    cin >> author;
    cout << "\nPages:";
    cin >> pages;
    cout << "\nIzdatel: ";
    cin >> izdat;
}



