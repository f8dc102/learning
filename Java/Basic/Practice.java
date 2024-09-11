import java.util.Scanner;

public class Practice {
  /**
   * Main Method
   * 
   * @param args
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
    int val2 = 0;

    if (val1 < 10) {
      val2 = val1 - 10;
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
    System.out.println("Area: " + area);
  }

  public static void Practice2_03() {
    // Ranges of byte Type
    System.out.println("Ranges of byte Type");
    System.out.println("Byte Min: " + Byte.MIN_VALUE);
    System.out.println("Byte Max: " + Byte.MAX_VALUE);

    // Ranges of short Type
    System.out.println("Ranges of short Type");
    System.out.println("Short Min: " + Short.MIN_VALUE);
    System.out.println("Short Max: " + Short.MAX_VALUE);

    // Ranges of int Type
    System.out.println("Ranges of int Type");
    System.out.println("Int Min: " + Integer.MIN_VALUE);
    System.out.println("Int Max: " + Integer.MAX_VALUE);
  }

  public static void Practice2_04() {
    final double TAX_RATE = 0.06;
    double price = 197.55;

    double tax = price * TAX_RATE;

    System.out.println("Price: " + (int) price);

  }
}
