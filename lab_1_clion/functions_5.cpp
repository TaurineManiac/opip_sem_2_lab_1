#include "Header_5.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include <sstream>

using namespace std;

Account::Account()
        : depositType("savings account"), owner("Unknown"), balance(0.0) {
    depositIndex = getDepositIndex();
    creationDate = getCurrentDateTime();
}

Account::Account(const string& index, const string& type, const string& date,
                 const string& owner, double balance)
        : depositIndex(index), depositType(type), creationDate(date),
          owner(owner), balance(balance) {}

Account::Account(const Account& other)
        : depositIndex(other.depositIndex), depositType(other.depositType),
          creationDate(other.creationDate), owner(other.owner), balance(other.balance) {}

Account::~Account() {}

string Account::getDepositIndex() const { return depositIndex; }
string Account::getDepositType() const { return depositType; }
string Account::getCreationDate() const { return creationDate; }
string Account::getOwner() const { return owner; }
double Account::getBalance() const { return balance; }

void Account::setDepositType(const string& type) { depositType = type; }
void Account::setOwner(const string& owner) { this->owner = owner; }
void Account::setBalance(double balance) { this->balance = balance; }

void Account::display() const {
    string typeDisplay;
    if (depositType == "savings account") {
        typeDisplay = "Сберегательный";
    } else {
        typeDisplay = "Зарплатный";
    }
    cout << "===== Информация о счёте =====\n"
         << "Номер депозита: " << depositIndex << "\n"
         << "Тип депозита: " << typeDisplay << "\n"
         << "Дата создания: " << creationDate << "\n"
         << "Владелец: " << owner << "\n"
         << "Баланс: " << fixed << setprecision(2) << balance << " RUB\n";
}

void Account::saveToFile(ofstream& outFile) const {
    string typeDisplay;
    if (depositType == "savings account") {
        typeDisplay = "Сберегательный";
    } else {
        typeDisplay = "Зарплатный";
    }
    outFile << "===== Информация о счёте =====\n"
            << "Номер депозита: " << depositIndex << "\n"
            << "Тип депозита: " << typeDisplay << "\n"
            << "Дата создания: " << creationDate << "\n"
            << "Владелец: " << owner << "\n"
            << "Баланс: " << fixed << setprecision(2) << balance << " RUB\n"
            << "=============================\n";
}

string Account::getCurrentDateTime() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    ostringstream oss;
    oss << put_time(ltm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

string Account::getDepositIndex() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 999999);
    int num = dis(gen);
    ostringstream oss;
    oss << setw(6) << setfill('0') << num;
    return oss.str();
}

void addAccount(Account*& accounts, int& size, int& capacity) {
    if (size >= capacity) {
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity = capacity * 2;
        }
        Account* newAccounts = new Account[capacity];
        for (int i = 0; i < size; ++i) {
            newAccounts[i] = accounts[i];
        }
        delete[] accounts;
        accounts = newAccounts;
    }

    cout << "Введите имя: ";
    string owner = mylib::checkTryToInputString(false); // Запрещаем кириллицу

    cout << "Выберите тип счёта (1 - savings account, 2 - salary account): ";
    int typeChoice = mylib::checkYourSolution(2);
    string type;
    if (typeChoice == 1) {
        type = "savings account";
    } else {
        type = "salary account";
    }

    cout << "Введите баланс: ";
    double balance = mylib::checkTryToInputDouble();
    while(balance<=0){
        cout << "Баланс не может быть <=0)" << endl;
        balance = mylib::checkTryToInputDouble();
    }

    // Создаем временный объект для вызова нестатических методов
    Account temp;
    accounts[size] = Account(temp.getDepositIndex(), type, temp.getCurrentDateTime(), owner, balance);

    // Сохранение нового счета в файл
    ofstream outFile("bank_accounts.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла!\n";
    } else {
        accounts[size].saveToFile(outFile);
        outFile.close();
    }

    ++size;
    cout << "Счёт добавлен успешно!\n";
}

void findAccountsByOwner(const Account* accounts, int size) {
    cout << "Введите имя владельца для поиска: ";
    string searchOwner = mylib::checkTryToInputString(false); // Запрещаем кириллицу
    int count = 0;

    cout << "\n=== Счета владельца " << searchOwner << " ===\n";
    for (int i = 0; i < size; ++i) {
        if (accounts[i].getOwner() == searchOwner) {
            accounts[i].display();
            count++;
        }
    }

    if (count == 0) {
        cout << "Нет счетов для " << searchOwner << ".\n";
    }
    cout << "Количество счетов у владельца: " << count << "\n"
         << "=============================\n";
}