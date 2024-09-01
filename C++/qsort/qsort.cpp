#include <fstream>
#include <iostream>
#include <vector>

// 퀵 정렬의 피벗을 기준으로 분할하는 함수
int partition(std::vector<int> &arr, int low, int high) {
  int pivot = arr[high]; // 피벗을 배열의 마지막 요소로 설정
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

// 퀵 정렬 함수
void quickSort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  // 시간 측정
  clock_t start = clock();

  // 파일에서 데이터 읽기
  std::ifstream inputFile("input.txt");
  std::vector<int> data;

  // 파일이 열리지 않을 경우 오류 메시지 출력
  if (!inputFile.is_open()) {
    std::cerr << "Unable to open file";
    return 1;
  }

  int value;
  // 파일에서 정수 읽기
  while (inputFile >> value) {
    data.push_back(value);
  }

  inputFile.close();

  // 퀵 정렬 실행
  quickSort(data, 0, data.size() - 1);

  // 시간 측정
  clock_t end = clock();

  // 정렬된 결과 출력
  std::cout << "Sorted data: ";
  for (const int &num : data) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // 시간 측정 결과 출력
  printf("Execution Time: %fms\n",
         (double)(end - start) / CLOCKS_PER_SEC * 1000);

  return 0;
}
