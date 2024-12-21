/*
 * 051523.c
 * Coded for Linux Environment
 *
 * 수업 내용
 * 1. 문자열 함수 활용
 * 2. 구조체 활용
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int catStr(); int cmpStr();
int fbuAtoi(char str[]);
double mulStr(char numA[], char numB[]);
int simpleDict(); int structIntro();
int structTriangle(); int structComplex();
int returnStructFunc(); int structArray();

int main() {
/*    
    printf("Function By Library\n");
    printf("%d\t", atoi("12345"));
    printf("%d\t", atoi("12abc"));
    printf("%d\n", atoi("abc"));

    printf("Function By User\n");
    printf("%d\t", fbuAtoi("12345"));
    printf("%d\t", fbuAtoi("12abc"));
    printf("%d\n", fbuAtoi("abc"));

    printf("%.2f\n", mulStr("129.41", "25.83"));

    simpleDict();
    structIntro();
    structTriangle();
    structComplex();
    returnStructFunc();
*/

    structArray();

    return 0;
}

int catStr() {
    char last[] = "Richie ";
    char first[] = "Dennis ";
    char year[] = "1941-2011";
    char info[100];

    strcpy(info, first);
    strcat(info, last);
    strcat(info, year);

    printf("%s\n", info);

    return 0;
}

int cmpStr() {
    char str1[81], str2[81];
    int result;

    printf("두 단어 입력: ");
    scanf("%s %s", str1, str2);

    result = strcmp(str1, str2);
    if (result < 0) {
        printf("%s가 %s보다 앞에 있음\n", str1, str2);
    } else if (result == 0) {
        printf("%s와 %s가 같음\n", str1, str2);
    } else {
        printf("%s가 %s보다 뒤에 있음\n", str1, str2);
    }

    result = strncmp(str1, str2, 3);
    printf("글자 비교: %d\n", result);

    return 0;
}

int fbuAtoi(char str[]) {
    int number = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') break;
        number = number * 10 + (str[i] - '0');
    }

    return number;
}

double mulStr(char numA[], char numB[]) {
    char result[100];
    double x, y;

    sscanf(numA, "%lf", &x);
    sscanf(numB, "%lf", &y);

    return x * y;
}

// EX7.13
char words[][3][40] = {
    "dog", "Hund", "개",
    "no", "nein", "아니오",
    "yes", "ja", "예",
    "child", "Kind", "아이",
    "I", "Ich", "나",
    "you", "dich", "너",
    "house", "Haus", "집",
    "love", "Liebe", "사랑",
    "", "", ""
};

int simpleDict() {
    char english[80];
    int i = 0;

    printf("영어 단어를 입력하시오: ");
    scanf("%s", english);

    while (strcmp(words[i][0], "")) {
        if (!strcmp(english, words[i][0])) {
            printf("Eng: %s, Ger: %s, Kor: %s\n", words[i][0], words[i][1], words[i][2]);

            return 0;
        }

        i++;
    }

    printf("사전에 없음\n");

    return 1;
}

// 구조체 시작
struct dotPoint {
    double x, y;
};

int structIntro() {
    struct dotPoint A, B;
    double dx, dy, distance;

    printf("첫 번째 점의 좌표: ");
    scanf("%lf, %lf", &A.x, &A.y);

    printf("두 번째 점의 좌표: ");
    scanf("%lf, %lf", &B.x, &B.y);

    dx = A.x - B.x; dy = A.y - B.y;
    distance = sqrt(dx * dx + dy * dy);

    printf("두 점 사이의 거리: %.2f\n", distance);

    return 0;
}

struct trianglePoint {
    struct dotPoint A, B, C;
};

int structTriangle() {
    struct trianglePoint A;
    double triangleArea;

    printf("첫 번째 점의 좌표: ");
    scanf("%lf, %lf", &A.A.x, &A.A.y);

    printf("두 번째 점의 좌표: ");
    scanf("%lf, %lf", &A.B.x, &A.B.y);

    printf("세 번째 점의 좌표: ");
    scanf("%lf, %lf", &A.C.x, &A.C.y);

    triangleArea = (A.A.x * (A.B.y - A.C.y) + A.B.x * (A.C.y - A.A.y) + A.C.x * (A.A.y - A.B.y)) / 2;

    if (triangleArea < 0) triangleArea *= -1;
    printf("삼각형의 넓이: %.2f\n", triangleArea);

    return 0;
}

struct complex {
    double real;
    double imag;
};

int structComplex() {
    struct complex A, B, R; 

    printf("첫 번째 복소수의 실수부와 허수부: ");
    scanf("%lf, %lf", &A.real, &A.imag);

    printf("두 번째 복소수의 실수부와 허수부: ");
    scanf("%lf, %lf", &B.real, &B.imag);

    R.real = A.real + B.real;
    R.imag = A.imag + B.imag;

    printf("두 복소수의 합: %.2f + %.2fi\n", R.real, R.imag);

    return 0;
}

// 리턴값과 매개변수가 모두 구조체인 경우
// 위에서 정의한 구조체 dotPoint를 사용
struct dotPoint midPoint(struct dotPoint A, struct dotPoint B) {
    struct dotPoint M;

    M.x = (A.x + B.x) / 2;
    M.y = (A.y + B.y) / 2;

    return M;
}

int returnStructFunc() {
    struct dotPoint A, B, M;

    printf("첫 번째 점의 좌표: ");
    scanf("%lf, %lf", &A.x, &A.y);

    printf("두 번째 점의 좌표: ");
    scanf("%lf, %lf", &B.x, &B.y);

    M = midPoint(A, B);

    printf("두 점의 중간 점의 좌표: %g, %g\n", M.x, M.y);

    return 0;
}

// 구조체 배열
struct studentInfo {
    int id;         // 학번
    char name[20];  // 학생 이름 
    int dept;       // 학과 코드
};

int structArray() {
    struct studentInfo student[] = {
        { 2023101, "홍길동", 100 },
        { 2023102, "김하나", 100 },
        { 2022851, "박두나", 101 },
        { 2021431, "이세나", 110 },
        { 2019001, "정다운", 200 },
        { 2022300, "한다해", 101 },
        { 2023003, "최윤", 201 }
    };    

    printf("검색할 입학년도를 입력하시오: ");
    int year; scanf("%d", &year);

    for (int i = 0; i < sizeof(student) / sizeof(student[0]); i++) {
        if (student[i].id / 1000 == year) {
            printf("학번: %d, 이름: %s, 학과: %d\n", student[i].id, student[i].name, student[i].dept);
        }
    }

    return 0;
}

// 수업 끝
