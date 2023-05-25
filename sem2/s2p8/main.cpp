
#include "PRINT.h"
#include "BOOK.h"

int main() {
    auto *a = new PRINT;
    a->Input();
    a->Show();

    auto *b = new BOOK;
    b->Input();
    b->Show();

    return 0;

    // TODO Отчет 8 лаба
}