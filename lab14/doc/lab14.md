# Лабораторна робота №14: Взаємодія з файлами 

## Вимоги:

**Розробник**: Зябченко Іван КН-922а

**Завдання**: Розробити програму, що в заданому файлі створює суцільний рівнобедрений трикутник із заданих символів (наприклад, зірочок). Висота трикутника, символ заповнювача та ширина основи задається у вхідному файлу.


## Опис програми:

### Функціональне призначення

Програма дає змогу вивести у консоль та записати у файл, піраміду яка задана параметрами що знаходяться у вхідному файлі

### Призначення та опис структури розроблених методів констант та змінних

**Опис функцій:**
1. `int main ( )` Точка входу в програму. Демонстрація рішення. Повертає: код помилки 0. Виводить та записує у файл: піраміду ща заданими параметрами.


2. `void write_to_file(char * file_name, char * text, char * mode);`, Записує потрібну строку до файлу з вибором режиму запису.

**Аргументи:**

* char * file_name - розташування файлу
* char * text - текст який потрібно записати у файл
* char * mode - режим додавання чи записування

**Повертає:**

Функція `void` не повертає значення.

3. `void read_from_file (char * file_name, int * x, int * y);`, Читає висоту та ширину піраміди, потім записує їх у задані змінні за адресою.

**Аргументи:**

* char * file_name - розташування файлу
* int * x - перше прочитане число 
* int * y - друге прочитане число 

**Повертає:**

Функція `void` не повертає значення.

4. `void print_pyramid(char * file_name, int width, int height);`, виводить піраміду до консолі та записує її до заданого файлу

**Аргументи:**

* char * file_name - розташування файлу в який потрібно замаоювати піраміду.
* int width - ширина піраміди
* int height - висота піраміди

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
│   └── lab14.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── main.c
│   ├── matrix.c
│   └── matrix.h
└── test
    └── test.c

```

### Варіанти використання

- приклад виводу в консоль при заданих значеннях 5 і 9:

```
    *
   ***
  *****
 *******
*********
```
## Висновки

На цій лабораторній роботі ми удосконалили свої знання з показчиками та динамічною пам'ятю, взаємодію з користувачем шляхом механізму введення/виведення, строками, дізналися та отримали корисні навички з роботи із файлами на мові С.

