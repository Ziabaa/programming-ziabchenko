# Лабораторна робота №18-cpp: Потоки 

## Вимоги:

**Розробник**: Зябченко Іван КН-922а

**Завдання**:  Поширити попередню лабораторну роботу таким чином:
```
    * використання функцій printf/scanf замінити на використання cin/cout;
    * усі конкатенації рядків замінити на використання stringstream;
    * усі строки типу char * замінити на std::string;
    * замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформацію про об’єкт, який далі можна виводити на екран;
    * замінити метод вводу інформації про об’єкт на метод, що приймає рядок з інформацією про об’єкт, обробляє його та створює об’єкт на базі цієї інформації
    * поширити клас-список, шляхом реалізації методів роботи з файлами за допомогою файлових потоків (fstream) (якщо використовувалися функції fprintf/fscanf – замінити їх на класи ifsteam/ofstream),
```
## Опис програми:

### Функціональне призначення

Програма дає змогу виводити структуру до консолі та записувати її у файл, також зчитувати сруктуру із файлу, рахувати кількість робітників певної компанії без наявності страховки. Може сортувати структуру за певною ознакою.

### Призначення та опис структури розроблених методів констант та змінних

**Опис функцій:**
1. `int main ( )` Точка входу в програму. Демонстрація рішення. Повертає: код помилки 0.


2. `string Colleague::toString();`, метод створення строки з інформацією про об'ект.

**Аргументи:**

* Use one`s parameter;

**Повертає:**

string - строка з інформацією про об'єкт.

3. `size_t Workers::findCountColleagueInCompany_WithoutInsurance(string company) const;`, метод 1 обходу колекції, рахує кількість співробітників певної компанії без навності страховки.

**Аргументи:**

* company - компанія в якій шукаємо.

**Повертає:**

Кількість співробітників певної компанії без навності страховки.

4. `Workers * readColleagueFromFile(string filename);`, зчитує параметри з файлу, та записує їх до стркутури. Сама виділяє пам'ять під структуру!  

**Аргументи:**

* file_name - розташування файлу з якого будуть зчитані структури.

**Повертає:**

Структру зі зчитаними параметрами записаних у файлі.

5. `void Workers::writeToFile(string filename) const;`,  метод запису у файл структуру.

**Аргументи:**

* file_name - розташування файлу в який потрібно записати структуру.

**Повертає:**

Функція `void` не повертає значення.

6. ` void print() const;`, метод виводення на екран структуру.

**Аргументи:**

* Use one`s parameter;

**Повертає:**

Функція `void` не повертає значення.

7. `void Workers::sort(string fieldName);`, метод сортування.

**Аргументи:**

* fieldName - поле за яким сортувати.

**Повертає:**

Функція `void` не повертає значення.

8. 
```
    bool getInsurance() const;
	const string& getNameCompany()const;
	float getWorkExperience() const;
	const string& getSurname() const;
	const string& getNameColleague() const;
	const string& getEmail() const;
	int getEmployCharacteristic() const;
```
Гетери елементів структури.

**Аргументи:**

* Use one`s parameter.

**Повертає:**

Зпрошений елемент.

9. `void Colleague::writeMe(ofstream& file) const;`, метод запису у файл.

**Аргументи:**

* file - відкритий поток у який записати.

**Повертає:**

Функція `void` не повертає значення.

10. `Colleague* parseColleague(const string& inputLine);`, зчитує одну строку у робить з неї одну готову структуру.

**Аргументи:**

* inputLine - сторка яку зчитуємо.

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
│   └── lab18-cpp.md
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
Work experience: 2 years
Contact information:
	Name: Teplyi
	Surname: Ivan
	Email: dev-good@lal.com
Employ Characteristic: confident

Have insurance: No
Name company: Google
Work experience: 3.6 years
Contact information:
	Name: Teplyi
	Surname: Ivan
	Email: dev-good@lal.com
Employ Characteristic: confident

Have insurance: No
Name company: Google
Work experience: 6.8 years
Contact information:
	Name: Teplyi
	Surname: Ivan
	Email: dev-good@lal.com
Employ Characteristic: confident

ASAN_OPTIONS=detect_leaks=1 LLVM_PROFILE_FILE="dist/test.profraw" dist/test.bin
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from programming_17_cpp
[ RUN      ] programming_18_cpp.sort_test
[       OK ] programming_18_cpp.sort_test (0 ms)
[ RUN      ] programming_18_cpp.find_withoutInsursnce_test
[       OK ] programming_18_cpp.find_withoutInsursnce_test (0 ms)
[ RUN      ] programming_18_cpp.parse_str_test
[       OK ] programming_18_cpp.parse_str_test (0 ms)
[----------] 3 tests from programming_18_cpp (2 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (4 ms total)
[  PASSED  ] 3 tests.
```
## Висновки

На цій лабораторній роботі ми дізналися про потоки та роботу з ними. Про особливості мови С++, та вдосконалили свої навички.

