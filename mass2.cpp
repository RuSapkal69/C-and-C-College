#include <iostream>
#include <string>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

// Function to add two integers
int add(int a, int b) {
    cout << "Adding two integers: " << a << " + " << b << endl;
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    cout << "Adding three integers: " << a << " + " << b << " + " << c << endl;
    return a + b + c;
}

// Function to concatenate two strings
string add(string a, string b) {
    cout << "Concatenating two strings: \"" << a << "\" + \"" << b << "\"" << endl;
    return a + b;
}

// Function to calculate the area of a rectangle
double calculateArea(double length, double width) {
    cout << "Calculating area of a rectangle with length = " << length << " and width = " << width << endl;
    return length * width;
}

// Function to calculate the area of a square
double calculateArea(double side) {
    cout << "Calculating area of a square with side = " << side << endl;
    return side * side;
}

// Function to calculate the area of a circle
double calculateAreaCircle(double radius) {
    cout << "Calculating area of a circle with radius = " << radius << endl;
    return M_PI * radius * radius;
}

// Function to calculate the area of a trapezoid
double calculateAreaTrapezoid(double base1, double base2, double height) {
    cout << "Calculating area of a trapezoid with base1 = " << base1 << ", base2 = " << base2 
         << " and height = " << height << endl;
    return 0.5 * (base1 + base2) * height;
}

// Function to multiply two floating-point numbers
float multiply(float a, float b) {
    cout << "Multiplying two floats: " << a << " * " << b << endl;
    return a * b;
}

// Function to multiply an integer and a float
float multiply(int a, float b) {
    cout << "Multiplying an integer and a float: " << a << " * " << b << endl;
    return a * b;
}

int main() {
    int choice;
    cout << "Choose an operation to test function overloading:\n";
    cout << "1. Add two integers\n";
    cout << "2. Add three integers\n";
    cout << "3. Concatenate two strings\n";
    cout << "4. Calculate area of a rectangle\n";
    cout << "5. Calculate area of a square\n";
    cout << "6. Calculate area of a circle\n";
    cout << "7. Calculate area of a trapezoid\n";
    cout << "8. Multiply two floating-point numbers\n";
    cout << "9. Multiply an integer and a float\n";
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int x, y;
            cout << "Enter two integers: ";
            cin >> x >> y;
            cout << "Result: " << add(x, y) << endl;
            break;
        }
        case 2: {
            int x, y, z;
            cout << "Enter three integers: ";
            cin >> x >> y >> z;
            cout << "Result: " << add(x, y, z) << endl;
            break;
        }
        case 3: {
            string str1, str2;
            cout << "Enter first string: ";
            cin.ignore();
            getline(cin, str1);
            cout << "Enter second string: ";
            getline(cin, str2);
            cout << "Result: \"" << add(str1, str2) << "\"" << endl;
            break;
        }
        case 4: {
            double length, width;
            cout << "Enter length of the rectangle: ";
            cin >> length;
            cout << "Enter width of the rectangle: ";
            cin >> width;
            cout << "Area of the rectangle: " << calculateArea(length, width) << endl;
            break;
        }
        case 5: {
            double side;
            cout << "Enter side of the square: ";
            cin >> side;
            cout << "Area of the square: " << calculateArea(side) << endl;
            break;
        }
        case 6: {
            double radius;
            cout << "Enter radius of the circle: ";
            cin >> radius;
            cout << "Area of the circle: " << calculateAreaCircle(radius) << endl;
            break;
        }
        case 7: {
            double base1, base2, height;
            cout << "Enter the first base of the trapezoid: ";
            cin >> base1;
            cout << "Enter the second base of the trapezoid: ";
            cin >> base2;
            cout << "Enter the height of the trapezoid: ";
            cin >> height;
            cout << "Area of the trapezoid: " << calculateAreaTrapezoid(base1, base2, height) << endl;
            break;
        }
        case 8: {
            float x, y;
            cout << "Enter two floating-point numbers: ";
            cin >> x >> y;
            cout << "Result: " << multiply(x, y) << endl;
            break;
        }
        case 9: {
            int x;
            float y;
            cout << "Enter an integer: ";
            cin >> x;
            cout << "Enter a floating-point number: ";
            cin >> y;
            cout << "Result: " << multiply(x, y) << endl;
            break;
        }
        default:
            cout << "Invalid choice! Please run the program again.\n";
    }

    return 0;
}
