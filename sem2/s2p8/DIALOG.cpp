
#include <iostream>
#include "DIALOG.h"

using namespace std;

//конструктор
Dialog::Dialog() : List(0) {
    EndState = 0;
}

//деструктор
Dialog::~Dialog() = default;

//получение события
void Dialog::GetEvent(TEvent &event) {
    string OpInt = "+-?/qam"; //строка содержит коды операций
    string s;
    string param;
    char code;
    cout << '>';
    cin >> s;
    code = s[0];//первый символ команды
    //является ли символ кодом операции
    if (OpInt.find(code) >= 0) {
        event.what = evMessage;
        switch (code) {
            case 'm':
                event.command = cmMake;
                break;//создать группу
            case '+':
                event.command = cmAdd;
                break;//добавить объект в группу
            case '-':
                event.command = cmDel;
                break;//удалить объект из группы
            case '?':
                event.command = cmShow;
                break;//просмотр группы
            case 'q':
                event.command = cmQuit;
                break; //конец работы
            case '/':
                event.command = cmGet;
                break;
        }
//выделяем параметры команды, если они есть
        if (s.length() > 1) {
            param = s.substr(1, s.length() - 1);
            int A = atoi(param.c_str());//преобразуем парметр в число
            event.a = A;//записываем в сообщение
        }
    } else event.what = evNothing;//пустое событие
}

int Dialog::Execute() {
    TEvent event{};
    do {
        EndState = 0;
        GetEvent(event); //получить событие
        HandleEvent(event); //обработать событие
    } while (!Valid());
    return EndState;
}

int Dialog::Valid() const {
    if (EndState == 0) return 0;
    else return 1;
}

void Dialog::ClearEvent(TEvent &event) {
    event.what = evNothing;//пустое событие
}

void Dialog::EndExec() {
    EndState = 1;
}

//обработчик событий
void Dialog::HandleEvent(TEvent &event) {
    if (event.what == evMessage) {
        switch (event.command) {
            case cmMake://создание группы
                size = event.a; //размер группы
                begin = new Object *[size];//выделяем память под массив указателей
                current = 0; //текущая позиция
                ClearEvent(event);//очищаем событие
                break;
            case cmAdd://добавление
                Add();
                ClearEvent(event);
                break;
            case cmDel:
                Del(); //удаление
                ClearEvent(event);
                break;
            case cmShow:
                Show(); //просмотр
                ClearEvent(event);
                break;
            case cmQuit:
                EndExec(); //выход
                ClearEvent(event);
                break;
            default:
                List::HandleEvent(event);
        };
    };
}