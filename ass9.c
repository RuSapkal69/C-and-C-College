#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adjMatrix[MAX][MAX];  // Adjacency matrix
int visited[MAX];         // To keep track of visited vertices
int queue[MAX], front = -1, rear = -1;  // Queue for BFS

// Function to create the graph using adjacency matrix
void createGraph(int vertices) {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  // Initialize all elements to 0
        }
    }

    int edges, src, dest;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;  // Add edge to the adjacency matrix
        adjMatrix[dest][src] = 1;  // Since the graph is undirected
    }
}

// Breadth-First Search (BFS) algorithm
void BFS(int startVertex, int vertices) {
    int i;

    // Initialize visited array
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // Enqueue the start vertex
    rear = front = 0;
    queue[rear] = startVertex;
    visited[startVertex] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Visit all adjacent vertices
        for (i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Depth-First Search (DFS) algorithm (Recursive)
void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);  // Recursive call for DFS
        }
    }
}

int main() {
    int vertices, startVertex, choice;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    createGraph(vertices);
    
    while (1) {
        printf("\n\nGraph Traversal Options:\n");
        printf("1. Breadth-First Search (BFS)\n");
        printf("2. Depth-First Search (DFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                BFS(startVertex, vertices);
                break;
                
            case 2:
                // Reset visited array for DFS
                for (int i = 0; i < vertices; i++) visited[i] = 0;
                
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("DFS Traversal: ");
                DFS(startVertex, vertices);
                printf("\n");
                break;
                
            case 3:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
