#include <stdio.h>

#define TABLE_SIZE 7

struct node {
    int key;
    struct node *next;
};

// Hash table array
struct node *ht[TABLE_SIZE] = {NULL};

// Hash function using modulo operation (replace with another hash function if needed)
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Secondary hash function (ensure it calculates a step size relatively prime to TABLE_SIZE)
int hash2(int key) {
    return 1 + (key % (TABLE_SIZE - 2)); // Ensures step size is 1 or TABLE_SIZE - 1
}

// Function to insert a new key-value pair into the hash table
void insert(int key) {
    int index1, index2, count = 0;

    // Calculate primary hash index
    index1 = hash1(key);

    // Probing using secondary hash function until empty slot found
    while (ht[index1] != NULL) {
        // Check if key already exists (optional for duplicates check)
        if (ht[index1]->key == key) {
            printf("Key %d already exists!\n", key);
            return;
        }

        // Calculate step size using secondary hash function and increment counter
        index2 = hash2(key);
        index1 = (index1 + index2) % TABLE_SIZE; // Apply step size and wrap around

        // Prevent infinite loop (check if all slots are full)
        count++;
        if (count >= TABLE_SIZE) {
            printf("Hash table overflow!\n");
            return;
        }
    }

    // Allocate memory for new node and insert at calculated index
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->key = key;
    newNode->next = NULL;
    ht[index1] = newNode;
}

// Function to search for a key in the hash table
void search(int key) {
    int index1, index2, count = 0;

    // Calculate primary hash index
    index1 = hash1(key);

    // Probing using secondary hash function until key found or empty slot
    while (ht[index1] != NULL && ht[index1]->key != key) {
        // Calculate step size using secondary hash function and increment counter
        index2 = hash2(key);
        index1 = (index1 + index2) % TABLE_SIZE; // Apply step size and wrap around

        // Prevent infinite loop (check if searched all slots)
        count++;
        if (count >= TABLE_SIZE) {
            printf("Key not found!\n");
            return;
        }
    }

    // Key found or reached an empty slot
    if (ht[index1] != NULL && ht[index1]->key == key) {
        printf("Key %d found!\n", key);
    } else {
        printf("Key not found!\n");
    }
}

// Function to display the contents of the hash table
void display() {
    int i;
    struct node *p;

    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (ht[i] == NULL) {
            printf("Empty\n");
        } else {
            for (p = ht[i]; p != NULL; p = p->next) {
                printf("%d -> ", p->key);
            }
            printf("\n");
        }
    }
}

int main() {
    int option, key;

    while (1) {
        printf("\nPress:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            
