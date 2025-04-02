#include <iostream>
#include <string>
#include <clocale>  // Заменил <locale.h> на <clocale>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include "Header.h"
#include "Header_2.h"
#include "Header_3.h"

using namespace std;

// Функция для заполнения объекта пользователем
void fillObject(StringLab3& obj, const string& objName) {
    cout << "\nЗаполнение объекта " << objName << " (введите строки, для завершения введите 'done'):" << endl;
    while (true) {
        cout << "Введите строку (или 'done' для завершения):" << endl;
        string input;
        getline(cin, input);
        if (input == "done") {
            break;
        }
        // Проверяем, не пустая ли строка
        if (input.empty()) {
            cout << "Строка не должна быть пустой. Попробуйте снова." << endl;
            continue;
        }
        // Проверяем, состоит ли строка только из пробелов
        size_t start = input.find_first_not_of(" \t");
        if (start == string::npos) {
            cout << "Строка не должна быть пробельной. Попробуйте снова." << endl;
            continue;
        }
        // Обрезаем начальные и конечные пробелы
        size_t end = input.find_last_not_of(" \t");
        input = input.substr(start, end - start + 1);
        // Преобразуем буквы в нижний регистр
        for (char& c : input) {
            if (isalpha(c)) {
                c = tolower(c);
            }
        }
        // Добавляем обработанную строку в объект
        obj.addString(input);
        cout << objName << " теперь: " << obj << endl;
    }
}

