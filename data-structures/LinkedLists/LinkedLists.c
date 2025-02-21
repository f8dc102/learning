#include <stdio.h>
#include <stdlib.h>

// Define Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function Prototypes
void append(Node** head, int data);
void printList(Node* head);


// Entry Point
int main() {
	// Create a linked list
    Node* head = NULL;

	// Add some nodes to the list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    
	// Print the list
    printList(head);

    return 0;
}

// Add Node to the end of the list
void append(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}