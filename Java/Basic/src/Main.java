public class Main {
  public static void main(String[] args) {
    aDog dog = new aDog();
    System.out.println("Type: " + dog.type);
    System.out.println("Name: " + dog.name);
    System.out.println("Age: " + dog.age);

    aCat cat = new aCat();
    System.out.println("Type: " + cat.type);
    System.out.println("Name: " + cat.name);
    System.out.println("Age: " + cat.age);
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
}
