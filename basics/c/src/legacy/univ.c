/*
 * =====================================================================================
 *
 *       Filename:  univ.c
 *
 *    Description:  Chapter 3 Examples 
 *
 *        Version:  1.0
 *        Created:  03/27/23 05:41:04
 *       Compiler:  gcc
 *
 *         Author:  정재윤 (Kernelily), 
 *   Organization:  YONSEI UNIVERSITY
 *
 * =====================================================================================
 */
// Essentials
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// INT_MAX & FLT_MIN_10_EXP 
#include <limits.h>
#include <float.h>

// Define PI
#define PI 3.141592

/*
 * Declare Function
 */
void E32(); void E34(); void E35();
void E36(); void E37(); void E39();
void E310(); void E311();

void testSum(); void moRaeSeeGae();
int testForLoop(); int elseIf();
int checkRange(); int yoonYearCheck();

/*
 * Main Function
 */
int main(void) {
    int funcNum;

    printf("Enter Example Number => ");
    scanf("%d", &funcNum);

    switch (funcNum) {
        case 32: E32(); break; case 34: E34(); break;
        case 35: E35(); break; case 36: E36(); break;
        case 37: E37(); break; case 39: E39(); break;
        case 310: E310(); break; case 311: E311(); break;
        case 123: testSum(); break; case 456: moRaeSeeGae(); break;
        default: return main();
    }

    return 0;
}

/*
 * Actual Function Declare
 */
int E210() {
    float scale = 1.609, mile = 85000.0;
    printf("km = %f\n", scale * mile);

    return 0;
}

int E211() {
    int a = 8, b = 20, t; // t는 임시변수
    a = a + 2;

    printf("BEFORE : a = %d, b = %d\n", a, b);

    t = a; a = b; b = t;
    printf("AFTER : a = %d, b = %d\n", a, b);
    
    return 0;
}

int E213() {
    float f, c;

    printf("TYPE f ==> ");
    scanf("%f", &f);

    c = 5.0 / 9.0 * (f - 32.0);
    printf("F => C, C = %f\n", c);

    return 0;
}

int E214() {
    int a = 10, b = 15, c;
    float x = 10.0, y = 30.0, z;

    printf("%f\t %d\t %d\t %f\n",
            5.0 / 9.0 * 9.0,
            5 / 9 * 5,
            (2 * b - a) / 3,
            (x + 3.0) / (y - 5.0)
            );
    
    return 0;
}

int E215() {
    double d;
    float f;
    int a;
    short b;

    d = 12356.789012;
    f = d;
    a = f;
    b = a;

    printf("d= %f\t f = %f\t a = %d\t b = %d\n", d, f, a, b);

    return 0;
}

int E2151() {
    double d0, d1;
    int num = 30, den = 8;

    d0 = num / den;
    d1 = (double)num / den;
    
    printf("d0 = %f\td1 = %f\n", d0, d1);
    return 0;
}

int E218() {
    int a, b, c, d, e;
    a = 0x8C67;

    b = a | 0x00F0;
    c = a ^  0x000F;
    d = a & 0x0F00;
    e = a & ~0x0F00;

    printf("%x\t%x\t%x\t%x\n", b, c, d, e);

    return 0;
}

int E220() {
    int a, b;
    
    a = 0x39; // %x는 16진수로 나타낸 값을 의미한다.
    printf("%d\t%d\t%d\t%d\n", a, a >> 2, a << 3, (a << 2) + a);

    b = (a & 0xF0) >> 4;
    printf("b >> 4 = %x\t", b);

    b = 1 << 31; // 최상위 비트(31번)가 1이고 나머지 0인 정수
    printf("1 << 31 = %x\n", b);

    a = 0x8000C000;
    printf("%x\t%x\n", a >> 2, (unsigned)a >> 2);
    // signed에서는 앞 비트를 1로 채운다.
    // unsigned에서는 앞 비트를 0으로 채운다.
    // result 0xE0003000 / 0x20003000

    return 0;
}

void E32() {
    char c = 'A';

    printf("%s 95%%\n", "C language");
    printf("%c의 코드 : %d, %o, %x\n", c, c, c, c);
    
    float f = 123.456;
    printf("%f\n", f);
}

void E34() {
    char c = 'A';
    printf("%c%c%c%c\n", c, c, c, c);
    printf("%6c%6c%6c%6c\n", c, c, c, c);

    int a = 123;
    printf("|%d|%5d|%-5d|\n", a, a, a);

    printf("%d %d\n", 1, 1);
    printf("%d %d\n", 12, 12);
    printf("%d %d\n\n", 123, 123);

    printf("%5d %5d\n", 1, 1);
    printf("%5d %5d\n", 12, 12);
    printf("%5d %5d\n", 123, 123);
}

void E35() {
    int a;
    float f;

    scanf("%d %f\n", &a, &f);
    printf("%d %f\n", a, f);
}

void E36() {
    int month, date, height;
    double weight;

    printf("월/ 일 ==> ");
    scanf("%d / %d", &month, &date);
    printf("몸무게, 키 ==> ");
    scanf("%lf, %d", &weight, &height);

    printf("측정일 : %d월 %d일, 몸무게 %fkg, 키 %dcm\n", 
            month, date, weight, height);
}

