#include <iostream>
#include <string>
#include <cctype>
#include <locale.h>
#include <fstream>
#include "Header.h"
#include "inputCheck.h"

using namespace std;
using namespace mylib;

//конструкторы
String::String(): str(""){}
String::String(const char *s): str(s) {}
String::String(const String& other): str(other.str) {}
//деструктор
String::~String(){}
//конструктор копирования
String& String::operator=(const String& other) {
    if (this != &other) {
        str = other.str;
    }
    return *this;
}
void String::concat(const String* other, int count) {
    for (int i = 0; i < count; i++) {
        if (!other[i].getStr().empty()) { // Проверяем, не пуста ли строка
            str += other[i].str;
        } else {
            cout << "Пустая строка пропущена в concat." << endl; // Отладка
        }
    }
}

void String::concat_ws(const String* other, const string& razdel, int count) {
    string result = str; // Начинаем с текущей строки
    for (int i = 0; i < count; i++) {
        if (!other[i].getStr().empty()) { // Проверяем, не пуста ли строка
            result += razdel;
            result += other[i].str;
        } else {
            cout << "Пустая строка пропущена в concat_ws." << endl; // Отладка
        }
    }
    str = result; // Присваиваем результат обратно в str
}

int String::length() const {
    return str.length();
}

void String::print() const {
    cout << str << endl;
}

void String::ltrim() {
    size_t start = str.find_first_not_of(' ');
    if (start != string::npos) {
        str = str.substr(start);
        cout << "После ltrim: " << str << endl; // Отладка
    }
    else {
        str.clear();
        cout << "Строка после ltrim стала пустой." << endl; // Отладка
    }
}

void String::rtrim() {
    size_t end = str.find_last_not_of(' ');
    if (end != string::npos) {
        if (end + 1 <= str.length()) { // Проверка на корректность
            str = str.substr(0, end + 1);
        } else {
            cout << "Ошибка: Некорректная длина строки после rtrim." << endl;
        }
    }
    else {
        str.clear(); // Если строка состоит только из пробелов, очищаем её
    }
}

// Метод для получения строки
const string& String::getStr() const {
    return str;
}

// Запись строки в файл
void String::writeToFile(const char* filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << str << endl;
        file.close();
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
}

void vvod(String* arr, int count) {
    // Динамическое выделение памяти
    String* strings = new String[count];

    // Ввод строк
    for (int i = 0; i < count; i++) {
        string input = checkTryToInputString(false); // Ввод строки (без кириллицы)
        strings[i] = String(input.c_str());
        cout << "До обработки (сырой ввод): '" << input << "'" << endl;

        strings[i].rtrim();
        strings[i].ltrim();
        cout << "После обработки: '" << strings[i].getStr() << "'" << endl;
    }

    // Копируем данные в arr (параметр функции)
    for (int i = 0; i < count; i++) {
        arr[i] = strings[i];
    }

    delete[] strings;  // Освобождаем память
}

void vivod(const String* arr, int count) {
    if (count <= 0) {
        cout << "Нет данных для вывода:)" << endl;
        return;
    }
    cout << "Список строк:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Строка " << i + 1 << ": ";
        arr[i].print();
    }
    cout << "Вывод завершён." << endl;
    for (int i = 0; i < count; i++) {
        arr[i].writeToFile("output.txt"); // Изменили путь на более универсальный
    }

    // Логика объединения строк
    if (count > 1) {
        int l = checkYourSolution(2); // Выбор типа объединения (1-2)

        String result = arr[0];  // Используем arr напрямую
        if (l == 1) {
            result.concat(arr + 1, count - 1);
            cout << "Объединение без разделителя: ";
        } else if (l == 2) {
            result.concat_ws(arr+1 , " ", count - 1);
            cout << "Объединение с разделителем ' ': ";
        }
        result.print();
        result.writeToFile("output.txt");
    }
}