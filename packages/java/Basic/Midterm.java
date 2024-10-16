import java.util.Scanner;

public class Midterm {
  public static void main(String[] args) {
    // Initialize variables
    String className = "";

    // Create a Scanner
    Scanner userInput = new Scanner(System.in);

    // Prompt the user for the function name
    System.out.print("Enter the function name: ");
    className = userInput.nextLine();

    // Call the function
    switch (className) {
      case "PrimeTable":
        PrimeTable.main();
        break;
      default:
        System.out.println("Invalid class name.");
    }
  }
}

class PrimeTable {
  public static void main() {
    // Initialize the counter
    byte counter = 0;

    // Initialize the number
    int number = 2; // 소수는 2부터 시작

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
}
