import java.util.Scanner;

public class HWOne {
  public static void main(String[] args) {
    // Create a Scanner object
    Scanner userInput = new Scanner(System.in);

    System.out.println("getTax, scannerDemo, primeNumberTable, switchDemo, printGPA");
    // Ask for user input for method name
    System.out.print("Enter the name of the method you want to run: ");
    String methodName = userInput.nextLine();

    // Run the method based on user input
    switch (methodName) {
      case "getTax":
        getTax();
        break;
      case "scannerDemo":
        System.err.println("scannerDemo 메서드는 사용자 입력을 요구합니다.");
        scannerDemo(userInput);
        break;
      case "primeNumberTable":
        primeNumberTable();
        break;
      case "switchDemo":
        switchDemo(userInput);
        break;
      case "printGPA":
        printGPA(userInput);
        break;
      default:
        System.out.println("Method not found.");
        break;
    }

    // Close the Scanner object
    userInput.close();
  }

  /**
   * Practice 2 - 4
   * Sales Tax
   */
  public static void getTax() {
    final double TAX_RATE = 0.06;
    final double PRICE = 197.55;

    // Calculate the tax
    double tax = PRICE * TAX_RATE;

    // Print the tax
    System.out.println("Sales tax is $" + (int) tax);
  }

  /**
   * Example 2
   * Scanner Demo
   * 
   * @COMMENT: 각각의 파일이 아닌 메서드로 구현하기 위해 Scanner 객체를 인자로 받아 사용
   * @WARNING: Scanner 객체를 사용한 후에는 close() 메서드를 반드시 호출해야 함 (누수 방지)
   *           이곳에서는 main 메서드에서 Scanner 객체를 생성하고 사용한 후 close() 메서드를 호출
   *
   * @param userInput
   */
  public static void scannerDemo(Scanner userInput) {
    // Get two integers
    int x = userInput.nextInt();
    int y = userInput.nextInt();

    // Print the multiplication
    System.out.printf("%d * %d는 %d입니다.\n", x, y, x * y);
  }

  /**
   * Practice 3 - 10
   * Prime Number Table
   *
   * @COMMENT: 10x5 table set
   *           To be efficient, use the Sieve of Eratosthenes algorithm
   *           But for now, we will use the brute force method
   */
  public static void primeNumberTable() {
    // Initialize the counter
    byte counter = 0;

    // Initialize the number
    short number = 2; // 소수는 2부터 시작

    // Display the prompt
    System.out.println("처음 50개의 소수는:");

    while (counter < 50) { // 50개 소수를 찾아야 하므로 counter < 50
      // Determine if the number is a prime number
      boolean isPrime = true;

      // Check if the number is prime
      if (number > 3) {
        // 소수 판정을 위해 2, 3을 제외하고 5부터 시작
        if (number % 2 == 0 || number % 3 == 0) {
          isPrime = false;
        } else {
          for (short i = 5; i <= Math.sqrt(number); i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
              isPrime = false;
              break;
            }
          }
        }
      }

      // 소수이면 출력하고 카운터 증가
      if (isPrime) {
        // Add Spacer every 10 numbers
        if (counter % 10 == 0) {
          System.out.println();
        }

        // Only if the number is a prime number.
        System.out.printf("%3d ", number);

        // Increment the counter for the next prime number
        counter++;
      }

      // Increment the number to check the next one
      number++;
    }
  }

  /*
   * Example 4
   * Switch Statement Demo
   */
  public static void switchDemo(Scanner userInput) {
    // Get the number
    System.out.print("등수를 입력하세요 : ");
    int rank = userInput.nextInt();

    // Determine the rank
    switch (rank) {
      case 1:
        System.out.println("일등입니다.");
        break;
      case 2:
        System.out.println("이등입니다.");
        break;
      case 3:
        System.out.println("삼등입니다.");
        break;
      default:
        System.out.println("등외입니다.");
        break;
    }
  }

  /*
   * Example 5
   * if-else Statement Demo
   */
  public static void printGPA(Scanner userInput) {
    // Initialize Grade
    char grade = 'F';

    // Get the score
    System.out.print("점수를 입력하세요 : ");
    byte score = userInput.nextByte();

    // Determine the grade
    if (score >= 90) {
      grade = 'A';
    } else if (score >= 80) {
      grade = 'B';
    } else if (score >= 70) {
      grade = 'C';
    } else if (score >= 60) {
      grade = 'D';
    }

    // Print the grade
    System.out.printf("%d점 %c등급입니다.", score, grade);
  }
}
