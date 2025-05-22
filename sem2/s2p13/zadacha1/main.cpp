#include "Money.h"
#include "StackAdapter.h"
#include <iostream>

using namespace std;

int main() {
    try {
        // 1. Создание стека
        int n;
        cout << "Enter stack size: ";
        cin >> n;
        StackAdapter<Money> moneyStack = makeStack(n);
        
        cout << "\nOriginal stack:" << endl;
        moneyStack.print();

        // 2. Добавление максимального элемента
        addMaxToEnd(moneyStack);
        cout << "\nAfter adding max to end:" << endl;
        moneyStack.print();

        // 3. Удаление элемента
        Money key;
        cout << "\nEnter money value to remove: ";
        cin >> key;
        if (removeByValue(moneyStack, key)) {
            cout << "Element removed. New stack:" << endl;
            moneyStack.print();
        } else {
            cout << "Element not found!" << endl;
        }

        // 4. Добавление среднего
        addAverageToElements(moneyStack);
        cout << "\nAfter adding average to elements:" << endl;
        moneyStack.print();

        // 5. Поиск элемента
        cout << "\nEnter money value to search: ";
        cin >> key;
        auto& cont = moneyStack.getContainer();
        auto found = find(cont.begin(), cont.end(), key);
        if (found != cont.end()) {
            cout << "Element found: " << *found << endl;
        } else {
            cout << "Element not found!" << endl;
        }

        // 6. Подсчет элементов
        cout << "\nEnter money value to count: ";
        cin >> key;
        int cnt = count(cont.begin(), cont.end(), key);
        cout << "Found " << cnt << " elements" << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}