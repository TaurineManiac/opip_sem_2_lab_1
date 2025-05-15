#ifndef HEADER_6_H
#define HEADER_6_H

#include <string>
#include "inputCheck.h"

using namespace std;

class Department {
protected:
    string NameDept;
    string Manager;

public:
    Department();
    Department(string name, string mgr);
    Department(const Department& other);
    virtual ~Department();

    void setNameDept(const string& name);
    void setManager(const string& mgr);

    string getNameDept() const;
    string getManager() const;

    virtual void print() const;
};

class Location {
protected:
    string LocationStr;

public:
    Location();
    Location(string loc);
    Location(const Location& other);
    virtual ~Location();

    void setLocation(const string& loc);
    string getLocation() const;

    virtual void print() const;
};

class Employee {
protected:
    string Nameemp;
    string Address;
    int Grade;

public:
    Employee();
    Employee(string name, string addr, int grade);
    Employee(const Employee& other);
    virtual ~Employee();

    void setNameEmp(const string& name);
    void setAddress(const string& addr);
    void setGrade(int grade);

    string getNameEmp() const;
    string getAddress() const;
    int getGrade() const;

    virtual void print() const;
};

class Hourly_emp : public Employee {
protected:
    double Hr_hour;
    double pay_scale;

public:
    Hourly_emp();
    Hourly_emp(string name, string addr, int grade, double hr, double scale);
    Hourly_emp(const Hourly_emp& other);
    virtual ~Hourly_emp();

    void setHr_hour(double hr);
    void setPay_scale(double scale);

    double getHr_hour() const;
    double getPay_scale() const;

    void print() const override;
};

class SalariedEmp : public Employee {
protected:
    double Salary;

public:
    SalariedEmp();
    SalariedEmp(string name, string addr, int grade, double salary);
    SalariedEmp(const SalariedEmp& other);
    virtual ~SalariedEmp();

    void setSalary(double salary);
    double getSalary() const;

    void print() const override;
};

class Completion_date {
protected:
    int year;
    int month;
    int day;

public:
    Completion_date();
    Completion_date(int year, int month, int day);
    Completion_date(const Completion_date& other);
    virtual ~Completion_date();

    void setDate(int year, int month, int day);
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    virtual void print() const;
};

class Project {
protected:
    string Namepro;
    string Details;
    Location* location;

public:
    Project();
    Project(string name, string details, Location* loc);
    Project(const Project& other);
    Project& operator=(const Project& other);
    virtual ~Project();

    void setNamepro(const string& name);
    void setDetails(const string& details);
    void setLocation(Location* loc);

    string getNamepro() const;
    string getDetails() const;
    Location* getLocation() const;

    virtual void print() const;
};

class Budget {
protected:
    double Value;

public:
    Budget();
    Budget(double value);
    Budget(const Budget& other);
    virtual ~Budget();

    void setValue(double value);
    double getValue() const;

    virtual void print() const;
};

class Payable {
protected:
    double TotalEarnings;

public:
    Payable();
    Payable(double TE);
    virtual void calculateEarning();
    double getTotalEarnings();
};

class ProjectPayable : public Project, public Payable {
protected:
    Budget* budget;
    Completion_date* completionDate;
    Employee* assignedEmployee;

public:
    ProjectPayable();
    ProjectPayable(string name, string details, Location* loc, double earnings, Budget* bud, Completion_date* compDate, Employee* emp = nullptr);
    ProjectPayable(const ProjectPayable& other);
    ProjectPayable& operator=(const ProjectPayable& other);
    virtual ~ProjectPayable();

    void setBudget(Budget* bud);
    void setCompletionDate(Completion_date* compDate);
    void setAssignedEmployee(Employee* emp);

    Budget* getBudget() const;
    Completion_date* getCompletionDate() const;
    Employee* getAssignedEmployee() const;

    void calculateEarning() override;
    void print() const override;
};

bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
void addProjectPayable(ProjectPayable*& projects, int& size, int& capacity, string name, string details, Location* loc, Budget* bud, Completion_date* compDate, Employee* emp = nullptr);
void printAllProjectPayables(const ProjectPayable* projects, int size);
void addEmployee(Employee**& employees, int& size, int& capacity, Employee* emp);
void printAllEmployees(Employee** employees, int size);

#endif // HEADER_6_H