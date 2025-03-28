#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adjMatrix[MAX][MAX];  // Adjacency matrix to represent the graph

// Function to find the vertex with the minimum key value from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed Minimum Spanning Tree
void printMST(int parent[], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, adjMatrix[i][parent[i]]);
}

// Function to implement Prim's Algorithm
void primMST(int vertices) {
    int parent[MAX];  // Array to store the MST
    int key[MAX];     // Key values used to pick the minimum weight edge
    int mstSet[MAX];  // To represent vertices not yet included in MST

    // Initialize all key values as infinite and mstSet as false (0)
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from the first vertex (index 0)
    key[0] = 0;      // Make key 0 for the first vertex to pick it first
    parent[0] = -1;  // First node is always the root of the MST

    // The MST will have vertices-1 edges
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);  // Pick the minimum key vertex not yet included in the MST
        mstSet[u] = 1;  // Add the picked vertex to the MST set

        // Update the key value and parent index of adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            // adjMatrix[u][v] is non-zero only for adjacent vertices
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if adjMatrix[u][v] is smaller than the current key value
            if (adjMatrix[u][v] && mstSet[v] == 0 && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, vertices);
}

// Function to create the graph using adjacency matrix
void createGraph(int vertices) {
    int edges, src, dest, weight;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  // Initialize all elements to 0 (no edges)
        }
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination weight): ");
        scanf("%d %d %d", &src, &dest, &weight);
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;  // Since it's an undirected graph
    }
}

// Function to display the adjacency matrix
void displayAdjMatrix(int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, choice;
    
    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Create Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Generate MST using Prim's Algorithm\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                createGraph(vertices);
                break;

            case 2:
                displayAdjMatrix(vertices);
                break;

            case 3:
                printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
                primMST(vertices);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
