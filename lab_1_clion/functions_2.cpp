#include "Header_2.h"
#include <iostream>
#include <clocale>  // <locale.h> на <clocale> для соответствия современным стандартам

using namespace std;

// Реализации методов класса NodeInt
NodeInt::NodeInt() : num(0), next(nullptr) {}

NodeInt::NodeInt(int value) : num(value), next(nullptr) {}

// Реализации методов класса LinkedListInt
LinkedListInt::LinkedListInt() : headInt(nullptr), count(0) {}

LinkedListInt::~LinkedListInt() {
    NodeInt* current = headInt;
    while (current != nullptr) {
        NodeInt* next = current->next;
        delete current;  // Освобождаем память каждого узла
        current = next;
    }
}

void LinkedListInt::addIntFront(int value) {
    NodeInt* newNode = new NodeInt(value);
    newNode->next = headInt;
    headInt = newNode;
    count++;
}

void LinkedListInt::addIntBack(int value) {
    NodeInt* newNode = new NodeInt(value);
    if (headInt == nullptr) {
        headInt = newNode;
        count++;
    } else {
        NodeInt* current = headInt;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        count++;
    }
}

void LinkedListInt::deleteIntPerIndex(int index) {
    if (index < 0) {
        cout << "Индекс не может быть отрицательным." << endl;
        return;
    }
    if (headInt == nullptr) {
        cout << "Список пуст, удаление невозможно." << endl;
        return;
    }
    if (index == 0) {
        NodeInt* temp = headInt;
        headInt = headInt->next;
        delete temp;
        count--;
        return;
    }
    if (index >= count) {
        cout << "Индекс за пределами списка." << endl;
        return;
    }

    NodeInt* current = headInt;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    NodeInt* temp = current->next;
    current->next = temp->next;
    delete temp;
    count--;
}

void LinkedListInt::searchIntPerIndex(int index) {
    if (index < 0) {
        cout << "Индекс не может быть отрицательным." << endl;
        return;
    }
    if (headInt == nullptr) {
        cout << "Список пуст, поиск невозможен." << endl;
        return;
    }
    if (index >= count) {
        cout << "Индекс за пределами списка." << endl;
        return;
    }

    NodeInt* current = headInt;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    cout << current->num << endl;
}

void LinkedListInt::LinkedListIntPrint() {
    NodeInt* current = headInt;
    while (current != nullptr) {
        cout << current->num << " -> ";
        current = current->next;
    }
    cout << "nullptr (Количество элементов: " << count << ")" << endl;
}

int LinkedListInt::GetCount() {
    return count;
}

// Реализации методов класса NodeString
NodeString::NodeString() : str(""), next(nullptr) {}

NodeString::NodeString(const string& value) : str(value), next(nullptr) {}

// Реализации методов класса LinkedListString
LinkedListString::LinkedListString() : headString(nullptr), count(0) {}

LinkedListString::~LinkedListString() {
    NodeString* current = headString;
    while (current != nullptr) {  // Исправлено: while (current != nullptr) вместо while (current == nullptr)
        NodeString* temp = current->next;
        delete current;
        current = temp;
    }
}

void LinkedListString::addStringFront(const string& value) {
    NodeString* current = new NodeString(value);
    current->next = headString;
    headString = current;
    count++;
    cout << "Элемент добавлен." << endl;
}

void LinkedListString::addStringBack(const std::string& value) {
    NodeString* current = headString;
    if (headString == nullptr) {  // Исправлено: если список пуст, устанавливаем новый узел как голову
        headString = new NodeString(value);
        count++;
        cout << "Элемент добавлен." << endl;
        return;
    }
    while (current->next != nullptr) {  // Проходим до последнего узла
        current = current->next;
    }
    current->next = new NodeString(value);  // Добавляем новый узел в конец
    count++;
    cout << "Элемент добавлен." << endl;
}

void LinkedListString::deleteStringPerIndex(int index) {
    if (index < 0) {
        cout << "Индекс не может быть отрицательным." << endl;
        return;
    }
    if (headString == nullptr) {
        cout << "Список пуст, удаление невозможно." << endl;
        return;
    }
    if (index == 0) {
        NodeString* temp = headString;
        headString = headString->next;
        delete temp;
        count--;
        cout << "Элемент удалён." << endl;
        return;
    }
    if (index >= count) {
        cout << "Индекс за пределами списка." << endl;
        return;
    }

    NodeString* current = headString;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == nullptr) {  // Дополнительная проверка на nullptr
            cout << "Индекс за пределами списка." << endl;
            return;
        }
        current = current->next;
    }
    NodeString* temp = current->next;
    if (temp == nullptr) {  // Проверка, чтобы избежать сегментации
        cout << "Индекс за пределами списка." << endl;
        return;
    }
    current->next = temp->next;
    delete temp;
    count--;
    cout << "Элемент удалён." << endl;
}

void LinkedListString::searchStringPerIndex(int index) {
    if (index < 0) {
        cout << "Индекс не может быть отрицательным." << endl;
        return;
    }
    if (headString == nullptr) {
        cout << "Список пуст, поиск невозможен." << endl;
        return;
    }
    if (index >= count) {
        cout << "Индекс за пределами списка." << endl;
        return;
    }

    NodeString* current = headString;
    for (int i = 0; i < index; i++) {
        if (current->next == nullptr) {  // Дополнительная проверка на nullptr
            cout << "Индекс за пределами списка." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Строка под индексом " << index << ": " << current->str << endl;
}

void LinkedListString::printAllListString() {
    NodeString* current = headString;
    int i = 0;
    while (current != nullptr) {
        cout << "Строка номер " << i + 1 << ": " << current->str << endl;
        current = current->next;
        i++;
    }
    cout << "Строки кончились." << endl;
}

int LinkedListString::GetCount() {  // Добавлено const для соответствия объявлению
    return count;
}