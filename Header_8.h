#ifndef HEADER_8_H
#define HEADER_8_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Класс Point3D (вершина)
class Point3D {
protected:
    double x; // Используем double для большей точности
    double y;
    double z;

public:
    Point3D();
    Point3D(double x, double y, double z);
    Point3D(const Point3D& vert);
    Point3D& operator = (const Point3D& vert);
    ~Point3D();

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void Print() const;
};

// Класс SurfaceMaterial (материал)
class SurfaceMaterial {
protected:
    string material;
    string color;
    string texture;

public:
    SurfaceMaterial();
    SurfaceMaterial(string mat, string col, string tex);
    SurfaceMaterial(const SurfaceMaterial& mat);
    SurfaceMaterial& operator = (const SurfaceMaterial& mat);
    ~SurfaceMaterial();

    string getMaterial() const;
    string getColor() const;
    string getTexture() const;
    void setMaterial(string mat);
    void setColor(string col);
    void setTexture(string tex);

    void print() const;
};

// Класс ObjectPhysics (физические свойства)
class ObjectPhysics {
protected:
    double temperature;
    double weight; // Переименовано в weight для консистентности

public:
    ObjectPhysics();
    ObjectPhysics(double temp, double weight);
    ObjectPhysics(const ObjectPhysics& physicalProperties);
    ObjectPhysics& operator =(const ObjectPhysics& physicalProperties);
    ~ObjectPhysics();

    double getTemperature() const;
    double getWeight() const;
    void setTemperature(double temp);
    void setWeight(double weight);

    void print() const;
};

// Класс GraphicObject (объект, наследующий ObjectPhysics и SurfaceMaterial)
class GraphicObject : public ObjectPhysics, public SurfaceMaterial {
private:
    Point3D* vertices; // Исправлено на vertices (множественное число)
    int vertexCount;  // Добавлено для управления количеством вершин

public:
    GraphicObject();
    GraphicObject(int vertexCount, double* xCoords, double* yCoords, double* zCoords, string mat, string col, string tex, double temp, double weight);
    GraphicObject(const GraphicObject& obj);
    GraphicObject& operator=(const GraphicObject& obj);
    virtual ~GraphicObject();

    Point3D* getVertices() const;
    int getVertexCount() const;
    void setVertices(Point3D* vertices, int count);
    void addVertex(double x, double y, double z);

    void print() const;
};

template<typename T>
class RenderHistory {
private:
    T* figures;
    int figuresCapacity;
    int figuresCount;
    string* figureType;
public:
    RenderHistory();
    RenderHistory(int figuresCapacity);
    RenderHistory(const RenderHistory& figureHistory);
    RenderHistory& operator=(const RenderHistory& figureHistory);
    ~RenderHistory();

    int getFigureHistoryCapacity() const;
    int getFigureHistoryCount() const;
    T* getFigureHistory() const;
    string getFigureType(int index) const;
    void setFigureType(string figureType,int index);
    void addFigureHistory(const T& obj);

    void print() const;
};

template<typename T>
class SceneObjects {
private:
    T* figures;
    int figuresCount;
    int figuresCapacity;

public:
    SceneObjects();
    SceneObjects(int figuresCapacity);
    SceneObjects(const SceneObjects& figures);
    ~SceneObjects();
    SceneObjects& operator=(const SceneObjects& figures);

    int getFiguresCapacity() const;
    int getFiguresCount() const;
    T* getFigures() const;
    void addFigure(T obj, RenderHistory<T>& history); // Добавить параметр RenderHistory
    void deleteFigure(int index, RenderHistory<T>& history);
    void recoverFigure(int index, RenderHistory<T>& history);


    void print() const;
};

#endif //HEADER_8_H