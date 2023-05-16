#include <iostream>
#include <string>

//Струткура ошибок
// ERR 1 = 
// ERR 2 = 
// ERR 3 = Ошибка чтения для вывода
// ERR 4 = 
// ERR 5 = 

#define N 3 //Первоначлаьный размер массива

typedef struct PATIENT {
    char* fio[128];
    char* address[40];
    int card;
    int snils;
};

void printFile(std::string);
void writePatientFile(std::string, PATIENT);
void writeFile(std::string, PATIENT*);
PATIENT createPatient();
void createStructFile(std::string);
void delRecord(std::string, int);

int main() {
    setlocale(LC_ALL, "rus");

    //ФОРМИРУЕМ ФАЙЛ
    createStructFile("f.dat");
    //Выводим файл
    printFile("f.dat");
    
    //Удаляем заданную карту
    int del;
    printf("Номер карты которую необходимо удалить=");
    scanf_s("%d", &del);

    printFile("f2.dat");
}

void printFile(std::string file_name) {
    FILE* _file;
    PATIENT _buffer;

    if (fopen_s(&_file, file_name.c_str(), "rb")) exit(3);
    printf("Содержимое файла %s:\n", file_name.c_str());

    while (fread(&_buffer, sizeof(struct PATIENT), 1, _file) == 1) {
        printf("fio=%s, address=%s, card=%i, snils=%i\n", _buffer.fio, _buffer.address, _buffer.card, _buffer.snils);
    }

    fclose(_file);
}

void writeFile(std::string file_name, PATIENT* buffer) {
    FILE* _file;
    if (fopen_s(&_file, file_name.c_str(), "wb+")) exit(1); // если при открытии файла возникает 
    fwrite(&buffer, sizeof(PATIENT), 1, _file);
    if (~ferror(_file) == NULL) exit(2);
    fclose(_file);
}

PATIENT createPatient() {
    PATIENT _buffer;
    printf("fio=");     scanf_s("%s", &_buffer.fio, 128);
    printf("address="); scanf_s("%s", &_buffer.address, 40);
    printf("card=");    scanf_s("%d", &_buffer.card);
    printf("snils=");   scanf_s("%d", &_buffer.snils);
    return _buffer;
}

void createStructFile(std::string file_name) {
    PATIENT _buffer;
    FILE* _file;
    if (fopen_s(&_file, file_name.c_str(), "wb+")) exit(1);
    printf("Формирование структуры %s:\n", file_name.c_str());
    for (int i = 0; i <= N - 1; i++) {
        _buffer = createPatient();
        fwrite(&_buffer, sizeof(PATIENT), 1, _file);
        if (~ferror(_file) == NULL) exit(2);
    }
    fclose(_file);
}

void delRecord(std::string file_name, int card) {
    FILE* f;            // указатель связанный с файлом
    if (fopen_s(&f, "f2.dat", "wb+")) exit(4); // если при открытии файла возникает 
    for (PATIENT val : mas) {
        if (val.card == del) continue;
        fwrite(&val, sizeof(PATIENT), 1, f);
    }
    fclose(f);
}
