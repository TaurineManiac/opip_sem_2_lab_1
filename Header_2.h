#ifndef HEADER_2_H
#define HEADER_2_H

#include <string>

using namespace std;

class LinkedListInt {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    LinkedListInt();
    ~LinkedListInt();
    void addIntFront(int value);
    void addIntBack(int value);
    void deleteIntPerIndex(int index);
    void LinkedListIntPrint() const;
    void searchIntPerIndex(int index) const;
    int getSize() const;
};

class LinkedListString {
private:
    struct Node {
        string data;
        Node* next;
        Node(const string& value) : data(value), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    LinkedListString();
    ~LinkedListString();
    void addStringFront(const string& value);
    void addStringBack(const string& value);
    void deleteStringPerIndex(int index);
    void printAllListString() const;
    void searchStringPerIndex(int index) const;
    int getSize() const;
};

#endif // HEADER_2_H