use std::io;

fn main() {
	let mut input = String::new();
	io::stdin().read_line(&mut input).expect("Failed to read line");
	let mut tokens = input.split_ascii_whitespace();
	let a: i32 = tokens.next().unwrap().parse().unwrap();
	let b: i32 = tokens.next().unwrap().parse().unwrap();
	if a < b {
		println!("<");
	} else if a > b {
		println!(">");
	} else {
		println!("==");
	}
}