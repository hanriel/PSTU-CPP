///
// ### Задача 2.
// 1. Создать адаптер контейнера.
// 2. Заполнить его элементами пользовательского типа (Вектор). Для пользовательского типа перегрузить необходимые операции.
// 3. Найти максимальный элемент и добавить его в конец контейнера (использовать алгоритмы replace_if(), replace_copy(), replace_copy_if(), fill()).
// 4. Найти элемент с заданным ключом и удалить его из контейнера (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
// 5. К каждому элементу добавить среднее арифметическое элементов контейнера.
// 6. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы find(), find_if(), count(), count_if()).
// 7. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()) .
// 8. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.
///
#include "Money.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    try {
        // 1. Создание стека
        int n;
        cout << "Enter stack size: ";
        cin >> n;
        MoneyStack moneyStack = makeStack(n);
        
        cout << "\nOriginal stack:" << endl;
        printStack(moneyStack);

        // 2. Добавление максимального элемента
        addMaxToEnd(moneyStack);
        cout << "\nAfter adding max to end:" << endl;
        printStack(moneyStack);

        // 3. Удаление элемента
        Money key;
        cout << "\nEnter money value to remove: ";
        cin >> key;
        if (removeByValue(moneyStack, key)) {
            cout << "Element removed. New stack:" << endl;
            printStack(moneyStack);
        } else {
            cout << "Element not found!" << endl;
        }

        // 4. Добавление среднего
        addAverageToElements(moneyStack);
        cout << "\nAfter adding average to elements:" << endl;
        printStack(moneyStack);

        // 5. Поиск элемента
        cout << "\nEnter money value to search: ";
        cin >> key;
        
        // Для поиска временно копируем стек в вектор
        vector<Money> temp;
        MoneyStack copyStack = moneyStack;
        while (!copyStack.empty()) {
            temp.push_back(copyStack.top());
            copyStack.pop();
        }
        
        auto found = find(temp.begin(), temp.end(), key);
        if (found != temp.end()) {
            cout << "Element found: " << *found << endl;
        } else {
            cout << "Element not found!" << endl;
        }

        // 6. Подсчет элементов
        cout << "\nEnter money value to count: ";
        cin >> key;
        int cnt = count(temp.begin(), temp.end(), key);
        cout << "Found " << cnt << " elements" << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}