int main() {
    system("chcp 65001");

    while (true) {
        cout << "Выберите номер лабораторной работы (1-8, 9 - выход): ";
        string input;
        int k;

        while (true) {
            cout << "Введите число: ";
            getline(cin, input);
            if (input.size() != 1) {
                continue;
            }
            try {
                k = stoi(input);
                break;
            } catch (const invalid_argument& ia) {
                cout << "Некорректный ввод. Введите целое число." << endl;
            } catch (const out_of_range& oor) {
                cout << "Число выходит за пределы диапазона для типа int." << endl;
            }
        }

        if (k == 1) {
            cout << "Лабораторная 1:" << endl;
            cout << "В КАЖДОМ ЗАДАНИИ НЕОБХОДИМО :" << endl;
            cout << "1. создать программу на языке С / С++, которая позволяет выбрать номер лабораторной работы семестра(1, 2, 3, 4…)," << endl;
            cout << "2. создать массив объектов указанных классов," << endl;
            cout << "3. считать данные объектов с клавиатуры" << endl;
            cout << "4. вывести данные объектов на экран и в файл" << endl;
            cout << "5. создать методы установки значений полей класса.Методы должны проверять корректность задаваемых параметров" << endl;
            cout << "6. создать конструктор с параметрами, конструктор без параметров, конструктор копирования, деструктор." << endl;
            cout << "" << endl;
            cout << "30. Создать класс String(строка).Создать в классе методы для работы со строками :" << endl;
            cout << "concat(объединяет строки, может объединять две и более строк)," << endl;
            cout << "concat_ws(объединяет строки, но в качестве одного из параметров принимает разделитель, который будет соединять строки), " << endl;
            cout << "length(возвращает количество символов в строке), ltrim(удаляет начальные пробелы в строке), rtrim(удаляет конечные пробелы в строке)." << endl;
            cout << "В класс добавить необходимый набор полей и методов(минимум два поля и два метода) на свое усмотрение." << endl;
            int count;
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

            String* strings = new String[count];

            vvod(strings, count);
            cout << "Строки после обработки:" << endl;
            vivod(strings, count);

            delete[] strings; // Освобождение памяти
        } else if (k == 2) {
            cout << "В КАЖДОМ ЗАДАНИИ НЕОБХОДИМО :" << endl;
            cout << "1. создать программу на языке С / С++, которая позволяет выбрать номер лабораторной работы семестра(1, 2, 3, 4…)," << endl;
            cout << "2. создать массив объектов указанных классов," << endl;
            cout << "3. считать данные объектов с клавиатуры" << endl;
            cout << "4. вывести данные объектов на экран и в файл" << endl;
            cout << "5. создать методы установки значений полей класса.Методы должны проверять корректность задаваемых параметров" << endl;
            cout << "6. создать конструктор с параметрами, конструктор без параметров, конструктор копирования, деструктор." << endl;
            cout << "" << endl;
            cout << "30. Создать два класса LinkedListInt (связанный список целых чисел) и \n"
                    "LinkedListString (связанный список строк) для хранения данных типа int и \n"
                    "строк соответственно. Методы добавляют элемент в список, удаляют элемент \n"
                    "из списка, выводят на экран элементы списка, находят элемент в списке. В \n"
                    "класс добавить необходимый набор полей и методов (минимум два поля и \n"
                    "два метода) на свое усмотрение." << endl;
            while(true){
                cout<< "Выберите int или string:" << endl;
                cout << "1-int" << endl;
                cout << "2-string" << endl;
                cout << "3-Выйти." << endl;
                string input_choose_all;  // Определяем переменную для ввода
                int choose_all;
                while (true) {
                    cout << "Введите число (1/2): ";
                    getline(cin, input_choose_all);  // Читаем в input_choose_all, а не в input
                    if (input_choose_all.empty()) {
                        cout << "Ввод не может быть пустым. Введите 1 или 2: " << endl;
                        continue;
                    }
                    bool hasInvalidChars = false;
                    for (size_t i = 0; i < input_choose_all.size(); i++) {
                        if (!isdigit(input_choose_all[i])) {  // Проверяем, что только цифры (1 или 2)
                            hasInvalidChars = true;
                            break;
                        }
                    }
                    if (hasInvalidChars) {
                        cout << "Некорректный ввод. Введите только 1 или 2 или 3: " << endl;
                        continue;
                    }
                    try {
                        choose_all = stoi(input_choose_all);
                        if (choose_all == 1 || choose_all == 2 || choose_all==3) {
                            break;  // Выходим, если введено 1 или 2
                        }
                        cout << "Некорректный ввод. Введите 1 или 2 или 3: " << endl;
                    } catch (const invalid_argument& ia) {
                        cout << "Некорректный ввод. Введите 1 или 2 или 3: " << endl;
                    } catch (const out_of_range& oor) {
                        cout << "Число выходит за пределы диапазона для типа int." << endl;
                    }
                }
                if (choose_all == 1) {
                    // Уникальные имена переменных для LinkedListInt
                    LinkedListInt int_list;  // Переименовали list в int_list
                    string input_choose_int;  // Переименовали input_choose_1 в input_choose_int
                    int choose_int;  // Переименовали choose_1 в choose_int
                    while (true) {
                        cout << "Выберите, что хотите сделать с целыми числами:" << endl;
                        cout << "1-Добавить в начало." << endl;
                        cout << "2-Добавить в конец." << endl;
                        cout << "3-Удалить элемент по индексу." << endl;
                        cout << "4-Вывести элементы." << endl;
                        cout << "5-Найти элемент по индексу." << endl;
                        cout << "6-Вернуться." << endl;
                        cout << "Введите число (1-6): ";
                        while (true) {
                            getline(cin, input_choose_int);
                            if (input_choose_int.empty()) {
                                cout << "Ввод не может быть пустым. Введите целое число от 1 до 6: " << endl;
                                continue;
                            }
                            bool hasInvalidChars = false;
                            for (size_t i = 0; i < input_choose_int.size(); i++) {
                                if (!isdigit(input_choose_int[i])) {
                                    hasInvalidChars = true;
                                    break;
                                }
                            }
                            if (hasInvalidChars) {
                                cout << "Некорректный ввод. Введите только цифры от 1 до 6: " << endl;
                                continue;
                            }
                            try {
                                choose_int = stoi(input_choose_int);
                                if (choose_int < 1 || choose_int > 6) {
                                    cout << "Некорректный ввод. Введите число от 1 до 6: " << endl;
                                    continue;
                                }
                                break;
                            } catch (const invalid_argument& ia) {
                                cout << "Некорректный ввод. Введите целое число от 1 до 6: " << endl;
                            } catch (const out_of_range& oor) {
                                cout << "Число выходит за пределы диапазона для типа int." << endl;
                            }
                        }

                        if (choose_int == 1) {
                            string input_value_int;
                            cout << "Введите число, которое хотите добавить в начало: " << endl;
                            while (true) {
                                getline(cin, input_value_int);
                                if (input_value_int.empty()) {
                                    cout << "Ввод не может быть пустым. Введите целое число: " << endl;
                                    continue;
                                }
                                bool hasInvalidChars = false;
                                for (size_t i = 0; i < input_value_int.size(); i++) {
                                    if (!isdigit(input_value_int[i]) && input_value_int[i] != '-') {
                                        hasInvalidChars = true;
                                        break;
                                    }
                                }
                                if (hasInvalidChars) {
                                    cout << "Некорректный ввод. Введите только целое число (с возможным минусом): " << endl;
                                    continue;
                                }
                                try {
                                    int value = stoi(input_value_int);
                                    int_list.addIntFront(value);
                                    break;
                                } catch (const invalid_argument& ia) {
                                    cout << "Некорректный ввод. Введите целое число: " << endl;
                                } catch (const out_of_range& oor) {
                                    cout << "Число выходит за пределы диапазона для типа int." << endl;
                                }
                            }
                        } else if (choose_int == 2) {
                            string input_value_int;
                            cout << "Введите число, которое хотите добавить в конец: " << endl;
                            while (true) {
                                getline(cin, input_value_int);
                                if (input_value_int.empty()) {
                                    cout << "Ввод не может быть пустым. Введите целое число: " << endl;
                                    continue;
                                }
                                bool hasInvalidChars = false;
                                for (size_t i = 0; i < input_value_int.size(); i++) {
                                    if (!isdigit(input_value_int[i]) && input_value_int[i] != '-') {
                                        hasInvalidChars = true;
                                        break;
                                    }
                                }
                                if (hasInvalidChars) {
                                    cout << "Некорректный ввод. Введите только целое число (с возможным минусом): " << endl;
                                    continue;
                                }
                                try {
                                    int value = stoi(input_value_int);
                                    int_list.addIntBack(value);
                                    break;
                                } catch (const invalid_argument& ia) {
                                    cout << "Некорректный ввод. Введите целое число: " << endl;
                                } catch (const out_of_range& oor) {
                                    cout << "Число выходит за пределы диапазона для типа int." << endl;
                                }
                            }
                        } else if (choose_int == 3) {
                            string input_index_int;
                            cout << "Введите индекс для удаления (0 и выше): " << endl;
                            while (true) {
                                getline(cin, input_index_int);
                                if (input_index_int.empty()) {
                                    cout << "Ввод не может быть пустым. Введите целое число (0 и выше): " << endl;
                                    continue;
                                }
                                bool hasInvalidChars = false;
                                for (size_t i = 0; i < input_index_int.size(); i++) {
                                    if (!isdigit(input_index_int[i])) {
                                        hasInvalidChars = true;
                                        break;
                                    }
                                }
                                if (hasInvalidChars) {
                                    cout << "Некорректный ввод. Введите только целое положительное число: " << endl;
                                    continue;
                                }
                                try {
                                    int index = stoi(input_index_int);
                                    if (index < 0) {
                                        cout << "Индекс не может быть отрицательным." << endl;
                                        continue;
                                    }
                                    int_list.deleteIntPerIndex(index);
                                    break;
                                } catch (const exception& e) {
                                    cout << "Некорректный ввод. Введите целое число: " << endl;
                                }
                            }
                        } else if (choose_int == 4) {
                            int_list.LinkedListIntPrint();
                        } else if (choose_int == 5) {
                            string input_index_int;
                            cout << "Введите индекс для поиска (0 и выше): " << endl;
                            while (true) {
                                getline(cin, input_index_int);
                                if (input_index_int.empty()) {
                                    cout << "Ввод не может быть пустым. Введите целое число (0 и выше): " << endl;
                                    continue;
                                }
                                bool hasInvalidChars = false;
                                for (size_t i = 0; i < input_index_int.size(); i++) {
                                    if (!isdigit(input_index_int[i])) {
                                        hasInvalidChars = true;
                                        break;
                                    }
                                }
                                if (hasInvalidChars) {
                                    cout << "Некорректный ввод. Введите только целое положительное число: " << endl;
                                    continue;
                                }
                                try {
                                    int index = stoi(input_index_int);
                                    if (index < 0) {
                                        cout << "Индекс не может быть отрицательным." << endl;
                                        continue;
                                    }
                                    int_list.searchIntPerIndex(index);
                                    break;
                                } catch (const exception& e) {
                                    cout << "Некорректный ввод. Введите целое число: " << endl;
                                }
                            }
                        } else if (choose_int == 6) {
                            cout << "Произошёл выход." << endl;
                            break;
                        }
                    }
                } else if (choose_all == 2) {
                    // Уникальные имена переменных для LinkedListString
                    LinkedListString str_list;  // Переименовали list в str_list
                    string input_choose_str;  // Переименовали input_choose_1 в input_choose_str
                    int choose_str;  // Переименовали choose_1 в choose_str
                    while (true) {
                        cout << "Выберите, что хотите сделать со строками:" << endl;
                        cout << "1-Добавить в начало." << endl;
                        cout << "2-Добавить в конец." << endl;
                        cout << "3-Удалить элемент по индексу." << endl;
                        cout << "4-Вывести элементы." << endl;
                        cout << "5-Найти элемент по индексу." << endl;
                        cout << "6-Вернуться." << endl;
                        cout << "Введите число (1-6): ";
                        while (true) {
                            getline(cin, input_choose_str);
                            if (input_choose_str.empty()) {
                                cout << "Ввод не может быть пустым. Введите целое число от 1 до 6: " << endl;
                                continue;
                            }
                            bool hasInvalidChars = false;
                            for (size_t i = 0; i < input_choose_str.size(); i++) {
                                if (!isdigit(input_choose_str[i])) {
                                    hasInvalidChars = true;
                                    break;
                                }
                            }
                            if (hasInvalidChars) {
                                cout << "Некорректный ввод. Введите только цифры от 1 до 6: " << endl;
                                continue;
                            }
                            try {
                                choose_str = stoi(input_choose_str);
                                if (choose_str < 1 || choose_str > 6) {
                                    cout << "Некорректный ввод. Введите число от 1 до 6: " << endl;
                                    continue;
                                }
                                break;
                            } catch (const invalid_argument& ia) {
                                cout << "Некорректный ввод. Введите целое число от 1 до 6: " << endl;
                            } catch (const out_of_range& oor) {
                                cout << "Число выходит за пределы диапазона для типа int." << endl;
                            }
                        }

                        if (choose_str == 1) {
                            string input_value_str;
                            cout << "Введите строку, которую хотите добавить в начало: " << endl;
                            getline(cin, input_value_str);
                            if (input_value_str.empty()) {
                                cout << "Ввод не может быть пустым. Введите строку: " << endl;
                                continue;
                            }
                            str_list.addStringFront(input_value_str);
                        } else if (choose_str == 2) {
                            string input_value_str;
                            cout << "Введите строку, которую хотите добавить в конец: " << endl;
                            getline(cin, input_value_str);
                            if (input_value_str.empty()) {
                                cout << "Ввод не может быть пустым. Введите строку: " << endl;
                                continue;
                            }
                            str_list.addStringBack(input_value_str);
                        } else if (choose_str == 3) {
                            string input_index_str;
                            cout << "Введите индекс для удаления (0 и выше): " << endl;
                            while (true) {
                                getline(cin, input_index_str);
                                if (input_index_str.empty()) {
                                    cout << "Ввод не может быть пустым. Введите целое число (0 и выше): " << endl;
                                    continue;
                                }
                                bool hasInvalidChars = false;
                                for (size_t i = 0; i < input_index_str.size(); i++) {
                                    if (!isdigit(input_index_str[i])) {
                                        hasInvalidChars = true;
                                        break;
                                    }
                                }
                                if (hasInvalidChars) {
                                    cout << "Некорректный ввод. Введите только целое положительное число: " << endl;
                                    continue;
                                }
                                try {
                                    int index = stoi(input_index_str);
                                    if (index < 0) {
                                        cout << "Индекс не может быть отрицательным." << endl;
                                        continue;
                                    }
                                    str_list.deleteStringPerIndex(index);
                                    break;
                                } catch (const exception& e) {
                                    cout << "Некорректный ввод. Введите целое число: " << endl;
                                }
                            }
                        } else if (choose_str == 4) {
                            str_list.printAllListString();
                        } else if (choose_str == 5) {
                            string input_index_str;
                            cout << "Введите индекс для поиска (0 и выше): " << endl;
                            while (true) {
                                getline(cin, input_index_str);
                                if (input_index_str.empty()) {
                                    cout << "Ввод не может быть пустым. Введите целое число (0 и выше): " << endl;
                                    continue;
                                }
                                bool hasInvalidChars = false;
                                for (size_t i = 0; i < input_index_str.size(); i++) {
                                    if (!isdigit(input_index_str[i])) {
                                        hasInvalidChars = true;
                                        break;
                                    }
                                }
                                if (hasInvalidChars) {
                                    cout << "Некорректный ввод. Введите только целое положительное число: " << endl;
                                    continue;
                                }
                                try {
                                    int index = stoi(input_index_str);
                                    if (index < 0) {
                                        cout << "Индекс не может быть отрицательным." << endl;
                                        continue;
                                    }
                                    str_list.searchStringPerIndex(index);
                                    break;
                                } catch (const exception& e) {
                                    cout << "Некорректный ввод. Введите целое число: " << endl;
                                }
                            }
                        } else if (choose_str == 6) {
                            cout << "Произошёл выход." << endl;
                            break;
                        }
                    }
                }
                else if(choose_all==3){
                    break;
                }


            }
        } else if (k == 3) {
            cout << "Лабораторная 3:"
                    "30. Реализовать класс String для работы со строками. Создать методы \n"
                    "доступа к полям класса. Перегрузить в классе операторы сравнивания строки \n"
                    "«<», «>», «!=», «+=» (дозапись в конец строки, append). Реализовать \n"
                    "конструкторы (по умолчанию, с параметрами, копирования), деструктор. \n"
                    "Реализовать friend-функции для операторов ввода/вывода в поток для \n"
                    "созданного класса." << endl;
            // Главная функция программы
            StringLab3 s1;                                     // Создаём пустой объект s1
            StringLab3 s2;                                     // Создаём пустой объект s2
            StringLab3 s3;                                     // Создаём пустой объект s3

            // Заполняем объекты вручную
            cout << "Давайте заполним объекты s1, s2 и s3." << endl;
            fillObject(s1, "s1");
            fillObject(s2, "s2");
            fillObject(s3, "s3");


            // Переходим к интерактивному меню
            int choiceStrLab3;
            string input_choose_str;
            while (true) {
                cout << "\n=== Меню программы ===" << endl;
                cout << "1. Ввести новую строку в объект" << endl;
                cout << "2. Вывести содержимое объекта" << endl;
                cout << "3. Сравнить два объекта (<, >, !=)" << endl;
                cout << "4. Добавить строку ко всем строкам объекта (+=)" << endl;
                cout << "5. Получить размер массива строк" << endl;
                cout << "6. Выход" << endl;
                cout << "Выберите действие (1-6): ";
                while (true) {
                    getline(cin, input_choose_str);
                    if (input_choose_str.empty()) {
                        cout << "Ввод не может быть пустым. Введите целое число от 1 до 6: " << endl;
                        continue;
                    }
                    bool hasInvalidChars = false;
                    for (size_t i = 0; i < input_choose_str.size(); i++) {
                        if (!isdigit(input_choose_str[i])) {
                            hasInvalidChars = true;
                            break;
                        }
                    }
                    if (hasInvalidChars) {
                        cout << "Некорректный ввод. Введите только цифры от 1 до 6: " << endl;
                        continue;
                    }
                    try {
                        choiceStrLab3 = stoi(input_choose_str);
                        if (choiceStrLab3 < 1 || choiceStrLab3 > 6) {
                            cout << "Некорректный ввод. Введите число от 1 до 6: " << endl;
                            continue;
                        }
                        break;
                    } catch (const invalid_argument &ia) {
                        cout << "Некорректный ввод. Введите целое число от 1 до 6: " << endl;
                    } catch (const out_of_range &oor) {
                        cout << "Число выходит за пределы диапазона для типа int." << endl;
                    }
                }
                if (choiceStrLab3 == 1) {
                    cout<< "Выберите где хотите изменить(1 - s1, 2 - s2, 3 - s3):" << endl;
                    int chooseStrLab3_choice1;
                    string input_choose_str_choice1;
                    while (true) {
                        getline(cin, input_choose_str_choice1);
                        if (input_choose_str_choice1.empty()) {
                            cout << "Ввод не может быть пустым. Введите целое число от 1 до 3: " << endl;
                            continue;
                        }
                        bool hasInvalidChars = false;
                        for (size_t i = 0; i < input_choose_str_choice1.size(); i++) {
                            if (!isdigit(input_choose_str_choice1[i])) {
                                hasInvalidChars = true;
                                break;
                            }
                        }
                        if (hasInvalidChars) {
                            cout << "Некорректный ввод. Введите только цифры от 1 до 3: " << endl;
                            continue;
                        }
                        try {
                            chooseStrLab3_choice1 = stoi(input_choose_str_choice1);
                            if (chooseStrLab3_choice1 < 1 || chooseStrLab3_choice1 > 3) {
                                cout << "Некорректный ввод. Введите число от 1 до 3: " << endl;
                                continue;
                            }
                            break;
                        } catch (const invalid_argument &ia) {
                            cout << "Некорректный ввод. Введите целое число от 1 до 3: " << endl;
                        } catch (const out_of_range &oor) {
                            cout << "Число выходит за пределы диапазона для типа int." << endl;
                        }
                    }
                    cin.clear();
                    if(chooseStrLab3_choice1==1){
                        // Ввод новой строки
                        cout << "Ввод строки в объект s1:" << endl;
                        cin >> s1;
                    }
                    else if(chooseStrLab3_choice1==2){
                        // Ввод новой строки
                        cout << "Ввод строки в объект s2:" << endl;
                        cin >> s2;
                    }
                    else if(chooseStrLab3_choice1==3){
                        // Ввод новой строки
                        cout << "Ввод строки в объект s3:" << endl;
                        cin >> s3;
                    }

                }
                else if (choiceStrLab3 == 2) {
                    cout<< "Выберите выберите что вы хотите вывести(1 - s1, 2 - s2, 3 - s3):" << endl;
                    int chooseStrLab3_choice1;
                    string input_choose_str_choice1;
                    while (true) {
                        getline(cin, input_choose_str_choice1);
                        if (input_choose_str_choice1.empty()) {
                            cout << "Ввод не может быть пустым. Введите целое число от 1 до 3: " << endl;
                            continue;
                        }
                        bool hasInvalidChars = false;
                        for (size_t i = 0; i < input_choose_str_choice1.size(); i++) {
                            if (!isdigit(input_choose_str_choice1[i])) {
                                hasInvalidChars = true;
                                break;
                            }
                        }
                        if (hasInvalidChars) {
                            cout << "Некорректный ввод. Введите только цифры от 1 до 3: " << endl;
                            continue;
                        }
                        try {
                            chooseStrLab3_choice1 = stoi(input_choose_str_choice1);
                            if (chooseStrLab3_choice1 < 1 || chooseStrLab3_choice1 > 3) {
                                cout << "Некорректный ввод. Введите число от 1 до 3: " << endl;
                                continue;
                            }
                            break;
                        } catch (const invalid_argument &ia) {
                            cout << "Некорректный ввод. Введите целое число от 1 до 3: " << endl;
                        } catch (const out_of_range &oor) {
                            cout << "Число выходит за пределы диапазона для типа int." << endl;
                        }
                    }
                    if (chooseStrLab3_choice1 == 1) {
                        cout << "s1: " << s1 << endl;
                    } else if (chooseStrLab3_choice1 == 2) {
                        cout << "s2: " << s2 << endl;
                    } else if (chooseStrLab3_choice1 == 3) {
                        cout << "s3: " << s3 << endl;
                    } else {
                        cout << "Ошибка: выберите 1, 2 или 3." << endl;
                    }
                }
                else if (choiceStrLab3 == 3) {
                    // Сравнение двух объектов
                    cout << "Сравнение s1 и s2:" << endl;
                    cout << "s1 < s2: " << (s1 < s2 ? "true" : "false") << endl;
                    cout << "s1 > s2: " << (s1 > s2 ? "true" : "false") << endl;
                    cout << "s1 != s2: " << (s1 != s2 ? "true" : "false") << endl;
                }
                else if (choiceStrLab3 == 4) {
                    cout << "Выберите объект для изменения (1 - s1, 2 - s2, 3 - s3): ";
                    int chooseStrLab3_choice1;
                    string input_choose_str_choice1;
                    while (true) {
                        getline(cin, input_choose_str_choice1);
                        if (input_choose_str_choice1.empty()) {
                            cout << "Ввод не может быть пустым. Введите целое число от 1 до 3: " << endl;
                            continue;
                        }
                        bool hasInvalidChars = false;
                        for (size_t i = 0; i < input_choose_str_choice1.size(); i++) {
                            if (!isdigit(input_choose_str_choice1[i])) {
                                hasInvalidChars = true;
                                break;
                            }
                        }
                        if (hasInvalidChars) {
                            cout << "Некорректный ввод. Введите только цифры от 1 до 3: " << endl;
                            continue;
                        }
                        try {
                            chooseStrLab3_choice1 = stoi(input_choose_str_choice1);
                            if (chooseStrLab3_choice1 < 1 || chooseStrLab3_choice1 > 3) {
                                cout << "Некорректный ввод. Введите число от 1 до 3: " << endl;
                                continue;
                            }
                            break;
                        } catch (const invalid_argument &ia) {
                            cout << "Некорректный ввод. Введите целое число от 1 до 3: " << endl;
                        } catch (const out_of_range &oor) {
                            cout << "Число выходит за пределы диапазона для типа int." << endl;
                        }
                    }
                    cout << "Введите строку для добавления:" << endl;
                    StringLab3 temp;
                    cin.clear();
                    cin >> temp;
                    if (chooseStrLab3_choice1 == 1) {
                        s1 += temp;
                        cout << "s1 после добавления: " << s1 << endl;
                    } else if (chooseStrLab3_choice1 == 2) {
                        s2 += temp;
                        cout << "s2 после добавления: " << s2 << endl;
                    } else if (chooseStrLab3_choice1 == 3) {
                        s3 += temp;
                        cout << "s3 после добавления: " << s3 << endl;
                    } else {
                        cout << "Ошибка: выберите 1, 2 или 3." << endl;
                    }
                }
                else if (choiceStrLab3 == 5) {
                    cout << "Выберите объект для изменения (1 - s1, 2 - s2, 3 - s3): ";
                    int chooseStrLab3_choice1;
                    string input_choose_str_choice1;
                    while (true) {
                        getline(cin, input_choose_str_choice1);
                        if (input_choose_str_choice1.empty()) {
                            cout << "Ввод не может быть пустым. Введите целое число от 1 до 3: " << endl;
                            continue;
                        }
                        bool hasInvalidChars = false;
                        for (size_t i = 0; i < input_choose_str_choice1.size(); i++) {
                            if (!isdigit(input_choose_str_choice1[i])) {
                                hasInvalidChars = true;
                                break;
                            }
                        }
                        if (hasInvalidChars) {
                            cout << "Некорректный ввод. Введите только цифры от 1 до 3: " << endl;
                            continue;
                        }
                        try {
                            chooseStrLab3_choice1 = stoi(input_choose_str_choice1);
                            if (chooseStrLab3_choice1 < 1 || chooseStrLab3_choice1 > 3) {
                                cout << "Некорректный ввод. Введите число от 1 до 3: " << endl;
                                continue;
                            }
                            break;
                        } catch (const invalid_argument &ia) {
                            cout << "Некорректный ввод. Введите целое число от 1 до 3: " << endl;
                        } catch (const out_of_range &oor) {
                            cout << "Число выходит за пределы диапазона для типа int." << endl;
                        }
                    }

                    if (chooseStrLab3_choice1 == 1) {
                        cout << "Размер s1: " << s1.getSize() << endl;
                    } else if (chooseStrLab3_choice1 == 2) {
                        cout << "Размер s2: " << s2.getSize() << endl;
                    } else if (chooseStrLab3_choice1 == 3) {
                        cout << "Размер s3: " << s3.getSize() << endl;
                    } else {
                        cout << "Ошибка: выберите 1, 2 или 3." << endl;
                    }

                }
                else if (choiceStrLab3 == 6) {
                    cout << "Произошёл выход." << endl;
                    break;
                }


            }


        } else if (k == 4) {
            cout << "Лабораторная 4:" << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 5) {
            cout << "Лабораторная 5:" << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 6) {
            cout << "Лабораторная 6:" << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 7) {
            cout << "Лабораторная 7:" << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 8) {
            cout << "Лабораторная 8:" << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 9) {
            cout << "Произошёл выход." << endl;
            return 0;
        } else {
            cout << "Вы ввели неверное значение." << endl;
        }
    }
}