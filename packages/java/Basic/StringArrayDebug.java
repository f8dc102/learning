import java.util.Scanner;
import java.util.Arrays;

public class StringArrayDebug {
  public static void main(String[] args) {
    // Get Scanner object
    Scanner userInput = new Scanner(System.in);

    // Test StringPractice class
    StringPractice.countUpperCase(userInput);
    System.out.println();

    // Test ArrayPractice class
    ArrayPractice.createArray(userInput);
    System.out.println();

    ArrayPractice.findMaxValue();
    System.out.println();

    ArrayPractice.calAvg(userInput);
    System.out.println();

    ArrayPractice.swapElement();
    System.out.println();

    ArrayPractice.sortArrayElement();
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
}

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
}
