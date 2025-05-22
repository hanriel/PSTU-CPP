#include <iostream>
#include <queue>
#include <cstdlib>
#include <stdexcept>
#include "Money.h"

using namespace std;

typedef queue<Money> Que;

// Create queue with random Money objects
Que make_queue(int n) {
    if (n <= 0) {
        throw invalid_argument("Queue size must be positive");
    }
    
    Que v;
    for (int i = 0; i < n; i++) {
        long rubles = rand() % 100 - 50;  // Random rubles (-50 to 49)
        int kopecks = rand() % 100;       // Random kopecks (0 to 99)
        Money a(rubles, kopecks);
        v.push(a);
    }
    return v;
}

// Print queue without modifying it
void print_queue(const Que &v) {
    Que tmp = v;
    while (!tmp.empty()) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

// Find maximum element and add it to the end
void add_max_to_end(Que &v) {
    if (v.empty()) {
        throw runtime_error("Queue is empty");
    }
    
    Que tmp = v;
    Money max_val = tmp.front();
    tmp.pop();
    
    while (!tmp.empty()) {
        if (tmp.front() > max_val) {
            max_val = tmp.front();
        }
        tmp.pop();
    }
    
    v.push(max_val);
}

// Remove first occurrence of element
bool remove_first_occurrence(Que &v, const Money &key) {
    Que tmp;
    bool found = false;
    bool removed = false;
    
    while (!v.empty()) {
        Money current = v.front();
        v.pop();
        
        if (!found && current == key) {
            found = true; // Skip first found element
            removed = true;
        } else {
            tmp.push(current); // Keep other elements
        }
    }
    
    v = tmp; // Restore queue
    return removed;
}

// Calculate average of all elements
Money get_average(const Que &v) {
    if (v.empty()) {
        throw runtime_error("Queue is empty");
    }
    
    Que tmp = v;
    Money sum;
    int count = 0;
    
    while (!tmp.empty()) {
        sum = sum + tmp.front();
        count++;
        tmp.pop();
    }
    
    return sum / count;
}

// Add average to each element
void add_average_to_elements(Que &v) {
    if (v.empty()) return;
    
    Money avg = get_average(v);
    Que tmp;
    
    while (!v.empty()) {
        tmp.push(v.front() + avg);
        v.pop();
    }
    
    v = tmp;
}

int main() {
    try {
        int n;
        cout << "Enter queue size N: ";
        cin >> n;
        
        Que v = make_queue(n);
        cout << "Queue: ";
        print_queue(v);

        // Task 3: Add max element to end
        add_max_to_end(v);
        cout << "Queue after adding max to end: ";
        print_queue(v);

        // Task 4: Remove element
        Money key;
        cout << "Enter money value to remove (format 'rubles.kopecks'): ";
        cin >> key;
        if (remove_first_occurrence(v, key)) {
            cout << "\nElement " << key << " removed. New queue: ";
            print_queue(v);
        } else {
            cout << "\nElement " << key << " not found." << endl;
        }

        // Task 5: Add average to each element
        add_average_to_elements(v);
        cout << "\nQueue after adding average to elements: ";
        print_queue(v);
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}