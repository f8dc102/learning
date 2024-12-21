/*
 * =====================================================================================
 *
 *       Filename:  041623.c
 *
 *    Description:  0416 실습 
 *
 *        Version:  1.0
 *        Created:  04/16/23 12:35:31
 *       Compiler:  gcc
 *
 *         Author:  정재윤 (@__77.4_), 
 *   Organization:  YONSEI UNIVERSITY
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Function Declaration Region
 */
int EX1(); int EX2(); int EX3();

/*
 * Main Function Region
 */
int main() {
    int funcNum = 0;

    printf("실행할 문제 번호 입력 => ");
    scanf("%d", &funcNum);

    switch (funcNum) {
        case 1: EX1(); break;
        case 2: EX2(); break;
        case 3: EX3(); break;
        default: printf("잘못된 입력입니다.\n"); break;
    }

    return 0;
}


/*
 * Function Region
 */
// Exercise 1

// Function Declaration
int recursive(int count);

// Sub-Main Function
int EX1() {
    char content[] = "어느 날 소프트웨어학부 학생이 내게 와서 물었다.\
        \n 조교님! 재귀 함수가 뭔가요?\
        \n 옛날에.. 호랑이 삶아지던 시절 어떤 똑똑한 조교가 살았더랬지.\
        \n 그 조교는 너무나 일처리가 빠르고 똑똑했지.\
        \n 학생들 뿐만 아니라 교수님들까지 모르는 것이 있으면 매일 같이\
        달려와 물어볼 정도였어.\
        \n 그러던 어느 날 한 학생이 찾아와서 물었네\
        \n";

    int howMany = 0;

    printf("재귀 횟수 입력 => ");
    scanf("%d", &howMany);

    system("clear"); // Linux = clear, Windows = cls
    printf("%s", content);

    recursive(howMany);

    return 0;
}

int recursive(int count) {
    char col1[] = "조교님! 재귀 함수가 뭔가요?\n ";
    char col2[] = "재귀 함수는 자기 자신을 호출하는 함수란다.\n ";
    char col3[] = "라고 말했어.";
    char dashSymbol = '-';

    if (count <= 0) {
        printf("%s\n", col3);

        return 0;
    } else {
        count--;
        
        printf(" %s%s%s\n", col1, col2, col3);

        return recursive(count);
    }
}

// Exercise 2

/*
 * 변경사항
 *
 * 올바른 double-quote로 변경 ("") 
 * 불완전한 함수 -> 제가 완성했습니다.
 * 친절함 추가 ㅎ
 */

// Function Declaration
int give_friend(int length, int m);
int eat(int length, int m);

// Sub-Main Function
int EX2() {
    int n, m;

    // scanf만 있으면 살짝 차갑잖아요? ㅎ
    printf("길이 인원 입력 => ");
    scanf("%d %d", &n, &m);

    eat(n, m);

    return 0;
}

// Actual Function
int eat(int length, int m) { 
    if (length <= 0) return 0;
    
    int rest = length % m;
   
    if (rest == 0) {
        // 먹을수록 길이는 작아져요!
        length /= m;
         
        printf("먹은 사람 : 김연세, 먹은 후 남은 길이 : %d\n", length);

        return eat(length, m); // eat 재귀하고 종료
    } else {
        return give_friend(length, m); // give_friend 호출하고 종료
    }
}

int give_friend(int length, int m) {
    if (length == 0) return eat(length, m); // 재귀함수 탈출

    length--; // 1을 빼장...
    int rest = length % m;

    printf("먹은 사람 : %d번째 친구, 먹은 후 남은 길이 : %d\n", rest + 1, length);

    return eat(length, m);
}

// Exercise 3

// Function Declaration
void stamp(int curr_island, int n);
void stamp2(int curr_island, int n);
void stamp3(int curr_island, int n);

// Sub-Main Function
int EX3() {
    int n;
    
    printf("숫자 입력 ==> ");
    scanf("%d", &n);

    printf("* 문제 1\n");
    stamp(1, n);
    printf("\n");

    printf("* 문제 2\n");
    stamp2(1, n);
    printf("\n");

    printf("* 문제 3\n");
    stamp3(1, n);
    printf("\n");

    return 0;
}

// 문제 3-1번 함수
void stamp(int curr_island, int n) {
    if (curr_island > n) return; // n보다 크면 종료

    printf("벽력%d섬 방문\n", curr_island);

    int next_island = 2 * curr_island;
    stamp(next_island, n); // 재귀 함수 호출

    next_island = 2 * curr_island + 1;
    stamp(next_island, n); // 재귀 함수 호출
}

// 문제 3-2번 함수
void stamp2(int curr_island, int n) {
    if (curr_island > n) return;

    int next_island = 2 * curr_island;
    stamp2(next_island, n);

    printf("벽력%d섬 방문\n", curr_island);

    next_island = 2 * curr_island + 1;
    stamp2(next_island, n);
}

// 문제 3-3번 함수
void stamp3(int curr_island, int n) {
    if (curr_island > n) return;

    int next_island = 2 * curr_island;
    stamp3(next_island, n);

    next_island = 2 * curr_island + 1;
    stamp3(next_island, n);

    printf("벽력%d섬 방문\n", curr_island);
}
