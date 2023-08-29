#include <iostream>
#include <string>

class Vector {
private:
    int* arr;
    int size;

public:
    Vector(int n) : size(n) {
        arr = new int[size];
    }

    ~Vector() {
        delete[] arr;
    }

    int& operator[](int index) {
        return arr[index];
    }

    int& at(int index) {
        if (index >= size) {
            throw std::string("Index out of bounds");
        }
        return (*this)[index];
    }
};

int main() {
    try {
        Vector myVector(5);
        myVector[3] = 10;
        std::cout << "Value at index 3: " << myVector.at(3) << std::endl;
        std::cout << "Value at index 6: " << myVector.at(6) << std::endl;
    } catch (const std::string& e) {
        std::cout << "Exception caught: " << e << std::endl;
    }

    return 0;
}
