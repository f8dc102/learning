// Code written at global scope is used as the entry point for the program, so you don’t need a main() function. 
// You also don’t need to write semicolons at the end of every statement.

// Introduction to Constant (let) & Variable (var)
// Note : Values are never implicitly converted to another type.
let myValue = 1024; // Compiler will automatically detect the type of value.
let presentYear: Int = 2023;
let floatType: Float = 3.141592;
let helloWorld: String = "Hello, world!";
// Parentheses with Backslash(\) is used to include values in strings.
let sumStr: String = "\"\(helloWorld + String(presentYear))\" is great sentence.";
// Use three double quotation marks (""") for strings that take up multiple lines.
let multiLines: String = """
    I said "\(helloWorld)"
    But this is bullshit.
    """

print(sumStr + "\n" + multiLines);

// Introduction to Array & Dictonary
// Creates an empty array and dictonary
let emptyArray: [String] = [];
let emptyDictonary: [String: Float] = [:];
// Creates an array with some values
var myCars: [String] = ["F8 Tributo", "SF90 Stradale Spider", "Ghost"];
// You can use subscript syntax to change an existing value at a given index.
myCars[2] = "Phantom";
// Arrays automatically grow as you add elements.
myCars.append("Chiron");

var testOccupations: [String: String] = [
    "Ferrari" : "Red",
    "McLaren" : "Black",
    "Lambo" : "Yellow"
];

// Dictonaries automatically grow as you add key-value pairs.
testOccupations["Bugatti"] = "Blue";

print("My Cars are \(myCars) and my favorite color is \(testOccupations["Bugatti"]!)");

// Introduction to Control Flow
// Use if and switch to make conditionals, and use for-in, while, and repeat-while to make loops.
// Parentheses around the condition or loop variable are optional. Braces around the body are required.
let individualScores = [75, 43, 100, 87, 88];
var teamScore = 0;

for score in individualScores {
    if (score > 50) {
        teamScore += 3;
    } else {
        teamScore += 1;
    }
}

print("Your team score equals to \"" + String(teamScore) + "\"");

// Write a question mark (?) after the type of a value to mark the value as optional.
var optionalString: String? = "Hello"; // This can be "nil" indicates that a value is missing.
print("Prints \(optionalString == nil), 'Cause it is not null. It has 'Hello'");

var optionalName: String? = "Jae Yun Jeong";
var greeting = "Hello?!";

if let name = optionalName {
    greeting = "Hello, \(name)";
} else { // If optionalName is nil, then this block will be executed.
    greeting = "Hello, stranger";
}

print(greeting);

// Another way to handle optional values is to provide a default value using the ?? operator.
let nickName: String? = nil;
let fullName: String = "Jae Yun Jeong";
// If the optional value is missing, the default value is used instead.
let informalGreeting = "Hi \(nickName ?? fullName)";

if let nickName {
    print("Hey, \(nickName)");
} // if not nickName = nil;

print(informalGreeting);

// Switches support any kind of data and a wide variety of comparison operations—they aren’t limited to integers and tests for equality.
let vegetable = "red pepper";

switch vegetable {
case "celery":
    print("Add some raisins and make ants on a log.");
case "cucumber", "watercress":
    print("That would make a good tea sandwich.");
// "let" can be used in a pattern to assign the value that matched that part of a pattern to a constant.
case let x where x.hasSuffix("pepper"):
    print("Is it spicy \(x)?");
default: // Default case is required.
    print("Everything tastes good in soup.")
}

// You can use for-in to iterate over items in a dictionary by providing a pair of names to use for each key-value pair.
let interestingNumbers = [
    "Prime" : [2, 3, 5, 7, 11, 13],
    "Fibonacci" : [1, 1, 2, 3, 5, 8],
    "Square" : [1, 4, 9, 16, 25]
];
var largest = 0;

// What if _ is used instead of key?
for (_, numbers) in interestingNumbers {
    for number in numbers {
        if (number > largest) {
            largest = number;
        }
    }
}

// Prints "Largest number is 25"
print("Largest number is \(largest)");

// Use while to repeat a block of code until a condition changes.
var n = 2;
while (n < 100) {
    n *= 2;
}

// Prints "n is 128"
print("n is \(n)");

var m = 2;
repeat {
    m *= 2;
} while (m < 100);

// Prints "m is 128"
print("m is \(m)");

// You can keep an index in a loop by using ..< to make a range of indexes.
// Use ..< to make a range that omits its upper value, and use ... to make a range that includes both values.
var total = 0;
for i in 0..<4 {
    total += i;
}

// Prints "total is 6"
print("total is \(total)");

// Functions and Closures
// Use "func" to declare a function.
// Use "->" to seperate the parameter names and types from the function’s return type.
// By default, functions use their parameter names as labels for their arguments.
// Write a custom argument label before the parameter name, or write _ to use no argument label.
func greet(_ person: String, day: String) -> String {
    return "Hello \(person), today is \(day).";
}

print(greet(person: "Kernel", day: "Wednesday"));

// Use a tuple to make a compound value—for example, to return multiple values from a function.
// The elements of a tuple can be referred to either by name or by number.
func calculateStatistics(scores: [Int]) -> (min: Int, max: Int, sum: Int) {
    var min = scores[0];
    var max = scores[0];
    var sum = 0;

    for score in scores {
        if (score > max) {
            max = score;
        } else if (score < min) {
            min = score;
        }

        sum += score;
    }

    return (min, max, sum);
}

let statistics = calculateStatistics(scores: [5, 3, 100, 3, 9]);

// Both prints "120"
print(statistics.sum);
print(statistics.2);

// Functions can be nested. Nested functions have access to variables that were declared in the outer function.
func returnFifteen() -> Int {
    var y = 10;

    func add() {
        y += 5;
    }

    add();

    return y;
}

returnFifteen();

// Functions are a first-class type. This means that a function can return another function as its value.
func makeIncrementer() -> ((Int) -> Int) {
    func addOne(number: Int) -> Int {
        return 1 + number;
    }

    return addOne;
}

var increment = makeIncrementer();
increment(7);
