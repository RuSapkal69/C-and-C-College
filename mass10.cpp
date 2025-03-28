#include <iostream>
#include <string>

using namespace std;

// Custom Namespace for Integer Operations
namespace MathOperations {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
}

// Custom Namespace for Floating-Point Operations
namespace AdvancedMath {
    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Error: Division by zero.");
        }
        return a / b;
    }
}

// Custom Namespace for String Operations
namespace StringOperations {
    string concatenate(string a, string b) {
        return a + " " + b;
    }

    void compareLength(string a, string b) {
        if (a.length() > b.length())
            cout << "\"" << a << "\" is longer than \"" << b << "\"" << endl;
        else if (a.length() < b.length())
            cout << "\"" << b << "\" is longer than \"" << a << "\"" << endl;
        else
            cout << "Both strings are of equal length." << endl;
    }
}

int main() {
    int choice;
    cout << "Choose operation:\n";
    cout << "1. Addition (Integers)\n2. Subtraction (Integers)\n";
    cout << "3. Multiplication (Decimals)\n4. Division (Decimals)\n";
    cout << "5. Concatenate Strings\n6. Compare String Length\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1 || choice == 2) {
        int a, b;
        cout << "Enter two integers: ";
        cin >> a >> b;

        if (choice == 1)
            cout << "Result: " << MathOperations::add(a, b) << endl;
        else
            cout << "Result: " << MathOperations::subtract(a, b) << endl;
    } 
    else if (choice == 3 || choice == 4) {
        double a, b;
        cout << "Enter two decimal numbers: ";
        cin >> a >> b;

        if (choice == 3)
            cout << "Result: " << AdvancedMath::multiply(a, b) << endl;
        else {
            try {
                cout << "Result: " << AdvancedMath::divide(a, b) << endl;
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
    } 
    else if (choice == 5 || choice == 6) {
        cin.ignore();  // To clear the newline character left in the buffer
        string str1, str2;
        cout << "Enter first string: ";
        getline(cin, str1);
        cout << "Enter second string: ";
        getline(cin, str2);

        if (choice == 5)
            cout << "Concatenated String: " << StringOperations::concatenate(str1, str2) << endl;
        else
            StringOperations::compareLength(str1, str2);
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
