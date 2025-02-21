#include <stdio.h>
#include <stdlib.h> // For malloc(), free() functions

// Function Prototypes
int Basic();
int arrayAndPointer();
int dynamicMemoryAllocation();
int dynamicMemoryAllocation();
int callByReference();

void swap(int* x, int* y);

// Entry Point
int main() {
    // Choose the function to run
    short choice;

    printf("Choose the function to run:\n");
    printf("1. Basic Pointer Example\n");
    printf("2. Array and Pointer Example\n");
    printf("3. Dynamic Memory Allocation Example\n");
    printf("4. Call by Reference Example\n");
    printf("\n");
    printf("Enter your choice: ");

    scanf_s("%hd", &choice);

    // Add Space
    printf("\n");

    switch (choice) {
    case 1:
        Basic();
        break;
    case 2:
        arrayAndPointer();
        break;
    case 3:
        dynamicMemoryAllocation();
        break;
    case 4:
        callByReference();
        break;
    default:
        printf("Invalid choice!\n");
    }

    return 0;
}

// Basic Pointer Example
int Basic() {
    int a = 10;      // 일반 변수
    int* p = &a;     // 포인터 변수 (p는 a의 주소를 저장)

    printf("a의 값: %d\n", a);       // 10
    printf("a의 주소: %p\n", &a);    // 메모리 주소
    printf("포인터 p의 값(=a의 주소): %p\n", p);  // &a와 같음
    printf("포인터 p가 가리키는 값: %d\n", *p);  // 10 (a의 값)

    *p = 20;  // 포인터를 이용해 a의 값을 변경
    printf("포인터를 통해 변경된 a의 값: %d\n", a); // 20

    return 0;
}

// Array and Pointer Example
int arrayAndPointer() {
    int arr[3] = { 10, 20, 30 };
    int* p = arr;  // 배열 이름은 첫 번째 원소의 주소를 가리킴

    printf("arr[0]의 값: %d\n", *p);       // 10
    printf("arr[1]의 값: %d\n", *(p + 1)); // 20
    printf("arr[2]의 값: %d\n", *(p + 2)); // 30

    return 0;
}

// Dynamic Memory Allocation Example
int dynamicMemoryAllocation() {
    int* ptr = (int*)malloc(sizeof(int) * 3);  // 정수 3개를 저장할 메모리 할당

    // If memory cannot be allocated then malloc() returns NULL
    if (ptr == NULL) {
        printf("메모리 할당 실패!\n");

        return 1;
    }

    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    printf("동적 할당된 배열: %d, %d, %d\n", ptr[0], ptr[1], ptr[2]);

    free(ptr);  // 할당한 메모리 해제
    return 0;
}

// Call by Reference Example
int callByReference() {
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b);  // 포인터로 변수의 주소를 전달

    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
