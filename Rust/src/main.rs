#[allow(dead_code)]
mod concepts;
mod exercises;

fn main() {
    println!("Rust Coding Dojo");

    // Basic functionalities
    // concepts::basic::output_text();
    // concepts::basic::functions();
    // concepts::basic::iterating_over_data();

    // Coding exercises and problems
    // exercises::palindrome::palindrome();
    // exercises::fizz_buzz::fizzbuzz();
    // exercises::bit_manipulation::single_number();
    exercises::bit_manipulation::power_of_two();
}
