#include <stdio.h>
#define TABLE_SIZE 7

// Global array representing the hash table with initial NULL values
int h[TABLE_SIZE] = {NULL};

// Function to insert a key into the hash table
void insert() {
    int key, index, i, hkey;

    // Prompt user to enter key
    printf("Enter a value to insert into hash table: ");
    scanf("%d", &key);

    // Calculate initial hash index using modulo operator
    hkey = key % TABLE_SIZE;

    // Quadratic probing for collision resolution
    for (i = 0; i < TABLE_SIZE; i++) {
        // Calculate probing index with quadratic probing formula
        index = (hkey + (i * i)) % TABLE_SIZE;

        // Check if key already exists at this index
        if (key == h[index]) {
            printf("Key already exists in the hash table!\n");
            break; // No need to insert again
        }

        // Check if empty slot found
        if (h[index] == NULL) {
            h[index] = key; // Insert key and break loop
            printf("Key inserted at index %d\n", index);
            break;
        }
    }

    // Hash table full message
    if (i == TABLE_SIZE) {
        printf("Hash table is full, element cannot be inserted!\n");
    }
}

// Function to search for a key in the hash table
void search() {
    int key, index, i, hkey;

    // Prompt user to enter key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Calculate initial hash index
    hkey = key % TABLE_SIZE;

    // Quadratic probing for searching
    for (i = 0; i < TABLE_SIZE; i++) {
        // Calculate probing index
        index = (hkey + (i * i)) % TABLE_SIZE;

        // Check if key found
        if (h[index] == key) {
            printf("Key found at index %d\n", index);
            break; // Key found, stop searching
        }
    }

    // Key not found message
    if (i == TABLE_SIZE) {
        printf("Key not found in the hash table.\n");
    }
}

// Function to display the contents of the hash table
void display() {
    int i;

    printf("\nElements in the hash table are:\n");

    // Print index and value for each slot
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: \tValue = %d\n", i, h[i]);
    }
}

// Function to delete a key from the hash table
void delete() {
    int dkey, index, i, hkey;

    // Prompt user to enter key to delete
    printf("Enter the value to delete: ");
    scanf("%d", &dkey);

    // Calculate initial hash index
    hkey = dkey % TABLE_SIZE;

    // Quadratic probing for deletion
    for (i = 0; i < TABLE_SIZE; i++) {
        // Calculate probing index
        index = (hkey + (i * i)) % TABLE_SIZE;

        // Check if key found
        if (h[index] == dkey) {
            h[index] = NULL; // Set slot to NULL to mark deletion
            printf("Element deleted from index %d\n", index);
            break; // Key deleted, stop searching
        }
    }

    // Key not found message
    if (i == TABLE_SIZE) {
        printf("Element not found in the hash table.\n");
    }
}

int main() {
    int opt, i;

    // Menu-driven loop for operations
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
                search();
                break;
            case 4:
                delete();
