use std::io;
use std::fmt::Write;

fn main() {

	let mut first_line = String::new();
	io::stdin().read_line(&mut first_line).expect("Failed to read line");
	let mut first_tokens = first_line.split_ascii_whitespace();
	let n: usize = first_tokens.next().unwrap().parse().unwrap();
	let m: usize = first_tokens.next().unwrap().parse().unwrap();
	let r: usize = first_tokens.next().unwrap().parse().unwrap();

	// adjacent matrix
	let mut adj = vec![Vec::<usize>::new(); n+1];

	for _i in 0..m {
		let mut line = String::new();
		io::stdin().read_line(&mut line).expect("Failed to read line");
		let mut tokens = line.split_ascii_whitespace();
		let u: usize = tokens.next().unwrap().parse().unwrap();
		let v: usize = tokens.next().unwrap().parse().unwrap();

		// add undirected edge
		adj[u].push(v);
		adj[v].push(u);
	}
	for i in 1..n+1 {
		adj[i].sort();
	}

	let mut depth = Vec::new();
	let mut visited = Vec::new();
	for _i in 0..n+1 {
		depth.push(1000000000);
		visited.push(false);
	}

	// dfs
	visited[r] = true;
	dfs(r, n, 0, &mut depth, &mut visited, &adj);

	// print answer
	let mut output = String::new();
	for i in 1..n+1 {
		if depth[i] > n {
			writeln!(output, "-1").unwrap();
		} else {
			writeln!(output, "{}", depth[i]).unwrap();
		}
	}
	print!("{}", output);
}

fn dfs(idx: usize, n: usize, cur_depth: usize, depth: &mut Vec<usize>, visited: &mut Vec<bool>, adj: &Vec<Vec<usize>>){
	if depth[idx] > cur_depth {
		depth[idx] = cur_depth;
	}
	for cur_adj in &adj[idx] {
		if visited[*cur_adj] == false {
			visited[*cur_adj] = true;
			dfs(*cur_adj, n, cur_depth+1, depth, visited, adj);
		}
	}
}
