// Given an array of integers where every element appears twice except for one element which appears only once.
// Find the element that appears only once.
pub fn single_number() {
    const ELEMENTS: [i32; 11] = [0, 1, 5, 3, 0, 5, 6, 3, 1, 9, 6];

    let mut result: i32 = 0;

    for value in ELEMENTS {
        result ^= value;
    }

    println!("Unique number: {}", result);
}

// Given an integer n, write a function to determine if it is a power of two.
pub fn power_of_two() {
    const ELEMENTS: [i32; 5] = [8, 16, 42, 1024, 3];

    for value in ELEMENTS {
        // Using the bitwise AND operator
        // Example: 8(1000) AND(&) 7(0111) = 0(0000)
        if value & (value - 1) != 0
        {
            println!("Value {} is NOT a power of two", value);
            continue;
        }

        println!("Value {} is a power of two", value);
    }
}

pub fn add() {
    let mut a = 2;
    let mut b = 3;
    let mut carry = 0;
    let mut result = 0;

    while b != 0 {
        result = a ^ b;       // XOR
        carry = (a & b) << 1; //
        a = result;
        b = carry;
    }

    println!("a+b={}", result);
}