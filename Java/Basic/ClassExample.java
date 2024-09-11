public class ClassExample {
  public static void main(String[] args) {
    aCat testCat = new aCat();

    testCat.eat();
  }
}

class anAnimal {
  // Properties
  String type;
  String name;
  int age;

  // Constructor
  public anAnimal() {
    this.type = "Animal";
    this.name = "Generic Animal";
    this.age = 0;
  }

  // Methods
  public void eat() {
    System.out.println("I am eating");
  }

}

class aDog extends anAnimal {
  // Constructor
  public aDog() {
    this.type = "Dog";
    this.name = "Generic Dog";
    this.age = 0;
  }

  public void bark() {
    System.out.println("I am barking");
  }
}

class aCat extends anAnimal {
  // Constructor
  public aCat() {
    this.type = "Cat";
    this.name = "Generic Cat";
    this.age = 0;
  }

  public void meow() {
    System.out.println("I am meowing");
  }

  public void eat() {
    System.out.println("I am eating like a cat");
  }
}
