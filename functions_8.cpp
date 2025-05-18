#include <iostream>
#include <fstream>
#include "Header_8.h"

using namespace std;

// Реализация класса Point3D
Point3D::Point3D() : x(0), y(0), z(0) {}

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

Point3D::Point3D(const Point3D& vert) {
    x = vert.x;
    y = vert.y;
    z = vert.z;
}

Point3D& Point3D::operator=(const Point3D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

Point3D::~Point3D() {}

void Point3D::setX(double x) { this->x = x; }
void Point3D::setY(double y) { this->y = y; }
void Point3D::setZ(double z) { this->z = z; }
double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }
void Point3D::Print() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

// Реализация класса SurfaceMaterial
SurfaceMaterial::SurfaceMaterial() : material(""), color(""), texture("") {}

SurfaceMaterial::SurfaceMaterial(string mat, string col, string tex)
    : material(mat), color(col), texture(tex) {}

SurfaceMaterial::SurfaceMaterial(const SurfaceMaterial& mat) {
    material = mat.material;
    color = mat.color;
    texture = mat.texture;
}

SurfaceMaterial& SurfaceMaterial::operator=(const SurfaceMaterial& other) {
    if (this != &other) {
        material = other.material;
        color = other.color;
        texture = other.texture;
    }
    return *this;
}

SurfaceMaterial::~SurfaceMaterial() {}

void SurfaceMaterial::setMaterial(string mat) { material = mat; }
void SurfaceMaterial::setColor(string col) { color = col; }
void SurfaceMaterial::setTexture(string tex) { texture = tex; }
string SurfaceMaterial::getMaterial() const { return material; }
string SurfaceMaterial::getColor() const { return color; }
string SurfaceMaterial::getTexture() const { return texture; }
void SurfaceMaterial::print() const {
    cout << "Материал: " << material << endl;
    cout << "Цвет: " << color << endl;
    cout << "Текстура: " << texture << endl;
}

// Реализация класса ObjectPhysics
ObjectPhysics::ObjectPhysics()
    : temperature(0), weight(0) {}

ObjectPhysics::ObjectPhysics(double temp, double weight)
    : temperature(temp), weight(weight) {}

ObjectPhysics::ObjectPhysics(const ObjectPhysics& pp)
    : temperature(pp.temperature), weight(pp.weight) {}

ObjectPhysics& ObjectPhysics::operator=(const ObjectPhysics& other) {
    if (this != &other) {
        temperature = other.temperature;
        weight = other.weight;
    }
    return *this;
}

ObjectPhysics::~ObjectPhysics() {}

void ObjectPhysics::setTemperature(double temp) { temperature = temp; }
void ObjectPhysics::setWeight(double weight) { this->weight = weight; }
double ObjectPhysics::getTemperature() const { return temperature; }
double ObjectPhysics::getWeight() const { return weight; }
void ObjectPhysics::print() const {
    cout << "Температура: " << temperature << endl;
    cout << "Масса: " << weight << endl;
}

// Реализация класса GraphicObject
GraphicObject::GraphicObject()
    : ObjectPhysics(), SurfaceMaterial(), vertices(nullptr), vertexCount(0) {}

GraphicObject::GraphicObject(int vertexCount, double* xCoords, double* yCoords, double* zCoords, string mat, string col, string tex, double temp, double weight)
    : ObjectPhysics(temp, weight), SurfaceMaterial(mat, col, tex), vertexCount(vertexCount) {
    vertices = new Point3D[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        vertices[i] = Point3D(xCoords[i], yCoords[i], zCoords[i]);
    }
}

GraphicObject::GraphicObject(const GraphicObject& obj)
    : ObjectPhysics(obj), SurfaceMaterial(obj), vertexCount(obj.vertexCount) {
    vertices = new Point3D[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        vertices[i] = obj.vertices[i];
    }
}

