package Modules;

import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Collections;

public class StringArrayDebug {
  public static void main(String[] args) {
    // Get Scanner object
    Scanner userInput = new Scanner(System.in);

    ArrayExample arrayExample = new ArrayExample();
    arrayExample.dynArray(userInput);

    // Close Scanner object
    userInput.close();
  }
}

class StringExample {
  public StringExample() {
    System.out.println("String constructor");
  }

  public static void checkEqual() {
    String s1 = "Hi, Java!";
    String s2 = "Hi, Java!";
    String s3 = new String("Hi, Java!");
    String s4 = new String("Hi, Java!");

    System.out.println("s1 == s2 -> " + (s1 == s2)); // true
    System.out.println("s1 == s3 -> " + (s1 == s3)); // false
    System.out.println("s3 == s4 -> " + (s3 == s4)); // false

    s1 = s3;
    System.out.println("s1 == s3 -> " + (s1 == s3)); // true
  }

  public static void comparingString() {
    String s1 = "Hi, Java!";
    String s2 = new String("Hi, Java!");
    String s3 = new String("Hi, Code!");
    String s4 = new String("Hi, java!");

    System.out.println(s1.equals(s2)); // true
    System.out.println(s1.equals(s3)); // false
    System.out.println(s1.equals(s4)); // false
    System.out.println(s1.equalsIgnoreCase(s4)); // true

    System.out.println(s1.compareTo(s3)); // -2
    System.out.println(s1.compareToIgnoreCase(s4)); // 0
    System.out.println(s3.compareTo(s4)); // 2
    System.out.println("Hi, Java!".compareToIgnoreCase("hi, java!")); // 0

    System.out.printf("'J' - 'C'=%d\n", 'J' - 'C'); // 2
    System.out.printf("'C' - 'j'=%d\n", 'C' - 'j'); // -2
  }

  public static void controlString() {
    String s1 = new String("Hi, ");
    String s2 = new String(" Java");
    String s3, s4;

    System.out.println("문자열의 길이(s1) : " + s1.length());

    char c = s1.charAt(1);
    System.out.println("s1의 두 번째 문자 : " + c);

    s1 = s1.concat(s2);

    s3 = s1.toLowerCase();
    s4 = s1.substring(4, 8);

    System.out.println("s1 : " + s1);
    System.out.println("s3 : " + s3);
    System.out.println("s4 : " + s4);
  }
}

class StringPractice {
  public StringPractice() {
    System.out.println("StringPractice constructor");
  }

  public static void countUpperCase(Scanner userInput) {
    // Read a string from the user
    System.out.print("Enter a string: ");
    String str = userInput.nextLine();

    // Count the number of uppercase letters
    int count = 0;

    for (int i = 0; i < str.length(); i++) {
      if (Character.isUpperCase(str.charAt(i))) {
        count++;
      }
    }

    System.out.println("대문자의 수는 " + count + "개 입니다.");
  }

  public static void reverseStringPrint(Scanner userInput) {
    // Read a string from the user
    System.out.print("Enter a string: ");
    String str = userInput.nextLine();

    // Reverse the string and print it
    for (int i = str.length() - 1; i >= 0; i--) {
      System.out.print(str.charAt(i));
    }

    // Print a newline
    System.out.println();
  }

  public static void howManyVowel(Scanner userInput) {
    // Read a string from the user
    System.out.print("Enter a string: ");
    String str = userInput.nextLine();

    // Count the number of vowels
    int consonants = 0;
    int vowels = 0;
  }
}

class ArrayExample {
  public ArrayExample() {
    System.out.println("ArrayExample constructor");

    int[] anArray = { 1, 2, 3 };
    callByReference(anArray);

    System.out.println("After: " + Arrays.toString(anArray));

    variableParameter(1, 2, 3, 4, 5);
    variableParameter(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  }

  public static void dynArray(Scanner userInput) {
    ArrayList<Integer> intArrayList = new ArrayList<Integer>();

    // Add elements to the ArrayList
    System.out.print("Enter 5 integers: ");

    for (int i = 0; i < 5; i++) {
      intArrayList.add(userInput.nextInt());
    }
  }

  /**
   * callByReference
   * Test call by reference
   * 
   * @param intArray
   * @return void
   */
  public static void callByReference(int[] intArray) {
    System.out.println("Before: " + Arrays.toString(intArray));

    // Do something with the array
    for (int i = 0; i < intArray.length; i++) {
      intArray[i] *= 2;
    }
  }

  /**
   * variableParameter
   * Test variable parameter
   *
   * @param int... intValue
   * @return void
   */
  public static void variableParameter(int... intValue) {
    // Declare variables
    int elementCount = intValue.length;
    int sum = 0;

    // Calculate the sum of the elements
    for (int i : intValue) {
      sum += i;
    }

    // Display the result
    System.out.println("Number of elements: " + elementCount);
    System.out.println("Sum of elements: " + sum);
  }
}

/**
 * ArrayPractice
 */
class ArrayPractice {
  public ArrayPractice() {
    System.out.println("ArrayPractice constructor");
  }

