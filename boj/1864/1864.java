import java.util.*;
import java.lang.*;
import java.io.*;
public class Main
{
	public static void main (String[] args)
	{
        Scanner sc = new Scanner(System.in);
        while(true){
            String s = sc.next();
            if(s.equals("#")==true) break;
            int ans=0;
            for(int i=0; i<s.length(); i++){
                ans*=8;
                switch(s.charAt(i)){
                    case '-': ans+=0; break;
                    case '\\': ans+=1; break;
                    case '(': ans+=2; break;
                    case '@': ans+=3; break;
                    case '?': ans+=4; break;
                    case '>': ans+=5; break;
                    case '&': ans+=6; break;
                    case '%': ans+=7; break;
                    case '/': ans-=1; break;
                }
            }
            System.out.println(ans);
        }
	}
}