GraphicObject& GraphicObject::operator=(const GraphicObject& other) {
    if (this != &other) {
        ObjectPhysics::operator=(other);
        SurfaceMaterial::operator=(other);

        delete[] vertices;
        vertexCount = other.vertexCount;

        vertices = new Point3D[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

GraphicObject::~GraphicObject() {
    delete[] vertices;
}

void GraphicObject::setVertices(Point3D* vertices, int count) {
    delete[] this->vertices;
    this->vertices = new Point3D[count];
    for (int i = 0; i < count; i++) {
        this->vertices[i] = vertices[i];
    }
    vertexCount = count;
}

Point3D* GraphicObject::getVertices() const { return vertices; }
int GraphicObject::getVertexCount() const { return vertexCount; }

void GraphicObject::addVertex(double x, double y, double z) {
    Point3D* NewVertices = new Point3D[vertexCount + 1];
    for (int i = 0; i < vertexCount; i++) {
        NewVertices[i] = vertices[i];
    }
    NewVertices[vertexCount] = Point3D(x, y, z); // Исправлен индекс
    delete[] this->vertices;
    vertices = NewVertices;
    vertexCount++;
}

void GraphicObject::print() const {
    cout << "Список вершин:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < vertexCount; i++) {
        cout << "[" << i << "] ";
        vertices[i].Print();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    SurfaceMaterial::print();
    ObjectPhysics::print();
}

// Реализация шаблонного класса SceneObjects
template<typename T>
SceneObjects<T>::SceneObjects()
    : figures(nullptr), figuresCount(0), figuresCapacity(0) {}

template<typename T>
SceneObjects<T>::SceneObjects(int capacity)
    : figuresCount(0), figuresCapacity(capacity) {
    figures = new T[figuresCapacity];
}

template<typename T>
SceneObjects<T>::SceneObjects(const SceneObjects& other)
    : figuresCount(other.figuresCount),
      figuresCapacity(other.figuresCapacity) {
    figures = new T[figuresCapacity];
    for (int i = 0; i < figuresCount; i++) {
        figures[i] = other.figures[i];
    }
}

template<typename T>
SceneObjects<T>::~SceneObjects() {
    delete[] figures;
}

template<typename T>
SceneObjects<T>& SceneObjects<T>::operator=(const SceneObjects<T>& other) {
    if (this != &other) {
        delete[] figures;
        figuresCount = other.figuresCount;
        figuresCapacity = other.figuresCapacity;
        figures = new T[figuresCapacity];
        for (int i = 0; i < figuresCount; i++) {
            figures[i] = other.figures[i];
        }
    }
    return *this;
}

template<typename T>
T* SceneObjects<T>::getFigures() const { return figures; }

template<typename T>
int SceneObjects<T>::getFiguresCapacity() const { return figuresCapacity; }

template<typename T>
int SceneObjects<T>::getFiguresCount() const { return figuresCount; }

template<typename T>
void SceneObjects<T>::addFigure(T obj, RenderHistory<T>& history) { // Добавить параметр
    if (figuresCount >= figuresCapacity) {
        int newCapacity = (figuresCapacity == 0) ? 1 : figuresCapacity * 2;
        T* newArray = new T[newCapacity];
        for (int i = 0; i < figuresCount; i++) {
            newArray[i] = figures[i];
        }
        delete[] figures;
        figures = newArray;
        figuresCapacity = newCapacity;
    }
    figures[figuresCount++] = obj;
    history.addFigureHistory(obj); // Использовать переданный history
}

template<typename T>
void SceneObjects<T>::deleteFigure(int index, RenderHistory<T>& history) {
    if (index < 0 || index >= figuresCount) return;

    history.setFigureType("deleted", index);

    for (int i = index; i < figuresCount - 1; i++) {
        figures[i] = figures[i + 1];
    }
    figuresCount--;

    if (figuresCount < figuresCapacity / 2 && figuresCapacity > 1) {
        int newCapacity = figuresCapacity / 2;
        T* newArray = new T[newCapacity];
        for (int i = 0; i < figuresCount; i++) {
            newArray[i] = figures[i];
        }
        delete[] figures;
        figures = newArray;
        figuresCapacity = newCapacity;
    }
}

template<typename T>
void SceneObjects<T>::recoverFigure(int index, RenderHistory<T>& history) {
    if (index < 0 || index >= history.getFigureHistoryCount()) {
        cout << "Недопустимый индекс для восстановления." << endl;
        return;
    }
    if (history.getFigureType(index) != "deleted") {
        cout << "Фигура с индексом " << index << " не была удалена." << endl;
        return;
    }
    T* historyFigures = history.getFigureHistory();
    addFigure(historyFigures[index], history); // Восстанавливаем фигуру
    history.setFigureType("recovered", index); // Обновляем статус в истории
    cout << "Фигура с индексом " << index << " восстановлена." << endl;
}

template<typename T>
void SceneObjects<T>::print() const {
    if (figuresCount == 0) {
        cout << "Фигур нет:" << endl;
        return;
    }
    cout << "Список фигур:" << endl;
    cout << "===========================" << endl;
    for (int i = 0; i < figuresCount; i++) {
        cout << "--------------" << i << "--------------" << endl;
        figures[i].print();
        cout << "-----------------------------" << endl;
    }
    cout << "===========================" << endl;
}

// Явная инстанциация шаблона
template class SceneObjects<GraphicObject>;

template<typename T>
RenderHistory<T>::RenderHistory() : figures(nullptr), figuresCount(0), figuresCapacity(0), figureType(nullptr) {}

template<typename T>
RenderHistory<T>::RenderHistory(int figuresCapacity) : figuresCapacity(figuresCapacity), figuresCount(0) {
    figures = new T[figuresCapacity];
    figureType = new string[figuresCapacity];
}

template<typename T>
RenderHistory<T>::~RenderHistory() {
    delete[] figureType;
    delete[] figures;
}

template<typename T>
RenderHistory<T>::RenderHistory(const RenderHistory& figureHistory) {
    figuresCapacity = figureHistory.figuresCapacity;
    figureType = new string[figureHistory.getFigureHistoryCapacity()];
    figures = new T[figureHistory.getFigureHistoryCapacity()];
    figuresCount = figureHistory.getFigureHistoryCount();
    for (int i = 0; i < figuresCount; i++) {
        figures[i] = figureHistory.figures[i];
        figureType[i] = figureHistory.getFigureType(i);
    }
}

template<typename T>
RenderHistory<T>& RenderHistory<T>::operator=(const RenderHistory& figureHistory) {
    if (this != &figureHistory) {
        delete[] figures;
        delete[] figureType;
        figuresCapacity = figureHistory.getFigureHistoryCapacity();
        figures = new T[figureHistory.getFigureHistoryCapacity()];
        figureType = new string[figureHistory.getFigureHistoryCapacity()];
        figuresCount = figureHistory.figuresCount;
        for (int i = 0; i < figuresCount; i++) {
            figureType[i] = figureHistory.getFigureType(i);
            figures[i] = figureHistory.figures[i];
        }
    }
    return *this;
}

template<typename T>
T* RenderHistory<T>::getFigureHistory() const {
    return figures;
}

template<typename T>
string RenderHistory<T>::getFigureType(int index) const {
    if (index >= 0 && index < figuresCount) {
        return figureType[index];
    }
    return ""; // Возвращаем пустую строку при недопустимом индексе
}

template<typename T>
int RenderHistory<T>::getFigureHistoryCapacity() const {
    return figuresCapacity;
}

template<typename T>
int RenderHistory<T>::getFigureHistoryCount() const {
    return figuresCount;
}

template<typename T>
void RenderHistory<T>::setFigureType(string figureType, int index) {
    if (index >= 0 && index < figuresCount) {
        this->figureType[index] = figureType;
    }
}

template<typename T>
void RenderHistory<T>::print() const {
    if (figuresCount == 0) {
        cout << "Фigur нет:" << endl;
        return;
    }
    cout << "Список фигур:" << endl;
    cout << "===========================" << endl;
    for (int i = 0; i < figuresCount; i++) {
        cout << "--------------" << i << "--------------" << endl;
        figures[i].print();
        cout << "Тип фигуры: " << figureType[i] << endl;
        cout << "-----------------------------" << endl;
    }
    cout << "===========================" << endl;
}

template<typename T>
void RenderHistory<T>::addFigureHistory(const T& obj) {
    if (figuresCount >= figuresCapacity) {
        int newFiguresCapacity;
        if (figuresCapacity == 0) {
            newFiguresCapacity = 1;
        } else {
            newFiguresCapacity = 2 * figuresCapacity;
        }
        T* newFigures = new T[newFiguresCapacity];
        string* newFigureType = new string[newFiguresCapacity];
        for (int i = 0; i < figuresCount; i++) {
            newFigures[i] = figures[i];
            newFigureType[i] = figureType[i];
        }
        delete[] figures;
        delete[] figureType;
        figures = newFigures;
        figureType = newFigureType;
        figuresCapacity = newFiguresCapacity;
    }
    figures[figuresCount] = obj;
    figureType[figuresCount] = "added";
    figuresCount++;
}

template class RenderHistory<GraphicObject>;