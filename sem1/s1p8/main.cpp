#include <iostream>
#include <string>

// Структура ошибок
// ERR 1 = 
// ERR 2 = 
// ERR 3 = Ошибка чтения для вывода
// ERR 4 = 
// ERR 5 = 

#define N 3 //Первоначальный размер массива

struct PATIENT {
    char *fio[128];
    char *address[40];
    int card;
    int snils;
};

void printFile(const std::string &);

void writePatientFile(std::string, PATIENT);

void writeFile(const std::string &, PATIENT *);

PATIENT createPatient();

void createStructFile(const std::string &);

void delRecord(const std::string &, int);

int main() {
    setlocale(LC_ALL, "rus");

    //ФОРМИРУЕМ ФАЙЛ
    createStructFile("f.dat");
    //Выводим файл
    printFile("f.dat");

    //Удаляем заданную карту
    int del;
    printf("Номер карты которую необходимо удалить=");
    scanf("%d", &del);
    delRecord("f.dat", del);

    printFile("f2.dat");
}

void printFile(const std::string &file_name) {
    FILE *_file;
    PATIENT _buffer{};

    if ((_file = fopen(file_name.c_str(), "rb")) == nullptr) exit(3);
    printf("Содержимое файла %s:\n", file_name.c_str());

    while (fread(&_buffer, sizeof(struct PATIENT), 1, _file) == 1) {
        printf("fio=%s, address=%s, card=%i, snils=%i\n", _buffer.fio, _buffer.address, _buffer.card, _buffer.snils);
    }

    fclose(_file);
}

void writeFile(const std::string &file_name, PATIENT *buffer) {
    FILE *_file;
    if ((_file = fopen(file_name.c_str(), "wb+")) == nullptr) exit(1); // если при открытии файла возникает
    fwrite(&buffer, sizeof(PATIENT), 1, _file);
    if (~ferror(_file) == NULL) exit(2);
    fclose(_file);
}

PATIENT createPatient() {
    PATIENT _buffer{};
    printf("fio=");
    scanf("%s", &_buffer.fio, 128);
    printf("address=");
    scanf("%s", &_buffer.address, 40);
    printf("card=");
    scanf("%d", &_buffer.card);
    printf("snils=");
    scanf("%d", &_buffer.snils);
    return _buffer;
}

void createStructFile(const std::string &file_name) {
    PATIENT _buffer{};
    FILE *_file;
    if ((_file = fopen(file_name.c_str(), "wb+")) == nullptr) exit(1);
    printf("Формирование структуры %s:\n", file_name.c_str());
    for (int i = 0; i <= N - 1; i++) {
        _buffer = createPatient();
        fwrite(&_buffer, sizeof(PATIENT), 1, _file);
        if (~ferror(_file) == NULL) exit(2);
    }
    fclose(_file);
}

void delRecord(const std::string &file_name, int card) {
    FILE *_file;            // указатель связанный с файлом
    PATIENT arr[N];
    PATIENT _buffer{};

    //if ((_file = fopen(file_name.c_str(), "rb")) == nullptr) exit(3);
    //while (fread(&_buffer, sizeof(struct PATIENT), 1, _file) == 1) {
    //    arr[] _buffer.fio, _buffer.address, _buffer.card, _buffer.snils);
    //}

    if ((_file = fopen("f2.dat", "wb+")) == nullptr) exit(4); // если при открытии файла возникает
    for (PATIENT val: arr) {
        if (val.card == card) continue;
        fwrite(&val, sizeof(PATIENT), 1, _file);
    }
    fclose(_file);
}
