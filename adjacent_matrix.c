#include <stdio.h>

// Define the maximum number of nodes in the graph
#define maxnode 10

// Initialize the adjacency matrix with all zeros
void initgraph(int adjmat[maxnode][maxnode], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adjmat[i][j] = 0;
        }
    }
}

// Create an undirected graph by entering edge information
void creategraph(int adjmat[maxnode][maxnode], int n) {
    int i, j;
    while (1) {
        printf("Enter the adjacency information of two nodes (0 0 to exit): ");
        scanf("%d %d", &i, &j);

        if (i == 0 && j == 0) {
            break;
        } else if (i > n || j > n || i < 1 || j < 1) {
            printf("Invalid node numbers. Nodes must be within the range 1 to %d.\n", n);
        } else {
            adjmat[i][j] = 1;
            adjmat[j][i] = 1; // Undirected graph, add edge in both directions
        }
    }
}

// Display the adjacency matrix representing the graph
void display(int adjmat[maxnode][maxnode], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adjmat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjmat[maxnode][maxnode], ch, n;

    do {
        printf("\n Enter your choice \n");
        printf(" 1. Create graph\n");
        printf(" 2. Display graph\n");
        printf(" 3. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of nodes in the graph: ");
                scanf("%d", &n);
                initgraph(adjmat, n);
                creategraph(adjmat, n);
                break;
            case 2:
                if (n == 0) { // Check if graph exists before displaying
                    printf("Please create a graph first.\n");
                } else {
                    display(adjmat, n);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose from 1, 2, or 3.\n");
        }
    } while (ch != 3);

    return 0;
}
