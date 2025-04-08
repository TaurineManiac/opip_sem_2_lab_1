#include <iostream>
#include "Header_3.h"

using namespace std;

StringLab3::StringLab3() : strings(nullptr), size(0), capacity(0) {}

StringLab3::StringLab3(const string& str) : size(1), capacity(2) {
    strings = new string[capacity];
    strings[0] = str;
}

StringLab3::StringLab3(const StringLab3& other) : size(other.size), capacity(other.capacity) {
    strings = new string[capacity];
    for (int i = 0; i < size; i++) {
        strings[i] = other.strings[i];
    }
}

StringLab3::~StringLab3() {
    delete[] strings;
}

StringLab3& StringLab3::operator=(const StringLab3& other) {
    if (this != &other) {
        delete[] strings; // Освобождаем старую память
        size = other.size;
        capacity = other.capacity;
        strings = new string[capacity];
        for (int i = 0; i < size; i++) {
            strings[i] = other.strings[i];
        }
    }
    return *this;
}

void StringLab3::resize(int newCapacity) {
    string* newStrings = new string[newCapacity];
    for (int i = 0; i < size; i++) {
        newStrings[i] = strings[i];
    }
    delete[] strings;
    strings = newStrings;
    capacity = newCapacity;
}

void StringLab3::addString(const string& str) {
    if (size == capacity) {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        resize(newCapacity);
    }
    strings[size] = str;
    size++;
}

int StringLab3::getSize() const {
    return size;
}

bool StringLab3::operator<(const StringLab3& other) const {
    if (size == 0 || other.size == 0) return false;
    return strings[0] < other.strings[0];
}

bool StringLab3::operator>(const StringLab3& other) const {
    if (size == 0 || other.size == 0) return false;
    return strings[0] > other.strings[0];
}

bool StringLab3::operator!=(const StringLab3& other) const {
    if (size == 0 || other.size == 0) return true;
    return strings[0] != other.strings[0];
}

StringLab3& StringLab3::operator+=(const StringLab3& other) {
    for (int i = 0; i < other.size; i++) {
        for (int j = 0; j < size; j++) {
            strings[j] += other.strings[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const StringLab3& obj) {
    for (int i = 0; i < obj.size; i++) {
        os << obj.strings[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, StringLab3& obj) {
    string input;
    getline(is, input);
    if (!input.empty()) {
        // Очищаем текущий массив
        delete[] obj.strings;
        obj.strings = new string[2];
        obj.strings[0] = input;
        obj.size = 1;
        obj.capacity = 2;
    }
    return is;
}