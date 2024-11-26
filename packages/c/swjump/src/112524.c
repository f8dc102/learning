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
  unsigned short exerciseNumber = 0;

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
}

// Exercise 2
void exercise2() {
}

// Exercise 3
void exercise3() {
}

// Exercise 4
void exercise4() {
}

// Exercise 5
void exercise5() {
}
