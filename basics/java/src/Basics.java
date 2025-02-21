// Basics.java

import Utils.UsrInput;

/**
 * Basics Class
 * 
 * This class contains basic Java programming concepts
 * And handles other modules
 * 
 * @version 1.0
 * @since 2024-09-14
 */
public class Basics {
  public static void main(String[] args) {
    // Select Module to Run
    System.out.println("Welcome to Java Programming Lecture!\n");

    System.out.println("Select Module to Start:");
    System.out.println("01. Java Langueage Intro");
    System.out.println("02. Common Basics");
    System.out.println("03. Controls");
    System.out.println("04. Methods");
    System.out.println("05. Strings");
    System.out.println("06. Arrays");
    System.out.println("07. OOP");
    System.out.println("08. Inheritance");
    System.out.println("09. Abstract Class");
    System.out.println("10. Interface");
    System.out.println("11. Nested Classes");
    System.out.println("12. Lambda Expression");
    System.out.println("13. Exception Handling");
    System.out.println("14. Generic Classes");
    System.out.println("15. Collections\n");

    // Ask for user input for module number
    short moduleNumber = UsrInput
        .getInput("Enter Module Number: ")
        .convertToShort();

    // Run Selected Module
    switch (moduleNumber) {
      case 1:
        break;
      case 2:
        break;
      default:
        System.out.println("Invalid Module Number!");
        break;
    }

    // Close userInput
    UsrInput.close();
  }
}
