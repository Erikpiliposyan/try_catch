#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception {
private:
    std::string errorMessage;

public:
    CustomException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

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
        if (index >= size) {
            throw CustomException("Custom Index out of bounds");
        }
        return arr[index];
    }
};

int main() {
    try {
        Vector myVector(5);
        myVector[4] = 10;
        std::cout << "Value at index 4: " << myVector[4] << std::endl;
        std::cout << "Value at index 5: " << myVector[5] << std::endl;
    } catch (const CustomException& error) {
        std::cout << "Exception caught: " << error.what() << std::endl;
    }

    return 0;
}
