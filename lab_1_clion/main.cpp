#include <iostream>
#include <string>
#include <clocale>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include "Header.h"
#include "Header_2.h"
#include "Header_3.h"
#include "Header_4.h"
#include "inputCheck.h"

using namespace std;
using namespace mylib;

// Функция для заполнения объекта пользователем
void fillObject(StringLab3& obj, const string& objName) {
    cout << "\nЗаполнение объекта " << objName << endl;
    string input = checkTryToInputString(false); // Запрещаем кириллицу
    obj.addString(input);
    cout << objName << " теперь: " << obj << endl;
}

int main() {
    system("chcp 65001");

    while (true) {
        cout << "Выберите номер лабораторной работы (1-8, 9 - выход): ";
        int k = checkYourSolution(9); // Выбор номера лабораторной работы (1-9)

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
        }
    }
}