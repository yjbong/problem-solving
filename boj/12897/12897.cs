using System;
 
public class myclass
{
    private static long[] D = new long[100001];
    private static long mod=1000000007;
 
    public static void Main(){
 
        string val=Console.ReadLine();
        long N=Convert.ToInt64(val);
 
        D[1]=2;
        for(int i=2; i<=N; i++) D[i]=(D[i-1]*3+2)%mod;
        Console.WriteLine(D[N]);
	}
}