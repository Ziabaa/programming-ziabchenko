# Лабораторна робота №17-cpp: Вступ до ООП 

## Вимоги:

**Розробник**: Зябченко Іван КН-922а

**Завдання**: Для предметної галузі з розділу Розрахункове завдання / Iндивідуальні завдання розробити два класи.
```
* Клас, що відображає сутність "базового класу", у тому числі:
    -конструктор за замовчуванням, копіювання та конструктор з аргументами (реалізація конструкторів повинна бути продемонстрована за допомогою списків ініціалізацій);
    -деструктор;
    -гетери та сетери на поля класу;
    -метод виводу об'єкта на екран;
*Клас, що має у собі динамічний масив об’єктів базового класу та має в собі методи додавання, видалення елемента, отримання елемента по індексу (або ідентифікатору), вивід усіх елементів на екран. Рекомендовані сигнатури методів:
    -додавання;
    -видалення;
    -отримання по індексу;
    -виведення усіх елементів;
    -метод 1 обходу колекції. 

```
## Опис програми:

### Функціональне призначення

Програма дає змогу виводити структуру до консолі та записувати її у файл, також зчитувати сруктуру із файлу, рахувати кількість робітників певної компанії без наявності страховки. Може сортувати структуру за певною ознакою.

### Призначення та опис структури розроблених методів констант та змінних

**Опис функцій:**
1. `int main ( )` Точка входу в програму. Демонстрація рішення. Повертає: код помилки 0.


2. `void Colleague::printMe()const;`, метод виводу об'єкта на екран.

**Аргументи:**

* Use one`s parameter;

**Повертає:**

Функція `void` не повертає значення.

3. `size_t Workers::findCountColleagueInCompany_WithoutInsurance(const char * company) const;`, метод 1 обходу колекції, рахує кількість співробітників певної компанії без навності страховки.

**Аргументи:**

* company - компанія в якій шукаємо.

**Повертає:**

Кількість співробітників певної компанії без навності страховки.

4. `struct Workers * readColleagueFromFile(char * filename);`, зчитує параметри з файлу, та записує їх до стркутури. Сама виділяє пам'ять під структуру!  

**Аргументи:**

* char * file_name - розташування файлу з якого будуть зчитані структури.

**Повертає:**

Структру зі зчитаними параметрами записаних у файлі.

5. `void writeToFile(char * filename) const;`,  метод запису у файл структуру.

**Аргументи:**

* char * file_name - розташування файлу в який потрібно записати структуру.

**Повертає:**

Функція `void` не повертає значення.

6. ` void print() const;`, метод виводення на екран структуру.

**Аргументи:**

* Use one`s parameter;

**Повертає:**

Функція `void` не повертає значення.

7. `void sort(const char * fieldName);;`, метод сортування.

**Аргументи:**

* fieldName - поле за яким сортувати.

**Повертає:**

Функція `void` не повертає значення.

8. 
```
    bool getInsurance() const;
	char * getNameCompany()const;
	float getWorkExperience() const;
	char * getSurname() const;
	char * getNameColleague() const;
	char * getEmail() const;
	int getEmployCharacteristic() const;
```
Гетери елементів структури.

**Аргументи:**

* Use one`s parameter.

**Повертає:**

Зпрошений елемент.

9. `void Colleague::writeMe(FILE *file) const;`, метод запису у файл.

**Аргументи:**

* FILE *file - відкритий файл у який записати.

**Повертає:**

Функція `void` не повертає значення.

10. `Colleague* parseColleague(char * line);`, зчитує одну строку у робить з неї одну готову структуру.

**Аргументи:**

* char * line - сторка яку зчитуємо.

**Повертає:**

Структуру коллеги.

11. `void Workers::delElement(size_t pos);`, метод видалення.

**Аргументи:**

*  size_t pos - позиція в якій видаляємо.

**Повертає:**

Функція `void` не повертає значення.
12. `void Workers::addElement(size_t pos, const Colleague *colleague);`, метод додавання.

**Аргументи:**

* size_t pos - позиція в яку додаємо.
* const Colleague *colleague - колега якого додаємо.

**Повертає:**

Функція `void` не повертає значення.

**Витоки памяті:**

За допомогою утиліти `leak-check`, перевірено та підтвердженно, що витоки відсутні.

### Структура прогами
```
.
├── assets
│   └── input.txt
├── doc
│   └── lab17-cpp.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── main.cpp
│   ├── colleague.cpp
│   └── colleague.h
│   └── worker.cpp
│   └── worker.h
└── test
    └── test.cpp

```

### Варіанти використання

- приклад виводу в консоль разом з тестами:

```
Worker without insurance in company Google: 2
Have insurance: Yes
Name company: Microsoft
Work experience: 2.00 years
Contact information:
	Name: Teplyi
	Surname: Ivan
	Email: dev-good@lal.com
Characteristic of the employee: confident

Have insurance: No
Name company: Google
Work experience: 3.60 years
Contact information:
	Name: Teplyi
	Surname: Ivan
	Email: dev-good@lal.com
Characteristic of the employee: confident

Have insurance: No
Name company: Google
Work experience: 6.80 years
Contact information:
	Name: Teplyi
	Surname: Ivan
	Email: dev-good@lal.com
Characteristic of the employee: confident

ASAN_OPTIONS=detect_leaks=1 LLVM_PROFILE_FILE="dist/test.profraw" dist/test.bin
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from programming_17_cpp
[ RUN      ] programming_17_cpp.sort_test
[       OK ] programming_17_cpp.sort_test (0 ms)
[ RUN      ] programming_17_cpp.find_withoutInsursnce_test
[       OK ] programming_17_cpp.find_withoutInsursnce_test (0 ms)
[----------] 2 tests from programming_17_cpp (26 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (56 ms total)
[  PASSED  ] 2 tests.
```
## Висновки

На цій лабораторній роботі ми дізналися як переходити на мову С++, її особливості, та вдосконалили свої навички.

