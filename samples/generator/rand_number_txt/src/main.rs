use rand::Rng;
use serde::Deserialize;
use std::fs;
use std::fs::File;
use std::io::{self, Write};

// Define Config struct
#[derive(Debug, Deserialize)]
struct Config {
    range: [u32; 2],
    size: usize,
}

fn main() -> io::Result<()> {
    // Read and parse JSON config
    let config_content = fs::read_to_string("config.json")?;
    let config: Config = serde_json::from_str(&config_content)?;

    // Generate random numbers
    let mut rng = rand::thread_rng();
    let numbers: Vec<u32> = (0..config.size)
        .map(|_| rng.gen_range(config.range[0]..=config.range[1]))
        .collect();

    // Write to file
    let mut file = File::create("output.txt")?;
    for number in numbers {
        write!(file, "{} ", number)?;
    }

    println!("Successfully generated random numbers to output.txt");

    Ok(())
}
