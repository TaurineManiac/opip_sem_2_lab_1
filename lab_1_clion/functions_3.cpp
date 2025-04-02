#include "Header_3.h"                                   // Подключаем заголовочный файл класса StringLab3
#include <cctype>                                       // Подключаем библиотеку для работы с символами (например, isalpha)

using namespace std;                                    // Используем пространство имён std

// Конструктор по умолчанию: создаёт пустой массив строк
StringLab3::StringLab3() : size(0), capacity(10) {     // Инициализируем size и capacity
    data = new string[capacity];                        // Выделяем память под массив из 10 строк
}

// Конструктор с параметром: принимает одну строку и добавляет её в массив
StringLab3::StringLab3(const string& str) : size(1), capacity(10) {  // Инициализируем size=1, capacity=10
    data = new string[capacity];                        // Выделяем память под массив из 10 строк
    data[0] = str;                                      // Добавляем переданную строку в начало массива
}

// Конструктор копирования: создаёт глубокую копию объекта
StringLab3::StringLab3(const StringLab3& other) : size(other.size), capacity(other.capacity) {  // Копируем size и capacity
    data = new string[capacity];                        // Выделяем новую память под массив
    for (int i = 0; i < size; ++i) {                    // Проходим по всем строкам
        data[i] = other.data[i];                        // Копируем каждую строку
    }
}

// Деструктор: освобождаем память
StringLab3::~StringLab3() {                            // Деструктор вызывается при уничтожении объекта
    delete[] data;                                      // Освобождаем память, выделенную под массив
}

// Геттер для массива строк: возвращает указатель на массив
const string* StringLab3::getData() const {            // Метод помечен как const, не изменяет объект
    return data;                                        // Возвращаем указатель на массив (нельзя изменить строки через этот указатель)
}

// Геттер для размера массива
int StringLab3::getSize() const {                      // Метод помечен как const, не изменяет объект
    return size;                                        // Возвращаем текущий размер массива
}

// Геттер для вместимости массива
int StringLab3::getCapacity() const {                  // Метод помечен как const, не изменяет объект
    return capacity;                                    // Возвращаем максимальную вместимость массива
}

// Метод для добавления строки в конец массива
void StringLab3::addString(const string& str) {        // Принимаем строку по константной ссылке
    while(size >= capacity){
        if (size >= capacity) {                             // Проверяем, достаточно ли места в массиве
            capacity *= 2;                                  // Удваиваем вместимость, если места не хватает
            string* newData = new string[capacity];         // Выделяем новую память с увеличенной вместимостью
            for (int i = 0; i < size; ++i) {                // Проходим по всем текущим строкам
                newData[i] = data[i];                       // Копируем старые данные в новый массив
            }
            delete[] data;                                  // Освобождаем старую память
            data = newData;                                 // Обновляем указатель на новый массив
        }
    }
    data[size] = str;                                   // Добавляем новую строку в конец массива
    ++size;                                             // Увеличиваем размер массива
}

// Сеттер для строки по индексу
void StringLab3::setData(int index, const string& str) {  // Принимаем индекс и новую строку
    if (index < 0 || index >= size) {                   // Проверяем, что индекс в допустимом диапазоне
        throw runtime_error("Ошибка: индекс вне диапазона.");  // Бросаем исключение, если индекс некорректен
    }
    data[index] = str;                                  // Устанавливаем новое значение строки по указанному индексу
}

// Перегрузка оператора <: сравниваем все строки в массиве
bool StringLab3::operator<(const StringLab3& other) const {  // Метод помечен как const, не изменяет объект
    int minSize = min(size, other.size);                // Находим минимальный размер для сравнения
    for (int i = 0; i < minSize; ++i) {                 // Проходим по строкам обоих массивов
        if (data[i] != other.data[i]) {                 // Если строки на текущей позиции различаются
            return data[i] < other.data[i];             // Возвращаем результат их сравнения
        }
    }
    return size < other.size;                           // Если все строки равны, сравниваем по размеру массивов
}

