# Лабораторна робота №18-cpp: Шаблонні функції та класи  

## Вимоги:

**Розробник**: Зябченко Іван КН-922а

**Завдання**:  Поширити попередню лабораторну роботу таким чином:
```
    * Зробити шаблоний клас-список (на базі динамічного масиву), що має шаблоноване поле масиву (для будь-якого існуючого типу даних)
    * Створити наступні методи:
    - вивод вмісту масиву на екран;
    - визначити індекс переданого елемента в заданому масиві;
    - відсортувати елементи масиву;
    - визначити значення мінімального елемента масиву;
    - додати елемент до кінця масиву;
    - видалити елемент з масиву за індексом.
```
## Опис програми:

### Функціональне призначення

Програма дає змогу виводити шаблонний клас до консолі та сортувати її, також має декілька потрібних методів дя роботи.

### Призначення та опис структури розроблених методів констант та змінних

**Опис функцій:**
1. `int main ( )` Точка входу в програму. Демонстрація рішення. Повертає: код помилки 0.


2. `T getElement(size_t pos);`, гетер для елементу певної позиції.

**Аргументи:**

* pos - позиція в якій брати елемент;

**Повертає:**

T - шаблонний тип.

3. `void print() const;`, метод виводу на екран.

**Аргументи:**

* Use one`s parameter;

**Повертає:**

Функція `void` не повертає значення.

4. `size_t getIndex(T val);`, знаходить індекс по полю. 

**Аргументи:**

* T val - яке поле шукаємо.

**Повертає:**

Позицію знайденого елемента .

5. `void delElementPos(size_t pos);`, метод видалення по позиції.

**Аргументи:**

*  size_t pos - позиція в якій видаляємо.

**Повертає:**

Функція `void` не повертає значення.

6. `void addToEnd(T pole);`, метод додавання в кінець.

**Аргументи:**

* size_t pos - позиція в яку додаємо.

**Повертає:**

Функція `void` не повертає значення.

**Витоки памяті:**

За допомогою утиліти `leak-check`, перевірено та підтвердженно, що витоки відсутні.

### Структура прогами
```
.
├── doc
│   └── lab21-cpp.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── list.hpp
│   └── main.cpp
└── test
    └── test.cpp
```

### Варіанти використання

- приклад виводу в консоль:

```
List: --> f    a    k    m    n    q
Index 'a' -> 1
Sorted list:  a    f    k    m    n    q
```
## Висновки

На цій лабораторній роботі ми дізналися про шаблонні функції та роботу з ними, про особливості мови С++, та вдосконалили свої навички.

