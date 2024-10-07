/**
 * OOP
 * Controls the functions of the program
 */
public class OOP {
  public static void main(String[] args) {
    System.out.println("Hello, World!");
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
  public Practice() {
    System.out.println("Practice constructor");
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

    class TestCircle {
      public TestCircle() {
        Circle circleA = new Circle();
        Circle circleB = new Circle(25.0);
        Circle circleC = new Circle(125.0);

        for (Circle circle : new Circle[] { circleA, circleB, circleC }) {
          System.out.printf("%s: 원의 반지름이 %f일때, 넓이는 %f, 둘레는 %f입니다.", circle, radius, circle.radius, circle.getArea(),
              circle.getCircumference());
        }

        circleA.setRadius(100.0);
        System.out.println("circleA의 반지름을 100으로 수정한 후:");

        System.out.printf("circleA: 원의 반지름이 %f일때, 넓이는 %f, 둘레는 %f입니다.", circleA.radius, circleA.getArea(),
            circleA.getCircumference());
      }
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

    class TestTVClass {
      // TV1
      TVClass tv1 = new TVClass();

      tv1.turnOn();
      tv1.setChannel(30);
      tv1.setVolume(3);

      System.out.printf("tv1's channel is %d, and volume level is %d", tv1.channel, tv1.volumeLevel);

      // TV2
      TVClass tv2 = new TVClass();

    }
  }
}
