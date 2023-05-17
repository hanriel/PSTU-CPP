# Лабораторная работа № 4 - Простое наследование. Принцип подстановки.

## Цель работы

1. Создание консольного приложения, состоящего из нескольких файлов в системе
программирования Visual Studio.
2. Создание иерархии классов с использованием простого наследования.
3. Изучение принципа подстановки.

## Постановка задачи

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами,
копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей
данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Определить производный класс.
8. Написать программу, в которой продемонстрировать создание объектов и работу
всех перегруженных операций.
9. Реализовать функции, получающие и возвращающие объект базового класса.
Продемонстрировать принцип подстановки.

>Базовый класс:
>    ТРОЙКА_ЧИСЕЛ (TRIAD)
>    Первое_число (first) - int
>    Второе_число (second) – int
>    Третье_число (third) - int
>Определить методы изменения полей и сравнения триады. Создать производный класс TIME с полями часы, минуты и секунды. Определить полный набор операций сравнения временных промежутков.

## Описание класса


## Определение компонентных функций
```
// Constructors and destructor
Triad::Triad(void) { first = 0; second = 0; third = 0; }
Triad::Triad(int f, int s, int t) { first = f; second = s; third = t; }
Triad::Triad(const Triad& triad) { first = triad.first; second = triad.second; third = triad.third; }
Triad::~Triad(void) { }

// Setters
void Triad::setFirst(int f) { first = f; }
void Triad::setSecond(int s) { second = s; }
void Triad::setThird(int t) { third = t; }

// Getters
int Triad::getFirst() { return first; }
int Triad::getSecond() { return second; }
int Triad::getThird() { return third; }

Triad &Triad::operator = (const Triad &t) {
    if(&t == this) return *this;
    first = t.first;
    second = t.second;
    third = t.third;
}

istream &operator >> (istream &in, Triad &c) {
    cout << "FIRST: "; in>>c.first;
    cout << "SECOND: "; in>>c.second;
    cout << "THIRD: "; in>>c.third;
    return in;
}

ostream &operator << (ostream &out, Triad &c) {
    out << "\nFIRST : " << c.first;
    out << "\nSECOND : " << c.second;
    out << "\nTHIRD : " << c.third;
    out << "\n";
    return out;
}

bool operator < (const Triad &lhs, const Triad &rhs) {
    return lhs.first == rhs.first ? lhs.second == rhs.second ?
            lhs.third < rhs.third :
            lhs.second < rhs.second :
            lhs.first < rhs.first;
}
 
bool operator == (const Triad &lhs, const Triad &rhs) {
    return lhs.first == rhs.first &&
        lhs.second == rhs.second &&
        lhs.third == rhs.third;
}
```
```
bool TIME::operator!=(const Triad &other) {
    return !(*this == other);
}
```

## Определение глобальных функций
```
ostream &operator<<(std::ostream &out, const TIME &t) {
    return out << t.first << ':' << t.second << ':' << t.third;
}

istream &operator>>(istream &in, TIME &t) {
    cout << "Hours: "; in >> t.first;
    cout << "Minutes: "; in >> t.second;
    cout << "Minutes: "; in >> t.third;
    return in;
}
```
```
//Функция принимает обект базавого класса как параметр
void f1(Triad &t){
    t.setFirst(0);
}

//Функция возвращает обект базавого класса
Triad f2(){
    TIME t(12, 30, 0);
    return t;
}
```

## Функция main()
```
int main() {
    // Работа с классом TRIAD
    Triad a;
    cin >> a;
    cout << a;

    Triad b(12, 30, 45);
    cout << b;
    a=b;
    cout << a;

    // Работа с классом TIME
    TIME t;
    cin >> t;
    cout << t;

    // Принцип подстановки
    f1(t);
    a = f2();
    cout << a;

    return 0;
}
```


## Объяснение результатов работы программы


## Ответы на контрольные вопросы
### 1. Для чего используется механизм наследования?
**Ответ:** 

### 2. Каким образом наследуются компоненты класса, описанные со спецификатором public?
**Ответ:** 

### 3. Каким образом наследуются компоненты класса, описанные со спецификатором private?
**Ответ:** 

### 4. Каким образом наследуются компоненты класса, описанные со спецификатором protected?
**Ответ:** 

### 5. Каким образом описывается производный класс?
**Ответ:** 

### 6. Наследуются ли конструкторы?
**Ответ:** 

### 7. Наследуются ли деструкторы?
**Ответ:** 

### 8. В каком порядке конструируются объекты производных классов?
**Ответ:** 

### 9. В каком порядке уничтожаются объекты производных классов?
**Ответ:** 

### 10. Что представляют собой виртуальные функции и механизм позднего связывания?
**Ответ:** 

### 11. Могут ли быть виртуальными конструкторы? Деструкторы?
**Ответ:** 

### 12. Наследуется ли спецификатор virtual?
**Ответ:** 

### 13. Какое отношение устанавливает между классами открытое наследование?
**Ответ:** 

### 14. Какое отношение устанавливает между классами закрытое наследование?
**Ответ:** 

### 15. В чем заключается принцип подстановки?
**Ответ:** 

### 16. Имеется иерархия классов:
```
class Student {
    int age;
public:
    string name;
    ...
};

class Employee : public Student {
protected:
    string post;
    ...
};

class Teacher : public Employee {
protected:
    int stage;
    ...
};
Teacher x;
```
Какие компонентные данные будет иметь объект х?

**Ответ:**

### 17. Для классов Student, Employee и Teacher написать конструкторы без параметров.
**Ответ:** 

### 18. Для классов Student, Employee и Teacher написать конструкторы с параметрами.
**Ответ:** 

### 19. Для классов Student, Employee и Teacher написать конструкторы копирования.
**Ответ:** 

### 20. Для классов Student, Employee и Teacher определить операцию присваивания.
**Ответ:** 
