#include <stdio.h>

#define TABLE_SIZE 7

// Define a node structure to store key values and linked list pointers
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
    struct node *newNode;

    // Prompt user to enter key
    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);

    // Calculate the hash index using the hash function
    index = hashFunction(key);

    // Allocate memory for a new node
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        return;
    }

    // Set the new node's key and next pointer
    newNode->key = key;
    newNode->next = ht[index]; // Insert at the beginning of the linked list

    // Update the head pointer of the linked list at the calculated index
    ht[index] = newNode;
}

// Function to search for a key in the hash table
void search() {
    int key, index;
    struct node *p;

    // Prompt user to enter key to search
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);

    // Calculate the hash index
    index = hashFunction(key);

    // Start searching from the head of the linked list at the index
    p = ht[index];

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
        printf("Entries at index %d:\n", i);

        if (ht[i] == NULL) {
            printf("No Hash Entry\n");
        } else {
            // Traverse the linked list and print each key
            for (p = ht[i]; p != NULL; p = p->next) {
                printf("%d -> ", p->key);
            }
            printf("\n"); // Newline after each linked list
        }
    }
}

// Function to delete a key-value pair from the hash table
void delete() {
    int key, index;
    struct node *p, *q = NULL; // Track current and previous nodes

    // Prompt user to enter key to delete
    printf("\nEnter the key to delete: ");
    scanf("%d", &key);

    // Calculate the hash index
    index = hashFunction(key);

    // Start searching from the head
    p = ht[index];

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
    int opt;

    // Menu-driven loop for operations
    while (1) {
        printf("\nPress:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        scanf("%d", &opt);

