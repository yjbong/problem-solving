import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	public static void main (String[] args)
	{
		// your code goes here
        Scanner sc=new Scanner(System.in);
        while(true){
            String s=sc.next();

            if(s.equals("0")) break;
            int n=s.length();
            int ans=0;
            for(int i=0; i<n; i++) ans+=(int)(s.charAt(i))-'0';

            while(ans>9){
                int tmp=ans;
                ans=0;
                while(tmp>0){
                    ans+=tmp%10;
                    tmp/=10;
                }
            }
            System.out.println(ans);
        }
	}
}