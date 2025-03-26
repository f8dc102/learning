/*
 * =====================================================================================
 *
 *       Filename:  lessImportant.c
 *
 *    Description:  Less Important Example
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

#define PI 3.1415921648

/*
 * Function Declare Region
 */
void printFuncLD();

int E25(); int E27(); int E28();
int E211(); int E212(); int E216();
int E32(); int E36(); int E41();

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
        case 25 : E25(); break; case 27 : E27(); break;
        case 28 : E28(); break; case 211 : E211(); break;
        case 212 : E212(); break; case 216 : E216(); break;
        case 32 : E32(); break; case 36 : E36(); break;
        case 41 : E41(); break;
        default : printf("다시 읽고 실행하세요.\n"); return 0; 
    }

    printf("\n");

    return 0;
}

void printFuncLD() {
    // funcList
    int funcList[10] = {25, 27, 28, 211, 212, 216, 32, 36, 41};

    printf("No  | Description\n");
    for (int i = 0; i <= 8; i++) {
        printf("%-3d | Description\n", funcList[i]);
    } 
}

/*
 * Acutal Fucntion Region
 */
int E25() {
    // 실수 변수 입력을 포함하는 프로그램
    float r, s;

    printf("Enter the radius of a circle => ");
    scanf("%f", &r);

    s = PI * r * r;
    printf("Area is %f\n", s);
    printf("Diameter is %f\n", 2 * r);

    return 0;
}

int E27() {
    // 여러 가지 상수를 사용하는 프로그램
    char dirty[] = "!0Aa \" \\ \101\x42";

    // 10, 8, 16, float, exp, backslah char
    printf("%d\t%d\t%d\t%f\t%f\t%s\n", 15, 017, 0xf, 0.034, 3.4e-2, dirty);

    return 0;
}

int E28() {
    // E25와 같음 
    // define으로 상수 정의 사용

    return E25();
}

int E211() {
    // 변수 값 갱신과 교환
    int a = 8, b = 20;
    int tmp; // temporary var

    a += 2; // a 값 2 증가
    printf("a = %d, b = %d\n", a, b); // prints 10

    // swap a, b using tmp var
    tmp = a; a = b; b = tmp;
    printf("a = %d, b = %d\n", a, b);

    return 0;
} // a = 10\n a = 20, b = 10

int E212() {
    // 산술 연산자를 포함한 프로그램
    // 정수 나눗셈 (몫), 정수 나머지, 실수 나눗셈
    printf("%d\t%d\t%f\n", 9 / 5, 9 % 5, 9.0 / 5.0);
    
    // 다른 부호 정수의 나머지 연산 * 2 / 결과가 0인 나눗셈
    printf("%d\t%d\t%d\n", -9 % 5, 9 % -5, 4 / 5);

    int a = 10, b = -a; // 할당문
    
    a += 5; // a에 +5 연산
    printf("b = %d, a = %d\n", b, a);

    return 0;
}

int E216() {
    // 형 변환 (casting) 연산자를 포함한 프로그램
    double da, db;
    int num = 30, den = 8;

    da = num / den; // loss of precision
    db = (double) num / den;

    printf("%f\t%f\n", da, db);

    return 0;
} // 3.00000 3.75000

int E32() {
    // 여러 가지 형식으로 자료를 출력하는 printf문
    int a = -7168, b = 7168;
    double r = 123.45678, s = 12340000.0;
    char c = 'A'; float f = 123.456;

    /*
     * 정수 출력
     * 정수 8, 16진수 출력
     * 실수 출력
     * 실수 출력
     * 문자열 출력
     * 문자를 문자와 정수로 출력
     *
     * float 실수 출력
     */

    printf("%d %u %o %x\n \
           %o %x\n \
           %f %e %g\n \
           %f %E %G\n \
           %s 95%%\n \
           %c의 코드: %d %o %x\n", \
           a, a, a, a, b, b, r, r, r, s, s, s, \
           "C language", c, c, c, c);

    printf("%f %e %g\n", f, f, f);
    
    return 0;
}

int E36() {
    // 여러 가지 자료를 입력받는 프로그램
    int mo, date, height;
    double weight;

    printf("월 / 일, 몸무게, 키 형식으로 입력 ==> ");
    scanf("%d / %d, %lf, %d", &mo, &date, &weight, &height);

    printf("측정일: %d월 %d일, 몸무게: %fkg, 키: %dcm\n", \
            mo, date, weight, height);

    return 0;
}

int E41() {


    return 0;
}

int E42() {

    return 0;
}
