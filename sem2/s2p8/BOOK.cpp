//
// Created by hanriel on 5/24/23.
//

#include "BOOK.h"

BOOK::BOOK() : PRINT() {
    pages = 0;
    publisher = "";
}

BOOK::~BOOK() {}

BOOK::BOOK(const string &_name, const string &_author, int _pages, const string &_publisher) : PRINT(_name, _author) {
    pages = _pages;
    publisher = _publisher;
}

BOOK::BOOK(const BOOK &L) {
    name = L.name;
    author = L.author;
    pages = L.pages;
    publisher = L.publisher;
}

void BOOK::setPages(int G) { pages = G; }

void BOOK::setPublisher(string G) { publisher = std::move(G); }


BOOK &BOOK::operator=(const BOOK &book) {
    if (&book == this) return *this;
    name = book.name;
    author = book.author;
    pages = book.pages;
    publisher = book.publisher;
    return *this;
}

void BOOK::Show() {
    cout << "\nNAME : " << name;
    cout << "\nAUTHOR : " << author;
    cout << "\nPAGES : " << pages;
    cout << "\nPUBLISHER : " << publisher;
    cout << "\n";
}

void BOOK::Input() {
    cout << "\nName:";
    cin >> name;
    cout << "\nAuthor:";
    cin >> author;
    cout << "\nPages:";
    cin >> pages;
    cout << "\nPublisher: ";
    cin >> publisher;
}



