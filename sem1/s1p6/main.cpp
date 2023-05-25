#include <iostream>
#include <sstream>

using namespace std;

bool check(string word) {
    int len = word.length();
    for (int i = 0; i < len / 2; ++i) {
        if (word[i] != word[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "rus");
    char line[255];
    gets(line);

    if (check(line))
        cout << "Данная строка палиндром\n";
    else
        cout << "Не полендром\n";
   
    system("pause");
}
