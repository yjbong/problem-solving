import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

import static java.lang.Math.sqrt;

public class Main {

    private static int getGcd(int a, int b) {
        if(b==0) return a;
        else return getGcd(b, a%b);
    }
    public static void main(String[] args) {

        int N;
        ArrayList<Integer> A = new ArrayList<>();
        Scanner in = new Scanner(System.in);

        // 수의 리스트를 입력받고 오름차순 정렬
        N = in.nextInt();
        for (int i = 0; i < N; i++) A.add(in.nextInt());
        Collections.sort(A);

        // 수의 차이값들을 D 배열에 저장
        ArrayList<Integer> D = new ArrayList<>();
        for(int i=1; i<N; i++) D.add(A.get(i) - A.get(i-1));

        // D 배열에 포함된 수들의 최대공약수 계산
        int gcd = D.get(0);
        for(int i=1; i<N-1; i++)
           gcd = getGcd(gcd, D.get(i));

        // 구한 최대공약수의 1보다 큰 모든 약수를 구함
        ArrayList<Integer> divider = new ArrayList<>();
        for(int i=1; i<=sqrt(gcd); i++) {
            if(gcd%i==0) {
                if(i>1) divider.add(i);
                if(gcd/i>1 && gcd/i!=i) divider.add(gcd/i);
            }
        }
        Collections.sort(divider);

        // 답 출력
        for(int i=0; i<divider.size(); i++)
            System.out.print(divider.get(i) + " ");
    }
}