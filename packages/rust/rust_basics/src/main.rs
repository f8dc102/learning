fn main() {
    variable();

    let sum = add(5, 10);
    println!("The sum is: {}", sum);

    print_labeled_measurement(5, 'h');
    unique_expression();
}

fn variable() {
    // Variables are immutable by default
    // @WARN: Cannot assign twice to immutable variable
    let x = 5;

    // Shadowing
    let x = x + 1;
    // x = 6

    {
        // x = 12
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }

    // This is valid
    // x = 6
    println!("The value of x is: {}", x);

    // Declare constants like this
    // const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;

    let spaces = "   ";
    let spaces = spaces.len();
    println!("The number of spaces is: {}", spaces);
}

// Data Types
// let cat_emoji: char = '🐈';
// let tup: (i32, f64, u8) = (500, 6.4, 1);

//         type | size
//           |   |
// let arr: [i32; 5] = [1, 2, 3, 4, 5];

//      value | length
//          |  |
// let a = [3; 5];

// Function signature
fn add(x: i32, y: i32) -> i32 {
    x + y
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {value}{unit_label}");
}

fn unique_expression() {
    // @WARN: This will not compile
    // let x = (let y = 6);
    // Nothing to bind to x from the statement let y = 6

    // Use this instead
    let y = {
        let x = 3;
        x + 1 // Return
    };

    println!("The value of y is: {y}");
}

// Control Flow
fn ctrl_flow() {
    // Difference with other languages
    let number = 3;

    // @WARN: This will not compile
    // number is not a boolean!!!
    // if number {
    //    println!("Condition was true");
    // }

    // (No braces)
    // |        |
    if number != 0 {
        println!("Number was something other than zero");
    }

    // What if we use if at let? (let-if)
    let condition = true;
    let number = if condition { 5 } else { 6 };

    println!("The value of number is: {}", number);

    let mut counter = 0;
    // Loops
    let result = loop {
        counter += 1;

        if counter == 10 {
            // break + return value?
            break counter * 2;
        }
    };
    println!("The result is {result}");

    // Loop Labels
    let mut count = 0;
    'counting_up: loop {
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("End count = {count}");
}
