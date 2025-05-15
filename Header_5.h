#ifndef HEADER_5_H
#define HEADER_5_H

#include <iostream>
#include <string>
#include <fstream>
#include "inputCheck.h"

using namespace std;

class Account {
private:
    string depositIndex;  // Номер счета (6 цифр с ведущими нулями)
    string depositType;   // Тип счета (savings/salary)
    string creationDate;  // Дата создания
    string owner;         // Владелец
    double balance;       // Баланс

public:
    // Конструкторы
    Account();
    Account(const string& index, const string& type, const string& date, const string& owner, double balance);
    Account(const Account& other);

    // Деструктор
    ~Account();

    // Геттеры
    string getDepositIndex() const;
    string getDepositType() const;
    string getCreationDate() const;
    string getOwner() const;
    double getBalance() const;

    // Сеттеры
    void setDepositType(const string& type);
    void setOwner(const string& owner);
    void setBalance(double balance);

    // Дополнительные методы
    void display() const;
    void saveToFile(ofstream& outFile) const;

    // Статические методы для генерации данных
    string getCurrentDateTime();
    string getDepositIndex();
};

// Функции для работы с массивом счетов
void addAccount(Account*& accounts, int& size, int& capacity);
void findAccountsByOwner(const Account* accounts, int size);

#endif // HEADER_5_H