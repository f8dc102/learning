/*
 * =====================================================================================
 *
 *       Filename:  starredExample.c
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// for main fucntion
#define typeName(x) _Generic((x), int : "int")

/*
 * Function Declare Region
 */
void printFuncLD();

int E217(); int E218(); int E34();
int E310(); int E435(); int E52();
int E53(); int E54(); int E56();
int E57(); int E58(); int E59();
int E510(); int E511(); int E512();
int E513();

/*
 * Main Function Region
 */
int main() {
    int funcNum;

    #ifdef _WIN32 
        system("cls");
    #else 
        system("clear");
    #endif

    printFuncLD();

    printf("예제 번호 => ");
    scanf("%d", &funcNum);

    printf("\n");

    switch (funcNum) {
        case 217: E217(); break; case 218 : E218(); break;
        case 34 : E34(); break; case 310 : E310(); break;
        case 435 : E435(); break; case 52: E52(); break;
        case 53 : E53(); break; case 56 : E56(); break;
        case 57 : E57(); break; case 58 : E58(); break;
        case 59 : E59(); break; case 510 : E510(); break;
        case 511 : E511(); break; case 512 : E512(); break;
        case 513 : E513(); break;
        default : printf("다시 읽고 실행하세요.\n"); return 0; 
    }

    printf("\n");

    return 0;
}

void printFuncLD() {
    // funcList
    int funcList[17] = {217, 218, 34, 310, 435, 52, 53, 54, 56, 57, 58, 59, 510, 511, 512, 513};

    // funcDesc
    const char *funcDesc[17];
    funcDesc[0] = "증감 연산자와 복합할당 연산자"; 
    funcDesc[1] = "증감 연산자를 두 번 사용하는 복잡한 수식";
    funcDesc[2] = "폭을 지정하여 새로 정렬로 자료를 출력하는 printf문";
    funcDesc[3] = "난수 생성 함수를 사용하는 프로그램";
    funcDesc[4] = "두 개의 반복 제어 변수를 사용하는 for 반복문 (콤마 연산자 사용)";
    funcDesc[5] = "실수의 거듭제곱을 계산하는 함수의 정의";
    funcDesc[6] = "void 자료형을 갖는 함수";
    funcDesc[7] = "뱐환값이 없는 return을 사용하는 함수";
    funcDesc[8] = "매개변수 값을 변화시키는 함수";
    funcDesc[9] = "수학 함수의 그래프 그리기";
    funcDesc[10] = "전역 변수를 함수의 결과를 저장하는 데 사용";
    funcDesc[11] = "재귀 함수로 구현한 1부터 n까지의 정수의 합 계산";
    funcDesc[12] = "점화식 수열의 항 계산";
    funcDesc[13] = "하노이 탑 문제";
    funcDesc[14] = "static 지역 변수와 보통 지역 변수의 동작 확인";
    funcDesc[15] = "static 지역 변수를 사용하는 난수 발생 함수";

    printf("No  | Description\n");
    for (int i = 0; i <= 15; i++) {
        printf("%-3d | %s\n", funcList[i], funcDesc[i]);
    } 
}

/*
 * Acutal Function Region
 */
int E217() {
    // 증감 연산자와 복합할당 연산자를 포함한 프로그램
    int aValue = 10, bValue;

    aValue++;
    printf("%d ", aValue);
    printf("%d ", ++aValue);
    printf("%d ", aValue--);
    printf("%d\n", aValue);

    printf("aValue = %d, bValue = %d\n", aValue, bValue = aValue * 10);

    aValue += 10; // aValue = aVaule + 10;
    printf("aValue += 10 ==> %d\n", aValue);

    return 0;
}

int E218() {
    // 증감 연산자를 두 번 사용하는 프로그램
    int a = 5, b = a++ * 10 + a++; // 사후, 사후 증가
    printf("후후 = %d\n", b);

    a = 5, b = a++ * 10 + ++a; // 사후, 사전 증가
    printf("후전 = %d\n", b);

    a = 5, b = ++a * 10 + ++a; // 사전, 사전 증가
    printf("전전 = %d\n", b);
    
    return 0;
}

int E34() {
    // 폭을 지정하여 세로 정렬로 자료를 출력하는 printf문

    // 필드 폭 미지정
    printf("%d %d\n", 1, 1);
    printf("%d %d\n", 12, 12);
    printf("%d %d\n", 123, 123);
   
    // 필드 폭 지정
    printf("%5d %5d", 1, 1);
    printf("%5d %5d", 12, 12);
    printf("%5d %5d", 123, 123);

    return 0;
}

int E310() {
    // 난수 생성 함수를 사용하는 프로그램
    // #include <stdlib.h>

    int a = rand(), b = rand(), c = rand();

    double x = (double) rand() / ((long) RAND_MAX + 1), \
           y = (double) rand() / ((long) RAND_MAX + 1), \
           z = (double) rand() / ((long) RAND_MAX + 1);

    // 0과 RAND_MAX 사이의 난수 생성
    printf("%d\t%d\t%d\n", a, b, c); 

    // 1과 100 사이의 난수 생성
    a = 1 + rand() % 100;
    b = 1 + rand() % 100;
    c = 1 + rand() % 100;
    printf("%d\t%d\t%d\n", a, b, c);

    // 0과 1사이의 실수 난수 생성
    printf("%g\t%g\t%g\n", x, y, z);

    return 0;
}

int E435() {
    // 두 개의 반복 제어 변수를 사용하는 for 반복문 (콤마 연산자 사용)
    int i, j;

    for(i = 0, j = 0; i + j <= 30; i++, j += 2) 
        printf("(%d, %d)\n", i, j);

    return 0;
}

// Declare Function that involed in E52()
double calPower(double base, int exp);

