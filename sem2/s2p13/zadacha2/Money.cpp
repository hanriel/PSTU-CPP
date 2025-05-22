#include "Money.h"
#include <iomanip>

Money::Money() : rub(0), cheers(0) {}

Money::Money(long r, int c) : rub(r), cheers(c) {
    // Нормализация копеек
    if (cheers >= 100 || cheers < 0) {
        rub += cheers / 100;
        cheers %= 100;
    }
    if (cheers < 0) {
        rub--;
        cheers += 100;
    }
}

Money::Money(const Money &m) : rub(m.rub), cheers(m.cheers) {}

Money::~Money() {}

long Money::getRub() const { return rub; }
int Money::getCheers() const { return cheers; }

void Money::setRub(long r) { rub = r; }
void Money::setCheers(int c) { cheers = c; }

Money &Money::operator=(const Money &m) {
    if (&m == this) return *this;
    rub = m.rub;
    cheers = m.cheers;
    return *this;
}

bool Money::operator==(const Money& other) const {
    return rub == other.rub && cheers == other.cheers;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

Money operator-(const Money &lhs, const Money &rhs) {
    long totalRub = lhs.rub - rhs.rub;
    int totalCheers = lhs.cheers - rhs.cheers;
    return Money(totalRub, totalCheers);
}

istream &operator>>(istream &in, Money &m) {
    cout << "Enter rubles: ";
    in >> m.rub;
    cout << "Enter kopecks: ";
    in >> m.cheers;
    // Нормализация при вводе
    if (m.cheers >= 100 || m.cheers < 0) {
        m.rub += m.cheers / 100;
        m.cheers %= 100;
    }
    if (m.cheers < 0) {
        m.rub--;
        m.cheers += 100;
    }
    return in;
}

ostream &operator<<(ostream &out, const Money &m) {
    return out << m.rub << "," << setfill('0') << setw(2) << m.cheers << " rub";
}

Money Money::operator+(const Money& money) const {
    long totalRub = rub + money.rub;
    int totalCheers = cheers + money.cheers;
    return Money(totalRub, totalCheers);
}

Money Money::operator/(int num) const {
    if (num == 0) throw runtime_error("Division by zero");
    long totalKop = rub * 100 + cheers;
    totalKop /= num;
    return Money(totalKop / 100, totalKop % 100);
}

bool Money::operator<(const Money& money) const {
    if (rub != money.rub) return rub < money.rub;
    return cheers < money.cheers;
}

// Реализация функций для работы со стеком
MoneyStack makeStack(int n) {
    MoneyStack s;
    for (int i = 0; i < n; ++i) {
        Money m;
        cin >> m;
        s.push(m);
    }
    return s;
}

void printStack(MoneyStack s) {
    cout << "Stack contents (top to bottom):" << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

void addMaxToEnd(MoneyStack& s) {
    if (s.empty()) return;
    
    // Создаем временный вектор для работы с элементами
    vector<Money> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }
    
    auto max_it = max_element(temp.begin(), temp.end());
    temp.push_back(*max_it);
    
    // Восстанавливаем стек
    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        s.push(*it);
    }
}

bool removeByValue(MoneyStack& s, const Money& key) {
    vector<Money> temp;
    bool found = false;
    
    while (!s.empty()) {
        if (s.top() == key && !found) {
            found = true;
            s.pop();
            continue;
        }
        temp.push_back(s.top());
        s.pop();
    }
    
    // Восстанавливаем стек
    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        s.push(*it);
    }
    
    return found;
}

Money calculateAverage(MoneyStack s) {
    if (s.empty()) throw runtime_error("Stack is empty");
    
    Money sum;
    int count = 0;
    
    while (!s.empty()) {
        sum = sum + s.top();
        count++;
        s.pop();
    }
    
    return sum / count;
}

void addAverageToElements(MoneyStack& s) {
    if (s.empty()) return;
    
    Money avg = calculateAverage(s);
    vector<Money> temp;
    
    while (!s.empty()) {
        temp.push_back(s.top() + avg);
        s.pop();
    }
    
    // Восстанавливаем стек
    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        s.push(*it);
    }
}