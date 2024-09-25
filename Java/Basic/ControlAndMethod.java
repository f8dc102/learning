import java.util.Scanner;

/**
 * September 20, 2024
 * Lecture 3: Control and Method
 */
public class ControlAndMethod {
  /**
   * The main method is the entry point of the program.
   *
   * @param args The command-line arguments.
   */
  public static void main(String[] args) {
    // Create Scanner object to read input from the keyboard
    Scanner userInput = new Scanner(System.in);

    // Initalize the Control class
    Control control = new Control();

    control.printGrade(userInput);
    System.out.println();

    control.compareThreeNumbers(userInput);
    System.out.println();

    control.simpleCalculator(userInput);
    System.out.println();

    control.simpleCalculatorII(userInput);
    System.out.println();

    control.calculateZodiac(userInput);
    System.out.println();

    control.multiplicationTable();
    System.out.println();

    control.additionQuiz(userInput);
    System.out.println();

    control.upAndDownGame(userInput);
    System.out.println();

    control.subtractionQuiz(userInput);
    System.out.println();

    control.primeNumbersTable();
    System.out.println();
  }
}

class Control {
  /**
   * Practice 3 - 1
   * Get Score and Print Grade
   * Using If-Else Statement
   */
  public void printGrade(Scanner userInput) {
    // Initialize the score
    char grade = 'F';

    // Get the score from the user
    System.out.print("점수를 입력하세요: ");

    // Read the score from the user
    byte score = userInput.nextByte();

    // Close the Scanner
    // scanner.close();

    // Determine the grade based on the score
    // Using if-else statement
    if (score >= 90) {
      grade = 'A';
    } else if (score >= 80) {
      grade = 'B';
    } else if (score >= 70) {
      grade = 'C';
    } else if (score >= 60) {
      grade = 'D';
    }

    // Print the Grade
    System.out.println(score + "점은 " + grade + "등급입니다.");
  }

  /**
   * Practice 3 - 2
   * Compare Three Numbers
   * Get Three Numbers and Print the Largest Number and the Smallest Number
   * Using Nested If-Else Statement
   */
  public void compareThreeNumbers(Scanner userInput) {
    // Initialize the numbers
    int numA = 0, numB = 0, numC = 0;

    // Get the numbers from the user
    System.out.print("Enter any three integers: ");

    // Read the numbers from the user
    numA = userInput.nextInt();
    numB = userInput.nextInt();
    numC = userInput.nextInt();

    // Close the scanner
    // scanner.close();

    // Determine the largest number and the smallest number
    // Initialize the largest and the smallest numbers
    int largest = 0, smallest = 0;

    // Using nested if-else statements
    // Determine the largest number
    if (numA >= numB) {
      if (numA >= numC) {
        largest = numA;
      } else {
        largest = numC;
      }
    } else {
      if (numB >= numC) {
        largest = numB;
      } else {
        largest = numC;
      }
    }

    // Determine the smallest number
    if (numA <= numB) {
      if (numA <= numC) {
        smallest = numA;
      } else {
        smallest = numC;
      }
    } else {
      if (numB <= numC) {
        smallest = numB;
      } else {
        smallest = numC;
      }
    }

    // Print the largest and the smallest numbers
    System.out.println("The largest integer is " + largest
        + "," + " and the smallest integer is " + smallest + "!");
  }

  /**
   * Practice 3 - 3
   * Calculater
   * Input Two Integers and an Operator and Print the Result
   * Using Nested if-else Statement
   *
   * @COMMENT: The method is too long. It is better to divide the method into
   *           smaller methods.
   * @COMMENT: The Instruction is inefficient. It is better to use a switch
   *           statement.
   */
  public void simpleCalculator(Scanner userInput) {
    // Initialize the numbers and the operator
    int numA = 0, numB = 0, result = 0;
    byte operator = 0;

    // Welcome!
    System.out.println("Simple Calculator");

    // Introduce the operator
    // 1: Addition, 2: Subtraction, 3: Multiplication, 4: Division, 5: Remainder
    System.out.println("1. Addition");
    System.out.println("2. Subtraction");
    System.out.println("3. Multiplication");
    System.out.println("4. Division");
    System.out.println("5. Remainder");

    // Get the operator from the user
    System.out.print("Choice number<1-5>: ");
    // Read the operator from the user
    operator = userInput.nextByte();

    // If the operator is not valid, print an error message and exit the program
    if (operator < 1 || operator > 5) {
      System.out.println("Wrong Input");

      return;
    }

    // Print Prompt
    System.out.println("\nStart:");

    // Get First Number
    System.out.print("Enter the first number: ");
    // Read the first number from the user
    numA = userInput.nextInt();

    // Get Second Number
    System.out.print("Enter the second number: ");
    // Read the second number from the user
    numB = userInput.nextInt();

    // Calculate the result
    // Using nested if-else statements
    if (operator == 1) {
      result = numA + numB;
    } else if (operator == 2) {
      result = numA - numB;
    } else if (operator == 3) {
      result = numA * numB;
    } else if (operator == 4) {
      result = numA / numB;
    } else if (operator == 5) {
      result = numA % numB;
    }

    // Print the result
    System.out.println("Result: " + result);
  }

