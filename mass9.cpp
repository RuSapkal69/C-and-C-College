#include <iostream>
#include <string>
using namespace std;

// Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Class Template
template <typename T>
class Calculator {
private:
    T val1, val2;
public:
    Calculator(T v1, T v2) : val1(v1), val2(v2) {}
    
    T concatenate() {
        return val1 + val2;
    }
    
    void compare() {
        if (val1 == val2)
            cout << "Both values are equal." << endl;
        else
            cout << "Values are different." << endl;
    }
};

int main() {
    int choice;
    cout << "Choose data type: 1. Integer 2. Double 3. String: ";
    cin >> choice;
    cin.ignore(); // To handle newline character from previous input
    
    if (choice == 1) {
        int a, b;
        cout << "Enter two integers: ";
        cin >> a >> b;
        cout << "Addition: " << add(a, b) << endl;
    } 
    else if (choice == 2) {
        double a, b;
        cout << "Enter two double values: ";
        cin >> a >> b;
        cout << "Addition: " << add(a, b) << endl;
    } 
    else if (choice == 3) {
        string str1, str2;
        cout << "Enter first word: ";
        getline(cin, str1);
        cout << "Enter second word: ";
        getline(cin, str2);
        
        Calculator<string> calc(str1, str2);
        cout << "Concatenated String: " << calc.concatenate() << endl;
        calc.compare();
    } 
    else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
