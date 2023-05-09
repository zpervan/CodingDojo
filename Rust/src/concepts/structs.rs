trait Util {
    fn print(&self);
    fn dump(&self) -> (String, i32);
}

struct Base {
    data_one: String,
    data_two: i32,
}

impl Util for Base {
    fn print(&self) {
        println!("Base data value");
        println!("Data one: {}", self.data_one);
        println!("Data two: {}", self.data_two)
    }

    fn dump(&self) -> (String, i32) {
        return (self.data_one.clone(), self.data_two.clone());
    }
}

fn new_dummy_base() -> Base {
    return Base { data_one: "Test base".to_string(), data_two: 123 };
}

pub fn simple_struct() {
    let simple_struct = new_dummy_base();
    simple_struct.print();

    let (mut string, mut numbers) = simple_struct.dump();
    string.push_str(", kinda.");
    numbers += 321;

    println!("String: {}", string);
    println!("Numbers: {}", numbers);
}