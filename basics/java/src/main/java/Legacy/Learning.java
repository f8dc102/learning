public class Learning {
    int age = 20, damage = 10;
    boolean healthy = false;

    final String howOld = "얼마나 살았니?";

    // With "final" keyword, We can declare variable as constant.
    // So if we declare like "howOld = '17'" again, it will give us an error.

    long stupidNum = 312312345670L;
    // Note that you should end the value with an "L":

    float f1 = 35E3f;
    // With E or e suffix, we can set power of 10.

    public static void main(String[] args) {
        System.out.println("Hell world!");

        // testFunctions
        testMethod("Kernel", 20);
    }

    /* Widening & Narrowing Casting
     * Widening (auto)
     * Narrowing (manual)
     * L Add (int), (float) front of variable
     * For example (int) 9.78 = 9
     */

    public static void testLength() {
        String txt = "Stupid World!";
        
        System.out.println("Length ==> " + txt.length());
        System.out.println(txt.toUpperCase());
        System.out.println(txt.indexOf("World"));
    }

    public static void testSC() {
        String firstName = "Jae Yun";
        String lastName = "Jeong";
        
        System.out.println(firstName + " " + lastName);
        System.out.println(firstName.concat(lastName));
        
        /* WARNING!
         * Java uses the + operator for both addition and concatenation.
         * Numbers are added. Strings are concatenated.
         */

    }

    public static void testMath() {
        int randomNum = (int) Math.random();
        System.out.println(randomNum);
    }
    
    public static void testMyAge() {
        int myAge = 20;
        int votingAge = 18;

        if (myAge >= votingAge) {
            System.out.println("Old enough to vote!");
        } else {
            System.out.println("Not old enough to vote.");
        }
    }

    public static void testCondition() {
        if (20 > 18) {
            System.out.println("This is absolutely TRUE!");
        } else if (20 == 18) {
            System.out.println("The world is strange...");
        } else {
            System.out.println("Dead Code.");
        }
   
        // Short Hand If...Else
        // variable = (condition) ? expressionTrue :  expressionFalse;
        int time = 20;
        String testQuo = (time == 20) ? "Absolutely True" : "Dead Code";
        
        System.out.println(testQuo);
    }

    public static void testSwitch() {
        int presentDay = 4;

        switch (presentDay) {
            case 1: System.out.println("Monday!"); break;
            case 2: System.out.println("Tuesday!"); break;
            case 3: System.out.println("Wednesday!"); break;
            case 4: System.out.println("Worth Nothing!"); break;
            // and so on...

            default: System.out.println("Input was WRONG!");

            // When Java reaches a break keyword, it breaks out of the switch block.
            // This will stop the execution of more code and case testing inside the block.
        }

        // Outputs "Worth Nothing"
    }

    public static void testWhile() {
        int i = 0;

        while (i < 5) {
            System.out.println(i);
            i++; // Add 1 to i
        }

        // Do/While Loop
        // The do/while loop is a variant of the while loop.
        // Syntax =>
        //
        // do {
        //    Code;
        // } while (condition);
        
        int k = 0;
        do {
            System.out.println(k);
            k++;
        }

        while (k < 5);
    }

    public static void testForLoop() {
        for (int i = 0; i < 5; i++) {
            System.out.println(i);
        }
        
        /* for (statement 1; statement 2; statement 3) 
         * Statement1 is executed (one time) before the execution of the code block.
         * Statement2 defines the condition for executing the code block.
         * Statement 3 is executed (every time) after the code block has been executed.
         */
         
        // Nested Loops (Loop inside Loop)
        // The "inner loop" will be executed one time for each iteration of the "outer loop":

        // For Each Loop (Using Array)
        // for (type variableName : arrayName)
        
        String[] carList = {"Ferrari", "McLaren", "Lambo"};

        for (String i : carList) {
            System.out.println(i);
        }
    }

    public static void testBrCo() {
        // The break statement can also be used to jump out of a loop.

        for (int i = 0; i < 10; i++) {
            if (i == 4) {
                break;
            } 

            System.out.println(i);
        }

        // The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.

        for (int i = 0; i < 10; i++) {
            if (i == 4) {
                continue;
            }

            System.out.println(i);
        }
    }

    public static void testArray() {
        String[] myCar = {"F8 Tributo", "SF90 Stradale", "Phantom"};
        int[] myNum = {10, 20, 30, 7, 40};

        System.out.println(myCar[1]);
        System.out.println(myNum[3]);

        myCar[2] = "Ghost";
        System.out.println(myCar.length);

        int[][] myTestArray = { {1, 2, 4, 6}, {9, 8, 7} };
        myTestArray[1][2] = 77;
        System.out.println(myTestArray[1][2]);

        for (int i = 0; i < myTestArray.length; ++i) {
            for(int j = 0; j < myTestArray[i].length; ++j) {
                System.out.println(myTestArray[i][j]);
            }
        }
    }

    // With method overloading, multiple methods can have the same name with different parameters
    static int plusMethod(int x, int y) {
        return x + y;
    }

    static double plusMethod(double x, double y) {
        return x + y;
    }

    static int testMethod(String tarName, int tarAge) {
        // [static] means that the method belongs to the Class and not an object of the class.
        // [void] means that this method has no return value.
        System.out.println(tarName + "(" +  tarAge + ")" + " called you!");

        if (tarAge < 19) {
            System.out.println("부러운 나이!");
        } else {
            System.out.println("인생 다 살았음 솔직히");
        }

        int myInt = plusMethod(7, 7);
        double myDouble = plusMethod(7.7, 7.7);

        System.out.println("int : " + myInt);
        System.out.println("double : " + myDouble);

        return tarAge;
    }
}
