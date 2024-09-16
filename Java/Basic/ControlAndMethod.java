import java.util.Scanner;

/**
 * September 16, 2024
 * Lecture 3: Control and Method
 * My dog ate my homework. I will submit it tomorrow.
 * Distracted by coding using NeoVim.
 */
public class ControlAndMethod {
  /**
   * The main method is the entry point of the program.
   *
   * @param args The command-line arguments.
   */
   public static void main(String[] args) {
    // Initalize the Control class
    Control control = new Control();
    control.switchStatement((byte) 112);

    // Initalize the method class
    // Method method = new Method();
    // method.printHello();
  }
}

class Control {
  /**
   * The constructor of the Control class.
   */
  public Control() {
    // Create a Scanner object to read input from the keyboard.
    Scanner scanner = new Scanner(System.in);

    // Ask the user to enter a number.
    System.out.print("Enter a number: ");

    // Read the number entered by the user
    int number = scanner.nextInt();

    // Ternary operator
    // Simply put, the ternary operator is a shortcut for an if-else statement.
    String result = (number % 2 == 0) ? "even" : "odd";
    System.out.println("The number is " + result + ".");

    // Multiple if-else statements
    if (number > 0) {
      System.out.println("The number is positive.");
    } else if (number < 0) {
      System.out.println("The number is negative.");
    } else {
      System.out.println("The number is zero.");
    }

    // Determine if the number is a prime number.
    // Initialize a boolean variable to store the result.
    boolean isPrime = isPrime(number);

    // Print the result
    if (isPrime) {
      System.out.println("The number is a prime number.");
    } else {
      System.out.println("The number is not a prime number.");
    }
  } 

  /**
   * This method checks if a number is a prime number.
   *
   * @param number The number to check.
   * @return true if the number is a prime number, false otherwise.
   */
  public static boolean isPrime(int number) {
    if (number <= 1) {
      return false;
    } else {
      for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
          return false;
        }
      }
    }

    return true;
  }

  /**
  * This method demonstrates the use of the switch statement
  * to determine the name of a number.
  *
  * @param number The number to determine the name of.
  */
  public static void switchStatement(Byte number) {
    // Switch statement
    switch (number) {
      case 1:
        System.out.println("One");
        break;
      case 2:
        System.out.println("Two");
        break;
      case 3:
        System.out.println("Three");
        break;
      default:
        System.out.println("Unknown number");
    }
  }
}