  public static void createArray(Scanner userInput) {
    // Create an array of 5 double values
    double[] arr = new double[5];

    // Read values from the user
    System.out.print("Enter 5 value: ");
    for (int i = 0; i < arr.length; i++) {
      arr[i] = userInput.nextDouble();
    }

    // Display the values
    System.out.println("Entered values are: ");
    for (int i = 0; i < arr.length; i++) {
      System.out.println(arr[i]);
    }
  }

  public static void findMaxValue() {
    // Initialize an array of 5 integers
    int[] arr = { 1, 2, 3, 4, 5 };

    // max and index
    int max = arr[0];
    int index = 0;

    // Find the largest
    for (int i = 1; i < arr.length; i++) {
      if (arr[i] > max) {
        max = arr[i];
        index = i;
      }
    }

    // Display the result
    System.out.println("Largest element is " + max + ", and the smallest index of 5 is " + index);
  }

  public static void calAvg(Scanner userInput) {
    // How many numbers to average?
    System.out.print("Enter the number of items: ");
    int size = userInput.nextInt();

    // Read the numbers
    System.out.print("Enter the numbers: ");
    double[] arr = new double[size];

    for (int i = 0; i < arr.length; i++) {
      arr[i] = userInput.nextDouble();
    }

    // Calculate the average
    double avg = 0, aboveAvg = 0;
    for (int i = 0; i < arr.length; i++) {
      avg += arr[i];
    }

    avg /= arr.length;
    System.out.println("Average: " + avg);

    // Find the number of elements above the average
    for (int i = 0; i < arr.length; i++) {
      if (arr[i] > avg) {
        aboveAvg++;
      }
    }

    System.out.println("Number of elements above the average: " + aboveAvg);
  }

  public static void swapElement() {
    // Declare an array that has two elements
    int[] arr = { 1, 2 };

    // Print the original array
    System.out.println("Original array: " + Arrays.toString(arr));

    // Swap the elements
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;

    // Print the swapped array
    System.out.println("Swapped array: " + Arrays.toString(arr));
  }

  public static void sortArrayElement() {
    double[] arr = { 1, 9, 4.5, 5.7, -4.5 };

    // Print the original array
    System.out.println("Original array: " + Arrays.toString(arr));

    // Sort the Array
    Arrays.sort(arr);

    // Print the sorted array
    System.out.println("Sorted array: " + Arrays.toString(arr));
  }

  public static void secondDimensionArray(Scanner userInput) {
    // Declare a 2D array
    int[][] arr = new int[3][4];

    // Get Eleemnts from the user
    System.out.println("Enter 3 rows and 4 columns: ");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        arr[i][j] = userInput.nextInt();
      }
    }

    // Display the sum of entire array
    int sum = 0;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        sum += arr[i][j];
      }
    }

    // Display the result
    System.out.println("Sum of all elements: " + sum);
  }

  public static void secondDimensionArrayOperation(Scanner userInput) {
    // Declare 2D arrays
    int[][] arrA = new int[3][3];
    int[][] arrB = new int[3][3];

    // Get elements from the user
    System.out.println("Enter 3x3 matrix A: ");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        arrA[i][j] = userInput.nextInt();
      }
    }

    System.out.println("Enter 3x3 matrix B: ");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        arrB[i][j] = userInput.nextInt();
      }
    }

    // Add two matrices
    int[][] sum = new int[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        sum[i][j] = arrA[i][j] + arrB[i][j];
      }
    }

    // Print Complete Matrices
    // Like : 1 2 3 1 2 3 2 4 6
    // 4 5 6 + 4 5 6 = 8 10 12
    // 7 8 9 7 8 9 14 16 18
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        System.out.print(arrA[i][j] + " ");
      }

      if (i == 1) {
        System.out.print("+  ");
      } else {
        System.out.print("   ");
      }

      for (int j = 0; j < 3; j++) {
        System.out.print(arrB[i][j] + " ");
      }

      if (i == 1) {
        System.out.print("=  ");
      } else {
        System.out.print("   ");
      }

      for (int j = 0; j < 3; j++) {
        System.out.print(sum[i][j] + " ");
      }

      System.out.println();
    }
  }
}
