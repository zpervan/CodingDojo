// Write a program that prints the numbers from 1 to 100. For multiples of three, print "Fizz" instead of the number.
// For multiples of five, print "Buzz" instead of the number. For numbers which are multiples of both three and five,
// print "FizzBuzz".
// Example:
// 1, 2, Fizz, 4, Buzz, ..., 13, 14, FizzBuzz, 16, ...

pub fn fizzbuzz() {
    let numbers = (1u64..100).collect::<Vec<_>>();
    let mut message = String::from("");

    for value in numbers
    {
        if value % 3 == 0 {
            message += "Fizz";
        }

        if value % 5 == 0 {
            message += "Buzz";
        }

        if !message.is_empty() {
            println!("{}", message);
            message.clear();
            continue;
        }

        println!("{}", value);
    }
}