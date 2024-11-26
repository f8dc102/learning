#include <stdio.h>
#include <stdlib.h>

// 함수 선언
void exercise1();
void exercise2();
void exercise3();
void exercise4();

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
  default:
    return main();
  }

  return 0;
}

void exercise1() {
  // 변수 선언
  unsigned int num;

  // 자연수 N 입력
  printf("자연수 N 입력 : ");
  scanf("%d", &num);

  // 별 찍기
  // 오른쪽 정렬
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num - i - 1; j++) {
      printf(" ");
    }

    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }

    printf("\n");
  }
}

void exercise2() {
  // 변수 선언
  unsigned int num;

  // 자연수 N 입력
  printf("자연수 N 입력 : ");
  scanf("%d", &num);

  // 1 <= num <= 100
  if (num < 1 || num > 100) {
    printf("1부터 100 사이의 수를 입력해주세요.\n");
    return;
  }

  // 별 찍기
  // 모래시계 모양으로 찍기
  for (int i = num; i > 0; i--) {
    for (int j = 0; j < num - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < i * 2 - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  for (int i = 2; i <= num; i++) {
    for (int j = 0; j < num - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < i * 2 - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void exercise3() {
  // 변수 선언
  unsigned short count;
  int tmp = 0, sum = 0;

  // 정수 10개 입력 받기
  // 음수일 경우에는 에러 메세지 출력 후 회기
  while (count < 10) {
    scanf("%d", &tmp);

    if (tmp < 0) {
      printf("%d는 잘못된 입력입니다.\n", tmp);

      continue;
    }

    sum += tmp;
    count++;
  }

  // 결과 출력
  printf("합 = %d\n", sum);
}

void exercise4() {
  // 변수 선언
  int num;

  // 마지막 정수 입력
  printf("출력할 마지막 정수 > ");
  scanf("%d", &num);

  // 1부터 num까지 출력
  // 한줄에 8개씩 출력
  for (int i = 0; i <= num; i++) {
    printf("%3d ", i);

    // 8개 출력 후 줄바꿈
    if (i % 8 == 0) {
      printf("\n");
    }

    if (i == num) {
      printf("\n");
      goto quit;
    }
  }

  // goto문 사용??
quit:
  printf("Good Bye!\n");
}
