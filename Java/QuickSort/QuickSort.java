import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class QuickSort {

  // 퀵 정렬의 피벗을 기준으로 분할하는 함수
  private static int partition(int[] arr, int low, int high) {
    int pivot = arr[high]; // 피벗을 배열의 마지막 요소로 설정
    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
  }

  // 퀵 정렬 함수
  private static void quickSort(int[] arr, int low, int high) {
    if (low < high) {
      int pi = partition(arr, low, high);

      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
  }

  public static void main(String[] args) {
    List<Integer> dataList = new ArrayList<>();

    // 파일 읽기
    try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
      String line;
      while ((line = br.readLine()) != null) {
        String[] numbers = line.split("\\s+");
        for (String num : numbers) {
          dataList.add(Integer.parseInt(num));
        }
      }
    } catch (IOException e) {
      System.err.println("Error reading file: " + e.getMessage());
      return;
    }

    // List<Integer>를 int[]로 변환
    int[] data = dataList.stream().mapToInt(i -> i).toArray();

    // 퀵 정렬 실행
    quickSort(data, 0, data.length - 1);

    // 정렬된 결과 출력
    System.out.print("Sorted data: ");
    for (int num : data) {
      System.out.print(num + " ");
    }
    System.out.println();
  }
}
