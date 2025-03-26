import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class QuickSort {
  /**
   * Partition Function
   *
   * @param arr  The array to be sorted
   * @param low  The starting index
   * @param high The ending index
   *
   * @return The index of the pivot element
   */
  private static int partition(int[] arr, int low, int high) {
    int pivot = arr[high];
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

  /**
   * Quick Sort Function
   * 
   * @param arr  The array to be sorted
   * @param low  The starting index
   * @param high The ending index
   */
  private static void quickSort(int[] arr, int low, int high) {
    if (low < high) {
      int pi = partition(arr, low, high);

      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
  }

  /**
   * Main Function
   */
  public static void main(String[] args) {
    // Measure Execution Time
    long startTime = System.currentTimeMillis();

    List<Integer> dataList = new ArrayList<>();

    // Read File
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

    // Execute Quick Sort
    quickSort(data, 0, data.length - 1);

    // Measure Execution Time
    long endTime = System.currentTimeMillis();

    // Print Sorted Data
    System.out.print("Sorted data: ");
    for (int num : data) {
      System.out.print(num + " ");
    }
    System.out.println();

    // Print Execution Time
    System.out.println("Execution Time: " + (endTime - startTime) + "ms");
  }
}
