import java.util.Scanner;

public class StringArrayDebug {
  public static void main(String[] args) {
    // Get Scanner object
    Scanner userInput = new Scanner(System.in);

    StringExample.checkEqual();
    StringExample.comparingString();

    StringPractice.countUpperCase(userInput);
  }
}

class StringExample {
  public StringExample() {
    System.out.println("String constructor");
  }

  public static void checkEqual() {
    String s1 = "Hi, Java!";
    String s2 = "Hi, Java!";
    String s3 = new String("Hi, Java!");
    String s4 = new String("Hi, Java!");

    System.out.println("s1 == s2 -> " + (s1 == s2)); // true
    System.out.println("s1 == s3 -> " + (s1 == s3)); // false
    System.out.println("s3 == s4 -> " + (s3 == s4)); // false

    s1 = s3;
    System.out.println("s1 == s3 -> " + (s1 == s3)); // true
  }

  public static void comparingString() {
    String s1 = "Hi, Java!";
    String s2 = new String("Hi, Java!");
    String s3 = new String("Hi, Code!");
    String s4 = new String("Hi, java!");

    System.out.println(s1.equals(s2)); // true
    System.out.println(s1.equals(s3)); // false
    System.out.println(s1.equals(s4)); // false
    System.out.println(s1.equalsIgnoreCase(s4)); // true

    System.out.println(s1.compareTo(s3)); // -2
    System.out.println(s1.compareToIgnoreCase(s4)); // 0
    System.out.println(s3.compareTo(s4)); // 2
    System.out.println("Hi, Java!".compareToIgnoreCase("hi, java!")); // 0

    System.out.printf("'J' - 'C'=%d\n", 'J' - 'C'); // 2
    System.out.printf("'C' - 'j'=%d\n", 'C' - 'j'); // -2
  }

  public static void controlString() {
    String s1 = new String("Hi, ");
    String s2 = new String(" Java");
    String s3, s4;

    System.out.println("문자열의 길이(s1) : " + s1.length());

    char c = s1.charAt(1);
    System.out.println("s1의 두 번째 문자 : " + c);

    s1 = s1.concat(s2);

    s3 = s1.toLowerCase();
    s4 = s1.substring(4, 8);

    System.out.println("s1 : " + s1);
    System.out.println("s3 : " + s3);
    System.out.println("s4 : " + s4);
  }
}

class StringPractice {
  public StringPractice() {
    System.out.println("StringPractice constructor");
  }

  public static void countUpperCase(Scanner userInput) {
    // Read a string from the user
    System.out.print("Enter a string: ");
    String str = userInput.nextLine();

    // Count the number of uppercase letters
    int count = 0;

    for (int i = 0; i < str.length(); i++) {
      if (Character.isUpperCase(str.charAt(i))) {
        count++;
      }
    }

    System.out.println("대문자의 수는 " + count + "개 입니다.");
  }
}
