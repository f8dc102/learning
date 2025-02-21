// UsrInput.java

package Utils;

import java.util.Scanner;

/**
 * User Input
 * 
 * @description Handle user input
 */
final public class UsrInput {
  // Input Field
  static String input;

  // Initialize scanner
  private static Scanner userInput = new Scanner(System.in);

  // Get user input
  public static String getInput(String prompt) {
    // Prompt user
    System.out.print(prompt);

    // Get user input
    input = userInput.nextLine();

    // Return UsrInput object
    return input;
  }

  // Convert string to integer
  public static int convertToInt() {
    return Integer.parseInt(input);
  }

  // Convert string to double
  public static double convertToDouble() {
    return Double.parseDouble(input);
  }

  // Convert string to short
  public static short convertToShort() {
    return Short.parseShort(input);
  }

  // Convert string to byte
  public static byte convertToByte() {
    return Byte.parseByte(input);
  }

  // Convert string to long
  public static long convertToLong() {
    return Long.parseLong(input);
  }

  // Convert string to float
  public static float convertToFloat() {
    return Float.parseFloat(input);
  }

  // Convert string to boolean
  public static boolean convertToBoolean() {
    return Boolean.parseBoolean(input);
  }

  // Convert string to character
  public static char convertToChar() {
    return input.charAt(0);
  }

  // Close scanner
  public static void close() {
    userInput.close();
  }
}
