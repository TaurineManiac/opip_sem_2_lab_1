#include <Header_6.h>
#include <iostream>
#include <stdio.h>
#include "generate.h"


using namespace std;
using namespace generate;

Department::Department():NameDept(""), Manager("") {

}

Department::Department(string name, string mgr) {
    NameDept = name;
    Manager = mgr;
}

Department::Department(const Department &other): NameDept(other.NameDept), Manager(other.Manager) {

}

void Department::setNameDept(const string &name) {
    NameDept = name;
}

string Department::getNameDept() const {
    return NameDept;
}

void Department::setManager(const string &mgr) {
    Manager = mgr;
}

string Department::getManager() const {
    return Manager;
}

Department::~Department() {

}

void Department::print() const {
    cout << "Название департамента: " << getNameDept() << endl;
    cout << "Имя менеджера: " << getManager() << endl;
}

Location::Location(): Location("") {

}

void Location::setLocation(const string &loc){/////////////////////////////////////////////////////////////////////////
    LocationStr=loc;
}

Location::Location(const Location &other): Location(other.LocationStr) {

}

Location::~Location() {

}

Location::Location(string loc): LocationStr(loc) {

}

string Location::getLocation() const {
    return LocationStr;
}

void Location::print() const {
    cout << "Адрес: "<< LocationStr << endl;
}

Employee::Employee(): Nameemp(""), Address(""), Grade(0) {
}

Employee::Employee(string name, string addr, int grade): Nameemp(name), Address(addr), Grade(grade) {
}

Employee::Employee(const Employee &other): Nameemp(other.Nameemp), Address(other.Address), Grade(other.Grade) {
}

void Employee::setNameEmp(const string &name) {
    Nameemp = name;
}

string Employee::getNameEmp() const {
    return Nameemp;
}

void Employee::setAddress(const string &addr) {
    Address = addr;
}

string Employee::getAddress() const {
    return Address;
}

void Employee::setGrade(int grade) {
    Grade = grade;
}

int Employee::getGrade() const {
    return Grade;
}

void Employee::print() const {
    cout << "Имя рабочего: " << Nameemp << endl;
    cout << "Адрес: " << Address<<endl;
    cout << "Уровень квалификации" << Grade<< endl;
}

Employee::~Employee() {
}

Hourly_emp::Hourly_emp(): Hr_hour(0), pay_scale(0), Employee("","",0){

}

Hourly_emp::Hourly_emp(string name, string addr, int grade, double hr, double scale): Hr_hour(hr), pay_scale(scale), Employee(name,addr,grade) {

}

Hourly_emp::Hourly_emp(const Hourly_emp &other):Hr_hour(other.Hr_hour), pay_scale(other.pay_scale), Employee(other.Nameemp, other.Address, other.Grade) {

}

void Hourly_emp::setHr_hour(double hr) {
    Hr_hour = hr;
}

double Hourly_emp::getHr_hour() const {
    return Hr_hour;
}

void Hourly_emp::setPay_scale(double scale) {
    pay_scale = scale;
}

double Hourly_emp::getPay_scale() const {
    return pay_scale;
}

void Hourly_emp::print() const {
    cout << "Имя рабочего: " << Nameemp << endl;
    cout << "Адрес: " << Address<<endl;
    cout << "Уровень квалификации: " << Grade<< endl;
    cout << "Часы работы: " <<Hr_hour << endl;
    cout << "Ставка: " << pay_scale << endl;
}

Hourly_emp::~Hourly_emp() {

}

SalariedEmp::SalariedEmp():Salary(0), Employee("","",0) {

}

SalariedEmp::SalariedEmp(string name, string addr, int grade, double salary): Salary(salary), Employee(name,addr,grade) {

}

SalariedEmp::~SalariedEmp() {

}

SalariedEmp::SalariedEmp(const SalariedEmp &other): Salary(other.Salary), Employee(other.Nameemp, other.Address, other.Grade) {

}

