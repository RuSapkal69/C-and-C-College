#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Function to display a complex number
    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }

    // Addition of two complex numbers
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction of two complex numbers
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication of two complex numbers
    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Division of two complex numbers
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;
        if (denominator == 0) {
            cout << "Error: Division by zero!" << endl;
            return Complex(0, 0);
        }
        return Complex((real * c.real + imag * c.imag) / denominator,
                       (imag * c.real - real * c.imag) / denominator);
    }

    // Finding complex conjugate
    Complex conjugate() const {
        return Complex(real, -imag);
    }
};

int main() {
    double r1, i1, r2, i2;
    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r1 >> i1;
    Complex c1(r1, i1);

    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r2 >> i2;
    Complex c2(r2, i2);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Complex Conjugate of first number\n";
        cout << "6. Complex Conjugate of second number\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Complex result;
        switch (choice) {
            case 1:
                cout << "First Complex Number: ";
                c1.display();
                cout << "Second Complex Number: ";
                c2.display();
                cout << "\t\t----------------" << endl;
                result = c1 + c2;
                cout << "\t\t" "Result: ";
                result.display();
                break;
            case 2:
                cout << "First Complex Number: ";
                c1.display();
                cout << "Second Complex Number: ";
                c2.display();
                cout << "\t\t----------------" << endl;
                result = c1 - c2;
                cout << "\t\t" "Result: ";
                result.display();
                break;
            case 3:
                cout << "First Complex Number: ";
                c1.display();
                cout << "Second Complex Number: ";
                c2.display();
                cout << "\t\t----------------" << endl;
                result = c1 * c2;
                cout << "\t\t" "Result: ";
                result.display();
                break;
            case 4:
                cout << "First Complex Number: ";
                c1.display();
                cout << "Second Complex Number: ";
                c2.display();
               cout << "\t\t----------------" << endl;
                result = c1 / c2;
                cout << "\t\t" "Result: ";
                result.display();
                break;
            case 5:
                cout << "Complex conjugate of first number: ";
                c1.conjugate().display();
                break;
            case 6:
                cout << "Complex conjugate of second number: ";
                c2.conjugate().display();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    } while (choice != 7);

    return 0;
}
