#include <stdio.h>
#define TABLE_SIZE 7

int h[TABLE_SIZE] = {NULL};

void insert() {
    int key, index, i, hkey;

    printf("enter a value to insert into hash table");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE; // Calculate the initial hash index using modulo

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; // Apply quadratic probing for collision resolution

        // Check if the key already exists at this index
        if (key == h[index]) {
            break; // Key already exists, no need to insert again
        }

        // Check if the slot is empty
        if (h[index] == NULL) {
            h[index] = key; // Insert the key if an empty slot is found
            break;
        }
    }

    if (i == TABLE_SIZE) {
        printf("\nelement cannot be inserted\n"); // Hash table is full
    }
}


void search() {
    int key, index, i, hkey;

    printf("enter search element\n");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE; // Calculate the initial hash index

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; // Apply quadratic probing for collision resolution

        if (h[index] == key) {
            printf("value is found at index %d", index); // Key found and index is printed
            break;
        }
    }

    if (i == TABLE_SIZE) {
        printf(" value is not found"); // Key not found after searching all slots
    }
}


void display() {
    int i;

    printf("\nelements in the hash table are \n");

    for (i = 0; i < TABLE_SIZE; i++) {
        printf("\nat index %d \t value = %d", i, h[i]); // Print index and value at each slot
    }
}

void delete() {
    int dkey, i, index, hkey;

    printf("enter a value to insert into hash table\n");
    scanf("%d", &dkey);

    hkey = dkey % TABLE_SIZE; // Calculate the initial hash index

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; // Apply quadratic probing for collision resolution

        if (h[index] == dkey) {
            h[index] = NULL; // Key found, set the slot to empty
            printf("element deleted \n");
            break;
        }
    }

    if (i == TABLE_SIZE) {
        printf("element is not found to delete\n"); // Key not found after

