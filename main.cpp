#include <iostream>
#include <string>
#include <locale>
#include <locale.h>
#include <clocale>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <windows.h>
#include "Header.h"
#include "Header_2.h"
#include "Header_3.h"
#include "Header_4.h"
#include "Header_5.h"
#include "Header_6.h"
#include "inputCheck.h"
#include "generate.h"

using namespace std;
using namespace mylib;
using namespace generate;

#include <clocale>
#include <locale>

#if defined(_WIN32)
#include <windows.h>
#endif
void setupRussLocale() {
#if defined(_WIN32)

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("rus_rus.1251"));
#else
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());
#endif
}

// Функция для заполнения объекта пользователем
void fillObject(StringLab3& obj, const string& objName) {
    cout << "\nЗаполнение объекта " << objName << endl;
    string input = checkTryToInputString(false); // Запрещаем кириллицу
    obj.addString(input);
    cout << objName << " теперь: " << obj << endl;
}

int main() {

    while (true) {
        cout << "Выберите номер лабораторной работы (1-9, 10 - выход): ";
        int k = checkYourSolution(10); // Выбор номера лабораторной работы (1-9)

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

            int count = checkTryToInputMaxSizeOfSmth(); // Ввод количества строк

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
            while (true) {
                cout << "Выберите int или string:" << endl;
                cout << "1-int" << endl;
                cout << "2-string" << endl;
                cout << "3-Выйти." << endl;
                int choose_all = checkYourSolution(

                        3); // Выбор типа данных (1-3)

                if (choose_all == 1) {
                    LinkedListInt int_list;
                    while (true) {
                        cout << "Выберите, что хотите сделать с целыми числами:" << endl;
                        cout << "1-Добавить в начало." << endl;
                        cout << "2-Добавить в конец." << endl;
                        cout << "3-Удалить элемент по индексу." << endl;
                        cout << "4-Вывести элементы." << endl;
                        cout << "5-Найти элемент по индексу." << endl;
                        cout << "6-Вернуться." << endl;
                        int choose_int = checkYourSolution(6); // Выбор действия (1-6)

                        if (choose_int == 1) {
                            int value = checkTryToInputInt(); // Ввод числа
                            int_list.addIntFront(value);
                        } else if (choose_int == 2) {
                            int value = checkTryToInputInt(); // Ввод числа
                            int_list.addIntBack(value);
                        } else if (choose_int == 3) {
                            int index = checkTryToInputInt(); // Ввод индекса
                            if (index < 0) {
                                cout << "Индекс не может быть отрицательным." << endl;
                                continue;
                            }
                            int_list.deleteIntPerIndex(index);
                        } else if (choose_int == 4) {
                            int_list.LinkedListIntPrint();
                        } else if (choose_int == 5) {
                            int index = checkTryToInputInt(); // Ввод индекса
                            if (index < 0) {
                                cout << "Индекс не может быть отрицательным." << endl;
                                continue;
                            }
                            int_list.searchIntPerIndex(index);
                        } else if (choose_int == 6) {
                            cout << "Произошёл выход." << endl;
                            break;
                        }
                    }
                } else if (choose_all == 2) {
                    LinkedListString str_list;
                    while (true) {
                        cout << "Выберите, что хотите сделать со строками:" << endl;
                        cout << "1-Добавить в начало." << endl;
                        cout << "2-Добавить в конец." << endl;
                        cout << "3-Удалить элемент по индексу." << endl;
                        cout << "4-Вывести элементы." << endl;
                        cout << "5-Найти элемент по индексу." << endl;
                        cout << "6-Вернуться." << endl;
                        int choose_str = checkYourSolution(6); // Выбор действия (1-6)

                        if (choose_str == 1) {
                            string value = checkTryToInputString(false); // Ввод строки (без кириллицы)
                            str_list.addStringFront(value);
                        } else if (choose_str == 2) {
                            string value = checkTryToInputString(false); // Ввод строки (без кириллицы)
                            str_list.addStringBack(value);
                        } else if (choose_str == 3) {
                            int index = checkTryToInputInt(); // Ввод индекса
                            if (index < 0) {
                                cout << "Индекс не может быть отрицательным." << endl;
                                continue;
                            }
                            str_list.deleteStringPerIndex(index);
                        } else if (choose_str == 4) {
                            str_list.printAllListString();
                        } else if (choose_str == 5) {
                            int index = checkTryToInputInt(); // Ввод индекса
                            if (index < 0) {
                                cout << "Индекс не может быть отрицательным." << endl;
                                continue;
                            }
                            str_list.searchStringPerIndex(index);
                        } else if (choose_str == 6) {
                            cout << "Произошёл выход." << endl;
                            break;
                        }
                    }
                } else if (choose_all == 3) {
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

            StringLab3 s1, s2, s3;
            cout << "Давайте заполним объекты s1, s2 и s3." << endl;
            fillObject(s1, "s1");
            fillObject(s2, "s2");
            fillObject(s3, "s3");

            while (true) {
                cout << "\n=== Меню программы ===" << endl;
                cout << "1. Ввести новую строку в объект" << endl;
                cout << "2. Вывести содержимое объекта" << endl;
                cout << "3. Сравнить два объекта (<, >, !=)" << endl;
                cout << "4. Добавить строку ко всем строкам объекта (+=)" << endl;
                cout << "5. Получить размер массива строк" << endl;
                cout << "6. Выход" << endl;
                int choiceStrLab3 = checkYourSolution(6); // Выбор действия (1-6)

                if (choiceStrLab3 == 1) {
                    int chooseStrLab3_choice1 = checkYourSolution(3); // Выбор объекта (1-3)
                    cin.clear();
                    if (chooseStrLab3_choice1 == 1) {
                        cout << "Ввод строки в объект s1:" << endl;
                        cin >> s1;
                    } else if (chooseStrLab3_choice1 == 2) {
                        cout << "Ввод строки в объект s2:" << endl;
                        cin >> s2;
                    } else if (chooseStrLab3_choice1 == 3) {
                        cout << "Ввод строки в объект s3:" << endl;
                        cin >> s3;
                    }
                } else if (choiceStrLab3 == 2) {
                    int chooseStrLab3_choice1 = checkYourSolution(3); // Выбор объекта (1-3)
                    if (chooseStrLab3_choice1 == 1) {
                        cout << "s1: " << s1 << endl;
                    } else if (chooseStrLab3_choice1 == 2) {
                        cout << "s2: " << s2 << endl;
                    } else if (chooseStrLab3_choice1 == 3) {
                        cout << "s3: " << s3 << endl;
                    }
                } else if (choiceStrLab3 == 3) {
                    cout << "s1: " << s1 << endl;
                    cout << "Сравнение s1 и s2:" << endl;
                    cout << "s1 < s2: " << (s1 < s2 ? "true" : "false") << endl;
                    cout << "s1 > s2: " << (s1 > s2 ? "true" : "false") << endl;
                    cout << "s1 != s2: " << (s1 != s2 ? "true" : "false") << endl;
                } else if (choiceStrLab3 == 4) {
                    int chooseStrLab3_choice1 = checkYourSolution(3); // Выбор объекта (1-3)
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
                    }
                } else if (choiceStrLab3 == 5) {
                    int chooseStrLab3_choice1 = checkYourSolution(3); // Выбор объекта (1-3)
                    if (chooseStrLab3_choice1 == 1) {
                        cout << "Размер s1: " << s1.getSize() << endl;
                    } else if (chooseStrLab3_choice1 == 2) {
                        cout << "Размер s2: " << s2.getSize() << endl;
                    } else if (chooseStrLab3_choice1 == 3) {
                        cout << "Размер s3: " << s3.getSize() << endl;
                    }
                } else if (choiceStrLab3 == 6) {
                    cout << "Произошёл выход." << endl;
                    break;
                }
            }
        } else if (k == 4) {
            cout << "Лабораторная 4:" << endl;
            cout << "30. Написать программу для обслуживания клиентов спортивного центра. Создать классы «Клиент», «Услуга», «Заказ» с необходимым набором полей и методов. Каждая услуга имеет название, цену, стоимость, время выполнения. При обслуживании клиента необходимо подготовить чек, в котором должно быть указано название услуги, её цена, количество сеансов, общая сумма чека, дата и время покупки. Данные чека вывести на экран и в файл." << endl;

            Order* orders = nullptr; // Динамический массив заказов
            int orderCount = 0; // Текущее количество заказов
            int capacity = 0; // Текущая вместимость массива

            while (true) {
                cout << "1. Добавить новый заказ" << endl;
                cout << "2. Просмотреть все заказы" << endl;
                cout << "3. Удалить заказ по индексу" << endl;
                cout << "4. Выйти" << endl;
                int choice = checkYourSolution(4); // Выбор действия (1-4)

                if (choice == 1) {
                    // Увеличиваем массив, если нужно
                    if (orderCount == capacity) {
                        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
                        Order* newOrders = new Order[newCapacity];
                        for (int i = 0; i < orderCount; i++) {
                            newOrders[i] = orders[i];
                        }
                        delete[] orders;
                        orders = newOrders;
                        capacity = newCapacity;
                    }

                    // Ввод данных клиента
                    cout << "Введите имя клиента: ";
                    string clientName = checkTryToInputString(false); // Запрещаем кириллицу
                    cout << "Введите фамилию клиента: "; // Исправили подсказку: вместо "контакт" теперь "фамилия"
                    string clientSurname = checkTryToInputString(false);
                    Client client(clientName, clientSurname);

                    // Ввод данных услуги
                    cout << "Введите название услуги: ";
                    string serviceName = checkTryToInputString(false);
//                    cout << "Введите цену услуги (руб.): ";
//                    double servicePrice = checkTryToInputDouble();
//                    while (servicePrice==0){
//                        cout<< "Не может быть 0)" << endl;
//                        servicePrice = checkTryToInputDouble();
//                    }
                    cout << "Введите стоимость услуги (руб.): ";
                    double serviceCost = checkTryToInputDouble();
                    while (serviceCost==0){
                        cout<< "Не может быть 0)" << endl;
                        serviceCost = checkTryToInputDouble();
                    }
                    cout << "Введите время выполнения услуги (в минутах): ";
                    int serviceDuration = checkTryToInputInt();
                    while(serviceDuration==0){
                        cout<< "Не может быть 0)" << endl;
                        serviceDuration = checkTryToInputInt();
                    }
                    if(serviceDuration<2){
                        cout<< "Что за услуга такая, которая меньше 2-х минут?)" << endl;
                    }
                    double servicePrice=serviceCost;
                    Service service(serviceName, servicePrice, serviceCost, serviceDuration);

                    // Ввод количества сеансов
                    cout << "Введите количество сеансов: ";
                    int sessionCount = checkTryToInputInt();
                    while (sessionCount <= 0) {
                        cout << "Количество сеансов должно быть больше 0. Попробуйте снова: ";
                        sessionCount = checkTryToInputInt();
                    }

                    // Создание заказа
                    orders[orderCount] = Order(client, service, sessionCount);
                    orderCount++;

                    // Вывод и сохранение чека
                    orders[orderCount - 1].printReceipt();
                    orders[orderCount - 1].saveReceiptToFile("receipt.txt");
                    cout << "Заказ успешно добавлен!" << endl;
                } else if (choice == 2) {
                    if (orderCount == 0) {
                        cout << "Список заказов пуст." << endl;
                    } else {
                        cout << "\n=== Список всех заказов ===" << endl;
                        for (int i = 0; i < orderCount; i++) {
                            cout << "Заказ #" << i << ":" << endl;
                            orders[i].printReceipt();
                        }
                    }
                } else if (choice == 3) {
                    if (orderCount == 0) {
                        cout << "Список заказов пуст." << endl;
                        continue;
                    }
                    cout << "Введите индекс заказа для удаления (0-" << (orderCount - 1) << "): ";
                    int index = checkTryToInputInt();
                    if (index < 0 || index >= orderCount) {
                        cout << "Недопустимый индекс." << endl;
                        continue;
                    }
                    // Сдвигаем элементы массива
                    for (int i = index; i < orderCount - 1; i++) {
                        orders[i] = orders[i + 1];
                    }
                    orderCount--;
                    cout << "Заказ с индексом " << index << " удалён." << endl;
                } else if (choice == 4) {
                    cout << "Произошёл выход из Лабы 4." << endl;
                    delete[] orders; // Освобождаем память
                    break;
                }
            }
        } else if (k == 5) {
            cout << "Лабораторная 5:\n"
                 << "30. Создать набор классов по теме «Банковские операции», одним из которых будет класс Account (счёт). \n"
                 << "В классе должны быть следующие поля: номер счёта, вид счёта, дата создания, владелец. \n"
                 << "Включить в состав класса необходимый минимум методов, обеспечивающий полноценное функционирование объектов указанного класса \n"
                 << "(конструкторы по умолчанию, с параметрами, копирования, деструктор). \n"
                 << "В класс добавить необходимый набор полей и методов (минимум два поля и два метода) на своё усмотрение. \n"
                 << "Создать массив счетов банка, заполнить его данными. \n"
                 << "Создать функции поиска в массиве всех счетов одного владельца. Данные поиска считываются с клавиатуры. \n"
                 << "Создать метод для записи полученных данных в файл. Создать методы доступа к полям класса.\n";

            Account* accounts = nullptr;
            int size = 0;
            int capacity = 0;

            while (true) {
                cout << "\nМеню:\n"
                     << "1. Добавить счёт\n"
                     << "2. Показать счета владельца\n"
                     << "3. Выход\n"
                     << "Выберите: ";

                int choice = mylib::checkYourSolution(3);

                if (choice == 1) {
                    addAccount(accounts, size, capacity);
                } else if (choice == 2) {
                    if (size == 0) {
                        cout << "Нет никаких банковских счетов.\n";
                    } else {
                        findAccountsByOwner(accounts, size);
                    }
                } else if (choice == 3) {
                    cout << "Произошёл выход.\n";
                    delete[] accounts; // Освобождаем память
                    break;
                }
            }

        } else if (k == 6) {
            // Инициализация массивов для проектов и сотрудников
            ProjectPayable* projects = nullptr;
            int projectSize = 0;
            int projectCapacity = 0;

            Employee** employees = nullptr;
            int employeeSize = 0;
            int employeeCapacity = 0;
            cout << "В КАЖДОМ ЗАДАНИИ НЕОБХОДИМО САМОСТОЯТЕЛЬНО \n"
                    "ДОБАВИТЬ КЛАССЫ ДЛЯ РЕАЛИЗАЦИИ МНОЖЕСТВЕННОГО \n"
                    "НАСЛЕДОВАНИЯ. " << endl;
            cout << "30. Построить иерархию классов согласно схеме наследования, \n"
                    "приведенной на рисунке ниже по предметной области «Распределение \n"
                    "бюджета проектов». Каждый класс должен содержать необходимые \n"
                    "конструкторы и методы работы с полями классов. Функция main() должна \n"
                    "иллюстрировать работу с массивами объектов всех созданных классов.  " << endl;
            while (true) {
                cout << "Выберите действие:" << endl;
                cout << "1. Добавить проект\n"
                        "2. Добавить работника\n"
                        "3. Показать все проекты\n"
                        "4. Показать всех работников\n"
                        "5. Назначить работника на проект\n"
                        "6. Выйти" << endl;

                int choice = mylib::checkYourSolution(6);
                if (choice == 1) {
                    std::string currentDate = generate::generateCurrentDataTime(); // Формат: YYYY-MM-DD HH:MM:SS
                    int currentYear, currentMonth, currentDay;
                    try {
                        currentYear = std::stoi(currentDate.substr(0, 4));
                        currentMonth = std::stoi(currentDate.substr(5, 2));
                        currentDay = std::stoi(currentDate.substr(8, 2));
                    } catch (...) {
                        std::cout << "Ошибка получения текущей даты.\n";
                        break;
                    }
                    cout << "Введите название проекта:" << endl;
                    string nameProject = checkTryToInputStringName("");
                    cout << "Введите описание проекта:" << endl;
                    string detalis= checkTryToInputStringName("");
                    cout << "Введите локацию проекта:" << endl;
                    string location = checkTryToInputStringName("");
                    Location* loc = new Location(location);
                    cout << "Введите бюджет проекта:" << endl;
                    double budget= checkTryToInputDouble();
                    Budget* bud = new Budget(budget);
                    cout << "Введите дату окончания проекта:" << endl;
                    cout << "Введите дату окончания проекта:" << endl;
                    int y;
                    cout << "Введите год (" << currentYear << "-2050): ";
                    while (true) {
                        y = mylib::checkTryToInputInt();
                        if (y < currentYear || y > 2050) {
                            cout << "Год должен быть от " << currentYear << " до 2050. Попробуйте снова." << endl;
                            continue;
                        }
                        if (y == 2050 && (currentMonth > 1 || currentDay > 1)) {
                            cout << "Максимальная дата — 1 января 2050. Попробуйте снова." << endl;
                            continue;
                        }
                        break;
                    }

                    int m;
                    cout << "Введите месяц (1-12): ";
                    while (true) {
                        m = mylib::checkTryToInputInt();
                        if (m < 1 || m > 12) {
                            cout << "Месяц должен быть от 1 до 12. Попробуйте снова." << endl;
                            continue;
                        }
                        if (y == currentYear && m < currentMonth) {
                            cout << "Для " << currentYear << " года месяц не может быть раньше текущего (" << currentMonth << "). Попробуйте снова." << endl;
                            continue;
                        }
                        if (y == 2050 && m > 1) {
                            cout << "Максимальная дата — 1 января 2050. Попробуйте снова." << endl;
                            continue;
                        }
                        break;
                    }

                    int d;
                    cout << "Введите день: ";
                    while (true) {
                        d = mylib::checkTryToInputInt();
                        int maxDays = getDaysInMonth(m, y);
                        if (y == currentYear && m == currentMonth) {
                            maxDays = std::min(maxDays, currentDay);
                        }
                        if (d < 1 || d > maxDays) {
                            cout << "В " << m << "-м месяце " << y << " года " << maxDays << " дней. Введите день от 1 до " << maxDays << ". Попробуйте снова." << endl;
                            continue;
                        }
                        if (y == currentYear && m == currentMonth && d < currentDay) {
                            cout << "Для " << currentMonth << " месяца " << currentYear << " года день не может быть раньше текущего (" << currentDay << "). Попробуйте снова." << endl;
                            continue;
                        }
                        if (y == 2050 && m == 1 && d > 1) {
                            cout << "Максимальная дата — 1 января 2050. Попробуйте снова." << endl;
                            continue;
                        }
                        break;
                    }

                    Completion_date* compDate = new Completion_date(y, m, d);

                    // Выбор сотрудника для назначения (опционально)
                    Employee* emp = nullptr;
                    if (employeeSize > 0) {
                        cout << "Хотите назначить сотрудника на проект? (1 - Да, 2 - Нет): ";
                        int assignChoice = checkYourSolution(2);
                        if (assignChoice == 1) {
                            printAllEmployees(employees, employeeSize);
                            cout << "Введите индекс сотрудника (0-" << (employeeSize - 1) << "): ";
                            int empIndex = checkTryToInputInt();
                            if (empIndex >= 0 && empIndex < employeeSize) {
                                emp = employees[empIndex];
                            } else {
                                cout << "Недопустимый индекс, сотрудник не назначен.\n";
                            }
                        }
                    }
                    addProjectPayable(projects,projectSize,projectCapacity,nameProject, detalis,loc ,bud,compDate, emp);
                }
                else if (choice == 2) {
                    // Ввод данных для нового сотрудника
                    cout << "Введите имя сотрудника: ";
                    string name = checkTryToInputStringName("");

                    cout << "Введите адрес сотрудника: ";
                    string addr = checkTryToInputStringName("");

                    cout << "Введите уровень квалификации (1-10): ";
                    int grade = checkTryToInputInt();
                    while (grade < 1 || grade > 10) {
                        cout << "Уровень должен быть от 1 до 10. Попробуйте снова: ";
                        grade = checkTryToInputInt();
                    }

                    cout << "Сотрудник с почасовой оплатой? (1 - Да, 2 - Нет): ";
                    int empType = checkYourSolution(2);
                    Employee* emp;
                    if (empType == 1) {
                        cout << "Введите часы работы: ";
                        double hours = checkTryToInputDouble();
                        cout << "Введите ставку за час (руб.): ";
                        double rate = checkTryToInputDouble();
                        emp = new Hourly_emp(name, addr, grade, hours, rate);
                    } else {
                        cout << "Введите зарплату (руб.): ";
                        double salary = checkTryToInputDouble();
                        emp = new SalariedEmp(name, addr, grade, salary);
                    }

                    // Добавление сотрудника в массив
                    addEmployee(employees, employeeSize, employeeCapacity, emp);
                }
                else if (choice == 3) {
                    printAllProjectPayables(projects, projectSize);
                }
                else if (choice == 4) {
                    printAllEmployees(employees, employeeSize);
                }
                else if (choice == 5) {
                    // Назначение сотрудника на существующий проект
                    if (projectSize == 0) {
                        cout << "Нет проектов для назначения сотрудников.\n";
                        continue;
                    }
                    if (employeeSize == 0) {
                        cout << "Нет сотрудников для назначения.\n";
                        continue;
                    }

                    // Вывод списка проектов
                    printAllProjectPayables(projects, projectSize);
                    cout << "Введите индекс проекта (0-" << (projectSize - 1) << "): ";
                    int projectIndex = checkTryToInputInt();
                    if (projectIndex < 0 || projectIndex >= projectSize) {
                        cout << "Недопустимый индекс проекта.\n";
                        continue;
                    }

                    // Вывод списка сотрудников
                    printAllEmployees(employees, employeeSize);
                    cout << "Введите индекс сотрудника (0-" << (employeeSize - 1) << "): ";
                    int empIndex = checkTryToInputInt();
                    if (empIndex < 0 || empIndex >= employeeSize) {
                        cout << "Недопустимый индекс сотрудника.\n";
                        continue;
                    }

                    // Назначение сотрудника на проект
                    projects[projectIndex].setAssignedEmployee(employees[empIndex]);
                    cout << "Сотрудник успешно назначен на проект.\n";
                }
                else if (choice == 6) {
                    // Вывод котика перед выходом
                    cout << "     |\\__/,|   (`\\\n";
                    cout << "  _.|o O  o O|_  ) )\n";
                    cout << "-(((---((( *-* )))  ~\n";
                    cout << "    |  ^_^  |  /|\\\n";
                    cout << "    |  > <  |_/ |_\n";
                    cout << "    ~ ~ ~ ~ ~ ~ Felix\n\n";

                    // Освобождение памяти
                    for (int i = 0; i < projectSize; i++) {
                        delete projects[i].getLocation();
                        delete projects[i].getBudget();
                        delete projects[i].getCompletionDate();
                    }
                    delete[] projects;

                    for (int i = 0; i < employeeSize; i++) {
                        delete employees[i];
                    }
                    delete[] employees;

                    cout << "Произошёл выход из лабораторной 6.\n";
                    break;
                }
            }

        } else if (k == 7) {
            cout << "В КАЖДОМ ИНДИВИДУАЛЬНОМ ЗАДАНИИ ДОЛЖНЫ БЫТЬ \n"
                    "ИСПОЛЬЗОВАНЫ ШАБЛОННЫЕ КЛАССЫ И ФУНКЦИИ. " << endl;
            cout << " Разработать набор классов (минимум 5) по теме «Разработка 3D \n"
                    "графики». Корректно реализовать связи между классами. В разработанном \n"
                    "наборе классов должен быть хотя бы один шаблонный класс. Все классы \n"
                    "должны иметь методы получения и установки значений полей. Программа \n"
                    "должна обеспечивать вывод детальной информации о созданных 3D \n"
                    "изображениях в табличном виде на экран и в файл. Использовать конструктор \n"
                    "с параметрами, конструктор без параметров, конструктор копирования, \n"
                    "деструктор." << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 8) {
            cout << "В КАЖДОМ ИНДИВИДУАЛЬНОМ ЗАДАНИИ ДОЛЖНЫ БЫТЬ \n"
                    "ИСПОЛЬЗОВАНЫ SMART-УКАЗАТЕЛИ И ТРАНЗАКЦИИ. " << endl;
            cout << " Разработать набор классов (минимум 5) по теме «Разработка 3D \n"
                    "графики». Корректно реализовать связи между классами. Использовать \n"
                    "smart-указатели для создания программы учета созданных и удаленных \n"
                    "изображений 3D графики. Реализовать механизм транзакций, который \n"
                    "позволит откатывать изменения, если данные о графике введены неверно \n"
                    "(например, материал или источник света имеют некорректное значение). В \n"
                    "разработанном наборе классов должен быть хотя бы один шаблонный класс. \n"
                    "Все классы должны иметь методы получения и установки значений полей. \n"
                    "Программа должна обеспечивать вывод детальной информации о созданных \n"
                    "3D изображениях в табличном виде на экран и в файл. Использовать \n"
                    "конструктор с параметрами, конструктор без параметров, конструктор \n"
                    "копирования, деструктор." << endl;
            cout << "Ещё не готова." << endl;
        } else if (k == 9) {
            cout << "В КАЖДОМ ИНДИВИДУАЛЬНОМ ЗАДАНИИ НЕОБХОДИМО: \n"
                    "1. Сгенерировать минимум пять типов исключительных ситуаций \n"
                    "2. Реализовать перенаправление исключительных ситуаций \n"
                    "3. Сгенерировать минимум одну исключительную ситуацию с оператором new \n"
                    "4. Создать исключительную ситуацию в конструкторе и продемонстрировать вызов конструкторов\n"
                    "и деструкторов при возникновении исключения \n"
                    "5. Задать собственную функцию завершения \n"
                    "6. Создать собственный (пользовательский) класс исключения, \n"
                    "сгенерировать исключение этого типа и обработать его. " << endl;
            cout << "30. Разработать набор классов (минимум 5 классов, связи между \n"
                    "классами: агрегация, композиция, наследование) по предметной области \n"
                    "«Конвертор файлов». Функционал программы должен позволить собрать \n"
                    "данные о проведенных конвертациях и времени их выполнения. " << endl;
            cout << "Ещё не готова." << endl;
        }
        else if(k==10){
            cout << "Произошёл выход." << endl;
            cout << "    |\\__/,|   (`\\\n";
            cout << "  _.|o o  |_   ) )\n";
            cout << "-(((---(((--------\n";
            cout << "Bye-Bye";
            break;
        }
    }
}