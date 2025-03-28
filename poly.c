#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in sorted order based on exponent
void insertNode(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*poly == NULL || (*poly)->exponent < exponent) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->exponent >= exponent) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertNode(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertNode(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertNode(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to subtract two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertNode(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertNode(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int diff = poly1->coefficient - poly2->coefficient;
            if (diff != 0) {
                insertNode(&result, diff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    for (struct Node* temp1 = poly1; temp1 != NULL; temp1 = temp1->next) {
        for (struct Node* temp2 = poly2; temp2 != NULL; temp2 = temp2->next) {
            int coeff = temp1->coefficient * temp2->coefficient;
            int exp = temp1->exponent + temp2->exponent;
            insertNode(&result, coeff, exp);
        }
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        if (poly->coefficient > 0 && poly != NULL) {
            printf("+%dx^%d ", poly->coefficient, poly->exponent);
        } else {
            printf("%dx^%d ", poly->coefficient, poly->exponent);
        }
        poly = poly->next;
    }
    printf("\n");
}

// Function to input a polynomial
struct Node* inputPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        insertNode(&poly, coeff, exp);
    }
    return poly;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    int choice;

    printf("Input first polynomial:\n");
    poly1 = inputPolynomial();

    printf("Input second polynomial:\n");
    poly2 = inputPolynomial();

    do {
        printf("\nChoose the operation to perform:\n");
        printf("1. Add Polynomials\n");
        printf("2. Subtract Polynomials\n");
        printf("3. Multiply Polynomials\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = addPolynomials(poly1, poly2);
                printf("Result of Addition: ");
                displayPolynomial(result);
                break;

            case 2:
                result = subtractPolynomials(poly1, poly2);
                printf("Result of Subtraction: ");
                displayPolynomial(result);
                break;

            case 3:
                result = multiplyPolynomials(poly1, poly2);
                printf("Result of Multiplication: ");
                displayPolynomial(result);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please choose a valid operation.\n");
        }
    } while (choice != 4);

    return 0;
}
