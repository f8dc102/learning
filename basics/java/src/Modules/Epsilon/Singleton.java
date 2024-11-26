package Modules.Epsilon;

public class Singleton {
  public static void main(String[] args) {
    // 싱글톤 객체 얻기
    SingletonDemo s1 = SingletonDemo.getInstance();
    SingletonDemo s2 = SingletonDemo.getInstance();

    // 같은 객체인지 확인
    System.out.println(s1 == s2); // true (같은 인스턴스)

    s1.showMessage();
  }
}

class SingletonDemo {
  // 1. 클래스의 유일한 인스턴스를 정적(static)으로 선언
  private static SingletonDemo instance;

  // 2. 생성자를 private으로 선언하여 외부에서 객체를 생성하지 못하게 함
  private SingletonDemo() {
  }

  // 3. 인스턴스를 반환하는 메서드 제공
  public static SingletonDemo getInstance() {
    if (instance == null) { // 처음 호출 시에만 객체 생성
      instance = new SingletonDemo();
    }
    return instance;
  }

  public void showMessage() {
    System.out.println("Hello from Singleton!");
  }
}
