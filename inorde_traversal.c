#include <stdio.h> // Assuming header file defines node structure

void inorder() {
    // Function to perform in-order traversal of a right-threaded binary search tree

    struct node *p = root; // Start at the root node
    struct node *q = NULL; // Initialize helper pointer

    do {
        // Find the leftmost node and its in-order successor

        q = NULL; // Reset q for each iteration
        while (p != NULL) {
            q = p; // Remember the current node
            p = p->left; // Move to the left child
        }

        if (q != NULL) {
            // Process the current node (leftmost or its successor)
            printf("\t %d", q->data); // Print the data

            // Follow the threaded link or move right
            if (q->rthread == 1) {
                // Thread indicates in-order successor
                p = NULL; // Mark end of traversal
            } else {
                // No thread, move to right child and follow threads if exist
                p = q->right;
                while (q->rthread && p != NULL) {
                    printf("\t %d", p->data); // Print data along the thread
                    q = p; // Remember the current node
                    p = p->right; // Move to next node
                }
            }
        }
    } while (q != NULL); // Continue until all nodes are processed
}
