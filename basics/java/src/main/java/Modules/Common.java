package Modules;

import java.util.Scanner;

/**
 * Basics Class
 * 
 * This class contains basic Java programming concepts
 * 
 * @version 1.0
 * @since 2024-09-14
 */
public class Common {
  /**
   * Main Method
   * 
   * @param args Command line arguments
   */
  public static void main(String[] args) {
    // Inintialize Scanner
    Scanner userInput = new Scanner(System.in);

    // Load Practice Class
    Practice practice = new Practice(userInput);

    // Test Logic
    boolean isTestPassed = (testMethod(userInput) && practice != null);

    // Print Blank
    System.out.println();

    if (isTestPassed) {
      System.out.println("Test Passed");
    } else {
      System.out.println("Test Failed");
    }

    // Close Scanner
    userInput.close();
  }

  /**
   * Test Method
   *
   * @return boolean
   */
  public static boolean testMethod(Scanner userInput) {
    final double PI = 3.141592;

    int val1 = 15;
    int val2 = 0;

    if (val1 > 10) {
      val2 = val1 - 10;
    }

    int val3 = val1 + val2 + 5;
    System.out.println("PI * val3 = " + (PI * val3));

    double circleArea = getCircleArea(5);
    System.out.println("Circle Area = " + circleArea);

    String userString = getUserString(userInput);
    System.out.println("User Input: " + userString);

    return true;
  }

  /**
   * getCircleArea Method
   *
   * @param radius double
   * @return double
   */
  public static double getCircleArea(double radius) {
    return radius * radius * Math.PI;
  }

  /**
   * Casting Method
   *
   * @param targetVar int
   * @return short
   */
  public static short castingMethod(int targetVar) {
    return (short) targetVar;
  }

  /**
   * Casting Method
   *
   * @param targetVar double
   * @return short
   */
  public static short castingMethod(double targetVar) {
    return (short) (targetVar);
  }

  /**
   * Get User Input
   *
   * @return String
   */
  public static String getUserString(Scanner userInput) {
    System.out.print("Enter a string: ");
    String input = userInput.nextLine();

    return input;
  }
}

/**
 * Practice Class
 * 
 * This class contains practice problems for Java programming
 * 
 * @version 1.0
 * @since 2024-09-14
 */
class Practice {
  /**
   * Constructor
   */
  public Practice(Scanner userInput) {
    System.out.println("Starting Practice Class...\n");

    // Practice 2-1
    System.out.println("Practice 2-1");
    scopeOfVariables();
    System.out.println();

    // Practice 2-2
    System.out.println("Practice 2-2");
    getAreaOfCircle(userInput);
    System.out.println();

    // Practice 2-3
    System.out.println("Practice 2-3");
    printRangeOfDataTypes();
    System.out.println();

    // Practice 2-4
    System.out.println("Practice 2-4");
    calculateTax();
    System.out.println();

    // Practice 2-5
    System.out.println("Practice 2-5");
    calculateAverage(userInput);
    System.out.println();
  }

  /**
   * Practice 2-1
   * Scope of Variables
   * 
   * @return void
   */
  public void scopeOfVariables() {
    int val1 = 15;
    int val2 = 0; // Fix Error of Scope of val2

    if (val1 < 10) {
      val2 = val1 - 10;
    }

    int val3 = val1 + val2 + 5;
    System.out.println("val3 = " + val3);
  }

  /**
   * Practice 2-2
   * Get Area of Circle
   * 
   * @return void
   */
  public void getAreaOfCircle(Scanner userInput) {
    // Get Radius from User
    // Scanner userInput = new Scanner(System.in);
    System.out.print("Enter Radius: ");
    double radius = userInput.nextDouble();

    // Get Area
    double area = Math.PI * radius * radius;

    // Print Area
    System.out.println("Area: " + area);
  }

  public void printRangeOfDataTypes() {
    // Ranges of byte Type
    System.out.println("Ranges of byte Type");
    System.out.println("Byte Min: " + Byte.MIN_VALUE);
    System.out.println("Byte Max: " + Byte.MAX_VALUE);
    System.out.println();

    // Ranges of short Type
    System.out.println("Ranges of short Type");
    System.out.println("Short Min: " + Short.MIN_VALUE);
    System.out.println("Short Max: " + Short.MAX_VALUE);
    System.out.println();

    // Ranges of int Type
    System.out.println("Ranges of int Type");
    System.out.println("Int Min: " + Integer.MIN_VALUE);
    System.out.println("Int Max: " + Integer.MAX_VALUE);
  }

  /**
   * Practice 2-4
   * calculateTax Method
   * 
   * @return void
   */
  public void calculateTax() {
    // Tax Rate
    final double TAX_RATE = 0.06;

    // Price
    double price = 197.55;
    double tax = price * TAX_RATE;

    // Print Price and Tax
    System.out.println("Casted Price and Tax to Integer");
    System.out.println("Price: " + (int) price);
    System.out.println("Tax: " + (int) tax);
  }

  /**
   * Practice 2-5
   * Calculate Average of 3 Numbers
   */
  public void calculateAverage(Scanner userInput) {
    // Print Prompt
    System.out.println("Enter three Numbers: ");

    // Read Input
    // @WARNING: Scanner is already initialized in Main Method
    int numA = userInput.nextInt();
    int numB = userInput.nextInt();
    int numC = userInput.nextInt();

    // Calculate Average
    double average = (numA + numB + numC) / 3.0;

    // Print Average
    System.out.printf("The average of %d, %d, and %d is %f", numA, numB, numC, average);
  }
}
