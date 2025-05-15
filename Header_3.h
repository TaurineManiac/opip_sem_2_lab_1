#ifndef HEADER_3_H
#define HEADER_3_H

#include <string>

using namespace std;

class StringLab3 {
private:
    string* strings; // Динамический массив строк
    int size;        // Текущий размер массива
    int capacity;    // Вместимость массива

    // Вспомогательный метод для увеличения вместимости массива
    void resize(int newCapacity);

public:
    StringLab3();
    StringLab3(const string& str);
    StringLab3(const StringLab3& other);
    ~StringLab3();

    // Оператор присваивания
    StringLab3& operator=(const StringLab3& other);

    void addString(const string& str);
    int getSize() const;

    bool operator<(const StringLab3& other) const;
    bool operator>(const StringLab3& other) const;
    bool operator!=(const StringLab3& other) const;
    StringLab3& operator+=(const StringLab3& other);

    friend ostream& operator<<(ostream& os, const StringLab3& obj);
    friend istream& operator>>(istream& is, StringLab3& obj);
};

#endif // HEADER_3_H