#include <iostream>
#include <string>
#include <cctype>
#include <clocale>  // Заменил <locale.h> на <clocale>
#include <fstream>
#include "Header.h"

using namespace std;

// Конструкторы и деструктор
String::String() : str("") {}
String::String(const char* s) : str(s) {}
String::String(const String& other) : str(other.str) {}
String::~String() {}
String& String::operator=(const String& other) {
    if (this != &other) {
        str = other.str;
    }
    return *this;
}

void String::setStr(const string& newStr) {
    if (newStr.empty()) {
        throw invalid_argument("Строка не может быть пустой");
    }
    str = newStr;
}

void String::concat(const String* other, int count) {
    for (int i = 0; i < count; i++) {
        if (!other[i].getStr().empty()) {
            str += other[i].str;
        } else {
            cout << "Пустая строка пропущена в concat." << endl; // Отладка
        }
    }
}

void String::concat_ws(const String* other, const string& separator, int count) {
    string result = str; // Начинаем с текущей строки
    bool firstNonEmpty = true;  // Флаг для отслеживания первой непустой строки
    for (int i = 0; i < count; i++) {
        if (!other[i].getStr().empty()) {
            if (!firstNonEmpty) {
                result += separator;  // Добавляем разделитель перед всеми строками, кроме первой
            }
            result += other[i].getStr();
            firstNonEmpty = false;
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
    } else {
        str.clear();
    }
}

void String::rtrim() {
    size_t end = str.find_last_not_of(' ');
    if (end != string::npos) {
        str = str.substr(0, end + 1);
    } else {
        str.clear();
    }
}

const string& String::getStr() const {
    return str;
}

void String::writeToFile(const char* filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << str << endl;
        file.close();
    } else {
        cout << "Ошибка открытия файла." << endl;
    }
}

void vvod(String* arr, int count) {
    string input;
    cout << "Введите количество строк:" << endl;
    while (true) {
        getline(cin, input);
        bool znacki = false;
        for (int i = 0; i < input.size(); i++) {
            if (ispunct(input[i]) || isspace(input[i])) {
                znacki = true;
            }
        }
        if (znacki) {
            cout << "Число должно быть не дробное:)" << endl;
            continue;
        }
        try {
            count = stoi(input);
            if (count <= 0) throw invalid_argument("Количество строк должно быть целым, положительным");
            break;
        } catch (const exception& e) {
            cout << "Некорректный ввод. Введите целое, положительное число: " << endl;
        }
    }

    // Динамическое выделение памяти
    String* strings = new String[count];

    // Ввод строк с проверкой на пустые строки
    for (int i = 0; i < count; i++) {
        cout << "Введите строку " << i + 1 << ": ";
        getline(cin, input);
        if (input.empty() || input.find_first_not_of(' ') == string::npos) {
            cout << "Строка не может быть пустой или состоять только из пробелов. Повторите ввод." << endl;
            i--;  // Повторяем ввод для текущей строки
            continue;
        }
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
        arr[i].writeToFile("C:\\Users\\Ignat\\Desktop\\Шестопалов Игнат Романович\\ООПиП\\Лаба 1\\newtxt.txt");
    }

    // Логика объединения строк
    if (count > 1) {
        string input;
        int l;
        cout << "Сделайте выбор (1-объединение без разделителя/2-объединение с разделителем): ";
        while (true) {
            getline(cin, input);
            bool znacki = false;
            for (int i = 0; i < input.size(); i++) {
                if (ispunct(input[i]) || isspace(input[i])) {
                    znacki = true;
                }
            }
            if (znacki) {
                cout << "Число должно быть не дробное и должно быть числом:)" << endl;
                continue;
            }
            try {
                l = stoi(input);
                if (l != 1 && l != 2) throw invalid_argument("Выберите 1 или 2");
                break;
            } catch (const exception& e) {
                cout << "Некорректный ввод. Введите целое число: " << endl;
            }
        }

        String result = arr[0];  // Используем arr напрямую
        if (l == 1) {
            result.concat(arr + 1, count - 1);
            cout << "Объединение без разделителя: ";
        } else if (l == 2) {
            result.concat_ws(arr + 1, " ", count - 1);
            cout << "Объединение с разделителем ' ': ";
        }
        result.print();
        result.writeToFile("C:\\Users\\Ignat\\Desktop\\Шестопалов Игнат Романович\\ООПиП\\Лаба 1\\newtxt.txt");
    }
}

void sort(String* arr, int count) {
    if (count <= 0) {
        cout << "Нет данных для сортировки:)" << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (arr[j].getStr() > arr[j + 1].getStr()) {
                String temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Строки отсортированы по алфавиту." << endl;
}