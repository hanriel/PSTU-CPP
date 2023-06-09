# Лабораторная работа № 5 - Наследование. Виртуальные функции. Полиморфизм.

## Цель работы

1. Создание консольного приложения, состоящего из нескольких файлов в системе
   программирования Visual Studio.
2. Создание иерархии классов с использованием простого наследования и абстрактного класса.
3. Изучение полиморфизма и виртуальных методов.

## Постановка задачи

1. Определить абстрактный класс.
2. Определить иерархию классов, в основе которой будет находиться абстрактный класс (см. лабораторную работу №4).
3. Определить класс Вектор, элементами которого будут указатели на объекты иерархии классов.
4. Перегрузить для класса Вектор операцию вывода объектов с помощью потоков.
5. В основной функции продемонстрировать перегруженные операции и полиморфизм Вектора.

> Базовый класс:
> ТРОЙКА_ЧИСЕЛ (TRIAD)
> Первое_число (first) - int
> Второе_число (second) – int
> Третье_число (third) - int
> Определить методы изменения полей и сравнения триады. Создать производный класс TIME с полями часы, минуты и секунды.
> Определить полный набор операций сравнения временных промежутков.

## Описание класса

```c++
class TIME : public Triad {
public:
    using Triad::Triad;

    void Show();//функция для просмотра атрибутов класса с помощью указателя
    bool operator==(const TIME &);

    bool operator!=(const TIME &);

    friend ostream &operator<<(ostream &, const TIME &);

    friend istream &operator>>(istream &, TIME &);
};
```

Программа имеет следующую UML-диаграмму:

![UML-Diagram][uml-diagram]

## Определение компонентных функций

```c++
ostream &operator<<(std::ostream &out, const TIME &t) {
    return out << t.first << ':' << t.second << ':' << t.third;
}

istream &operator>>(istream &in, TIME &t) {
    cout << "Hours: ";
    in >> t.first;
    cout << "Minutes: ";
    in >> t.second;
    cout << "Minutes: ";
    in >> t.third;
    return in;
}

void TIME::Show() {
    cout << "\nHOU : " << first;
    cout << "\nMIN : " << second;
    cout << "\nSEC : " << third;
    cout << "\n";
}
```

## Определение глобальных функций

```c++
bool TIME::operator==(const TIME &other) {
    return (
        this->first == other.first &&
        this->second == other.second &&
        this->third == other.third
    );
}

bool TIME::operator!=(const TIME &other) { return !(*this == other); }
```

## Функция main()

```c++
int main() {
    Array v(5); // Вектор из 5 элементов

    Triad a;
    cin >> a;

    TIME b;
    cin >> b;

    Object *p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);

    cout << v;
    return 0;
}
```

## Объяснение результатов работы программы

```c++
FIRST: 10
SECOND: 20
THIRD: 30

Hours: 10
Minutes: 20
Minutes: 30

FIRST : 10
SECOND : 20
THIRD : 30

HOU : 10
MIN : 20
SEC : 30
```

## Ответы на контрольные вопросы

### 1. Какой метод называется чисто виртуальным? Чем он отличается от виртуального метода?

**Ответ:** Чисто виртуальный метод содержит признак = 0 вместо тела, например:

```c++
virtual void f(int) = 0;
```

Чисто виртуальный метод должен переопределяться в производном классе (возможно,
опять как чисто виртуальный).

### 2. Какой класс называется абстрактным?

**Ответ:** Класс, содержащий хотя бы один чисто виртуальный метод, называется абстрактным.

### 3. Для чего предназначены абстрактные классы?

**Ответ:** Абстрактные классы предназначены для представления общих понятий, которые
предполагается конкретизировать в производных классах. Абстрактный класс может
использоваться только в качестве базового для других классов

### 4. Что такое полиморфные функции?

**Ответ:**

### 5. Чем полиморфизм отличается от принципа подстановки?

**Ответ:** Таким образом, можно создать функцию, параметром которой является указатель на
абстрактный класс. На место этого параметра при выполнении программы может передаваться
указатель на объект любого производного класса. Это позволяет создавать полиморфные
функции, работающие с объектом любого типа в пределах одной иерархии

### 6. Привести примеры иерархий с использованием абстрактных классов.

**Ответ:** Иерархия животных. Абстрактный класс Animal определяет базовые свойства и методы для всех животных:

```c++
class Animal {
public:
   virtual void eat() = 0;
   virtual void sleep() = 0;
   virtual void makeSound() = 0;
};
```

От этого класса можно наследовать более конкретные классы, такие как Cat, Dog, Elephant и т.д.:

```c++
class Cat : public Animal {
public:
   void eat() override { /* реализация */ }
   void sleep() override { /* реализация */ }
   void makeSound() override { /* реализация */ }
};

class Dog : public Animal {
public:
   void eat() override { /* реализация */ }
   void sleep() override { /* реализация */ }
   void makeSound() override { /* реализация */ }
};

class Elephant : public Animal {
public:
   void eat() override { /* реализация */ }
   void sleep() override { /* реализация */ }
   void makeSound() override { /* реализация */ }
};
```

### 7. Привести примеры полиморфных функций.

**Ответ:**
Функция вывода информации о животных

Полиморфная функция printInfo принимает указатель на объект класса Animal и выводит информацию о животном, используя
методы eat(), sleep() и makeSound():

```c++
void printInfo(Animal* animal) {
    animal->eat();
    animal->sleep();
    animal->makeSound();
}
```

Эта функция может быть вызвана для любого объекта класса, который наследует Animal

```c++
Cat cat;
Dog dog;
Elephant elephant;

printInfo(&cat);
printInfo(&dog);
printInfo(&elephant);
```

### 8. В каких случаях используется механизм позднего связывания?

**Ответ:** Механизм позднего связывания используется в случаях, когда необходимо работать с объектами разных классов,
которые имеют общий базовый класс, но могут иметь различную реализацию методов. Это позволяет вызывать методы объектов
на основе их реального типа, а не на основе типа указателя или ссылки на базовый класс. Таким образом, механизм позднего
связывания обеспечивает гибкость и расширяемость кода, позволяя добавлять новые классы, не изменяя существующий код.

---
Лабораторная работа доступна в GitHub репозитории [hanriel/PSTU-CPP](https://github.com/hanriel/PSTU-CPP/)

[uml-diagram]: ./assets/LAB5.svg "UML Diagram"
