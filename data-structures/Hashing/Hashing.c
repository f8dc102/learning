#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return -1;
}

int main() {
    insert(10, 100);
    insert(20, 200);
    insert(30, 300);
    printf("Value for key 20: %d\n", search(20));
    return 0;
}