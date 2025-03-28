#include <iostream>
using namespace std;

// Function to read the array
void readArray(int* arr, int size) {
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
}

// Function to display the array
void displayArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort function with passes and iterations
void bubbleSort(int* arr, int size) {
    cout << "\nSorting process:\n";
    for (int pass = 0; pass < size - 1; pass++) {
        cout << "Pass " << pass + 1 << ":\n";
        bool swapped = false; // To track if any swapping happens in this pass
        for (int i = 0; i < size - pass - 1; i++) {
            cout << "  Iteration " << i + 1 << ": Comparing " << *(arr + i) << " and " << *(arr + i + 1);
            if (*(arr + i) > *(arr + i + 1)) {
                swap((arr + i), (arr + i + 1));
                swapped = true;
                cout << " => Swapped";
            }
            cout << "\n    Array after iteration: ";
            displayArray(arr, size);
        }
        if (!swapped) {
            cout << "  No swaps in this pass. Array is already sorted.\n";
            break;
        }
    }
}

// Selection sort function
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + minIndex)) {
                minIndex = j;
            }
        }
        swap((arr + i), (arr + minIndex));
    }
}

// Insertion sort function
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = *(arr + i);
        int j = i - 1;

        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

int main() {
    int size;

    // Take the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Please enter a positive integer." << endl;
        return 1;
    }

    int* arr = new int[size]; // Dynamically allocate memory for the array

    // Read and display the array
    readArray(arr, size);
    cout << "Original Array: ";
    displayArray(arr, size);

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Display the sorted array
    cout << "Sorted Array (using Bubble Sort): ";
    displayArray(arr, size);

    delete[] arr; // Free allocated memory
    return 0;
}