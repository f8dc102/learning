import java.util.Scanner;

public class Chapter6 {
  public static void main(String[] args) {
    Practice.P01 p01 = new Practice().new P01();
    System.out.print("\n");

    Practice.P02 p02 = new Practice().new P02();
  }
}

class Practice {
  class P01 {
    public P01() {
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

  class P02 {
    public P02() {
      Rectangle rect = new Rectangle(10, 10, 20, 20);

      rect.print();
      rect.draw();
      System.out.println("area: " + rect.area());

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
        System.out.println("x: " + x + ", y: " + y);
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
        System.out.println("Rectangle: x: " + getX() + ", y: " + getY() + ", width: " + width + ", height: " + height);
      }

      public double area() {
        return width * height;
      }
    }
  }

  class P03 {
    class Employee {
      public String name;
      String address;
      protected int salary;
      private int rrn;

      public Employee(String name, String address, int salary, int rrn) {
        this.name = name;
        this.address = address;
        this.salary = salary;
        this.rrn = rrn;
      }

      public String toString(int a) {
        return Integer.toString(a);
      }
    }
  }
}
