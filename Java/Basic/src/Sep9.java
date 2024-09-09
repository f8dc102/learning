import java.util.Scanner;

public class Sep9 {
  /**
   * Main Method
   * 
   * @param args Command line arguments
   */
  public static void main(String[] args) {
    boolean isTestPassed = testMethod();

    // Print Blank
    System.out.println();

    if (isTestPassed) {
      System.out.println("Test Passed");
    } else {
      System.out.println("Test Failed");
    }
  }

  /**
   * Test Method
   *
   * @return boolean
   */
  public static boolean testMethod() {
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
  public static String getUserInput() {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter a string: ");

    String input = scanner.nextLine();
    scanner.close();

    return input;
  }
}
