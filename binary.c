#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, return a new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the (unchanged) node pointer
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (key > root->data)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// In-order traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data, key;
    struct Node* searchResult;

    while (1) {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert a node\n");
        printf("2. Search a node\n");
        printf("3. In-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted into the tree.\n", data);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                searchResult = search(root, key);
                if (searchResult != NULL)
                    printf("%d found in the tree.\n", key);
                else
                    printf("%d not found in the tree.\n", key);
                break;

            case 3:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                exit(0);
            
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
