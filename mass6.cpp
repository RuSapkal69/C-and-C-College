#include <iostream>
#include <cstring>
using namespace std;

class StringOperations {
private:
    char str[100];

public:
    void acceptString() {
        cout << "Enter a string: ";
        cin.ignore();
        cin.getline(str, 100);
    }

    void displayString() {
        cout << "String: " << str << endl;
    }

    int findLength() {
        return strlen(str);
    }

    void copyString(char dest[]) {
        strcpy(dest, str);
    }

    void reverseString() {
        int len = strlen(str);
        for (int i = 0; i < len / 2; i++) {
            swap(str[i], str[len - i - 1]);
        }
    }

    void concatenateString(const char *other) {
        strcat(str, other);
    }

    char* getString() {
        return str;
    }
};

int main() {
    StringOperations str1, str2;
    int choice;
    char copiedStr[100];
    char extra[100];

    do {
        cout << "\nMenu:";
        cout << "\n1. Accept String";
        cout << "\n2. Display String";
        cout << "\n3. Find Length";
        cout << "\n4. Copy String";
        cout << "\n5. Reverse String";
        cout << "\n6. Concatenate Strings";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            str1.acceptString();
            break;
        case 2:
            str1.displayString();
            break;
        case 3:
            cout << "Length: " << str1.findLength() << endl;
            break;
        case 4:
            str1.copyString(copiedStr);
            cout << "Copied String: " << copiedStr << endl;
            break;
        case 5:
            str1.reverseString();
            cout << "Reversed String: ";
            str1.displayString();
            break;
        case 6:
            cout << "Enter another string to concatenate: ";
            cin.ignore();
            cin.getline(extra, 100);
            str1.concatenateString(extra);
            cout << "Concatenated String: ";
            str1.displayString();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
