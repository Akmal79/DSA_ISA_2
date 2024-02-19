#include <stdio.h>
#define TABLE_SIZE 7 // Define the size of the hash table (usually a prime number)

// Define a node structure for storing key-value pairs and linked list pointers
struct node {
    int key;
    struct node *next;
};

// Create an array of pointers to node structures, representing the hash table
struct node *ht[TABLE_SIZE] = {NULL}; // Initialize all slots to NULL

// Hash function to map keys to index in the hash table
int hashFunction(int key) {
    return key % TABLE_SIZE; // Simple modulo operation for this example
}

// Function to insert a new key-value pair into the hash table
void insert() {
    int key, index;

    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);

    // Calculate the hash index using the hash function
    index = hashFunction(key);

    // Create a new node to store the key
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL; // New node points to nothing initially

    // Insert the new node at the beginning of the linked list at the calculated index
    newNode->next = ht[index];
    ht[index] = newNode;
}

// Function to search for a key in the hash table
void search() {
    int key, index;
    struct node *p;

    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);

    index = hashFunction(key);

    p = ht[index]; // Start searching from the head of the linked list at the index

    while (p != NULL) {
        if (p->key == key) {
            printf("Element found!\n");
            return; // Early exit if found
        }
        p = p->next; // Move to the next node in the linked list
    }

    printf("Element not found.\n");
}

// Function to display the contents of the hash table
void display() {
    int i;
    struct node *p;

    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Key at index %d:\t", i);

        if (ht[i] == NULL) {
            printf("No Hash Entry\n");
        } else {
            // Traverse the linked list and print each key
            for (p = ht[i]; p != NULL; p = p->next) {
                printf("->%d", p->key);
            }
            printf("\n");
        }
    }
}

// Function to delete a key-value pair from the hash table
void delete() {
    int key, index;
    struct node *p, *q = NULL; // Track current and previous nodes

    printf("\nEnter the key to delete: ");
    scanf("%d", &key);

    index = hashFunction(key);

    p = ht[index]; // Start searching from the head

    while (p != NULL && p->key != key) {
        q = p; // Keep track of the previous node for efficient deletion
        p = p->next;
    }

    if (p == NULL) { // Key not found
        printf("Element not found in the hash table.\n");
        return;
    }

    // Remove the node from the linked list
    if (q == NULL) { // Deleting the head node
        ht[index] = p->next;
    } else {
        q->next = p->next; // Link the previous node to the next node
    }

    free(p); // Free the memory of the deleted node
}

int main() {
    int opt, i;

    while (1) {
        printf("\nPress:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:

