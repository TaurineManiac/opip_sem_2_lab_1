#ifndef LAB_1_CLION_HEADER_2_H
#define LAB_1_CLION_HEADER_2_H

#include <iostream>
#include <string>

using namespace std;

class NodeInt {
public:
    int num;         // Данные узла (число)
    NodeInt* next;   // Указатель на следующий узел

    // Объявления конструкторов (без реализаций)
    NodeInt();
    explicit NodeInt(int value);

    // Деструктор (тривиальный)
    ~NodeInt() = default;
    // Деструктор ~NodeInt() = default;: Это говорит компилятору, что вы хотите использовать
    // автоматически сгенерированный деструктор по умолчанию, который ничего не делает (тривиальный деструктор).
    // Тривиальный деструктор просто уничтожает объект, вызывая деструкторы его полей (если они есть),
    // но не выполняет дополнительной логики.
};

class LinkedListInt {
private:
    NodeInt* headInt;
    int count;

public:
    // Конструктор по умолчанию (без параметров, пустой список)
    LinkedListInt();

    // Деструктор для освобождения памяти
    ~LinkedListInt();

    // Добавление элемента в начало списка
    void addIntFront(int value);

    // Добавление элемента в конец списка
    void addIntBack(int value);

    // Удаление элемента по индексу (0-based)
    void deleteIntPerIndex(int index);

    // Поиск элемента по индексу
    void searchIntPerIndex(int index);

    // Вывод списка и счётчика
    void LinkedListIntPrint();

    // Геттер для получения количества элементов
    int GetCount();
};

class NodeString{
public:
    string str;
    NodeString* next;

    NodeString();
    explicit NodeString(const string& value);

    ~NodeString() = default;
};

class LinkedListString{
private:
    NodeString* headString;
    int count;
public:
    LinkedListString();

    ~LinkedListString();

    void addStringFront(const string& value);
    void addStringBack(const string& value);
    void deleteStringPerIndex(int index);
    void searchStringPerIndex(int index);
    void printAllListString();
    int GetCount();

};

#endif //LAB_1_CLION_HEADER_2_H