// Записи в линейном списке содержат ключевое поле типа int. Сформировать двунаправленный список.
// Удалить из него К элементов перед элементом с заданным номером, добавить К элементов в конец списка.

#include <iostream>
#include <fstream>

using namespace std;

struct point {
    int key;
    point *prev;
    point *next;
};

point *make_point(int n) {
    auto* head = new point;
    cout << "Введите значение: ";
    cin >> head->key;
    head->prev = nullptr;
    head->next = nullptr;
    point* curr = head;
    for (int i = 2; i <= n; i++) {
        auto* newNode = new point;
        cout << "Введите значение: ";
        cin >> newNode->key;
        newNode->prev = curr;
        newNode->next = nullptr;
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}

void print(point *head) {
    if (head == nullptr) {
        cout << "Список пустой" << endl;
    } else {
        point *p = head;
        while (p != nullptr) {
            cout << p->key << " ";
            p = p->next;
        }
        cout << endl;
    }
}

point *get_last(point *head) {
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}

point *delete_element(point *head, int k, int number) {
    if (head == nullptr) {
        cout << "Список пустой" << endl;
        return head;
    }

    point* temp = head;
    for (int i = 1; i < number-k && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Неверная позиция.\n";
        return nullptr;
    }
    point* delNode = temp->next;
    for (int i = 0; i < k && delNode != nullptr; i++) {
        delNode = delNode->next;
        delete temp->next;
        temp->next = delNode;
        if (delNode != nullptr) {
            delNode->prev = temp;
        }
    }

    return head;
}

point *add_elements(point *head, int k) {
    if (head == nullptr) {
        cout << "Список пустой" << endl;
        return head;
    }

    point *curr = get_last(head);
    for (int i = 0; i < k; i++) { // добавление K элементов к концу массива
        auto* newNode = new point;
        cout << "Введите значение: ";
        cin >> newNode->key;
        newNode->prev = curr;
        newNode->next = nullptr;
        curr->next = newNode;
        curr = newNode;
    }

    return head;
}

void free_list(point **head) {
    point *p = *head, *t;
    while (p != nullptr) {
        t = p->next;
        delete p;
        p = t;
    }
    *head = nullptr;
}


void save_to_file(point *head, const char *filename) {
    if (head == nullptr) {
        cout << "Список пустой" << endl;
        return;
    }
    ofstream file(filename);
    point *p = head;
    while (p != nullptr) {
        file << p->key;
        if (p->next != nullptr) {
            file << " ";
        }
        p = p->next;
    }
    file.close();
}

point *read_file(const char *filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return nullptr;
    }
    point *beg = nullptr, *p, *pred = nullptr;
    int num;
    while (!file.eof()) {
        file >> num;
        p = new point();
        p->key = num;
        p->next = nullptr;
        if (beg == nullptr) {
            beg = p;
        } else {
            pred->next = p;
        }
        pred = p;
    }
    file.close();
    return beg;
}


int main() {
    setlocale(LC_ALL, "rus");

    point *beg = nullptr;
    int oper;
    do {
        cout << "1.Создать список" << endl;
        cout << "2.Удалить элементы перед элементом с заданным номером" << endl;
        cout << "3.Вставка элементов" << endl;
        cout << "4.Вывод списка" << endl;
        cout << "5.Сохранение в файл" << endl;
        cout << "6.Загрузка из файла" << endl;
        cout << "0.Выход" << endl;
        cin >> oper;
        switch (oper) {
            case 1: {
                int n;
                cout << "Кол-во эл-тов списка = ";
                cin >> n;
                beg = make_point(n);
                print(beg);
                break;
            }
            case 2: {
                print(beg);
                int number;
                int k;
                cout << "Введите номер: ";
                cin >> number;
                cout << "Введите количество: ";
                cin >> k;
                beg = delete_element(beg, k, number);
                print(beg);
                break;
            }
            case 3: {
                print(beg);
                int k;
                cout << "Сколько эл-тов добавить: ";
                cin >> k;
                beg = add_elements(beg, k);
                print(beg);
                break;
            }
            case 4: {
                print(beg);
                break;
            }

            case 5: {
                char filename[200];
                cout << "Введите название файла: ";
                cin >> filename;
                save_to_file(beg, filename);
                free_list(&beg);
                print(beg);
                break;
            }
            case 6: {
                char filename[200];
                cout << "Введите название файла: ";
                cin >> filename;
                beg = read_file(filename);
                print(beg);
                break;
            }
            default: {
                break;
            }
        }
        if (oper != 0) {}
    } while (oper != 0);
    {
        free_list(&beg);
    }

    return 0;
}