void E37() {
    int c;

    c = getchar(); // 한 글자만 읽음.
    putchar(c);

    c = getchar(); // 한 글자만 읽음.
    putchar(c);
}

void E39() {
    double a, b, c, alpha;

    printf("b, c, alpha 형식으로 입력해라 ==> ");
    scanf("%lf, %lf, %lf", &b, &c, &alpha);
    a = sqrt(b * b + c * c - 2 * b * c * cos(alpha * PI / 180.0));

    printf("a = %lf\n", a);
}

void E310() {
    srand((unsigned int)time(NULL));

    int a = rand(), b = rand(), c = rand();
    int h = rand() % 100 + 1, j = rand() % 100 + 1, l = rand() % 100 + 1;
    double x = (double) rand() / ((long) RAND_MAX + 1),
           y = (double) rand() / ((long) RAND_MAX + 1),
           z = (double) rand() / ((long) RAND_MAX + 1);
    
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    printf("h = %d, j = %d, l = %d\n", h, j, l);
    printf("x = %g, y = %g, z = %g\n", x, y, z);
}

void E311() {
    int a, b, c;

    printf("a + b + c의 형식으로 입력해라 ==> ");
    scanf("%d + %d + %d", &a, &b, &c);
    printf("Sum is %d\n", a + b + c);
}

void moRaeSeeGae() {
    int i, j;

	for(i = 1; i <= 4; i++){
		for(j = 2; j <= i; j++) {
			printf(" ");
		}

		for(j = 9; j >= i * 2 - 1; j--) {
			printf("*");
		}

		printf("\n");
	}
	
	for(i = 1; i <= 5; i++){
		for(j = 4; j >= i; j--) {
			printf(" ");
		}

		for(j = 1; j <= i * 2 - 1; j++) {
			printf("*");
		}

		printf("\n");
	}
}

int yoonYearCheck() {
    int year, isLeap;

    printf("Year? ==> ");
    scanf("%d", &year);

    isLeap = (year % 4 == 0) && (year % 100 !=0) || (year % 400 == 0);
    isLeap ? printf("%d년은 윤년이야.\n", year) : printf("응 %d년은 윤년이 아니야~\n", year);

    return 0;
}

int checkRange() {
    int number;

    printf("정수를 입력해라 ==> ");
    scanf("%d", &number);

    if (number >= 80 && number < 90) 
        printf("입력은 80이상 90미만이다.");
    
    return 0; 
}

int elseIf() {
    int score;
    char grade;

    printf("점수 입력 ==> ");
    scanf("%d", &score);

    if (score >= 90) 
        grade = 'A';
    else if (score >= 80) 
        grade = 'B';
    else if (score >= 70) 
        grade = 'C';
    else if (score >= 60) 
        grade = 'D';
    else
        grade = 'F';

    printf("등급 : %c\n", grade);

    return 0;
}

int calCircleS() {
    float r;

    printf("원의 반지름 ==> ");
    scanf("%f", &r);

    while (r >= 0) {
        printf("반지름 = %f, 넓이 = %f\n", r, r * r * PI);
        scanf("%f", &r);
    }

    return 0;
}

int floatFbs() {
    int n; float r, prod = 1.0;

    printf("거듭제곱할 실수 ==> "); 
    scanf("%f", &r);

    printf("거듭제곱 횟수 ==> ");
    scanf("%d", &n);

    while (n > 0) {
        prod *= r;
        n -= 1;
    }

    printf("결과 = %f\n", prod);

    return 0;
}

int testForLoop() {
    // Syntax of "For Loop"
    // for (init; cond; renew) {}
    int sum = 0, N;

    printf("1~N까지의 합이라 할 때의 N의 값을 입력 ==> ");
    scanf("%d", &N);

    for (int i = 0; i <= N; i++) {
        sum += i;
    }

    printf("sum = %d\n", sum);

    return 0;
}

int incTest() {
    int init = 1, incr = 1, sum = 0;

    for (int i = 1; i < 20; i++) {
        printf("%4d\n", init);

        sum += init;
        init += incr;
        incr++;
    }

    return 0;
}



// Deprecated Functions
int tscan() {
    float r, s, v;
    
    printf("원의 널이를 구해드림!\n");
    printf("반지름 ==> ");
    scanf("%f", &r);

    s = PI * r * r;
    
    printf("\n넓이 ==> %f\n", s);
    printf("둘레 ==> %f\n", 2 * PI * r);
    printf("부피 ==> %f\n", 4 / 3 * PI * r * r * r);
    return 0;
}

int cver() {
    printf("__STDC_VERSION__ = %ld\n", __STDC_VERSION__);
    return 0;
}

int ds() {
    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
        sizeof(char),        // 1
        sizeof(short),       // 2
        sizeof(int),         // 4
        sizeof(long),        // 4
        sizeof(long long)    // 8
    );

    return 0;
}

int strangef() {
    printf("INT_MAX = %d\n", INT_MAX);
    printf("FLT_MAX_10_EXP = %d\n", FLT_MAX_10_EXP);
    printf("FLT_MIN_10_EXP = %d\n", FLT_MIN_10_EXP);
    printf("FLT_DIG = %d\n", FLT_DIG);

    return 0;
}

void testSum() {
    static int a = 10;
    int b = 20;

    a++; b++;
    printf("a = %d, b = %d\n", a, b);
}
