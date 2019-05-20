import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	public static void main (String[] args)
	{
        Scanner sc = new Scanner(System.in);
	    int [][]card = new int[100][100];
        int R = sc.nextInt();
        int C = sc.nextInt();
        String s;
        for(int i=0; i<R; i++){
            s = sc.next();
            for(int j=0; j<C; j++)
                card[i][j]=(s.charAt(j)=='#'?1:0);
        }
        int A = sc.nextInt(); A--;
        int B = sc.nextInt(); B--;

        for(int i=0; i<R; i++)
            for(int j=C; j<C*2; j++)
                card[i][j]=card[i][C*2-1-j];
        for(int i=R; i<R*2; i++)
            for(int j=C; j<C*2; j++)
                card[i][j]=card[R*2-1-i][j];
        for(int i=R; i<R*2; i++)
            for(int j=0; j<C; j++)
                card[i][j]=card[i][C*2-1-j];
        card[A][B]=1-card[A][B];

        for(int i=0; i<R*2; i++){
            for(int j=0; j<C*2; j++)
                System.out.print(card[i][j]==1?'#':'.');
            System.out.println("");
        }
	}
}