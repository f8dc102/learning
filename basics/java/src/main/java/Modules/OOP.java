package Modules;

/**
 * OOP
 * Controls the functions of the program
 */
public class OOP {
  public static void main(String[] args) {
    System.out.println("carExample");

    Practice practice = new Practice();
  }
}

/**
 * Example
 */
class Example {
  public Example() {
    System.out.println("Example constructor");
  }

}

/**
 * Practice
 */
class Practice {
  /**
   * Constructor
   */
  public Practice() {
    // Test Car Class
    {
      Car carExample = new Car();

      System.out.printf("제작회사: %s\n모델명: %s\n색깔: %s\n최고 속도: %d\n현재 속도: %d\n", carExample.company,
          carExample.color, carExample.model, carExample.maxSpeed, carExample.speed);

      carExample.speed = 60;
      System.out.printf("\n수정된 속도: %d\n", carExample.speed);
    }

    // Test Korean Class
    {
      Korean k1 = new Korean("연세", "011225-1234567");
      Korean k2 = new Korean("믿음", "930525-0654321");

      for (Korean k : new Korean[] { k1, k2 }) {
        System.out.printf("\n%s.name: %s\n%s.id: %s\n", k, k.name, k, k.id);
      }
    }

    // Test GetCircleArea Class
    {
      GetCircleArea getCircleArea = new GetCircleArea();
      GetCircleArea.Circle circle = getCircleArea.new Circle(5);
      System.out.printf("\n원의 반지름: %.2f\n원의 면적: %.2f\n원의 둘레: %.2f\n", circle.radius, circle.getArea(circle.radius),
          circle.getCirumference(circle.radius));
    }

  }

  class Car {
    // Fields
    String company = "현대자동차";
    String model = "그랜저";
    String color = "검정";
    int maxSpeed = 250;
    int speed;
  }

  class Korean {
    String nation = "대한민국";
    String name;
    String id;

    public Korean(String name, String id) {
      this.name = name;
      this.id = id;
    }
  }

  class GetCircleArea {
    class Circle {
      // Fields
      double radius;

      // Constructors
      public Circle() {
        // Defaults to 1
        this.radius = 1;
      }

      public Circle(double radius) {
        this.radius = radius;
      }

      // Methods
      /**
       * getArea
       * 
       * @param radius the radius of the circle
       * @return the area of the circle
       */
      public double getArea(double radius) {
        return Math.PI * radius * radius;
      }

      /**
       * getCirumference
       *
       * @param radius the radius of the circle
       * @return the circumference of the circle
       */
      public double getCirumference(double radius) {
        return Math.PI * 2 * radius;
      }

      /**
       * setRadius
       *
       * @param radius the radius of the circle
       * @return void
       */
      public void setRadius(double radius) {
        this.radius = radius;
      }
    }

    class TV {
      class TVClass {
        // Fields
        int channel;
        int volumeLevel;
        boolean on;

        // Constructors
        public TVClass() {
          this.channel = 1;
          this.volumeLevel = 1;
          this.on = false;

        }

        // Methods
        /**
         * turnOn
         *
         * @return void
         */
        public void turnOn() {
          this.on = true;
        }

        /**
         * turnOff
         *
         * @return void
         */
        public void turnOff() {
          this.on = false;
        }

        /**
         * setChannel
         *
         * @param channel the channel to set
         * @return void
         */
        public void setChannel(int channel) {
          this.channel = channel;
        }

        /**
         * setVolume
         *
         * @param volume the volume to set
         * @return void
         */
        public void setVolume(int volume) {
          this.volumeLevel = volume;
        }

        /**
         * channelUp
         *
         * @return void
         */
        public void channelUp() {
          this.channel++;
        }

        /**
         * channelDown
         *
         * @return void
         */
        public void channelDown() {
          this.channel--;
        }

        /**
         * volumeUp
         *
         * @return void
         */
        public void volumeUp() {
          this.volumeLevel++;
        }

        /**
         * volumeDown
         *
         * @return void
         */
        public void volumeDown() {
          this.volumeLevel--;
        }
      }
    }
  }

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
    public int divide(int v1, int v2) {
      return v1 / v2;
    }
  }
}
