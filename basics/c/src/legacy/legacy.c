/*
 * =====================================================================================
 *
 *       Filename:  legacy.c
 *
 *    Description:  Archive of old codes.
 *
 *        Created:  05/14/23 13:02:19
 *       Compiler:  gcc
 *
 *         Author:  정재윤(@__77.4_) 
 *   Organization:  YONSEI UNIVERSITY
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Declarations
int getFactorial(); int pointerIntro();
int rockSissorsPaper(); int pascalTriangle();
int coffeeCount(); int timeCheck();
int guessOperator(); int triangleStar();
int arrayMaxMin();

// Main Function
int main() {
    char funcName[20];

    printf("Enter the function name: "); scanf("%s", funcName);

    if (strcmp(funcName, "getFactorial") == 0) getFactorial();
    else if (strcmp(funcName, "pointerIntro") == 0) pointerIntro();
    else if (strcmp(funcName, "rockSissorsPaper") == 0) rockSissorsPaper();
    else if (strcmp(funcName, "pascalTriangle") == 0) pascalTriangle();
    else if (strcmp(funcName, "coffeeCount") == 0) coffeeCount();
    else if (strcmp(funcName, "timeCheck") == 0) timeCheck();
    else if (strcmp(funcName, "guessOperator") == 0) guessOperator();
    else if (strcmp(funcName, "triangleStar") == 0) triangleStar();
    else printf("Function not found\n");

    return 0;
}

// Function Definitions
int getFactorial() {
    int till = 0, factorial = 1;

    printf("Enter a number: "); scanf("%d", &till);

    for (int i = 1; i <= till; i++) factorial *= i;
    printf("Factorial of %d is %d\n", till, factorial);

    return 0;
}

// Function Declarations for pointerIntro()
int createPointers(); int ptrAndArrays();
int aValue = 7;

// Entry Point 
int pointerIntro() {
    createPointers();
    ptrAndArrays();

    return 0;
}

int createPointers() {
    // ptr holds the value of aValue's memory address.
    int* ptr = &aValue; // A pointer variable, with the name ptr
                        // that stores the address of aValue
                        
    printf("aValue => %d/nmemoryAddr => %p\nptr => %p\nDereference => %d\n", \
            aValue, &aValue, ptr, *ptr);

    return 0;
}

int ptrAndArrays() {
    int aNumbers[4] = {25, 50, 75, 100};
   
    for (int i = 0; i < 4; i++) {
        printf("\n");

        printf("aNumbers[%d]\t", i);
        printf("%d\t", aNumbers[i]);
        printf("%p\t", &aNumbers[i]);
    }

    printf("\n\n");

    printf("Now Let's learn about the relationship between pointers and Arrays\n");
    printf("aNumbers : %p / &aNumbers[0] : %p\n\n", aNumbers, &aNumbers[0]);
    
    // Get the value of the first element in myNumbers
    printf("What value *aNumbers has => %d\n", *aNumbers);

    // Get the value of the second element in myNumbers
    printf("What value *(aNumbers + 1) has => %d\n", *(aNumbers + 1));

    // Get the value of the third element in myNumbers
    printf("What value *(aNumbers + 2) has => %d\n", *(aNumbers + 2));

    printf("\n");

    /*
     * We can know that *(aNumbers + N) equals to index; aNumbers[N]
     * This is how pointers and Arrays works.
     */
    
    // Now Let's change a value in an Arrays.
    // Change the value of the first element to 7.
    *aNumbers = 7;

    // Change th value of the second element to 18;
    *(aNumbers + 1) = 18;

    // Get the value of first element.
    printf("The changed equals to aNumbers[0] %d and aNumbers[1] %d\n", *aNumbers, *(aNumbers + 1));

    return 0;
}

//  rockSissorsPaper
int rockSissorsPaper() {
    int player = 0, computer = 0;
    int pScore = 0, cScore = 0;

    do {
        // Get Player's input
        printf("Enter 0 for Rock, 1 for Scissors, 2 for Paper: ");
        scanf("%d", &player);

        // Get Computer's input
        computer = (rand() % 3);

        // Display the result
        printf("\nPlayer: %d\tComputer: %d\n", player, computer);

        // Display the winner
        if ((player == 0 && computer == 1) || (player == 1 && computer == 2) || (player == 2 && computer == 0)) {
            printf("Player wins!\n\n");
            pScore++;
        } else if ((player == 1 && computer == 0) || (player == 2 && computer == 1) || (player == 0 && computer == 2)) {
            printf("Computer wins!\n\n");
            cScore++;
        } else {
            printf("It's a tie!\n\n");
        }
    } while (pScore < 3 && cScore < 3);

    printf("Final Score: Player %d\tComputer %d\n", pScore, cScore);

    return 0;
}

