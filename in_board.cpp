#include <iostream>
#include <string>

class figure {
protected:
    const std::string white = "W";
    const std::string black = "B";

public:
    virtual ~figure() {}
    
    bool inBoard(int x, int y) {
        if (x <= 8 && x >= 1 && y <= 8 && y >= 1) {
            return true;
        }
        return false;
    }
};

int main() {
    try {
        figure f;

        int x, y;
        std::cout << "Enter x and y coordinates: ";
        std::cin >> x >> y;

        if (f.inBoard(x, y)) {
            std::cout << "Position (" << x << ", " << y << ") is on the chessboard." << std::endl;
        } else {
            throw std::string("Position is outside the chessboard.");
        }
    } catch (const std::string& error) {
        std::cout << "Caught exception: " << error << std::endl;
    }

    return 0;
}
