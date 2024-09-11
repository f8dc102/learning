
/******************************************************************************
 * File:        Practice.java
 * Description: Homework of Java Programming Class.
 *
 * Author:      F8DC102(정재윤)
 * Created:     2024-09-11
 * Version:     1.0 
 *
 * Company:     YONSEI UNIVERSITY
 * License:     MIT License
 *
 * Repo URL:    https://github.com/f8dc102/learning
 *
 * ----------------------------------------------------------------------------
 * Change Log: N/A
 * ----------------------------------------------------------------------------
 * Date           Author          Version     Description
 * ----------------------------------------------------------------------------
 * 2024-09-11     F8DC102           1.0     Initial version.
 *
 *****************************************************************************/

import java.util.Scanner;

/**
 * Practice Class
 */
public class Practice {
  /**
   * Main Method
   * 
   * @param args But not used in this case
   */
  public static void main(String[] args) {
    Practice2_01();
    System.out.println();

    Practice2_02();
    System.out.println();

    Practice2_03();
    System.out.println();

    Practice2_04();
  }

  /**
   * Practice 2-1
   */
  public static void Practice2_01() {
    int val1 = 15;
    int val2 = 0; // Fix Error of Scope of val2

    if (val1 < 10) {
      val2 = val1 - 10; // Scope of val2
    }

    int val3 = val1 + val2 + 5;
    System.out.println("val3 = " + val3);
  }

  /**
   * Practice 2-2
   */
  public static void Practice2_02() {
    // Get Radius
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter Radius: ");
    double radius = scanner.nextDouble();
    scanner.close();

    // Get Area
    double area = Math.PI * radius * radius;

    // Print Area
    System.out.println("Area: " + area);
  }

  /**
   * Practice 2-3
   */
  public static void Practice2_03() {
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
   */
  public static void Practice2_04() {
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
}
