#include <iostream>
#include <fstream>
#include <ctime>
#include "Header_4.h"

using namespace std;

// Реализация Client
Client::Client() : name(""), surname("") {} // Исправили инициализацию: вместо nullptr используем пустую строку

Client::Client(const string& name, const string& surname) : name(name), surname(surname) {}

Client::Client(const Client& other) : name(other.name), surname(other.surname) {}

Client::~Client() {}

string Client::getName() const { // Добавили const
    return name;
}

string Client::getSurname() const { // Добавили const
    return surname;
}

void Client::setName(const string& name) { // Добавили const для параметра
    this->name = name;
}

void Client::setSurname(const string& surname) { // Добавили const для параметра
    this->surname = surname;
}

// Реализация Service
Service::Service() : name(""), price(0.0), costs(0.0), duration(0) {}

Service::Service(const string& name, double price, double costs, int duration)
        : name(name), price(price), costs(costs), duration(duration) {}

Service::Service(const Service& other)
        : name(other.name), price(other.price), costs(other.costs), duration(other.duration) {}

Service::~Service() {}

string Service::getName() const { // Добавили const
    return name;
}

double Service::getPrice() const { // Добавили const
    return price;
}

double Service::getCosts() const { // Добавили const
    return costs;
}

int Service::getDuration() const { // Добавили const
    return duration;
}

void Service::setName(const string& name) {
    this->name = name;
}

void Service::setPrice(double price) {
    this->price = price;
}

void Service::setCosts(double costs) {
    this->costs = costs;
}

void Service::setDuration(int duration) {
    this->duration = duration;
}

// Реализация Order
string Order::getCurrentDateTime() const { // Добавили реализацию
    time_t now = time(nullptr);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

Order::Order() : Client(), service(), sessionCount(0), totalAmount(0.0), purchaseDateTime(getCurrentDateTime()) {}

Order::Order(const Client& client, const Service& service, int sessionCount)
        : Client(client), service(service), sessionCount(sessionCount), purchaseDateTime(getCurrentDateTime()) {
    calculateTotal();
}

Order::Order(const Order& other)
        : Client(other), service(other.service), sessionCount(other.sessionCount),
          totalAmount(other.totalAmount), purchaseDateTime(other.purchaseDateTime) {}

Order::~Order() {}

Service Order::getService() const {
    return service;
}

int Order::getSessionCount() const {
    return sessionCount;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

string Order::getPurchaseDateTime() const {
    return purchaseDateTime;
}

void Order::setService(const Service& newService) {
    service = newService;
    calculateTotal();
}

void Order::setSessionCount(int newSessionCount) {
    sessionCount = newSessionCount;
    calculateTotal();
}

void Order::calculateTotal() {
    totalAmount = service.getPrice() * sessionCount;
}

void Order::printReceipt() const {
    cout << "===== Чек =====" << endl;
    cout << "Клиент: " << getName() << endl;
    cout << "Контакт: " << getSurname() << endl;
    cout << "Услуга: " << service.getName() << endl;
    cout << "Цена за сеанс: " << service.getPrice() << " руб." << endl;
    cout << "Количество сеансов: " << sessionCount << endl;
    cout << "Общая сумма: " << totalAmount << " руб." << endl;
    cout << "Дата и время покупки: " << purchaseDateTime << endl;
    cout << "===============" << endl;
}

void Order::saveReceiptToFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "===== Чек =====\n";
        file << "Клиент: " << getName() << "\n";
        file << "Контакт: " << getSurname() << "\n"; // Исправили getContact() на getSurname()
        file << "Услуга: " << service.getName() << "\n";
        file << "Цена за сеанс: " << service.getPrice() << " руб.\n";
        file << "Количество сеансов: " << sessionCount << "\n";
        file << "Общая сумма: " << totalAmount << " руб.\n";
        file << "Дата и время покупки: " << purchaseDateTime << "\n";
        file << "===============\n";
        file.close();
    } else {
        cout << "Ошибка открытия файла для записи чека." << endl;
    }
}