#include <stdio.h>

#define TABLE_SIZE 7 // Define the size of the hash table (usually a prime number)

// Array to store hash table elements (integers in this case)
int h[TABLE_SIZE] = {NULL}; // Initialize all slots to NULL

// Function to insert a new value into the hash table
void insert() {
    int key, index, i, hkey;

    // Prompt user to enter a value
    printf("Enter a value to insert into the hash table: ");
    scanf("%d", &key);

    // Calculate the initial hash index using the modulo operation
    hkey = key % TABLE_SIZE;

    // Linear probing for finding an empty slot
    for (i = 0; i < TABLE_SIZE; i++) {
        // Calculate the probing index with wrap-around using modulo
        index = (hkey + i) % TABLE_SIZE;

        // Check if the existing value matches or an empty slot is found
        if (key == h[index] || h[index] == NULL) {
            break;
        }
    }

    // Check if insertion was successful
    if (i == TABLE_SIZE) {
        printf("\nElement cannot be inserted (hash table full)\n");
    } else {
        h[index] = key; // Insert the value at the found index
    }
}

// Function to search for a value in the hash table
void search() {
    int key, index, i, hkey;

    // Prompt user to enter the value to search
    printf("Enter search element: ");
    scanf("%d", &key);

    // Calculate the initial hash index
    hkey = key % TABLE_SIZE;

    // Linear probing for finding the value
    for (i = 0; i < TABLE_SIZE; i++) {
        // Calculate the probing index
        index = (hkey + i) % TABLE_SIZE;

        // Check if the value is found or the end of the table is reached
        if (h[index] == key) {
            printf("Value found at index %d\n", index);
            break;
        } else if (h[index] == NULL) { // Empty slot indicates value not found
            break;
        }
    }

    // If not found after probing
    if (i == TABLE_SIZE) {
        printf("Value not found\n");
    }
}

// Function to display the contents of the hash table
void display() {
    int i;

    printf("\nElements in the hash table: \n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %d\n", i, h[i]); // Print index and value
    }
}

// Function to delete a value from the hash table
void delete() {
    int dkey, i, index, hkey;

    // Prompt user to enter the value to delete
    printf("Enter a value to delete: ");
    scanf("%d", &dkey);

    // Calculate the initial hash index
    hkey = dkey % TABLE_SIZE;

    // Linear probing for finding the value
    for (i = 0; i < TABLE_SIZE; i++) {
        // Calculate the probing index
        index = (hkey + i) % TABLE_SIZE;

        // Check if the value is found and delete it
        if (h[index] == dkey) {
            h[index] = NULL; // Set the slot to NULL
            printf("Element deleted\n");
            break;
        } else if (h[index] == NULL) { // Empty slot indicates value not found
            break;
        }
    }

    // If not found after probing
    if (i == TABLE_SIZE) {
        printf("Element not found\n");
    }
}

int main() {
    int opt, i;

    while (1) {
        // Menu for operations
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
