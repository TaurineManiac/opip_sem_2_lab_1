#ifndef LAB_1_CLION_HEADER_4_H
#define LAB_1_CLION_HEADER_4_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Client {
protected:
    string name;
    string surname;

public:
    Client();
    Client(const string& name, const string& surname); // Уточнили, что параметры передаются по константной ссылке
    Client(const Client& other);
    virtual ~Client();

    // Геттеры и сеттеры
    virtual void setName(const string& name); // Добавили const для параметра
    virtual void setSurname(const string& surname); // Добавили const для параметра
    virtual string getName() const; // Добавили const для метода
    virtual string getSurname() const; // Добавили const для метода
};

class Service {
private:
    string name;
    double price;
    double costs;
    int duration;

public:
    Service();
    Service(const string& name, double price, double costs, int duration); // Уточнили, что параметры передаются по значению или константной ссылке
    Service(const Service& other);
    ~Service();

    // Геттеры и сеттеры
    void setName(const string& name);
    void setPrice(double price);
    void setCosts(double costs);
    void setDuration(int duration);
    string getName() const; // Добавили const
    double getPrice() const; // Добавили const
    double getCosts() const; // Добавили const
    int getDuration() const; // Добавили const
};

class Order : public Client {
private:
    Service service;
    int sessionCount;
    double totalAmount;
    string purchaseDateTime;

    string getCurrentDateTime() const;

public:
    Order();
    Order(const Client& client, const Service& service, int sessionCount);
    Order(const Order& other);
    ~Order();

    // Геттеры и сеттеры
    Service getService() const;
    int getSessionCount() const;
    double getTotalAmount() const;
    string getPurchaseDateTime() const;
    void setService(const Service& newService);
    void setSessionCount(int newSessionCount);

    // Методы для работы с чеком
    void calculateTotal();
    void printReceipt() const;
    void saveReceiptToFile(const string& filename) const;
};

#endif //LAB_1_CLION_HEADER_4_H