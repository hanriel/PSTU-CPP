// 1) Скопировать из файла F1 в файл F2 все строки, которые содержат только одно слово.
//2) Найти самое длинное слово в файле F2.

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool checkLine(const string &_buff) {
    for (char i: _buff)
        if (i == ' ') return false;
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    ifstream in;
    ofstream out;
    string _buff;
    in.open("F1.txt");
    if (!in) {
        cout << "Error: Can't open the file named F1.txt.\n";
        exit(1);
    }
    out.open("F2.txt", ios::__noreplace);

    getline(in, _buff);
    while (in) {
        if (checkLine(_buff))
            out.write(_buff.c_str(), _buff.size());
        getline(in, _buff);
    }
    in.close();
    out.close();

    in.open("F2.txt");
    getline(in, _buff);

    int max_size = 0;
    string max_word;
    string word;
    while (in) {
        istringstream is(_buff);
        while (is >> word) {
            if (max_size < word.size()) {
                max_size = word.size();
                max_word = word;
            }
        }

        getline(in, _buff);
    }
    in.close();

    cout << "Самое длинное слово в F2: " << word;

    return 0;
}

