use rand::Rng;
use std::fs::File;
use std::io::{self, Write};

fn main() -> io::Result<()> {
    // Create Random Number Generator
    let mut rng = rand::thread_rng();

    // Generate Random Number
    let numbers: Vec<u32> = (0..4096).map(|_| rng.gen_range(1..=1000000)).collect();

    // Open File
    let mut file = File::create("output.txt")?;

    // Write to File
    for number in numbers {
        write!(file, "{} ", number)?;
    }

    // Print Success Message
    println!("Successfully generated random numbers to output.txt");

    Ok(())
}