  /**
   * Practice 3 - 4
   * Calculator II
   * Using Switch Statement
   */
  public void simpleCalculatorII(Scanner userInput) {
    // Initialize the numbers and the operator
    // @WARNING: Initialize the operator as a character
    // to avoid an error when reading the operator
    // from the user.
    int numA = 0, numB = 0, result = 0;
    char operator = ' ';

    // Show Instruction
    System.out.print("Enter the first number operator(+, -, *, /, %) the second number (e.g., 2 + 3) : ");

    // Read the first number from the user
    numA = userInput.nextInt();

    // Read the operator from the user
    operator = userInput.next().charAt(0);

    // Exit the program if the operator is not valid
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%') {
      System.out.println("Wrong Input");

      return;
    }

    // Read the second number from the user
    numB = userInput.nextInt();

    // Calculate the result
    // Using switch statement
    switch (operator) {
      case '+':
        result = numA + numB;
        break;
      case '-':
        result = numA - numB;
        break;
      case '*':
        result = numA * numB;
        break;
      case '/':
        result = numA / numB;
        break;
      case '%':
        result = numA % numB;
        break;
    }

    // Print the result
    System.out.println("Result: " + result);
  }

  /**
   * Practice 3 - 5
   * Zodiac Calculation
   * Using Switch Statement
   */
  public void calculateZodiac(Scanner userInput) {
    // Initialize the year and the zodiac
    int year = 0;
    String zodiac = "";

    // Get the year from the user
    System.out.print("연도를 입력하세요: ");

    // Read the year from the user
    year = userInput.nextInt();

    // Calculate the zodiac
    // Using switch statement
    switch (year % 12) {
      case 0:
        zodiac = "Monkey";
        break;
      case 1:
        zodiac = "Rooster";
        break;
      case 2:
        zodiac = "Dog";
        break;
      case 3:
        zodiac = "Pig";
        break;
      case 4:
        zodiac = "Rat";
        break;
      case 5:
        zodiac = "Ox";
        break;
      case 6:
        zodiac = "Tiger";
        break;
      case 7:
        zodiac = "Rabbit";
        break;
      case 8:
        zodiac = "Dragon";
        break;
      case 9:
        zodiac = "Snake";
        break;
      case 10:
        zodiac = "Horse";
        break;
      case 11:
        zodiac = "Sheep";
        break;
    }

    // Print the zodiac
    System.out.println(year + "년은 " + zodiac + "의 해입니다.");
  }

  /**
   * Practice 3 - 6
   * 9x9 Multiplication Table
   * Using Nested for Statement
   */
  public void multiplicationTable() {
    // Print the first row
    System.out.println("  \t1\t2\t3\t4\t5\t6\t7\t8\t9");

    // Print the multiplication table
    for (byte i = 2; i <= 9; i++) {
      System.out.println();
      System.out.print(i + ":\t");

      for (byte j = 1; j <= 9; j++) {
        System.out.print(i * j + "\t");
      }
    }

    // Print a new line
    System.out.println();
  }

  /**
   * Practice 3 - 7
   * Addition Quiz
   * Using Loop Statement
   */
  public void additionQuiz(Scanner userInput) {
    // Initialize the counter
    byte counter = 1;

    // Generate two random numbers
    int numA = (int) (Math.random() * 10);
    int numB = (int) (Math.random() * 10);

    // Calculate the answer
    // @WARNING: Initialize the answer as an integer to avoid an error
    // when reading the answer from the user.
    int answer = numA + numB;

    do {
      // Print the quiz
      System.out.print("What is " + numA + " + " + numB + "? ");

      // Read the answer from the user
      int userAnswer = userInput.nextInt();

      // Check if the answer is correct
      // if the answer is correct, break the loop
      // if the answer is incorrect, print an error message and increment the counter
      // and continue the loop
      if (userAnswer == answer) {
        break;
      } else {
        System.out.print("틀렸습니다! 다시해보세요. ");

        counter++;
      }
    } while (true);

    // Print the counter
    System.out.println(counter + "번만에 맞췄습니다.");
  }

  /**
   * Practice 3 - 8
   * Up and Down Game
   * Using Loop Statement
   */
  public void upAndDownGame(Scanner userInput) {
    // Generate a random number
    byte targetNumber = (byte) (Math.random() * 100);

    // Initialize the counter
    byte counter = 1;

    // Print the prompt
    System.out.println("0부터 100사이의 숫자를 맞춰보세요.");

    do {
      // Display the prompt
      System.out.print("추측한 숫자를 입력하세요: ");

      // Read the number from the user
      byte guessNumber = userInput.nextByte();

      // Determine if the guess number is correct or not
      if (guessNumber == targetNumber) {
        break;
      } else if (guessNumber < targetNumber) {
        System.out.println("Up!");
      } else {
        System.out.println("Down!");
      }

      // If the guess number is incorrect, increment the counter
      counter++;
    } while (true);

    // Print the counter
    System.out.println("맞습니다. 숫자는 " + targetNumber + "입니다.");
    System.out.println(counter + "번만에 맞췄습니다.");
  }

  /**
   * Practice 3 - 9
   * Subtraction Quiz
   * 
   * @COMMENT: for statement와 while statement를 둘 다 이용할 수 있으나, while로 구현하겠다.
   */
  public void subtractionQuiz(Scanner userInput) {
    // Initialize the counter
    byte counter = 1, correct = 0;

    // Repeat the quiz five times
    while (counter <= 5) {
      // Initialize the user answer
      byte userAnswer = 0;

      // Generate two random numbers
      byte numA = (byte) (Math.random() * 10);
      byte numB = (byte) (Math.random() * 10);

      // If the answer is negative, swap the numbers
      if (numA < numB) {
        byte temp = numA;
        numA = numB;
        numB = temp;
      }

      // Calculate the answer
      byte answer = (byte) (numA - numB);

      // Print the quiz
      System.out.print(numA + " - " + numB + " ? ");

      // Get the answer from the user
      userAnswer = userInput.nextByte();

      // Check if the answer is correct
      if (userAnswer == answer) {
        System.out.println("정답입니다.");

        correct++;
      } else {
        System.out.print("틀렸습니다. ");
        System.out.println(numA + " - " + numB + "은 " + answer + "입니다.");
      }

      // Increment the counter
      counter++;
    }

    // Print the result
    System.out.println("\nGame Over!");
    System.out.println("총 " + counter + "문제 중 " + correct + "문제 맞추었습니다.");
  }

  /**
   * Practice 3 - 10
   * Prime Numbers Table
   *
   * @COMMENT: 10x5 table set
   *           To be efficient, use the Sieve of Eratosthenes algorithm
   *           But for now, we will use the brute force method
   */
  public void primeNumbersTable() {
    // Initialize the counter
    byte counter = 0;

    // Initialize the number
    short number = 2; // 소수는 2부터 시작

    // Display the prompt
    System.out.println("처음 50개의 소수는:");

    while (counter < 50) { // 50개 소수를 찾아야 하므로 counter < 50
      // Determine if the number is a prime number
      boolean isPrime = true;

      // Check if the number is prime
      if (number > 3) {
        // 소수 판정을 위해 2, 3을 제외하고 5부터 시작
        if (number % 2 == 0 || number % 3 == 0) {
          isPrime = false;
        } else {
          for (short i = 5; i <= Math.sqrt(number); i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
              isPrime = false;
              break;
            }
          }
        }
      }

      // 소수이면 출력하고 카운터 증가
      if (isPrime) {
        // Add Spacer every 10 numbers
        if (counter % 10 == 0) {
          System.out.println();
        }

        // Only if the number is a prime number.
        System.out.printf("%3d ", number);

        // Increment the counter for the next prime number
        counter++;
      }

      // Increment the number to check the next one
      number++;
    }
  }
}
