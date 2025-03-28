#include <stdio.h>

void printArray(int A[], int size) {
    for (int i=0; i < size; i++) {          //print function(for displaying array)
        printf("%d\t", A[i]);
    }
}

void deleteElement(int A[], int size) {
    int choice, element, position, found = 0;

    printf("Choose deletion method:\n");
    printf("1. Delete by element value\n");
    printf("2. Delete by position\n");
    printf("Enter your choice (1 or 2): ");             //deleting an element by taking it's value or position.
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the element you want to delete: ");
        scanf("%d", &element);

        for (int i = 0; i < size; i++) {
            if (A[i] == element) {
                position = i;
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Element %d found at position %d, deleting...\n", element, position);

          
            for (int i = position; i < size - 1; i++) {
                A[i] = A[i + 1];
            }

            size--;

            printf("Array after deletion:\n");
            for (int i = 0; i < size; i++) {
                printf("%d\t", A[i]);
            }
            printf("\n");

        } else {
            printf("Element %d not found in the array.\n", element);
        }

    } else if (choice == 2) {
        
        printf("Enter the position of the element you want to delete (0 to %d): ", size - 1);
        scanf("%d", &position);

        if (position >= 0 && position < size) {
            printf("Deleting element %d at position %d...\n", A[position], position);

            for (int i = position; i < size - 1; i++) {
                A[i] = A[i + 1];
            }

            size--;

            printf("Array after deletion:\n");
            for (int i = 0; i < size; i++) {
                printf("%d\t", A[i]);
            }
            printf("\n");

        } else {
            printf("Invalid position.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void insertElement(int A[], int size) {
    int element, position;

    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the position (0 to %d) where you want to insert the element: ", size);
    scanf("%d", &position);

    if (position > size || position < 0) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", size);          //inserting an element
        return;
    }

    printf("Inserting %d at position %d......\n", element, position);
    for (int i = size; i > position; i--) {
        A[i] = A[i - 1];
        printf("Array after shifting element from index %d to %d: ", i-1, i);
        printArray(A, size + 1);
        printf("\n");
    }

    A[position] = element;
    printf("Element %d inserted at index %d: ", element, position);
    printArray(A, size + 1);
    printf("\n");
}

void linearSearch(int A[], int size, int target) {
    int found = 0;
    printf("Enter the element you have to find by linear searching :- ", target);
    scanf("%d", &target);
    for (int i = 0; i < size; i++) {
        printf("Comparing %d with %d ",target, A[i]);
        printf("\n");                                                        //linear search function
        if (A[i] == target) {
            printf("The target element is: %d\t", target);
            printf("\n");
            printf("The target element is present at index number: %d\t", i);
            found = 1;
            break; 
        } 
    }  
    if (!found) {
        printf("The target element %d is not present in the array.\n", target);
    }
}

void bubbleSort(int A[], int size) {
    for (int i = 0; i < size-1; i++) {
        printf("Working on pass no. :-%d", i+1);
        printf("\n");
        for (int j = 0; j < size-i-1; j++) {
            if (A[j] > A[j+1]) {                            //bubble-sorting function
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
            printf("Iteration no. :-%d" , i+1);
            printf("\n");
            printArray(A, 6);
            printf("\n");
        }
    }
}

void insertionSort(int A[], int size) {
    int temp;
    int j;

    for (int i = 1; i < size; i++) {
        temp = A[i];
        j = i - 1;

        printf("Inserting %d into the sorted subarray:\n", temp);

        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
            
            printf("Array after shifting %d to the right: ", A[j + 1]);
            printArray(A, size);
            printf("\n");
        }

        A[j + 1] = temp;

        printf("Array after inserting %d: ", temp);
        printArray(A, size);
        printf("\n\n");
    }
}

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[5], R[5];

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];                                 
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    printf("Array after merging from index %d to %d: ", left, right);
    printArray(A, right - left + 1);
    printf("\n");
}

void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);                        //merge_sorting
        mergeSort(A, mid + 1, right);  
        merge(A, left, mid, right);
    }
}

