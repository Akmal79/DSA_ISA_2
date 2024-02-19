#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int rthread;
};

struct node *root = NULL;

void insert(int item) {
    // Allocate memory for new node
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Initialize node data and threads
    ptr->data = item;
    ptr->left = NULL;
    ptr->rthread = 1; // Right child initially a thread

    if (root == NULL) {
        root = ptr;
    } else {
        // Find insertion position and update thread pointers
        struct node *parentptr = NULL;
        struct node *nodeptr = root;
        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (item < nodeptr->data) {
                nodeptr = nodeptr->left;
            } else {
                // Update thread if no right child
                if (nodeptr->rthread == 0) {
                    nodeptr->right = ptr;
                } else {
                    break; // Reached in-order successor's thread
                }
            }
        }

        // Link new node based on position
        if (item < parentptr->data) {
            parentptr->left = ptr;
            ptr->right = parentptr; // Right child points to parent
        } else {
            ptr->right = parentptr->right;
            parentptr->right = ptr;
            parentptr->rthread = 0; // Update parent's right thread
        }
    }
}

void inorder_traversal() {
    struct node *ptr = root;
    while (ptr != NULL) {
        // Follow right child pointers or threads
        printf("%d ", ptr->data);
        ptr = (ptr->rthread == 1) ? NULL : ptr->right;
    }
    printf("\n");
}

int main() {
    // Insert nodes and perform in-order traversal
    return 0;
}
