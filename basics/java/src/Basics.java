package f8dc102;

import java.util.Scanner;

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
    // Inintialize Scanner
    Scanner userInput = new Scanner(System.in);

    // Select Module to Run
    System.out.println("Welcome to Java Programming Lecture!\n");

    System.out.println("Select Module to Run:");
    System.out.println("01. Java Langueage Intro");
    System.out.println("02. Basics");
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

    System.out.print("Enter Module Number: ");
    short moduleNumber = userInput.nextShort();

    // Run Selected Module
    switch (moduleNumber) {
      case 1:
        intro();
        break;
      case 2:
        basics();
        break;
      case 3:
        Controls.run(userInput);
        break;
      case 4:
        MethodsModule.run(userInput);
        break;
      case 5:
        StringsModule.run(userInput);
        break;
      case 6:
        ArraysModule.run(userInput);
        break;
      case 7:
        OOPModule.run(userInput);
        break;
      case 8:
        InheritanceModule.run(userInput);
        break;
      case 9:
        AbstractClassModule.run(userInput);
        break;
      case 10:
        InterfaceModule.run(userInput);
        break;
      case 11:
        NestedClassesModule.run(userInput);
        break;
      case 12:
        LambdaExpressionModule.run(userInput);
        break;
      case 13:
        ExceptionHandlingModule.run(userInput);
        break;
      case 14:
        GenericClassesModule.run(userInput);
        break;
      case 15:
        CollectionsModule.run(userInput);
        break;
      default:
        System.out.println("Invalid Module Number!");
        break;
    }

    // Close userInput
    userInput.close();
  }

  /**
   * Java Langueage Intro
   *
   * @version 1.0
   * @since 2024-09-14
   */
  public static void intro() {
    System.out.println("Java is a high-level programming language developed by Sun Microsystems.");
    System.out.println("It was originally designed for developing programs for set-top boxes and handheld devices,");
    System.out.println("but later became a popular choice for creating web applications.");
  }

  /**
   * Basics Module
   *
   * @version 1.0
   * @since 2024-09-14
   */
  public static void basics() {
    System.out.println("Java Basics Module");
    System.out.println("This module contains basic Java programming concepts.");
  }
}
