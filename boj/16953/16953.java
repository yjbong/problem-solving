/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        int step=1;
        while(A<B){
            if(B%2==0) B/=2; // B가 짝수라면 2를 곱하는 연산을 한 것이다.
            else if(B%10==1) B/=10; // B가 홀수라면 B의 마지막 자리수는 1이어야 하고, 이때는 오른쪽에 1을 붙이는 연산을 한 것이다.
            else break;
            step++;
        }
        if(A==B) System.out.println(step);
        else System.out.println("-1");
    }
}