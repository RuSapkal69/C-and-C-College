#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the front of the list
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert in the middle after a specified position
void insertMiddle(struct Node** head, int pos, int data) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        insertFront(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from the front of the list
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from the end of the list
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete a node from the middle at a given position
void deleteMiddle(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteFront(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode);
}

// Display the linked list with addresses
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    
    // Display data part
    while (temp != NULL) {
        printf("| %d | -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    // Reset temp to head for address display
    temp = head;
    
    // Display address part
    while (temp != NULL) {
        printf("  %p  ", temp);
        temp = temp->next;
        if (temp != NULL) printf("   ");
    }
    printf("\n");
}

// Display the linked list in reverse order
void displayReverse(struct Node* head) {
    if (head == NULL) return;
    displayReverse(head->next);
    printf("| %d | -> ", head->data);
}

// Revert (reverse) the linked list
void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n1. Insert Front\n2. Insert End\n3. Insert Middle\n4. Delete Front\n5. Delete End\n6. Delete Middle\n7. Display\n8. Display Reverse\n9. Reverse List\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                insertMiddle(&head, pos, data);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteMiddle(&head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                displayReverse(head);
                printf("NULL\n");
                break;
            case 9:
                reverse(&head);
                printf("List reversed\n");
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
