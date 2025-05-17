#include <iostream>
#include <fstream>
#include "Header_7.h"

using namespace std;

// Реализация класса Vertex
Vertex::Vertex() : x(0), y(0), z(0) {}

Vertex::Vertex(double x, double y, double z) : x(x), y(y), z(z) {}

Vertex::Vertex(const Vertex& vert) {
    x = vert.x;
    y = vert.y;
    z = vert.z;
}

Vertex::~Vertex() {}

Vertex& Vertex::operator=(const Vertex& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

void Vertex::setX(double x) { this->x = x; }
void Vertex::setY(double y) { this->y = y; }
void Vertex::setZ(double z) { this->z = z; }
double Vertex::getX() const { return x; }
double Vertex::getY() const { return y; }
double Vertex::getZ() const { return z; }
void Vertex::Print() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

// Реализация класса Material
Material::Material() : material(""), color(""), texture("") {}

Material::Material(string mat, string col, string tex)
    : material(mat), color(col), texture(tex) {}

Material::Material(const Material& mat) {
    material = mat.material;
    color = mat.color;
    texture = mat.texture;
}

Material::~Material() {}

Material& Material::operator=(const Material& other) {
    if (this != &other) {
        material = other.material;
        color = other.color;
        texture = other.texture;
    }
    return *this;
}

void Material::setMaterial(string mat) { material = mat; }
void Material::setColor(string col) { color = col; }
void Material::setTexture(string tex) { texture = tex; }
string Material::getMaterial() const { return material; }
string Material::getColor() const { return color; }
string Material::getTexture() const { return texture; }
void Material::print() const {
    cout << "Материал: " << material << endl;
    cout << "Цвет: " << color << endl;
    cout << "Текстура: " << texture << endl;
}

// Реализация класса PhysicalProperties
PhysicalProperties::PhysicalProperties()
    : temperature(0), weight(0) {}

PhysicalProperties::PhysicalProperties(double temp, double weight)
    : temperature(temp), weight(weight) {}

PhysicalProperties::PhysicalProperties(const PhysicalProperties& pp)
    : temperature(pp.temperature), weight(pp.weight) {}

PhysicalProperties::~PhysicalProperties() {}

PhysicalProperties& PhysicalProperties::operator=(const PhysicalProperties& other) {
    if (this != &other) {
        temperature = other.temperature;
        weight = other.weight;
    }
    return *this;
}

void PhysicalProperties::setTemperature(double temp) { temperature = temp; }
void PhysicalProperties::setWeight(double weight) { this->weight = weight; }
double PhysicalProperties::getTemperature() const { return temperature; }
double PhysicalProperties::getWeight() const { return weight; }
void PhysicalProperties::print() const {
    cout << "Температура: " << temperature << endl;
    cout << "Масса: " << weight << endl;
}

// Реализация класса Object
Object::Object()
    : PhysicalProperties(), Material(), vertices(nullptr), vertexCount(0) {}

Object::Object(double x, double y, double z,
               string mat, string col, string tex,
               double temp, double weight)
    : PhysicalProperties(temp, weight),
      Material(mat, col, tex),
      vertexCount(1) {
    vertices = new Vertex[vertexCount];
    vertices[0] = Vertex(x, y, z);
}

Object::Object(const Object& obj)
    : PhysicalProperties(obj),
      Material(obj),
      vertexCount(obj.vertexCount) {
    vertices = new Vertex[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        vertices[i] = obj.vertices[i];
    }
}

Object::~Object() {
    delete[] vertices;
}

Object& Object::operator=(const Object& other) {
    if (this != &other) {
        PhysicalProperties::operator=(other);
        Material::operator=(other);

        delete[] vertices;
        vertexCount = other.vertexCount;

        vertices = new Vertex[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

void Object::setVertices(Vertex* vertices, int count) {
    delete[] this->vertices;
    this->vertices = new Vertex[count];
    for (int i = 0; i < count; i++) {
        this->vertices[i] = vertices[i];
    }
    vertexCount = count;
}

Vertex* Object::getVertices() const { return vertices; }
int Object::getVertexCount() const { return vertexCount; }

void Object::print() const {
    cout << "Список вершин:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < vertexCount; i++) {
        cout << "[" << i << "] ";
        vertices[i].Print();
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    Material::print();
    PhysicalProperties::print();
}

// Реализация шаблонного класса Figures
template<typename T>
Figures<T>::Figures()
    : figures(nullptr), figuresCount(0), figuresCapacity(0) {}

template<typename T>
Figures<T>::Figures(int capacity)
    : figuresCount(0), figuresCapacity(capacity) {
    figures = new T[figuresCapacity];
}

template<typename T>
Figures<T>::Figures(const Figures& other)
    : figuresCount(other.figuresCount),
      figuresCapacity(other.figuresCapacity) {
    figures = new T[figuresCapacity];
    for (int i = 0; i < figuresCount; i++) {
        figures[i] = other.figures[i];
    }
}

template<typename T>
Figures<T>::~Figures() {
    delete[] figures;
}

template<typename T>
Figures<T>& Figures<T>::operator=(const Figures<T>& other) {
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
T* Figures<T>::getFigures() const { return figures; }

template<typename T>
int Figures<T>::getFiguresCapacity() const { return figuresCapacity; }

template<typename T>
int Figures<T>::getFiguresCount() const { return figuresCount; }

template<typename T>
void Figures<T>::addFigure(T obj) {
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
}

template<typename T>
void Figures<T>::deleteFigure(int index) {
    if (index < 0 || index >= figuresCount) return;

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
void Figures<T>::print() const {
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
template class Figures<Object>;