#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Platform-specific delay function
#ifdef _WIN32
    #include <windows.h>  // For Sleep() function
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>  // For usleep() function
    #define SLEEP(ms) usleep((ms) * 1000)  // Convert milliseconds to microseconds
#endif

// Fibonacci Search function
int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    int idx = 0;
    int step = 0;  // Step counter to show the number of steps during the search

    printf("\033[1;32m\nStarting Fibonacci search..............\033[0m\n");

    // Find the smallest Fibonacci number greater than or equal to n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    while (fib > 1) {
        step++;
        int offset = (idx + fib2 < n) ? idx + fib2 : n - 1;

        // Print step info and direction of the search
        printf("\nStep %d: Checking element at index %d\n", step, offset);

        if (arr[offset] == x) {
            printf("Element found at index %d\n", offset);
            return offset;
        }

        if (arr[offset] < x) {
            printf("Moving right (searching in the larger part)\n");
            idx = offset;
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
        } else {
            printf("Moving left (searching in the smaller part)\n");
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }

        // Show the array size reduction in each step
        printf("\033[1;33mArray size reduced to %d elements\033[0m\n", n - idx);

        // Add a delay to simulate animation effect
        SLEEP(4000);  // Sleep for 500 milliseconds (platform-specific)
    }

    // Checking if the last remaining element is the target
    if (arr[idx] == x) {
        return idx;
    }

    return -1;  // If the element is not found
}

int main() {
    int data[MAX_SIZE];
    int n = MAX_SIZE;
    int x, result;
    int low = 1000, high = 5000, num;
    int choice;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    // Infinite loop to keep showing the menu
    while (1) {
        
        printf("\033[1;35m\n\t\t\t\t\t\t*~*~*~*~*~*~*~*~*~*~*~*~* Fibonacci Search Project *~*~*~*~*~*~*~*~*~*~*~*~*\033[0m\n"); //Bold magenta
        printf("\033[1;33m\t\t\t\t\t\t1. Generate and display array of random numbers\033[0m\n");  // Bold yellow
        printf("\033[1;32m\t\t\t\t\t\t2. Perform Fibonacci search\033[0m\n");                 // Bold green
        printf("\033[1;31m\t\t\t\t\t\t3. Exit\033[0m\n");                                           // Bold red
        printf("\033[1;34m\t\t\t\t\t\t--~~--~~--~~--~~--~~--~~----~~--~~--~~--~~--~~--~~----~~--~~--~~--~~--~~--~~--\033[0m\n");

        printf("\033[1;34mEnter your choice: \033[0m");  // Bold blue text
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Generate 1000 random numbers between 1000 and 5000
                printf("\033[1;32m\nGenerating array of random numbers...\n\033[0m");  // Bold green text
                for (int i = 0; i < n; i++) {
                    num = rand() % (high - low + 1) + low;  // Corrected random number formula
                    data[i] = num;
                }

                // Sort the array for Fibonacci search
                qsort(data, n, sizeof(int), compare);

                printf("\033[1;32m\nArray generated and sorted from 0 to 999 elements:\n\033[0m");  // Bold green text
                for (int i = 0; i < n; i++) {
                    printf("Index[%d]: %5d\n", i, data[i]);
                }
                break;

            case 2:
                // Get user input for the element to search
                printf("\033[1;32m\nEnter the element to search for: \033[0m");  // Bold green text

                scanf("%d", &x);

                // Start the clock to measure time taken
                start = clock();

                // Perform Fibonacci search
                result = fibonacciSearch(data, n, x);

                // Stop the clock
                end = clock();

                // Calculate time taken
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

                if (result == -1) {
                    printf("\033[1;31m\nElement not found.\n\033[0m");  // Bold red text

                } else {
                    printf("\033[1;32m\nElement found at index %d\n\033[0m", result);  // Bold green text

                }

                // Display the time taken and time complexity
                printf("\033[1;36m\nTime taken for search: %f seconds\n\033[0m", time_taken); 
                printf("\033[1;36mTime Complexity of Fibonacci Search: O(log n)\033[0m\n");   // Bold cyan text

                break;

            case 3:
               printf("\033[1;31mExiting the program................\033[0m\n");             // Bold red text
                exit(0);

            default:
                printf("\033[1;31mInvalid choice. Please try again.\033[0m\n"); // Bold red text
            break;
        }
    }

    return 0;
}
