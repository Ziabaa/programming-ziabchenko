# Лабораторна робота №15: Структуровані типи данних 

## Вимоги:

**Розробник**: Зябченко Іван КН-922а

**Завдання**: з розділу Індивідуальні завдання комплексної роботи взяти прикладну галузь стосовно номеру варіанту за попередньо-визначеною формулою створити структуру, що відображає "базовий клас"
Поля базового класу:

    07. Співробітник
    * Наявність страхування (наприклад: так, ні)
    * Назва компанії (наприклад: “Epam”, “NIX Solution”, “Google”)
    * Досвід роботи, років (наприклад: 0, 2, 10)
    * Контактні дані (структура, що містить прізвище, ім’я та електронну пошту співробітника)
    * Характеристики (декілька з переліку: впевнений, стресо-стійкий, цілеспрямований, організований)
    Методи для роботи з колекцією:
    - Визначити кількість співробітників компанії “Google” без наявності страхування
    - Pозробити функцію, яка читає дані (масив елементів) з файлу;
    - Pозробити функцію, яка записує дані (масив елементів) у файл;
    - Pозробити функцію, яка виводить масив елементів на екран;
    - Pозробити функцію, яка буде сортувати масив елементів за заданим критерієм (полем);


## Опис програми:

### Функціональне призначення

Програма дає змогу виводити структуру до консолі та записувати її у файл, також зчитувати сруктуру із файлу, рахувати кількість робітників певної компанії без наявності страховки. Може сортувати структуру за певною ознакою.

### Призначення та опис структури розроблених методів констант та змінних

**Опис функцій:**
1. `int main ( )` Точка входу в програму. Демонстрація рішення. Повертає: код помилки 0.


2. `void printCharacteristicColleague(enum Characters character);`, виводить певну характеристику списку.

**Аргументи:**

* enum Characters character - характеристика списку яку потрібно вивести 

**Повертає:**

Функція `void` не повертає значення.

3. `size_t findCountColleagueInCompany_WithoutInsurance(struct Workers * workers, char * company);`, рахує кількість співробітників певної компанії без навності страховки.

**Аргументи:**

* company - компанія в якій шукаємо
* workers - співробітники серед яких шуаємо

**Повертає:**

Кількість співробітників певної компанії без навності страховки.

4. `struct Workers * readColleagueFromFile(char * filename);`, зчитує параметри з файлу, та записує їх до стркутури. Сама виділяє пам'ять під структуру!  

**Аргументи:**

* char * file_name - розташування файлу з якого будуть зчитані структури.

**Повертає:**

Структру зі зчитаними параметрами записаних у файлі.

5. `void writeColleagueToFile(char * filename, struct Workers * workers);`, записує у файл структуру.

**Аргументи:**

* char * file_name - розташування файлу в який потрібно записати структуру.
* struct Workers * workers- структура яку записуємо.

**Повертає:**

Функція `void` не повертає значення.

6. `void printColleague(struct Workers * workers);`, виводить на екран структуру.

**Аргументи:**

* struct Workers * workers - структура яку виводити до консолі.

**Повертає:**

Функція `void` не повертає значення.

7. `void sortColleague(struct Workers * workers, char * fieldName);`, сортує структуру за певним полем.

**Аргументи:**

* struct Workers * workers - структура яку потрібно відсторувати.
* char * fieldName - поле за яким сортувати.

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
│   └── lab15.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── main.c
│   ├── colleague.c
│   └── colleague.h
└── test
    └── test.c

```

### Варіанти використання

- приклад виводу в консоль:

```
Worker №0:
Have insurance: No
Name company: Google
Work experience: 2.30 years
Contact information:
	Name: Ivan
	Surname: Teplyi
	Email: dev-good@lal.com
Characteristic of the employee: confident

Worker №1:
Have insurance: No
Name company: NIX
Work experience: 6.00 years
Contact information:
	Name: leo
	Surname: Pender
	Email: lesly-gerd@lal.com
Characteristic of the employee: stress_resistant

Worker №2:
Have insurance: No
Name company: Google
Work experience: 0.30 years
Contact information:
	Name: Dany
	Surname: Abraham
	Email: abraham1998@lal.com
Characteristic of the employee: purposeful

Count colleagues in company Google: 2
```
## Висновки

На цій лабораторній роботі ми удосконалили свої знання з показчиками та динамічною пам'ятю, взаємодію з користувачем шляхом механізму введення/виведення, строками, файлами, дізналися та отримали корисні навички з роботи із структурами на мові С.

