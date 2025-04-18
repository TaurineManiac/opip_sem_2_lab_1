#ifndef LAB_1_STRING_HEADER_H  // Более уникальное имя макроса
#define LAB_1_STRING_HEADER_H

#include <string>

using namespace std;

class String {
private:
    string str; // Основное поле для хранения строки

public:
    // Конструктор без параметров
    String();

    // Конструктор с параметром
    explicit String(const char* s);

    // Конструктор копирования
    String(const String& other) = default;

    // Деструктор
    ~String() = default;

    // Оператор присваивания
    String& operator=(const String& other);

    // Методы установки значений с проверкой корректности
    void setStr(const string& newStr);

    // Методы для работы со строками
    void concat(const String* other, int count);
    void concat_ws(const String* other, const string& separator, int count);
    int length() const;
    void ltrim();
    void rtrim();
    void print() const;
    void writeToFile(const char* filename) const;

    // Геттеры
    const string& getStr() const;
};

// Прототипы функций
void vvod(String* arr, int count);
void vivod(const String* arr, int count);
void sort(String* arr, int count);

#endif // LAB_1_STRING_HEADER_H