#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define Stack Structure
typedef struct Stack {
	int top;
	int data[MAX];
} Stack;

// Function Prototypes
void init(Stack* s);

void push(Stack* s, int value);
int pop(Stack* s);

int isEmpty(Stack* s);
int isFull(Stack* s);

// Entry Point
int main() {
	// Create a stack
	Stack s;

	// Initialize the stack
	init(&s);

	// Push some elements to the stack
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	// Pop elements from the stack
	printf("Popped: %d\n", pop(&s));
	printf("Popped: %d\n", pop(&s));

	return 0;
}

// Initialize the Stack
void init(Stack* s) {
	s->top = -1;
}

// Push and Pop Operations
void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack Overflow\n");
		return;
	}
	s->data[++s->top] = value;
}

// Pop Operation
int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack Underflow\n");
		return -1;
	}
	return s->data[s->top--];
}

// Check if the Stack is Empty
int isEmpty(Stack* s) { return s->top == -1; }

// Check if the Stack is Full
int isFull(Stack* s) { return s->top == MAX - 1; }