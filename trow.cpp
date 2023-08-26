#include <iostream>
#include <string>

class A {
public:
    A() {
        std::cout << "A constructor" << std::endl;
    }

    ~A() {
        std::string errorMessage = "Exception thrown from A destructor";
        throw errorMessage;
    }
};

int main() {
    try {
        A obj;
    } 
    catch (const std::string& error) {
        std::cout << "Caught exception: " << error << std::endl;
    }

    return 0;
}
