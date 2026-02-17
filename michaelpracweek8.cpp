#include <iostream>
using namespace std;

class Square {
protected:
    double side; 

public:

    Square(double s) {
        side = s;
        cout << "Square object created with side: " << side << endl;
    }

    ~Square() {
        cout << "Square object destroyed" << endl;
    }

    double getPeri() {
        return 4 * side;
    }

    double getArea() {
        return side * side;
    }
};

class Cube : public Square {
public:

    Cube(double s) : Square(s) {
        cout << "Cube object created with side: " << side << endl;
    }

    
    ~Cube() {
        cout << "Cube object destroyed" << endl;
    }


    double getArea() {
        return 6 * side * side;
    }

    double getVolume() {
        return side * side * side;
    }
};

int main() {
    cout << "========== Square and Cube Shapes ==========\n" << endl;

    cout << "Creating Square:" << endl;
    Square square(5.0);
    
    cout << "\nSquare Details:" << endl;
    cout << "Side length: 5.0" << endl;
    cout << "Perimeter: " << square.getPeri() << endl;
    cout << "Area: " << square.getArea() << endl;
    
    cout << "\n------------------------------------------\n" << endl;
    

    cout << "Creating Cube:" << endl;
    Cube cube(3.0);
    
    cout << "\nCube Details:" << endl;
    cout << "Side length: 3.0" << endl;
    cout << "Surface Area: " << cube.getArea() << endl;
    cout << "Volume: " << cube.getVolume() << endl;
    
    cout << "\n========== Program Ending ==========\n" << endl;
    

    return 0;
}