void SalariedEmp::setSalary(double salary) {
    Salary = salary;
}

double SalariedEmp::getSalary() const {
    return Salary;
}

void SalariedEmp::print() const {
    cout << "Имя рабочего: " << Nameemp << endl;
    cout << "Адрес: " << Address<<endl;
    cout << "Уровень квалификации" << Grade<< endl;
    cout << "Зарплата:" << Salary << endl;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для определения количества дней в месяце
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    return 30;
}

Completion_date::~Completion_date() {

}

Completion_date::Completion_date(int year,int month, int day): year(year), month(month), day(day) {

}

void Completion_date::setDate(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Completion_date::Completion_date(const Completion_date &other) {
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
}

Completion_date::Completion_date():year(0), month(0), day(0) {

}

int Completion_date::getYear() const {
    return year;
}

int Completion_date::getMonth() const {
    return month;
}

int Completion_date::getDay() const {
    return day;
}

void Completion_date::print() const {
    cout << day << "." << month << "." << year << endl;
}

Project::Project(): Namepro(""), Details(""), location(new Location()) {

}

Project::Project(string name, string details, Location *loc): Namepro(name), Details(details), location(loc) {

}

Project::Project(const Project& other) {
    this->Namepro = other.Namepro;
    this->Details = other.Details;
    this->location = new Location(*other.location); // Глубокое копирование
}

Project& Project::operator=(const Project& other) {
    if (this != &other) {
        delete location; // Освобождаем старую память
        this->Namepro = other.Namepro;
        this->Details = other.Details;
        this->location = new Location(*other.location); // Глубокое копирование
    }
    return *this;
}

Project::~Project() {
    delete location; // Убедимся, что память освобождается
}

void Project::setNamepro(const string &name) {
    this->Namepro = name;
}

string Project::getNamepro() const {
    return Namepro;
}

void Project::setDetails(const string &details) {
    this->Details = details;
}

string Project::getDetails() const {
    return Details;
}

void Project::setLocation(Location *loc) {
    this->location = loc;
}

Location *Project::getLocation() const {
    return location;
}

void Project::print() const {
    cout << "Название проекта: " << Namepro << endl;
    cout << "Описание проекта: " << Details << endl;
    cout << "Адрес проекта: " << location->getLocation() << endl;
}

Budget::~Budget() {

}

Budget::Budget(double value): Value(value) {

}

Budget::Budget():Value(0) {

}

Budget::Budget(const Budget &other) {
    this->Value = other.Value;
}

void Budget::setValue(double value) {
    this->Value = value;
}

double Budget::getValue() const {
    return this->Value;
}

void Budget::print() const {
    cout << "Бюджет проекта: " << Value<< endl;
}

Payable::Payable(double TE): TotalEarnings(TE) {

}

Payable::Payable(): TotalEarnings(0) {

}

void Payable::calculateEarning() {
    cout << "Заработок с проекта: "<<TotalEarnings*generateRandomDoubleNumber(0.1,5) << endl;
}

double Payable::getTotalEarnings() {
    return this->TotalEarnings;
}

ProjectPayable::ProjectPayable(): budget(), completionDate(new Completion_date()),assignedEmployee(nullptr), Payable(0), Project()  {

}

ProjectPayable::~ProjectPayable() {
    delete completionDate;
    delete assignedEmployee;
    delete budget;
}

ProjectPayable::ProjectPayable(string name, string details, Location* loc, double earnings, Budget* bud, Completion_date* compDate, Employee* emp)
    : Project(name, details, loc), Payable(earnings), budget(new Budget(*bud)), completionDate(new Completion_date(*compDate)), assignedEmployee(emp) {
    // Убедимся, что location уже обработан базовым классом
}

ProjectPayable::ProjectPayable(const ProjectPayable &other) {
    Payable(other.TotalEarnings);
    Project(other.Namepro,other.Details,other.location);
    budget=new Budget(*other.budget);
    assignedEmployee=new Employee(*other.assignedEmployee);
    completionDate=new Completion_date(*other.completionDate);
}

ProjectPayable &ProjectPayable::operator=(const ProjectPayable &other) {
    if (this != &other) {
        delete budget;
        delete completionDate;
        this->TotalEarnings = other.TotalEarnings;
        Project::operator=(other);
        budget=new Budget(*other.budget);
        this->assignedEmployee = other.assignedEmployee;
        completionDate = new Completion_date(*other.completionDate);
    }
    return *this;
}

void ProjectPayable::calculateEarning() {
    TotalEarnings = budget->getValue() * generateRandomDoubleNumber(0.1, 5); // Умножаем бюджет на случайный коэффициент
    cout << "Заработок с проекта: " << TotalEarnings << endl;
}

void ProjectPayable::setBudget(Budget *bud) {
    this->budget=bud;
}

void ProjectPayable::setAssignedEmployee(Employee *emp) {
    this->assignedEmployee=emp;
}

void ProjectPayable::setCompletionDate(Completion_date *compDate) {
    this->completionDate=compDate;
}

Budget *ProjectPayable::getBudget() const {
    return budget;
}

Employee *ProjectPayable::getAssignedEmployee() const {
    return assignedEmployee;
}

Completion_date *ProjectPayable::getCompletionDate() const {
    return completionDate;
}

void ProjectPayable::print() const {
    Project::print();
    budget->print();
    completionDate->print();
    cout << "Общие доходы: " << TotalEarnings << " руб.\n";
    cout << "Назначенный сотрудник: ";
    if (assignedEmployee != nullptr) {
        cout << "\n";
        assignedEmployee->print();
    } else {
        cout << "Сотрудник не назначен.\n";
    }
}

void addProjectPayable(ProjectPayable*& projects, int& size, int& capacity, string name, string details, Location* loc, Budget* bud, Completion_date* compDate, Employee* emp) {
    int newCapacity = capacity;
    if (size == capacity) {
        if (capacity == 0) {
            newCapacity = 1;
        } else {
            newCapacity += 2;
        }
        ProjectPayable* newProjects = new ProjectPayable[newCapacity];
        for (int i = 0; i < size; i++) {
            newProjects[i] = projects[i];
        }
        delete[] projects;
        projects = newProjects;
        capacity = newCapacity;
    }
    cout << "Отладка: Локация перед созданием проекта: " << loc->getLocation() << endl;
    projects[size] = ProjectPayable(name, details, loc, 0, bud, compDate, emp);
    projects[size].calculateEarning();
    size++;
    cout << "Проект успешно добавлен." << endl;
}

void addEmployee(Employee**& employees, int& size, int& capacity, Employee* emp) {
    int newCapacity = capacity;
    if (size==capacity) {
        if (capacity==0) {
            newCapacity=1;
        }
        else {
            newCapacity+=2;
        }
        Employee** newEmployees = new Employee*[newCapacity];
        for (int i = 0; i < size; i++) {
            newEmployees[i] = employees[i];
        }
        delete employees;
        employees = newEmployees;
        capacity = newCapacity;
    }
    employees[size]=emp;
    size++;
    cout << "Сотрудник успешно добавлен." << endl;
}

void printAllProjectPayables(const ProjectPayable* projects, int size) {
    if (size == 0) {
        cout << "Список проектов пуст.\n";
        return;
    }
    cout << "Список всех проектов:" << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < size; i++) {
        cout << "--------------" << i << "--------------" << endl;
        projects[i].print();
        cout << "------------------------------" << endl;
    }
}

void printAllEmployees(Employee** employees, int size) {
    if (size == 0) {
        cout << "Список сотрудников пуст.\n";
        return;
    }
    cout << "Список всех сотрудников:" << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < size; i++) {
        cout << "--------------" << i << "--------------" << endl;
        employees[i]->print();
        cout << "------------------------------" << endl;
    }
}
