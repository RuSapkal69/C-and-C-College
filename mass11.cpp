#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void copyFile(const string& sourceFile, const string& destFile) {
    ifstream inputFile(sourceFile, ios::in);
    ofstream outputFile(destFile, ios::out);

    if (!inputFile) {
        cerr << "Error: Cannot open source file: " << sourceFile << endl;
        return;
    }
    if (!outputFile) {
        cerr << "Error: Cannot create destination file: " << destFile << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << "\n";
    }

    cout << "File copied successfully from " << sourceFile << " to " << destFile << "!\n";
    
    inputFile.close();
    outputFile.close();
}

int main() {
    string sourceFile, destFile;
    
    cout << "Enter the source file name: ";
    cin >> sourceFile;
    cout << "Enter the destination file name: ";
    cin >> destFile;

    copyFile(sourceFile, destFile);
    return 0;
}
