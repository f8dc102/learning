import java.util.Scanner;

/**
 * JPHWTwo
 * Caller class for methods
 */
public class JPHWTwo {
  public static void main(String[] args) {
    // Create a Scanner object
    Scanner userInput = new Scanner(System.in);

    // Ask for user input for method name
    System.out.print("Enter the number of the method you want to run: ");
    Short methodNum = userInput.nextShort();

    // Run the method based on user input
    switch (methodNum) {
      case 1:
        One hwOne = new One(userInput);
        break;
      case 2:
        Two hwTwo = new Two();
        Two.KoreanExample hwTwoKoreanExample = hwTwo.new KoreanExample();
        break;
      case 3:
        Three hwThree = new Three();
        Three.TestCalculator hwThreeTest = hwThree.new TestCalculator(userInput);
        break;
      case 4:
        Four hwFour = new Four();
        break;
      case 5:
        Five hwFive = new Five();
        break;
      default:
        System.out.println("Method not found.");
    }

    // Close the Scanner object
    userInput.close();
  }
}

/**
 * Number One
 */
class One {
  /**
   * 2차원 배열을 선언한 뒤, 모든 요소의 합계 구하기
   * 
   * @param Scanner userInput
   * @return void
   */
  public One(Scanner userInput) {
    // Declare a 2D array
    int[][] array = new int[3][4];
    int sum = 0;

    // Initialize the array
    // Fill Zero
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array[i].length; j++) {
        array[i][j] = 0;
      }
    }

    // Get from user input
    System.out.println("Enter 3 rows and 4 columns:");
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array[i].length; j++) {
        array[i][j] = userInput.nextInt();
      }
    }

    // Get the sum of all elements
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array[i].length; j++) {
        sum += array[i][j];
      }
    }

    // Print the sum
    System.out.println("Sum of all elements: " + sum);
  }
}

/**
 * Number Two
 */
class Two {
  /**
   * Korean 클래스
   */
  class Korean {
    // Fields
    String nation = "대한민국";
    String name;
    String id;

    // Constructor
    public Korean(String name, String id) {
      this.name = name;
      this.id = id;
    }
  }

  /**
   * KoreanExample 클래스
   */
  class KoreanExample {
    public KoreanExample() {
      // Create two Korean objects
      Korean k1 = new Korean("연세", "011225-1234567");
      Korean k2 = new Korean("믿음", "930525-0654321");

      // Print the name and id of the two Korean objects
      for (Korean k : new Korean[] { k1, k2 }) {
        System.out.printf("\n%s.name: %s\n%s.id: %s\n", k, k.name, k, k.id);
      }
    }
  }
}

class Three {
  class Calculator {
    // Fields
    int v1;
    int v2;

    // Constructors
    public Calculator() {
      this.v1 = 0;
      this.v2 = 0;
    }

    public Calculator(int v1, int v2) {
      this.v1 = v1;
      this.v2 = v2;
    }

    // Methods
    /**
     * add
     *
     * @param v1 the first value
     * @param v2 the second value
     * @return the sum of the two values
     */
    public int add(int v1, int v2) {
      return v1 + v2;
    }

    /**
     * subtract
     *
     * @param v1 the first value
     * @param v2 the second value
     * @return the difference of the two values
     */
    public int subtract(int v1, int v2) {
      return v1 - v2;
    }

    /**
     * multiply
     *
     * @param v1 the first value
     * @param v2 the second value
     * @return the product of the two values
     */
    public int multiply(int v1, int v2) {
      return v1 * v2;
    }

    /**
     * divide
     *
     * @param v1 the first value
     * @param v2 the second value
     * @return the quotient of the two values
     */
    public double divide(int v1, int v2) {
      return v1 / v2;
    }

    /**
     * remainder
     *
     * @param v1 the first value
     * @param v2 the second value
     * @return the remainder of the two values
     */
    public double remainder(int v1, int v2) {
      return v1 % v2;
    }
  }

  class TestCalculator {
    public TestCalculator(Scanner userInput) {
      System.out.print("Enter: number1 OperationalSymbol(+, -, *, /, %) number2: ");

      double result = 0;
      // Get user input
      int v1 = userInput.nextInt();
      char op = userInput.next().charAt(0);
      int v2 = userInput.nextInt();

      // Create a Calculator object
      Calculator cal = new Calculator();

      // Run the method based on the operator
      switch (op) {
        case '+':
          result = cal.add(v1, v2);
          break;
        case '-':
          result = cal.subtract(v1, v2);
          break;
        case '*':
          result = cal.multiply(v1, v2);
          break;
        case '/':
          result = cal.divide(v1, v2);
          break;
        default:
          System.out.println("Wrong Input");
          return;
      }

      // Print the result
      System.out.println("Result: " + result);
    }
  }
}

class Four {
  public Four() {
    Lion lion = new Lion();
    Eagle eagle = new Eagle();

    lion.eat();
    lion.sleep();
    lion.roar();

    eagle.eat();
    eagle.sleep();
    eagle.fly();
  }

  class Animal {
    double weight;
    String picture;

    public void eat() {
      System.out.println("eat()가 호출되었음");
    }

    public void sleep() {
      System.out.println("sleep()가 호출되었음");
    }
  }

  class Lion extends Animal {
    int legs;

    public void roar() {
      System.out.println("roar()가 호출되었음");
    }
  }

  class Eagle extends Animal {
    int wings;

    public void fly() {
      System.out.println("fly()가 호출되었음");
    }
  }
}

class Five {
  public Five() {
    Rectangle rect = new Rectangle(5, 3, 10, 20);

    rect.print();
    rect.draw();
    // System.out.println("area: " + rect.area());

    rect.setX(8);
    rect.setY(9);
    rect.print();
    rect.draw();
  }

  class Shape {
    private int x, y;

    public Shape(int x, int y) {
      this.x = x;
      this.y = y;
    }

    public Shape() {
      this(0, 0);
    }

    public int getX() {
      return x;
    }

    public int getY() {
      return y;
    }

    public void setX(int x) {
      this.x = x;
    }

    public void setY(int y) {
      this.y = y;
    }

    public void print() {
      System.out.println("x좌표: " + getX() + ", y좌표: " + getY());
    }
  }

  class Rectangle extends Shape {
    private int width, height;

    public Rectangle(int x, int y, int width, int height) {
      super(x, y);

      this.width = width;
      this.height = height;
    }

    public Rectangle() {
      this(0, 0, 0, 0);
    }

    public int getWidth() {
      return width;
    }

    public int getHeight() {
      return height;
    }

    public void setWidth(int width) {
      this.width = width;
    }

    public void setHeight(int height) {
      this.height = height;
    }

    public void draw() {
      System.out.println("(" + getX() + ", " + getY() + ") 위치에 가로: " + width + ", 세로: " + height);
    }

    public double area() {
      return width * height;
    }
  }
}
