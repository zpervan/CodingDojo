pub fn output_text() {
    println!("Hello from the output_text function");
}

fn read_only_function(data: &String) {
    println!("read_only_function");
    println!("{}", data);
}

fn mutable_function(data: &mut String) {
    println!("mutable_function");
    println!("Before the change: {}", data);
    data.push_str(" has something new");
    println!("After the change: {}", data)
}

fn move_value_function(data: String) {
    println!("move_value_function");
    println!("{}", data);
}

pub fn functions() {
    let mut data = String::from("The data");
    read_only_function(&data);
    mutable_function(&mut data);
    move_value_function(data);

    // Trying to print a move value - not possible
    //println!("{}", data);
}

pub fn iterating_over_data() {
    let mut data = vec![42, 1, 3, 89, 56, 420];

    // Index based approach
    println!("### INDEX BASED ###");

    for i in 0..data.len() {
        println!("[I] Before: {}", data[i]);
        data[i] += 1;
        println!("[I] After: {}", data[i]);
    }

    // Range based
    println!("### RANGE BASED ###");

    for value in &mut data {
        println!("[R] Before: {}", value);
        *value += 2;
        println!("[R] After: {}", value);
    }
}
