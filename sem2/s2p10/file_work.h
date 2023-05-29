//
// Created by hanriel on 5/29/23.
//

#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char *filename) {
    fstream file;
    file.open(filename, ios::out);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    int n;
    Money m;
    cout << "Enter the N: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter the Money: ";
        cin >> m;
        file << m << endl;
    }

    file.close();
    return n;
}

int print_file(const char *filename) {
    fstream file(filename, ios::in); // open the file
    if (!file) return -1; // Error opening file
    Money m;
    int i = 0;
    while (file >> m) {
        cout << i << ": " << m << endl;
        i++;
    }
    file.close();
    return i;
}

// Delete the object from the stream
int delete_record(const char *filename, int k) {
    fstream temp("temp.txt", ios::out);
    fstream file(filename, ios::in); // open the file
    if (!file) return -1; // Error opening file
    Money m;
    int i = 0;
    while (file >> m) {
        if (file.eof()) break;
        i++;
        if (i != k) temp << m << endl;
    }
    temp.close();
    file.close();
    remove(filename);
    rename("temp.txt", filename);
    return i;
}

int add_record(const char *filename, int k, const Money &mm) {
    fstream temp("temp.txt", ios::out);
    fstream file(filename, ios::in); // open the file
    if (!file) return -1; // Error opening file
    Money m;
    int i = 0, l = 0;
    while (file >> m) {
        if (file.eof()) break;
        i++;
        if (i != k) temp << mm;
        temp << m;
    }
    temp.close();
    file.close();
    remove(filename);
    rename("temp.txt", filename);
    return l;
}

int add_end(const char *filename, const Money &mm) {
    fstream file(filename, ios::app); // open the file
    if (!file) return -1; // Error opening file
    file << mm;
    return 1;
}

int change_record(const char *filename, int k, const Money &mm) {
    fstream temp("temp.txt", ios::out);
    fstream file(filename, ios::in); // open the file
    if (!file) return -1; // Error opening file
    Money m;
    int i = 0, l = 0;
    char x;
    while (file >> m) {
        if (file.eof()) break;
        i++;
        if (i == k) {
            cout << m << " - is changing... Continue? (Y/N): ";
            cin >> x;
            if (x == 'n' || x == 'N') break;
            temp << mm;
            l++;
        } else {
            temp << m;
        }
    }
    temp.close();
    file.close();
    remove(filename);
    rename("temp.txt", filename);
    return l;
}