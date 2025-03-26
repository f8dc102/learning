#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define Queue Structure
typedef struct Queue {
    int front, rear;
    int data[MAX];
} Queue;

// Function Prototypes
void init(Queue* q);

void enqueue(Queue* q, int value);
int dequeue(Queue* q);

int isEmpty(Queue* q);
int isFull(Queue* q);

// Entry Point
int main() {
	// Create a queue
    Queue q;

	// Initialize the queue
    init(&q);

	// Enqueue some elements to the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

	// Dequeue elements from the queue
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}

// Initialize the Queue
void init(Queue* q) {
    q->front = q->rear = -1;
}

// Enqueue Operation
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = value;
}

// Dequeue Operation
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->data[++q->front];
}

// Check if the Queue is Empty
int isEmpty(Queue* q) { return q->front == q->rear; }

// Check if the Queue is Full
int isFull(Queue* q) { return q->rear == MAX - 1; }
