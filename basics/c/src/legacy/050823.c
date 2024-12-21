/*
 * =====================================================================================
 *
 *       Filename:  050823.c
 *
 *    Description:  Highlighted Example
 *
 *        Version:  1.0
 *        Created:  04/21/23 10:31:25
 *       Compiler:  gcc
 *
 *         Author:  정재윤 (@__77.4_),
 *   Organization:  YONSEI UNIVERSITY
 *
 * =====================================================================================
 */
/*
 * Import Area
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define arraySize52 5 // Exercise 5.2

/*
 * Function Declaration
 */
void printFuncDesc(); void clearScreen();
int revArray(); int sortFunc(); int searchFunc();
int stringFunc();

/*
 * Main Function
 */
int main() {
    int funcNum = 0;

    clearScreen();
    printf("============================\n");
    printFuncDesc();
    printf("\nSelect Function: "); scanf("%d", &funcNum);
    printf("============================\n\n");

    switch (funcNum) {
        case 1: revArray(); break;
        case 2: sortFunc(); break;
        case 3: searchFunc(); break;
        case 4: stringFunc(); break;
        default : printf("다시 읽고 실행하세요.\n"); return 0; 
    }

    printf("\n============================\n");

    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printFuncDesc() {
    printf("1. revArray\n");
    printf("2. sortArray\n");
    printf("3. searchArray\n");
    printf("4. stringFunc\n");
    printf("0. Exit\n");
}

/*
 * Function Definition
 */
// revArray -------------------------------------
void printArray(int sourceArray[], int arraySize);
void revCopy(int destinationArray[], int sourceArray[], int arraySize);
void dynRev(int sourceArray[], int arraySize);

int revArray() {
    int a[6] = {10, 20, 30, 40, 50, 60}, b[6];

    // Reset b
    for (int i = 0; i < 6; i++) {
        b[i] = 0;
    }

    revCopy(b, a, 6);
    printArray(b, 6);

    dynRev(b, 6);
    printArray(b, 6);

    return 0;
}

void printArray(int sourceArray[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", sourceArray[i]);
    }
    printf("\n");
}

void revCopy(int destinationArray[], int sourceArray[], int arraySize) {
    for (int from = 0, to = arraySize - 1; from < arraySize; from++, to--) {
        destinationArray[to] = sourceArray[from];
    }
}

void dynRev(int sourceArray[], int arraySize) {
    int tmpArray;

    for (int front = 0, rear = arraySize - 1; front < arraySize / 2; front++, rear--) {
        tmpArray = sourceArray[front];
        sourceArray[front] = sourceArray[rear];
        sourceArray[rear] = tmpArray;
    }
}

// sortFunc -------------------------------------
// void printArray(int sourceArray[], int arraySize);
void bubbleSort(int sourceArray[], int arraySize);
void selectionSort(int sourceArray[], int arraySize); 
void quickSort(int sourceArray[], int arraySize);

int sortFunc() {
    int a[arraySize52] = {63, 24, 88, 90, 75};

    {
        selectionSort(a, arraySize52);
        printf("Selection Sort : ");
        printArray(a, arraySize52);
    }

    {
        bubbleSort(a, arraySize52);
        printf("Bubble Sort : ");
        printArray(a, arraySize52);
    }

    {
        quickSort(a, arraySize52);
        printf("Quick Sort : ");
        printArray(a, arraySize52);
    }

    return 0;
}

void bubbleSort(int sourceArray[], int arraySize) {
    int tmpArray;

    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - 1 - i; j++) {
            if (sourceArray[j] > sourceArray[j + 1]) {
                tmpArray = sourceArray[j];
                sourceArray[j] = sourceArray[j + 1];
                sourceArray[j + 1] = tmpArray;
            }
        }
    }
}

void selectionSort(int sourceArray[], int arraySize) {
    int tmpArray, minIndex;
    
    for (int i = 0; i < arraySize - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < arraySize; j++) {
            if (sourceArray[j] < sourceArray[minIndex]) {
                minIndex = j;
            }
        }
    
        if (minIndex == i) {
            continue;
        }

        tmpArray = sourceArray[i];
        sourceArray[i] = sourceArray[minIndex];
        sourceArray[minIndex] = tmpArray;
    }
}

void quickSort(int sourceArray[], int arraySize) {
    int pivot = sourceArray[0];
    int left = 0, right = arraySize - 1;
    int tmpArray;

    while (left < right) {
        while (sourceArray[left] < pivot) {
            left++;
        }

        while (sourceArray[right] > pivot) {
            right--;
        }

        if (left < right) {
            tmpArray = sourceArray[left];
            sourceArray[left] = sourceArray[right];
            sourceArray[right] = tmpArray;
        }

        if (left == right) break;
    }
}

// searchFunc -------------------------------------
int linearSearch(int sourceArray[], int arraySize, int target);
int binarySearch(int sourceArray[], int arraySize, int target);

int searchFunc() {
    int arraySize = 10, a[10] = {77, 2, 8, 16, 34, 56, 13, 20, 22, 45};     
    int target = 0, targetIndex = 0;

    printf("Enter Target Number: "); scanf("%d", &target);

    {
        targetIndex = linearSearch(a, arraySize, target);
        (targetIndex != -1) ? printf("Target Index: %d\n", targetIndex) : printf("Target Not Found\n");
    }

    {
        targetIndex = binarySearch(a, arraySize, target);
        (targetIndex != -1) ? printf("Target Index: %d\n", targetIndex) : printf("Target Not Found\n");
    }

    return 0;
}

int linearSearch(int sourceArray[], int arraySize, int target) {
    for (int i = 0; i < arraySize; i++) {
        if (sourceArray[i] == target) {
            return i;
        }
    }

    return -1;
}

int binarySearch(int sourceArray[], int arraySize, int target) {
    int low = 0, high = arraySize - 1, mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (sourceArray[mid] == target) {
            return mid;
        } else if (sourceArray[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

// stringFunc -------------------------------------
int stringFunc() {
    // Strange Function
    {
        char aString[20] = "Hello World";
        char bString[20] = "Hello <string.h>";

        printf("Before strcopy()"); puts(aString); 
        strcpy(aString, bString); puts(aString);
        printf("Type a String: "); fgets(aString, 20, stdin); puts(aString);

        for (int i = 0; i < 20; i++) {
            putchar(aString[i]);
        }
    }

    // Convert lower to upper
    {
        int index;
        char strA[20];
        fgets(strA, 20, stdin);

        for (index = 0; index < 20 && strA[index]; index++) {
            if (strA[index] >= 'a' && strA[index] <= 'z') {
                strA[index] -= 'a' + 'A';
            }
        }

        if (strA[index] == '\n') {
            strA[index] = '\0';
        }

        puts(strA);
    }

    // Try input 'til int typed
    {
        char strB[20];
        int a;

        scanf("%s", strB, sizeof(strB)); puts(strB);
        scanf("%s", strB, sizeof(strB)); puts(strB);

        while (scanf("%d", &a) != 1) {
            scanf("%*s");
        }

        printf("%s\n", strB);
        printf("%d\n", a);
    }

    printf("\n\nFunction Ended\n");

    return 0;
}