int E52() {
    // 실수의 거듭제곱을 계산하는 함수의 정의
    double a, p;
    int n;

    printf("밑^지수 형식으로 입력해라 => ");
    scanf("%lf^%d", &a, &n);

    printf("calPower(%g, %d) = %g", a, n, calPower(a, n));

    return 0;
}

double calPower(double base, int exp) {
    double res = 1.0; // Fallback Number

    for (int i = 0; i < exp; i++) res*= base; 

    return res;
}

// Declare Function that involed in E53()
void printChar(char c, int n); 

int E53() {
    for (int i = 1; i <= 6; i++) printChar('*', i);
    for (int i = 1; i <= 6; i++) printChar('^', i);

    return 0;
}

void printChar(char c, int n) {
    // void 자료형을 갖는 함수
    for (int i = 0; i < n; i++) putchar(c); putchar(' ');
    putchar('\n');
}

// Declare Function that involed in E54()
void printSum(int n);

int E54() {
    // 변환값이 없는 return statemen를 사용하는 함수
    int t = 0; // t = 0으로 초기화

    printf("Enter the target number to sum utill => ");
    scanf("%d", &t);

    printSum(t);

    return 0;
}

void printSum(int n) {
    if (n <= 0) {
        printf("Error: a negative or zero argument passed.\n"); 
        return; // 변환값이 없는 return
    } else {
        int sum = 0;

        for (int i = 0; i <= n; i++) sum += i;
        printf("Sum from 1 to %d is %d.\n", n, sum);    
    }
}

// Declare Function that involed in E56()
void decrPrintChar(char c, int n);

int E56() {
    int count = 10;

    decrPrintChar('*', count);
    printf("count = %d\n", count);
    
    return 0;
}

void decrPrintChar(char c, int n) {
    while (n--) putchar(c);
    putchar('\n');
}

// #include <math.h>
// Declare Functions that involed in E57()
int starPos(double y, double min, double max, int maxPos);
void printStar(int howMany);

int E57() {
    double y;
    int pos;

    // x가 0부터 2pi까지 0.3 간격으로 함수값 출력
    for (double x = 0.0; x < 6.4; x += 0.3) {
        y = sin(x);
        pos = starPos(y, -1.0, 1.0, 40);
        printStar(pos);
    }

    return 0;
}

int starPos(double y, double min, double max, int maxPos) {
    if (min >= max) return 0;

    int yPos;

    if (y < min) yPos = 0;
    else if (y > max) yPos = maxPos;
    else yPos = (y - min) / (max - min) * maxPos;

    return yPos;
}

void printStar(int howMany) {
    for (int i = 0; i < howMany; i++) putchar(' ');
    printf("*\n");
}

// Declare Functions in E58()
int loacalScopeSum(int a, int b);
void globalScopeSum(int a, int b);

// Declare Global Scope Variables
int globalSum, globalDiff;

int E58() {
    int localSum = loacalScopeSum(10, 20);
    printf("localSum = %d / ", localSum);

    globalScopeSum(10, 20);
    printf("globalSum = %d, globalDiff = %d\n", \
            globalSum, globalDiff);

    return 0;
}

int loacalScopeSum(int a, int b) {
    return a + b;
}

void globalScopeSum(int a, int b) {
    // 전역 변수에 결과 저장]
    globalSum = a + b;
    globalDiff = a - b;
}

// Declare Function in E59()
int sumOneToN(int n);

int E59() {
    printf("sumOneToN(10, 1, -1) => (%d, %d, %d)\n", \
            sumOneToN(10), sumOneToN(1), sumOneToN(-1));

    return 0;
}

int sumOneToN(int n) {
    if (n == 1) return 1; 
    else if (n > 1) return sumOneToN(n - 1) + n;
    else return 0; // Invaild Argument
}

// Declare Function in E510()
int igniteExpression(int n);

int E510() {
    printf("igniteExpression(10, 1, -1) => (%d, %d, %d)\n", \
            igniteExpression(10), igniteExpression(1), igniteExpression(-1));

    return 0;
}

int igniteExpression(int n) {
    if (n == 1) return 3;
    else if (n > 1) return 2 * igniteExpression(n - 1) + 1;
    else return 0; // Invaild Argument
} // An = 2An-1 + 1

// Hanoi
void calHanoi(int n, char a, char b, char c);

int E511() {
    int discNum;
    
    printf("discNum ==> ");
    scanf("%d", &discNum);

    calHanoi(discNum, 'A', 'B', 'C'); // Disc Count, Notation * 3

    return 0;
}

void calHanoi(int n, char a, char b, char c) {
    if (n < 1) printf("Error: Invalid number of dicss\n");
    else if (n == 1) printf("원반 %d : %c ==> %c\n", n, a, c);
    else {
        calHanoi(n - 1, a, c, b);
        printf("원반 %d : %c ==> %c\n", n, a, c);
        calHanoi(n - 1, b, a, c);
    }
}

// E512()
void tCountStatic();

int E512() {
    printf("Check the difference between normal variable(a) and variables with static keyword(b, c).\n");
    tCountStatic();
    tCountStatic();
    tCountStatic();

    return 0;
}

void tCountStatic() {
    int a = 0;
    static int b = 0, c;

    c = 0; // 호출될 때마다 c = 0으로 초기화됨을 잊지말장..
    a++; b++; c++;

    printf("a = %d, b = %d, c = %d\n", a, b, c);
}

// E513()
unsigned randomNum(); // unsigned = unsigned int

int E513() {
    for (int i = 0; i < 10; i++) printf("%5d ", randomNum());
    printf("\n");

    return 0;
}

unsigned randomNum() {
    static unsigned seed = 17; // static loaclVariable
    seed = (25173 * seed + 13849) % 65536;

    return seed;
}
