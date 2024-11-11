// import java.util.Scanner;

public class Chapter7 {
  public static void main(String[] args) {
    Circle circleA = new Circle(3);
    circleA.draw();

    System.out.println("원의 넓이는 %.1f\n", circleA.findArea());

    Rectangle rectangleA = new Rectangle(3, 4);
  }
}

/**
 * Shape
 */
abstract class Shape {
  // abstract method
  abstract void draw();

  /**
   * findArea
   *
   * @return double
   */
  public double findArea() {
    return 0.0;
  }
}

/**
 * Circle
 */
class Circle extends Shape {
  int radius;

  public Circle(int radius) {
    this.radius = radius;
  }

  @Override
  public void draw() {
    System.out.println("Drawing Circle");
  }

  @Override
  public double findArea() {
    return Math.PI * radius * radius;
  }
}
