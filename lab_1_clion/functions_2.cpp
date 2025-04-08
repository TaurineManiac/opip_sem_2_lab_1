#include <iostream>
#include "Header_2.h"

using namespace std;

// Реализация LinkedListInt
LinkedListInt::LinkedListInt() : head(nullptr), size(0) {}

LinkedListInt::~LinkedListInt() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedListInt::addIntFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
    cout << "Добавлено в начало: " << value << endl;
}

void LinkedListInt::addIntBack(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
    cout << "Добавлено в конец: " << value << endl;
}

void LinkedListInt::deleteIntPerIndex(int index) {
    if (index < 0 || index >= size) {
        cout << "Недопустимый индекс." << endl;
        return;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << "Элемент с индексом " << index << " удалён." << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
    cout << "Элемент с индексом " << index << " удалён." << endl;
}

void LinkedListInt::LinkedListIntPrint() const {
    if (size == 0) {
        cout << "nullptr (Количество элементов: 0)" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr (Количество элементов: " << size << ")" << endl;
}

void LinkedListInt::searchIntPerIndex(int index) const {
    if (index < 0 || index >= size) {
        cout << "Недопустимый индекс." << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    cout << "Элемент с индексом " << index << ": " << current->data << endl;
}

int LinkedListInt::getSize() const {
    return size;
}

// Реализация LinkedListString
LinkedListString::LinkedListString() : head(nullptr), size(0) {}

LinkedListString::~LinkedListString() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedListString::addStringFront(const string& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
    cout << "Добавлено в начало: " << value << endl;
}

void LinkedListString::addStringBack(const string& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
    cout << "Добавлено в конец: " << value << endl;
}

void LinkedListString::deleteStringPerIndex(int index) {
    if (index < 0 || index >= size) {
        cout << "Недопустимый индекс." << endl;
        return;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << "Элемент с индексом " << index << " удалён." << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
    cout << "Элемент с индексом " << index << " удалён." << endl;
}

void LinkedListString::printAllListString() const {
    if (size == 0) {
        cout << "nullptr (Количество элементов: 0)" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr (Количество элементов: " << size << ")" << endl;
}

void LinkedListString::searchStringPerIndex(int index) const {
    if (index < 0 || index >= size) {
        cout << "Недопустимый индекс." << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    cout << "Элемент с индексом " << index << ": " << current->data << endl;
}

int LinkedListString::getSize() const {
    return size;
}