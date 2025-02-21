package Modules;

public class AbstractClass {
  public static void main(String[] args) {
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
