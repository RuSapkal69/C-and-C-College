#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

// Stack using array
int stack[MAX], top = -1;

// Queue using array
int queue[MAX], front = -1, rear = -1;

// Stack using linked list
struct Node {
    int data;
    struct Node* next;
};

// Linked list pointers for stack and queue
struct Node* topList = NULL;
struct Node *frontList = NULL, *rearList = NULL;

// Function declarations
void pushArray(int value);
void popArray();
void insertArray(int value);
void deleteArray();
void displayStackArray();
void displayQueueArray();

void pushList(int value);
void popList();
void insertList(int value);
void deleteList();
void displayStackList();
void displayQueueList();

int main() {
    int choice, type, value;

    do {
        printf("\nChoose Data Structure:\n1. Stack\n2. Queue\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("\nChoose Implementation:\n1. Array\n2. Linked List\n");
            scanf("%d", &type);
        }

        switch (choice) {
            case 1:  // Stack Operations
                if (type == 1) {
                    printf("\nStack Operations (Array):\n1. Push\n2. Pop\n3. Display\n");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            pushArray(value);
                            break;
                        case 2:
                            popArray();
                            break;
                        case 3:
                            displayStackArray();
                            break;
                        default:
                            printf("Invalid operation!\n");
                    }
                } else if (type == 2) {
                    printf("\nStack Operations (Linked List):\n1. Push\n2. Pop\n3. Display\n");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            pushList(value);
                            break;
                        case 2:
                            popList();
                            break;
                        case 3:
                            displayStackList();
                            break;
                        default:
                            printf("Invalid operation!\n");
                    }
                }
                break;

            case 2:  // Queue Operations
                if (type == 1) {
                    printf("\nQueue Operations (Array):\n1. Insert\n2. Delete\n3. Display\n");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Enter value to insert: ");
                            scanf("%d", &value);
                            insertArray(value);
                            break;
                        case 2:
                            deleteArray();
                            break;
                        case 3:
                            displayQueueArray();
                            break;
                        default:
                            printf("Invalid operation!\n");
                    }
                } else if (type == 2) {
                    printf("\nQueue Operations (Linked List):\n1. Insert\n2. Delete\n3. Display\n");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Enter value to insert: ");
                            scanf("%d", &value);
                            insertList(value);
                            break;
                        case 2:
                            deleteList();
                            break;
                        case 3:
                            displayQueueList();
                            break;
                        default:
                            printf("Invalid operation!\n");
                    }
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}


// Stack Using Array

void pushArray(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

void popArray() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d popped from stack\n", stack[top--]);
}

void displayStackArray() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}


// Queue Using Array

void insertArray(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

void deleteArray() {
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("%d deleted from queue\n", queue[front++]);
}

void displayQueueArray() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Stack Using Linked List

void pushList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = topList;
    topList = newNode;
}

void popList() {
    if (topList == NULL)
        printf("Stack Underflow\n");
    else {
        struct Node* temp = topList;
        printf("%d popped from stack\n", topList->data);
        topList = topList->next;
        free(temp);
    }
}

void displayStackList() {
    if (topList == NULL)
        printf("Stack is empty\n");
    else {
        struct Node* temp = topList;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Queue Using Linked List

void insertList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rearList == NULL) {
        frontList = rearList = newNode;
    } else {
        rearList->next = newNode;
        rearList = newNode;
    }
}

void deleteList() {
    if (frontList == NULL)
        printf("Queue Underflow\n");
    else {
        struct Node* temp = frontList;
        printf("%d deleted from queue\n", frontList->data);
        frontList = frontList->next;
        if (frontList == NULL) rearList = NULL;
        free(temp);
    }
}

void displayQueueList() {
    if (frontList == NULL)
        printf("Queue is empty\n");
    else {
        struct Node* temp = frontList;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
