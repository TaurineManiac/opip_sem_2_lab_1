#ifndef HEADER_7_H
#define HEADER_7_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Класс Vertex (вершина)
class Vertex {
protected:
    double x; // Используем double для большей точности
    double y;
    double z;

public:
    Vertex();
    Vertex(double x, double y, double z);
    Vertex(const Vertex& vert);
    Vertex& operator = (const Vertex& vert);
    ~Vertex();

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void Print() const;
};

// Класс Material (материал)
class Material {
protected:
    string material;
    string color;
    string texture;

public:
    Material();
    Material(string mat, string col, string tex);
    Material(const Material& mat);
    Material& operator = (const Material& mat);
    ~Material();

    string getMaterial() const;
    string getColor() const;
    string getTexture() const;
    void setMaterial(string mat);
    void setColor(string col);
    void setTexture(string tex);

    void print() const;
};

// Класс PhysicalProperties (физические свойства)
class PhysicalProperties {
protected:
    double temperature;
    double weight; // Переименовано в weight для консистентности

public:
    PhysicalProperties();
    PhysicalProperties(double temp, double weight);
    PhysicalProperties(const PhysicalProperties& physicalProperties);
    PhysicalProperties& operator =(const PhysicalProperties& physicalProperties);
    ~PhysicalProperties();

    double getTemperature() const;
    double getWeight() const;
    void setTemperature(double temp);
    void setWeight(double weight);

    void print() const;
};

// Класс Object (объект, наследующий PhysicalProperties и Material)
class Object : public PhysicalProperties, public Material {
private:
    Vertex* vertices; // Исправлено на vertices (множественное число)
    int vertexCount;  // Добавлено для управления количеством вершин

public:
    Object();
    Object(int vertexCount, double* xCoords, double* yCoords, double* zCoords, string mat, string col, string tex, double temp, double weight);
    Object(const Object& obj);
    Object& operator=(const Object& obj);
    virtual ~Object();

    Vertex* getVertices() const;
    int getVertexCount() const;
    void setVertices(Vertex* vertices, int count);
    void addVertex(double x, double y, double z);

    void print() const;
};

template<typename T>
class Figures {
private:
    T* figures;
    int figuresCount;
    int figuresCapacity;

public:
    Figures();
    Figures(int figuresCapacity);
    Figures(const Figures& figures);
    ~Figures();
    Figures& operator=(const Figures& figures);
    int getFiguresCapacity() const;
    int getFiguresCount() const;
    T* getFigures() const;
    void addFigure(T obj);
    void deleteFigure(int index);
    void print() const;
};

#endif //HEADER_7_H