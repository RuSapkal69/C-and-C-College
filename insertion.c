#include<stdio.h>

void printArray(int *A, int n) {
    for(int i = 0; i<n; i++ ) {
        printf("%d", A[i]);
        printf("\t");
    }
    
}

void insertionSort(int *A, int n) {

    int temp;
    int j;
    for (int i = 1; i<n; i++) {

        temp = A[i];
        j = i-1;
        while(j>=0 && A[j]>temp) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}


int main() {
    int i;
    int A[8];
    int n = 8;

    printf("Please enter 8 numbers :- ");
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Your input Array is :- ");
    printArray(A, n);
    insertionSort(A, n);
    printf("\n");
    printf("After sorting, required Array is :- ");
    printArray(A, n);
}