// Перегрузка оператора >: сравниваем все строки в массиве
bool StringLab3::operator>(const StringLab3& other) const {  // Метод помечен как const, не изменяет объект
    int minSize = min(size, other.size);                // Находим минимальный размер для сравнения
    for (int i = 0; i < minSize; ++i) {                 // Проходим по строкам обоих массивов
        if (data[i] != other.data[i]) {                 // Если строки на текущей позиции различаются
            return data[i] > other.data[i];             // Возвращаем результат их сравнения
        }
    }
    return size > other.size;                           // Если все строки равны, сравниваем по размеру массивов
}

// Перегрузка оператора !=: проверяем на неравенство
bool StringLab3::operator!=(const StringLab3& other) const {  // Метод помечен как const, не изменяет объект
    if (size != other.size) {                           // Если размеры массивов разные
        return true;                                     // Возвращаем true (массивы не равны)
    }
    for (int i = 0; i < size; ++i) {                    // Проходим по всем строкам
        if (data[i] != other.data[i]) {                 // Если строки на текущей позиции различаются
            return true;                                 // Возвращаем true (массивы не равны)
        }
    }
    return false;                                       // Если все строки равны, возвращаем false (массивы равны)
}

// Перегрузка оператора +=: добавляем строку ко всем строкам массива
StringLab3& StringLab3::operator+=(const StringLab3& other) {  // Принимаем другой объект по константной ссылке
    if (other.size == 0) {                              // Проверяем, есть ли строки в other
        return *this;                                   // Если other пустой, ничего не делаем
    }

    if (size == 0) {                                    // Если текущий массив пустой
        addString(other.data[0]);                       // Добавляем строку из other как первый элемент
    } else {                                            // Если в массиве уже есть строки
        for (int i = 0; i < size; ++i) {                // Проходим по всем строкам текущего массива
            data[i] += other.data[0];                   // Добавляем строку из other к каждой строке
        }
    }
    return *this;                                       // Возвращаем текущий объект для цепочки операций
}


// Friend-функция для вывода объекта StringLab3 в поток
ostream& operator<<(ostream& out, const StringLab3& str) {  // Принимаем поток и объект по константной ссылке
    if (str.size == 0) {                                // Проверяем, пустой ли массив
        out << "Массив пуст";                            // Если пустой, выводим сообщение
    } else {                                            // Если массив не пустой
        out << "Массив строк: ";                        // Выводим заголовок
        for (int i = 0; i < str.size; ++i) {            // Проходим по всем строкам
            out << str.data[i];                         // Выводим текущую строку
            if (i < str.size - 1) {                     // Если это не последняя строка
                out << ", ";                             // Добавляем запятую и пробел
            }
        }
    }
    return out;                                         // Возвращаем поток для цепочки операций
}

istream& operator>>(istream& in, StringLab3& other){
    string temp;
    while(true){
        int spaceCounter=0;
        cout<< "Введите строку:" << endl;
        getline(in, temp);
        if(temp.empty()){
            cout << "Строка не должна быть пустой." << endl;
            temp.clear();
            continue;
        }
        for(int i=0;i<temp.size();i++){
            if(isspace(temp[i])){
                spaceCounter++;
            }
        }
        if(temp.size()==spaceCounter){
            cout << "Строка не должна быть пробельной." << endl;
            temp.clear();
            continue;
        }
        for(int i=0;i<temp.size();i++){
            if(isalpha(temp[i])){
                temp[i]= tolower(temp[i]);
            }
        }
        size_t start = temp.find_first_not_of(" \t");
        size_t end = temp.find_last_not_of(" \t");

        temp = temp.substr(start, end - start + 1);     // Обрезаем начальные и конечные пробелы

        // Добавляем строку в массив
        other.addString(temp);                            // Добавляем новую строку в конец массива
        break;                                          // Выходим из цикла, так как ввод корректен

    }
    return in;                                          // Возвращаем поток для цепочки операций
}
