#include<stdio.h>


void bubbleSort(int *A, int n) {

    int temp;

    for (int i = 0; i<n-1; i++) {
        printf("Working on pass number %d :- \n", i+1);
        for (int j=0; j<n-1-i; j++) {
            if(A[j]>A[j+1]) {
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;

            }
        }
    }
}

void printArray(int *A, int n) {
    for (int i=0; i<n; i++) {
        printf("%d", A[i]);
        printf("\t");
    }
    
}

int main() {
    
    int i;
    int A[5];
    int n = 5;
    printf("PLease enter your 5-digit Roll No :- ");

    for (i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    printArray(A, n);
    printf("\n");
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}