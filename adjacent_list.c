#include <stdio.h>
#include <stdlib.h>

#define maxnode 4

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct List {
    struct Node* head;
} List;

List* adjlist[maxnode];

int main() {
    int i;

    // Initialize adjacency list heads to NULL for all vertices
    for (i = 1; i <= maxnode; i++) {
        adjlist[i] = (List*)malloc(sizeof(List));
        adjlist[i]->head = NULL;
    }

    // Add edges to the adjacency list (consider using a separate function for clarity)
    addnode(1, 2);
    addnode(1, 3);
    addnode(1, 4);  // Duplicate edge (already added)
    addnode(3, 4);
    addnode(3, 2);
    print();  // Call print function to display current graph

    return 0;
}

// Function to add a new node to the adjacency list of a given vertex
void addnode(int node1, int node2) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = node2;
    newNode->next = NULL;

    // Handle the case where the adjacency list is empty
    if (adjlist[node1]->head == NULL) {
        adjlist[node1]->head = newNode;
    } else {
        // Traverse to the end of the list
        Node* temp = adjlist[node1]->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the adjacency list for each vertex
void print() {
    int i;

    for (i = 1; i <= maxnode; i++) {
        Node* temp = adjlist[i]->head;

        printf("\nAdjacency list for vertex %d: ", i);
        if (temp == NULL) {
            printf("NULL");
        } else {
            while (temp != NULL) {
                printf("%d ", temp->vertex);
                temp = temp->next;
            }
        }
    }
    printf("\n");
}
