#include <stdio.h>
#include <string.h>

int EXERCISE1(); int EXERCISE2();
int EXERCISE3(); int EXERCISE4();

int main() {
    int EXERCISE_NUMBER = 1;
    printf("EXERCISE NUMBER => "); scanf("%d", &EXERCISE_NUMBER);

    switch (EXERCISE_NUMBER) {
        case 1: EXERCISE1(); break;
        case 2: EXERCISE2(); break;
        case 3: EXERCISE3(); break;
        case 4: EXERCISE4(); break;
        default: printf("EXERCISE NUMBER ERROR\n"); break;
    }

    return 0;
}

// 문자열 S와 정수 N을 입력 받아 다음의 규칙대로 문자열 S를 변환하는 프로그램을 작성하시오.
//
// 대문자 : 해당 대문자로부터 아스키 코드표 순서대로 N번째 뒤 문자
// 소문자 : 해당 소문자로부터 아스키 코드표 순서대로 N번째 앞 문자
// 숫자 : 해당 숫자 번째의 알파벳 대문자를 N번 반복
// 그외 : 공백으로 변경
//
// 조건 : (1 <= N <= 20, 0 <= N <= 10, 0 <= 숫자 <= 27)
//
// 예시 
// 입력 : CLikp5tGLE?Qej15J 2
// 출력 : ENgineerING SchOOL
int EXERCISE1() {
    int N; char str[100];
    printf("Input string / num => "); scanf("%s / %d", str, &N);

    for (int i = 0; str[i] != '\0'; i++) {
        // 대문자인 경우
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // N번째 뒤 문자 연산
            str[i] += N; 
        // 소문자인 경우
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            // N번째 앞 문자 연산
            str[i] -= N;
        // 숫자인 경우
        } else if(str[i] >= '0' && str[i] <= '9') {
            // 다음 문자가 숫자인 경우 한 숫자로 보자
            if (str[i + 1] >= '0' && str[i + 1] <= '9') {
                // 다음 처리 때 한번에 처리
                continue;
            } else {
                if (str[i - 1] >= '0' && str[i - 1] <= '9') {
                    // 숫자가 두 자리 숫자이면 두 자리 숫자에 대해서만 처리
                    for (int j = 0; j < N; j++) {
                        printf("%c", ((str[i] - '0') + 10 * (str[i - 1] - '0')) + 'A' - 1);
                    }

                    continue;
                }
                // 숫자가 한 자리 숫자이면 그 숫자에 대해서만 처리
                for (int j = 0; j < N; j++) {
                    printf("%c", str[i] - '1' + 'a');
                }
            }

            // 출력에만 사용완료됐으므로  문자열에서 제거
            str[i] = '\0';
        // 그 외
        } else {
            str[i] = ' ';
        }

        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}

int EXERCISE2() {
    char input[21];
    printf("Input / operator numA numB => "); scanf("%s", input);

    // Split Input
    char operator[4]; int numA = 0, numB = 0;
    
    // Copy Operator
    for (int i = 0; i < 3; i++) {
        if (input[i] == '\0') break;

        operator[i] = input[i];
    }

    // Get Space Index Number
    int spaceIndexLeft = 0;
    int spaceIndexRight = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        // Space (Left or Right)
        if (input[i] == ' ') {
            // Space from left
            if (spaceIndexLeft == 0) {
                spaceIndexLeft = i;
            } else {
                // Space from right
                spaceIndexRight = i;
            }

            break;
        }
    }

    printf("Space Index Left : %d, Right : %d\n", spaceIndexLeft, spaceIndexRight);

    // Get Number
    // numA
    for (int i = spaceIndexLeft + 1; i < spaceIndexRight; i++) {
        // Base 10 Calculation
        for (int j = 0; j < spaceIndexRight; j++) {
            numA += 10 * j * (input[i] - '0');
        }
    }

    // numB
    for (int i = spaceIndexRight + 1; input[i] < 21; i++) {
        // Base 10 Calculation
        for (int j = 0; j < 21; j++) {
            if (input[i] == '\0') break;
            numB += 10 * j * (input[i] - '0'); 
        }
    }

    // Calculate Integer
    printf("O : %s, A : %d, B : %d\n", operator, numA, numB);

    return 0;
}

int EXERCISE3() {

    return 0;
}

int EXERCISE4() {
    char input[100];
    
    // Get Input
    printf("Input => "); scanf("%s", input);

    // Check Input
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] < '0' && input[i] > '9') {
            printf("Wrong Input\n");
            return 0;
        }
    }

    // Get Index of Number
    // Also Get Index of Operator
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            printf("Index of Number : %d\n", i);
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("Index of Operator : %d\n", i);
        }
    }

    // Calculate


    return 0;
}
