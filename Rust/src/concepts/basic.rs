pub fn output_text()
{
    println!("Hello from the output_text function");
}

fn read_only_function(data: &String)
{
    println!("read_only_function");
    println!("{}", data);
}

fn mutable_function(data: &mut String)
{
    println!("mutable_function");
    println!("Before the change: {}", data);
    data.push_str(" has something new");
    println!("After the change: {}", data)
}

fn move_value_function(data: String)
{
    println!("move_value_function");
    println!("{}", data);
}

pub fn functions() 
{
    let mut data = String::from("The data");
    read_only_function(&data);
    mutable_function(&mut data);
    move_value_function(data);

    // Trying to print a move value - not possible
    //println!("{}", data);
}