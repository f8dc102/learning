#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 함수 선언
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();

int main() {
  int exerciseNumber;

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
  case 6:
    exercise6();
    break;
  default:
    break;
  }

  return 0;
}

void exercise1() {
  // 변수 선언
  int year, month, day, hour, minute;

  // 입력 i.e 2023/03/20 16:10
  printf("입력 : ");
  scanf("%d/%d/%d %d:%d", &year, &month, &day, &hour, &minute);

  // 출력 i.e 2023년 3월 20일 16시 10분
  printf("출력: %d년 %d월 %d일 %d시 %d분\n", year, month, day, hour, minute);
}

void exercise2() {
  // 변수 선언
  double a, b, c, d, average, geometricMean;

  // 입력 i.e 3.5, 4.5, 2.5, 1.5
  printf("입력 : ");
  scanf("%lf, %lf, %lf, %lf", &a, &b, &c, &d);

  // 평균 계산 (산술)
  average = (a + b + c + d) / 4;
  geometricMean = pow(a * b * c * d, 0.25); // 4제곱근

  // 출력
  printf("%.3lf, %.3lf\n", average, geometricMean);
}

void exercise3() {
  // 2부터 20 사이의 10개의 짝수 임의 생성
  for (int i = 0; i < 10; i++) {
    printf("%d ", 2 * (rand() % 10 + 1));
  }
}

void exercise4() {
  // 변수 선언
  int x, y;

  // 입력 i.e 3, 4
  printf("입력 : ");
  scanf("%d, %d", &x, &y);

  // 부호로 사분면 판별
  if (x > 0 && y > 0) {
    printf("1사분면\n");
  } else if (x < 0 && y > 0) {
    printf("2사분면\n");
  } else if (x < 0 && y < 0) {
    printf("3사분면\n");
  } else if (x > 0 && y < 0) {
    printf("4사분면\n");
  }
}

void exercise5() {
  // 변수 선언
  int pH;

  // 입력 i.e 7
  printf("입력 : ");
  scanf("%d", &pH);

  // pH 값에 따른 출력
  if (pH > 12) {
    printf("강알칼리성\n");
  } else if (pH <= 12 && pH > 7) {
    printf("알칼리성\n");
  } else if (pH == 7) {
    printf("중성\n");
  } else if (pH < 7 && pH > 2) {
    printf("산성\n");
  } else if (pH <= 2) {
    printf("강산성\n");
  }
}

void exercise6() {
  // 변수 선언
  int shape;
  double area, radius, width, height;

  // 모양 입력
  printf("도형을 선택하세요 (1: 원, 2: 사각형, 3: 삼각형) : ");
  scanf("%d", &shape);

  // 도형에 따른 계산
  switch (shape) {
  case 1:
    printf("반지름을 입력하세요 : ");
    scanf("%lf", &radius);
    area = 3.141592 * radius * radius;
    break;
  case 2:
    printf("가로, 세로를 입력하세요 : ");
    scanf("%lf, %lf", &width, &height);
    area = width * height;
    break;
  case 3:
    printf("밑변, 높이를 입력하세요 : ");
    scanf("%lf, %lf", &width, &height);
    area = width * height / 2;
    break;
  default:
    printf("잘못된 입력입니다.\n");
    break;
  }

  // 출력
  printf("면적은 %.2lf입니다.\n", area);
}
