import java.util.Scanner;

public class Main
{
	static long getGcd(long a, long b){
        	if(b==0) return a;
        	else return getGcd(b, a%b);
	}
	public static void main (String[] args){

        	Scanner in = new Scanner(System.in);
        	int N = in.nextInt(); // 로그 쌍의 수
        
        	long bal = 0; // 기존 잔고
        	long maxbal = 0; // (충전이 필요한 경우의) 최대 잔고
        	long gcd=-1;
        	boolean error=false;
        	for(int i=0; i<N; i++){
            	long a = in.nextLong(); // 입출금액
           		long b = in.nextLong(); // 입출금 후 잔고
            		if(bal+a>=0){
                		if(bal+a!=b) error=true; // 로그가 틀림
                		bal=b; continue;
            		}
            
            		if(gcd<0) gcd = b-a-bal;
            		else gcd=getGcd(gcd, b-a-bal);
            		if(maxbal<b) maxbal=b;

            		bal=b;
        	}

        	if(gcd<0) gcd=1;
        	if(gcd<=maxbal) error=true; // 가능한 M값이 존재하지 않음
        
        	if(!error) System.out.println(gcd);
        	else System.out.println("-1");
	}
}