void selectionSort(int A[], int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size-1; i++) {
        minIndex = i;

        for (j = i+1; j < size; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }                                                     //selection sorting function
        }

        if (minIndex != i) {
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }

        printf("Array after pass %d:- ", i+1);
        printArray(A, size);
        printf("\n");
    }
}

void binarySearch(int A[], int size, int target) {
    int left = 0, right = size - 1;
    int mid;
    int found = 0;

    printf("Enter the element you want to find by Binary-searching method :- ");
    scanf("%d", &target);

    while (left <= right) {
        mid = left + (right-left)/2;  
        printf("The middle element is at index %d :- %d\n", mid, A[mid]);

        if (A[mid] == target) {
            printf("The target element %d is present at index number :- %d\n", target, mid);                //binary searching function
            found = 1;
            break;
        } else if (A[mid] < target) {
            left = mid + 1;
            printf("The element is greater than %d, moving right.\n", A[mid]);
        } else {
            right = mid - 1;
            printf("The element is less than %d, moving left.\n", A[mid]);
        }
    }

    if (!found) {
        printf("The target element %d is not present in the array.\n", target);
    }
}

int main() {
    int rollNumber;
    int target;
    int sum = 0;
    int A[5];
    int ArrayCase;
    int sort_Choice;
    
    printf("Enter a 5-digit roll number: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < 5; i++) {
        sum += rollNumber % 10;             //loop for sum of the digits in roll number.
        rollNumber /= 10;
    }
    printf("For Worstcase Array enter 0.");
    printf("\n");
    printf("For BestCase Array enter 1.");
    printf("\n");
    printf("For random array enter any integer.");
    printf("\n");
    scanf("%d", &ArrayCase);        //bestcase, worstcase, random array selection.
    if (ArrayCase==1) {
        A[0] = sum - 2;
        A[1] = sum - 1;
        A[2] = sum;
        A[3] = sum + 1;
        A[4] = sum + 2;
    }
    else if(ArrayCase==0) {
        A[0] = sum + 2;
        A[1] = sum + 1;
        A[2] = sum;
        A[3] = sum - 1;
        A[4] = sum - 2;
    }
    else{
        A[0] = sum;
        A[1] = sum + 1;
        A[2] = sum - 1;
        A[3] = sum + 2;
        A[4] = sum - 2;
    }
    
    printf("Unique Array to be generated is : ");
    printArray(A, 5);
    printf("\n");
    printf("\n");
    deleteElement(A, 5);
    printf("\n");
    insertElement(A, 5);
    printf("\n");
    linearSearch(A, 6, target);
    printf("\n");
    printf("For Bubble sorting enter 1.");
    printf("\n");
    printf("For insertion sorting enter 2.");
    printf("\n");
    printf("For merge-sorting enter 3.");
    printf("\n");
    printf("For selection sorting enter 4.");
    printf("\n");
    printf("To execute all, enter any integer.");
    printf("\n");
    scanf("%d", &sort_Choice);                      //sorting to be executed.
    printf("\n");
    if(sort_Choice==1) {
        bubbleSort(A, 6);
        printf("\n");
        printf("Array sorted using bubble sort :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
    }
    else if(sort_Choice==2) {
        insertionSort(A, 6);
        printf("Array sorted using insertion sort :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
    }
    else if(sort_Choice==3) {
        mergeSort(A, 0, 4);
        printf("\n");
        printf("Array sorted using merge-sorting :- ");
        printArray(A, 5);
        printf("\n");
        printf("\n");
    }
    else if(sort_Choice==4) {
        selectionSort(A, 6);
        printf("Array sorted using selection-sorting :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
    }
    else {
        bubbleSort(A, 6);
        printf("\n");
        printf("Array sorted using bubble sort :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
        insertionSort(A, 6);
        printf("Array sorted using insertion sort :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
        mergeSort(A, 0, 4);
        printf("\n");
        printf("Array sorted using merge-sorting :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
        selectionSort(A, 6);
        printf("Array sorted using selection-sorting :- ");
        printArray(A, 6);
        printf("\n");
        printf("\n");
    }
    binarySearch(A, 6, target);
    return 0;
}
