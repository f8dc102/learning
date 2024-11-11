#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 함수 선언
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();

int main() {
  int exerciseNumber = 0;

  // 문제 번호 입력
  printf("문제 번호 입력 : ");
  scanf("%d", &exerciseNumber);

  // 문제 번호에 따라 함수 호출
  switch (exerciseNumber) {
  case 1:
    exercise1();
    break;
  case 2:
    exercise2();
    break;
  case 3:
    exercise3();
    break;
  case 4:
    exercise4();
    break;
  case 5:
    exercise5();
    break;
  default:
    return main();
  }

  return 0;
}

// Exercise 1
void exercise1() {
  // 변수 선언
  int T, R;
  char S[21];

  // 테스트 케이스 개수 입력
  printf("테스트 케이스 개수 입력: ");
  scanf("%d", &T);

  // R과 문자열 S 입력
  // 문자열 S의 각 문자
  // R번 반복 출력
  for (int i = 0; i < T; i++) {
    printf("R과 문자열 S 입력: ");
    scanf("%d %s", &R, S);

    for (int j = 0; S[j] != '\0'; j++) {
      for (int k = 0; k < R; k++) {
        printf("%c", S[j]);
      }
    }
    printf("\n");
  }
}

// Exercise 2
void exercise2() {
  // 변수 선언
  char str[1000001];
  unsigned int count = 0;

  // 문자열 입력 프롬포트 출력
  printf("문자열 입력: ");

  // 문자열 입력 부분은 GPT의 도움을 받음
  getchar();
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';

  // strtok 함수를 이용하여 공백을 기준으로 단어 개수 세기
  char *token = strtok(str, " ");
  while (token != NULL) {
    count++;
    token = strtok(NULL, " ");
  }

  // 단어 개수 출력
  printf("단어의 개수: %u\n", count);
}

// Exercise 3
typedef struct {
  double real;
  double imag;
} Complex;

// Exercise 3: 서브 함수
Complex divideComplex(Complex a, Complex b) {
  Complex result;
  double denominator = b.real * b.real + b.imag * b.imag;

  result.real = (a.real * b.real + a.imag * b.imag) / denominator;
  result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
  return result;
}

// Exercise 3: Main function
void exercise3() {
  Complex a = {1.0, 2.0};
  Complex b = {2.0, -3.0};

  Complex result = divideComplex(a, b);
  printf("결과: %.2lf + %.2lfi\n", result.real, result.imag);
}

// Exercise 4
typedef struct {
  int x;
  int y;
} Point;

// Exercise 4: 서브 함수
unsigned short determineQuadrant(Point p) {
  if (p.x > 0 && p.y > 0)
    return 1;
  else if (p.x < 0 && p.y > 0)
    return 2;
  else if (p.x < 0 && p.y < 0)
    return 3;
  else if (p.x > 0 && p.y < 0)
    return 4;
  else
    return 0;
}

// Exercise 4: Main function
void exercise4() {
  // 좌표 입력
  Point p;
  printf("좌표 입력 (x y): ");
  scanf("%d %d", &p.x, &p.y);

  // 사분면 출력
  printf("%hd사분면입니다.\n", determineQuadrant(p));
}

// Exercise 5
void exercise5() {
  // 구조체 선언
  typedef struct {
    char time[7];
    char food[128];
    unsigned int calories;
  } Meal;

  // 샘플 데이터
  Meal meals[4] = {
      {"아침", "시리얼", 120},
      {"점심", "김밥", 300},
      {"점심", "닭가슴살 샐러드", 200},
      {"저녁", "피자", 800},
  };

  unsigned int totalCalories = 0;
  unsigned short menu = 0;
  char tmpStr[7];

  // 프롬포트 출력
  printf("식단 관리 프로그램\n");
  printf("1. 시간대별 섭취한 칼로리 출력\n");
  printf("2. 하루 동안 먹은 전체 칼로리 출력\n");
  printf("3. 종료\n");

  // 메뉴 선택
  printf("\n메뉴 선택: ");
  scanf("%hu", &menu);

  // 메뉴에 따라 함수 호출
  switch (menu) {
  case 1:
    // 프롬포트 출력
    printf("검색할 시간대를 입력하세요 (아침, 점심, 저녁): ");
    scanf("%s", tmpStr);

    // 시간대에 따른 칼로리 출력
    for (int i = 0; i < 4; i++) {
      if (strcmp(tmpStr, meals[i].time) == 0) {
        printf("- %s: %d kcal\n", meals[i].food, meals[i].calories);
        totalCalories += meals[i].calories;
      }
    }

    printf("총 칼로리: %u kcal\n", totalCalories);

    break;
  case 2:
    // 하루 동안 먹은 전체 칼로리 출력
    for (int i = 0; i < 4; i++) {
      totalCalories += meals[i].calories;
    }

    printf("하루 동안 먹은 전체 칼로리: %u kcal\n", totalCalories);

    break;
  case 3:
    printf("프로그램을 종료합니다.\n");

    return;
  default:
    return exercise5();
  }
}
