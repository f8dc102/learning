#include <stdio.h>
#include <string.h>

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
    return main();
  }

  return 0;
}

void exercise1() {
  // 배열 선언 및 초기화
  // 크기 9, 자연수
  unsigned short numArray[9] = {0};

  // 자연수 N 입력
  printf("입력 :\n");
  for (int i = 0; i < 9; i++) {
    scanf("%hd", &numArray[i]);
    if (numArray[i] < 1) {
      printf("1 이상의 자연수를 입력해주세요.\n");
      return exercise1();
    } else if (numArray[i] > 100) {
      printf("100 이하의 자연수를 입력해주세요.\n");
      return exercise1();
    }
  }

  // 최대값 찾기
  int maxIndex = 0;
  for (int i = 0; i < 9; i++) {
    if (numArray[i] > numArray[0]) {
      numArray[0] = numArray[i];
      maxIndex = i;
    }
  }

  // 결과 출력
  printf("\n최대값 : %d, %d번째 수\n", numArray[0], maxIndex + 1);
}

void exercise2() {
  // 배열 선언 및 초기화
  //                     행 열
  //                     |  |
  unsigned short matrixA[9][9] = {0};

  // 자연수 N 입력
  printf("입력 :\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%hd", &matrixA[i][j]);

      if (matrixA[i][j] < 0 || matrixA[i][j] > 100) {
        printf("100 이하의 자연수를 입력해주세요.\n");
        return exercise2();
      }
    }
  }

  // 최댓값 찾기
  // 최댓값, 행, 열 변수 선언 & 초기화
  unsigned short max = matrixA[0][0];
  unsigned short maxRow = 0, maxCol = 0;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (matrixA[i][j] > max) {
        max = matrixA[i][j];
        maxRow = i;
        maxCol = j;
      }
    }
  }

  // 결과 출력
  printf("\n최대값 : %hd, %hd행 %hd열\n", max, maxRow + 1, maxCol + 1);
}

// exercise3
// 전역 변수 선언
int paperA[100][100] = {0};

// 이놈은 호출되는 함수
void exercise3_sub() {
  int N = 0, x = 0, y = 0;
  int coverArea = 0, coverSize = 10;

  // 입력
  printf("입력 :\n");
  // 색종이의 수를 입력 받음
  scanf("%d", &N);

  // N개의 종이에 대해
  // x, y, width, height 입력
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &x, &y);

    // 종이에 대한 영역을 1로 채움
    // 판별하기 위함임!
    for (int a = x; a < x + 10; a++) {
      for (int b = y; b < y + 10; b++) {
        paperA[a][b] = 1;
      }
    }
  }

  // 종이에 채워진 영역 계산
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (paperA[i][j] == 1) {
        coverArea++;
      }
    }
  }

  // 출력
  printf("\n넓이 : %d\n", coverArea);
}

// 요놈이 호출하는 함수
// 즉, 메인 함수로 하자구요.
void exercise3() { exercise3_sub(); }

void exercise4() {
  // 변수 선어 및 초기화
  // N : 행, M : 열, K : 반복 횟수
  int arrayA[300][300] = {0};
  int i = 0, j = 0, x = 0, y = 0;
  int N = 0, M = 0, K = 0;
  int sum[128] = {0};

  printf("입력 :\n");
  // 배열 크기 입력
  scanf("%d %d", &N, &M);

  // 배열 입력
  for (int a = 1; a <= N; a++) {
    for (int b = 1; b <= M; b++) {
      scanf("%d", &arrayA[a][b]);
    }
  }

  // 반복 횟수 입력
  scanf("%d", &K);

  // 각 쿼리에 대해 합 계산
  for (int k = 0; k < K; k++) {
    scanf("%d %d %d %d", &i, &j, &x, &y);
    sum[k] = 0;

    // (i, j)부터 (x, y)까지의 합 계산
    for (int a = i; a <= x; a++) {
      for (int b = j; b <= y; b++) {
        sum[k] += arrayA[a][b];
      }
    }
  }

  // 개행
  printf("\n");

  // 결과 출력
  for (int k = 0; k < K; k++) {
    printf("%d\n", sum[k]);
  }
}

void exercise5() {
  // 변수 선언 및 초기화
  char wordA[1000];
  int strIndex = 0;

  // 단어와 인덱스 입력받기
  printf("입력 :\n");
  scanf("%s\n%d", wordA, &strIndex);

  // 인덱스에서 문자 가져오기
  char charAtIndex = wordA[strIndex - 1];

  // 출력하면 끝 아닌가? ㅎㅎ
  printf("\n%c\n", charAtIndex);
}

void exercise6() {
  // @brief
  // 단어가 포함되어 있는 경우 처음 위치를
  // 포함되어 있지 않다면 -1을 출력
  // for문 쓰면 될듯?

  // 변수 정의 및 초기화
  char wordS[100];

  // 알파벳 위치 저장 배열
  //        26개의 알파벳
  //             |
  int positions[26] = {0};

  // 모든 위치를 -1로 초기화
  for (int i = 0; i < 26; i++) {
    positions[i] = -1;
  }

  // 단어 가져오기
  printf("입력 :\n");
  scanf("%s", wordS);

  // 각 문자에 대해 위치 저장
  for (int i = 0; i < strlen(wordS); i++) {
    // 머리 좀 써서 char 연산을 적용했다.
    // 역시 난 천재인가 ㅎ
    int index = wordS[i] - 'a';

    if (positions[index] == -1) { // 첫 번째 등장 위치만 저장
      positions[index] = i;
    }
  }

  // 결과 출력
  // 문제에는 없지만 친절하게 ~~ A B C D --- 순으로 출력
  for (int i = 0; i < 26; i++) {
    printf("%2c ", 'a' + i);
  }

  // 보기 좋게 스페이서 추가
  printf("\n");

  for (int i = 0; i < 26; i++) {
    printf("%2d ", positions[i]);
  }

  // 학고 탈출 후 깔끔한 마무리~
  printf("\n");
}
