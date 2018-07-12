import java.util.*;
class Main{
	public static void main(String args[]){
		int d[];
		d = new int[1000+1];
		Scanner scanner = new Scanner(System.in);
		String tmp = scanner.nextLine();
		int n = Integer.parseInt(tmp);

		d[0]=1;
		d[1]=1;
		for(int i=2; i<=n; i++) d[i]=(d[i-1]+d[i-2])%10007;
		System.out.printf("%d\n", d[n]);
	}
}