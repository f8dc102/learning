/**
 * Let's Study About Java's Structure
 */

public class Structure {
    public static void main(String[] args) {
        // main()은 반드시 public static void 타입으로 선언!
        // 한 클래스에는 main() 메소드는 한 개만 존재해야 함
        // 모든 클래스가 main() 메소드를 가질 필요는 없따!

        // 클래스의 멤버 함수를 자바에서는 메소드라고 부름
        // 메소드 갯수는 무제한!

        // 몇가지 메소드를 여기에 써서 테스트해보쟝!
        System.out.println(sum(1, 6));

    }

    public static int sum(int n, int m) {
        return n + m; 
    }

    // Identifier Naming Rule

    // 특수 문자 중에서는 식별자에는 "_", "$"만 사용할 수 있다! ex) HACK_ON
    // 식별자의 문자로 숫자는 사용불가!! ex) 7Great ~
    // 한글도 식별자로 사용가능 벗, 웬만해서는 ㄴㄴ
    // 길이 제한이 없고, 대소문자 따지는 씨크한 놈

    // 몇가지 변수를 선언해보쟝!
    int i = 7;
    char a = 'a', z = 'z';
    int ALPHA = 30, OMEGA = 7;

    // 아래는 모범이되는 변수 식별자 네이밍 룰이닷
    // 1 : "목적성", 2 : "길이에 연연 노노",
    // 3 : "언어의 관습을 따르자"

    // 언어의 관습?!
    // 클래스 이름 명명 룰 == 클래스 이름의 첫 글자는 대문자!
    // EX) GreatServerBootstrap
    //
    // 변수 메소드 이름 == 첫 단어는 소문자 이후 첫 글자는 대문자!
    // EX) yourMother, myGrade
    // 
    // 상수 이름 == 상수는 이름 전체를 대문자로 표기!
    // EX) HEAL_RATE, REFRASH_ALLOW

    // 데이터 타입에서 String은 기본 타입이 아니다.
    // 자바에서는 문자열과 기본 타입의 + 연산이 실행되면,
    // 기본 타입의 값이 문자열로 바뀌고 두 문자열이 연결된
    // 새로운 문자열이 생성된다.

    // 변수를 선언한 뒤 값을 변경할 때는 다음과 같이!
    ALPHA = OMEGA; // 앞에 데이터 타입을 빼고 선언하면 된다.

}
