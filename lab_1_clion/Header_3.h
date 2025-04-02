//    Глубокая копия — это процесс копирования объекта, при котором создаётся полностью независимая копия всех данных объекта,
//    включая все динамически выделенные ресурсы (например, память, на которую указывает указатель).
//    Это означает, что новый объект не зависит от оригинального: изменения в одном объекте не влияют на другой

#ifndef STRINGLAB3_H                                    // Защита от повторного включения заголовочного файла
#define STRINGLAB3_H                                    // Определяем макрос для защиты

#include <iostream>                                     // Подключаем библиотеку для ввода-вывода (cin, cout)
#include <string>                                       // Подключаем библиотеку для работы со строками (std::string)

using namespace std;                                    // Используем пространство имён std

class StringLab3 {                                      // Объявляем класс с именем StringLab3
private:
    string* data;                                       // Указатель на динамический массив строк (std::string*)
    int size;                                           // Текущий размер массива (количество строк)
    int capacity;                                       // Максимальная вместимость массива (размер выделенной памяти)

public:
    StringLab3();                                       // Конструктор по умолчанию (пустой массив)
    StringLab3(const string& str);                      // Конструктор с параметром (инициализация одной строкой)
    StringLab3(const StringLab3& other);                // Конструктор копирования (глубокая копия)
    ~StringLab3();                                      // Деструктор для освобождения памяти

    const string* getData() const;                      // Геттер для массива строк (возвращает указатель на массив)
    int getSize() const;                                // Геттер для текущего размера массива
    int getCapacity() const;                            // Геттер для максимальной вместимости массива
    void addString(const string& str);                  // Метод для добавления строки в конец массива
    void setData(int index, const string& str);         // Сеттер для изменения строки по индексу

    bool operator<(const StringLab3& other) const;      // Оператор < (сравнение массивов строк)
    bool operator>(const StringLab3& other) const;      // Оператор > (сравнение массивов строк)
    bool operator!=(const StringLab3& other) const;     // Оператор != (проверка на неравенство)
    StringLab3& operator+=(const StringLab3& other);    // Оператор += (добавление всех строк из другого объекта)

    friend ostream& operator<<(ostream& out, const StringLab3& str);  // Friend-функция для вывода объекта в поток
    friend istream& operator>>(istream& in, StringLab3& str);         // Friend-функция для ввода данных из потока в объект
};

#endif // STRINGLAB3_H                                 // Завершаем защиту от повторного включения