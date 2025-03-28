#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_SIZE 1000

// Global variables
int data[MAX_SIZE];
int n = MAX_SIZE;
HWND hwndOutput;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Fibonacci Search function
int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    int idx = 0;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    while (fib > 1) {
        int offset = (idx + fib2 < n) ? idx + fib2 : n - 1;

        if (arr[offset] == x) {
            return offset;
        }

        if (arr[offset] < x) {
            idx = offset;
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
        } else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (arr[idx] == x) {
        return idx;
    }
    return -1;
}

// Function to display output in the GUI
void displayOutput(const char* output) {
    SendMessage(hwndOutput, WM_SETTEXT, 0, (LPARAM)output);
}

// Window Procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND btnGenerate, btnSearch, txtInput;

    switch (uMsg) {
        case WM_CREATE:
            btnGenerate = CreateWindow("BUTTON", "Generate Numbers",
                                        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                        20, 50, 150, 30, hwnd, (HMENU)1, NULL, NULL);
            btnSearch = CreateWindow("BUTTON", "Search Number",
                                      WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                      20, 100, 150, 30, hwnd, (HMENU)2, NULL, NULL);
            txtInput = CreateWindow("EDIT", "",
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     200, 100, 100, 30, hwnd, NULL, NULL, NULL);
            hwndOutput = CreateWindow("STATIC", "",
                                       WS_CHILD | WS_VISIBLE | SS_LEFT,
                                       20, 150, 380, 200, hwnd, NULL, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == 1) { // Generate Numbers button
                srand(time(NULL));
                for (int i = 0; i < n; i++) {
                    data[i] = rand() % (5000 - 1000 + 1) + 1000; // Generate numbers between 1000 and 5000
                }
                qsort(data, n, sizeof(int), compare);
                char buffer[5000];
                sprintf(buffer, "Generated Numbers:\n");
                for (int i = 0; i < n; i++) {
                    sprintf(buffer + strlen(buffer), "Index[%d]: %5d\n", i, data[i]);
                }
                displayOutput(buffer);
            } else if (LOWORD(wParam) == 2) { // Search Number button
                char input[10];
                GetWindowText(txtInput, input, sizeof(input));
                int x = atoi(input);
                int result = fibonacciSearch(data, n, x);
                char buffer[100];
                if (result == -1) {
                    sprintf(buffer, "Element %d not found.", x);
                } else {
                    sprintf(buffer, "Element %d found at index %d.", x, result);
                }
                displayOutput(buffer);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Main function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "FibonacciSearchWindowClass";

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Fibonacci Search GUI",
                               WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                               CW_USEDEFAULT, CW_USEDEFAULT, 400, 400,
                               NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