// Pascal Triangle
int pascalTriangle() {
    int rows, coef = 1, space;

    printf("Enter the number of rows: "); scanf("%d", &rows);
    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int space = 1; space <= rows - i; space++) printf("  ");
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0) coef = 1;
            else coef = coef * (i - j + 1) / j;
            printf("%4d", coef);
        }
        printf("\n");
    }

    return 0;
}

int coffeeCount() {
    int num = 0, total = 0;
    printf("~~~~~~\n");

    do {
        printf("coffe count => ");
        scanf("%d", &num);
        
        total += num;
    } while (num != 0); 

    printf("오늘의 ㅋ피 %d잔\n", total);

    return 0;
}

int timeCheck() {
    int h, m, sum;

    printf("HH:MM형식으로 시간을 입력해라 => ");
    scanf("%02d:%02d", &h, &m);

    if (h > 23 || h < 0 || m < 0 || m > 59) {
        printf("넌 입력을 왜 그따구로 하니?\n");
        return 1;
    }

    sum = (h + m);
    
    if (h > 12 || h == 12) {
        if (sum % 7 == 0) printf("[가능] 돌아갈 수 있따!\n");
        else printf("[불가] 못 돌아간다.\n");
    } else if (h > 0 && h < 12) {
        if (sum % 3 == 0) printf("[가능] 돌아갈 수 있따!\n");
        else printf("[불가] 못 돌아간다.\n");
    } else {
        printf("출력될 수 없는 문장\n");
    }

    return 0;
}

int guessOperator() {
    int a1 = 0, a2 = 0, r = 0;
    char ro, wo;

    printf("a1 (+/-/*//) a2 = r의 형식으로 입력해라 => ");
    scanf("%d %c %d = %d", &a1, &wo, &a2, &r);

    if (a1 + a2 == r) ro = '+';
    else if (a1 - a2 == r) ro = '-';
    else if (a1 / a2 == r) ro = '/';
    else if (a1 * a2 == r) ro = '*';
    else {
        printf("사칙 연산으로는 절대 나올 수가 없는 값..?\n");
        return 1;
    }

    if (ro == wo) {
        printf("문제 없는데 왜 굳이 확인해?\n");
        return 0;
    }

    printf("XXXX끼야, %c가 아니라 %c겠지!\n", wo, ro);
    
    return 0;
}

int triangleStar() {
    int n = 0, m = 0;

    printf("n, m 형식으로 입력해라 => ");
    scanf("%d, %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) printf("  ");
        for (int j = 0; j < i + m + 1; j++) printf("%d ", j);

        printf("\n");
    }

    return 0;
}

int arrayMaxMin() {
    int howMany = 0, maxArray[5], minArray[5];

    // 배열 초기화
    for (int i = 0; i < 5; i++) { 
        maxArray[i] = 0; minArray[i] = 0;
    }

    printf("배열 크기 입력: "); scanf("%d", &howMany);
    if (howMany > 20 || howMany < 1 ) {
        printf("배열 크기는 15 이하로 입력해주세요.\n");
        return 0;
    }

    // 입력 받은 배열 크기 만큼 배열 생성
    int array[howMany];
    printf("배열 요소 입력: ");
    for (int i = 0; i < howMany; i++) {
        scanf("%d", &array[i]);
        if (array[i] < 0 || array[i] > 100) {
            printf("범위를 벗어나서 입력할 수 없습니다.\n");
            return 0;
        }
    }

    // 역순 출력
    printf("역순: ");
    for (int i = howMany - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 최대값, 최소값 by 3
    int splitSize = 3;

    // 배열을 인덱스 원소가 3개인 인덱스로 나누어서 최대값, 최소값 구하기
    { 
        for (int i = 0, x = 0; i < howMany; i += splitSize, x++) {
            for (int k = splitSize * x; k < howMany; k++) {
                for (int j = k + 1; j < splitSize * (x + 1); j++) {
                    if (array[k] > array[j]) {
                        int temp = array[k];
                        array[k] = array[j];
                        array[j] = temp;
                    }
                }
            }
            maxArray[x] = array[splitSize * (x + 1) - 1];
        }
    }

    { 
        for (int i = 0, x = 0; i < howMany; i += splitSize, x++) {
            for (int k = splitSize * x; k < howMany; k++) {
                for (int j = k + 1; j < splitSize * (x + 1); j++) {
                    if (array[k] < array[j]) {
                        int temp = array[j];
                        array[j] = array[k];
                        array[k] = temp;
                    }
                }
            }
            minArray[x] = array[splitSize * (x + 1) - 1];
        }
    }

    // 최대값, 최소값 출력
    for (int i = 0; i < 5; i++) {
        if (maxArray[i] == 0) continue;
        printf("%d ", maxArray[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        if (minArray[i] == 0) continue;
        printf("%d ", minArray[i]);
    }
    printf("\n");

    return 0;
}
