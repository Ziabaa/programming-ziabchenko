# Лабораторна робота №22-cpp: Вступ до Стандартної бібліотеки шаблонів STL 

## Вимоги:

**Розробник**: Зябченко Іван КН-922а

**Завдання**:  Поширити попередню лабораторну роботу таким чином:
```
    Поширити реалізацію лабораторної роботи "Поліморфірзм" наступним шляхом:
    * замінити масив та CRUD (create/read/update/delete) методи роботи з ним на використання STL
    * для предметної галузі з розділу Розрахункове завдання / Iндивідуальні завдання реалізувати/оновити всі методи роботи з колекцією на використання функцій STL
    * додати функцію сортування коллекції з використанням функтора
    * додати функцію об'єднання двох класів-списків
```
## Опис програми:

### Функціональне призначення

Програма дає змогу виводити структуру до консолі та записувати її у файл, також зчитувати сруктуру із файлу, рахувати кількість робітників певної компанії без наявності страховки. Може сортувати структуру за певною ознакою.

### Призначення та опис структури розроблених методів констант та змінних

**Опис функцій:**
1. `int main ( )` Точка входу в програму. Демонстрація рішення. Повертає: код помилки 0.


2. `void sortProgrammer(string fieldName, vector<Programmer> &enter)`, функція сортування програмістів за полем

**Аргументи:**

* fieldName параметр за яким сортувати.
* vector<Programmer> &enter сама колекція

**Повертає:**

Нічого не повертає.

3. `void sortColleague(string fieldName, vector<Colleague> &enter)`, функція сортування колег за полем

**Аргументи:**

* fieldName параметр за яким сортувати.
* vector<Colleague> &enter сама колекція

**Повертає:**

Нічого не повертає.

4. `void sortTranslator(string fieldName, vector<Translator> &enter)`, функція сортування перекладачів за полем

**Аргументи:**

* fieldName параметр за яким сортувати.
* vector<Translator> &enter сама колекція

**Повертає:**

Нічого не повертає.

5. `size_t findCountColleagueInCompany_WithoutInsurance(string company, vector<Colleague> enter);`, рахує кількість співробітників певної компанії без навності страховки.

**Аргументи:**

* company - компанія в якій шукаємо.
* vector<Programmer> &enter - коллекція в якій шукаємо.

**Повертає:**

Кількість співробітників певної компанії без навності страховки.

5. `vector<Programmer> findProgrammerInCompany_WithMiddleLev_and_WorkExperMoreThenOneYear(vector<Programmer> &enter)`, шукає програмістів з рівнем Middle та досвідом роботи більше 1 року.

**Аргументи:**

* vector<Programmer> &enter - коллекція в якій шукаємо.

**Повертає:**

Коллекцію програмістів з рівнем Middle та досвідом роботи більше 1 року.

5. `vector<Translator> findTranslatorInCompany_WithSincTranslate_and_WorkExperMoreThenFiveYear(vector<Translator> &enter)`, шукає перекладачів з можливістю синхронного перекладу та досвідом роботи більше 5 років.

**Аргументи:**

* vector<Programmer> &enter - коллекція в якій шукаємо.

**Повертає:**

Коллекцію перекладачів з можливістю синхронного перекладу та досвідом роботи більше 5 років.

6. `template <typename T> vector<T> merge(vector<T> &first, vector<T> &second)`, об'єднує два класи-списки

**Аргументи:**

* vector<T> &first - перша коллекція для об'єднання.
* vector<T> &second - друга коллекція для об'єднання.

**Повертає:**

Коллекцію об'єднанних двох класів-списків.

**Витоки памяті:**

За допомогою утиліти `leak-check`, перевірено та підтвердженно, що витоки відсутні.

### Структура прогами
```
.
├── doc
│   └── lab22-cpp.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── main.cpp
│   ├── colleague.hpp
│   └── list.hpp
└── test
    └── test.cpp
```

### Варіанти використання

- приклад виводу в консоль разом з тестами:

```
Find programmer in collection : 
0,next,3.5,N/A,N/A,N/A,0, 1, 1
0,rex,7.5,N/A,N/A,N/A,0, 1, 1
Not sorted collection : 
0,rex,12.4,N/A,N/A,N/A,0, 1, 2
0,next,3.5,N/A,N/A,N/A,0, 1, 1
0,fool,6.4,N/A,N/A,N/A,0, 1, 0
0,rex,7.5,N/A,N/A,N/A,0, 1, 1
0,next,9.5,N/A,N/A,N/A,0, 1, 0
0,fool,-6.4,N/A,N/A,N/A,0, 1, 1
After sort
0,fool,-6.4,N/A,N/A,N/A,0, 1, 1
0,next,3.5,N/A,N/A,N/A,0, 1, 1
0,fool,6.4,N/A,N/A,N/A,0, 1, 0
0,rex,7.5,N/A,N/A,N/A,0, 1, 1
0,next,9.5,N/A,N/A,N/A,0, 1, 0
0,rex,12.4,N/A,N/A,N/A,0, 1, 2
ASAN_OPTIONS=detect_leaks=1 LLVM_PROFILE_FILE="dist/test.profraw" dist/test.bin
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from programming_22_cpp
[ RUN      ] programming_22_cpp.sort_test
[       OK ] programming_22_cpp.sort_test (0 ms)
[ RUN      ] programming_22_cpp.find_test
[       OK ] programming_22_cpp.find_test (0 ms)
[ RUN      ] programming_22_cpp.merge_test
[       OK ] programming_22_cpp.merge_test (0 ms)
[----------] 3 tests from programming_22_cpp (2 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (3 ms total)
[  PASSED  ] 3 tests.
```
## Висновки

На цій лабораторній роботі ми дізналися про шаблонну бібліотеку STL та роботу з нею. Про особливості мови С++, та вдосконалили свої навички.

