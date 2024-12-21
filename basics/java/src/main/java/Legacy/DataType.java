/*
 * * 자바의 기본 데이터 타입 (8개)
 * boolean, char, [byte, short, int, long] (정수), [float, double] (실수)
 *
 * * 레퍼런스 타입 (1개) - C언어와 달리 실제 주소값 X
 * 배열에 대한 레퍼런스
 * 클래스에 대한 레퍼런스
 * 인터페이스에 대한 레퍼런스
 */

public class DataType {
    public static void main(String[] args) {
        // 자바에서는 문자열과 기본 타입의 "+" 연산이 실행되면,
        // 기본 타입의 값이 문자열로 바뀌고 두 문자열이 연결된
        // 새로운 문자열이 생성된다.
        
        String toolName = "JDK"; // String Declare
        System.out.println(toolName + 17 + "로 연습 중!"); // "JDK17"

        // 변수 선언하기!
        // 변수 선언과 동시에 초기화
        // {데이터 타입} + {변수 이름};
        
        int myAge = 20;
        char c1 = 'a'; //, c2 = 'b', c3 = 'c';
        double myHand = 776.7121;

        // 변수 읽기와 저장
        // 오버라이드된다!
        myAge = myAge * 5;
        c1 = 'A';
        myHand = myHand + 0.43;

        System.out.println("myAge = " + myAge + ", char1 = " + c1 + ", myHand = " + myHand);
        
        // 리터럴(literal)
        // 프로그램에 직접 표현한 값
       
        // 정수 리터럴
        int n = 15, m = 015;
        long g = 24L; // long 타입 지정 => "L"을 숫자 뒤에 붙이자!
        System.out.println("n = " + n + ", m = " + m + ", g = " + g);

        /*
         * * 진수별 유형과 사례
         *
         * 10 | 0으로 시작하지 않는 수 | 15 => 10진수 15
         *  8 | 0으로 시작하는 수      | 015 => 십진수 13(1x8+5=13)
         * 16 | 0x로 시작하는 수       | 0x15 => 십진수 21(1x16+5=21)
         *  2 | 0b로 시작하는 수       | 0b0101 => 십진수 5
         */

        // 실수 리터럴
        // 아래 두 개 변수는 같은 값을 가진다.
        // 1234E-4 = 1234 x 10^-4
        double d = 0.1234;
        double e = 1234E-4;
       
        double w = .1234D; // .1234D = .1234
        float f = 0.1234f; // 맨 뒤의 f를 빼면 오류

        System.out.println("d = " + d + ", e = " + e + ", w = " + w + ", f = " + f);

        // 문자 리터럴        
        // 'w', 'A', '개', '^', '섻', \u0041

        /*
         * * 특수 문자 리터럴
         * 규칙 : 백슬레시(\) 다음에 특수 기호를 붙임
         *
         * '\b' | backspace | '\r' | carriage return
         * '\t' | tab       | '\"' | double quote
         * '\n' | line feed | '\'' | single quote
         * '\f' | form feed | '\\' | backslash
         */
        
        // 논리 리터럴
        // true, false Only!!
        
        boolean updateCheck = true;
        boolean autoUpdate = false;

        boolean testBool = 10 < 1;

        System.out.println("updateCheck = " + updateCheck + ", autoUpdate = " + autoUpdate + ", 10 < 1 = " + testBool);

        // Null, String Literal
        // Null, String은 객체 레퍼런스에 이용된다.

        // [TIP] Java 10 이상부터의 "var" 키워드 사용
        // 이때까지 int a = 7; 이라고 하였다면, var 키워드를 사용할 때
        // var a = 7; var name = "Your"; var pi = 3.14; var point = new Point();
        // 다만... var의 사용은 "지역변수"에만 한정된다.
        // 또한, 변수 선언문에 초깃값이 주어지지 않으면 오류가 발생한다.
        // ex) var name;의 경우

        // 상수(CONSTANT)
        // 상수는 말 그대로 한번 정해지면 변수와 달리 바뀔 수 없다.
        // final 키워드를 사용하여 상수를 만들 수 있다!

        final double Pie = 3.141592;
        System.out.println("파이 = " + Pie);    

        // 타입변환
        // 변수나 상수 혹은 리터럴 타입을 다른 타입으로 변환!
        // 작은 타입을 큰 타입으로 변환한다.

        // 자동 타입변환
        long si = 25; // 리터럴 25는 int 타입. 25가 long 타입으로 자동 변환
        double cs = 3.14 * 10; // 실수 연산을 하기 위하여 10이 10.0으로 자동 변환
                              
        // 강제 타입변환 (CASTING)
        int casting = 300;
        // byte bc = n; // 컴파일 오류!
        byte bc = (byte)casting; // n을 byte타입으로 강제 변환. b = 44
                           // 데이터 손실이 발생한다! 컴파일 오류만 안 뜨지..

        double dc = 1.9;
        int nc = (int)dc; // 강제 타입변환으로 n은 1이 된다.

        System.out.println("si = " + si + ", cs = " + cs + ", casting = " + casting + ", bc = " + bc + ", nc = " + nc);
    }
}
