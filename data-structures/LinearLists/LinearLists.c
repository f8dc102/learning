#include <stdio.h>

// Entry Point
int main() {
    int arr[5] = { 1, 2, 3, 4, 5 }; // 정적 배열 선언
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}