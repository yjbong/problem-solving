import java.util.*;
import java.math.*;
import java.io.*;

public class Main
{
    public static void main (String[] args)
    {
        int N; // 단어의 개수
        String[] word;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        word = new String[N];
        for(int i=0; i<N; i++) word[i] = sc.next();

        // 각 알파벳의 노드 생성
        Node[] node = new Node[26];
        for(int i=0; i<26; i++) node[i] = new Node();

        // 입력에 등장한 알파벳 체크
        int valids=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<word[i].length();  j++){
                int idx=word[i].charAt(j)-(int)'a';
                if(node[idx].valid==false){
                    node[idx].valid=true;
                    valids++;
                }
            }
        }

        boolean error=false;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                // word[i]는 word[j]보다 사전 순으로 앞
                if(word[i].length()>word[j].length() && word[j].equals(word[i].substring(0,word[j].length()))==true) error=true; // 모순 발생 (word[i]가 word[j]보다 앞일 수 없음)
                for(int k=0; k<Math.min(word[i].length(), word[j].length()); k++){
                    if(word[i].charAt(k)!=word[j].charAt(k)){
                        int curIn=word[i].charAt(k)-'a';
                        int curOut=word[j].charAt(k)-'a';
                        if(!node[curIn].out.contains(curOut)) node[curIn].out.add(curOut);
                        if(!node[curOut].in.contains(curIn)) node[curOut].in.add(curIn);
                        break;
                    }
                }
            }
        }

        // Topological sort
        int []topOrder = new int[valids];
        int topOrders=0;
        boolean multiOrder=false;
        while(true){
            int cur = -1;
            for(int i=0; i<26; i++){
                if(node[i].in.size()==0 && node[i].valid==true){
                    if(cur<0) cur=i;
                    else{ // 가능한 순서가 2개 이상
                        multiOrder=true;
                    }
                }
            }
            if(cur>=0){
                node[cur].valid=false;
                for(int curOut : node[cur].out)
                    node[curOut].in.remove(cur);
                topOrder[topOrders] = cur;
                topOrders = topOrders+1;
            }
            else break;
        }

        // 출력
        if(topOrders<valids || error==true) System.out.println("!");
        else if(multiOrder==true) System.out.println("?");
        else{
            for(int i=0; i<topOrders; i++) System.out.print((char)(topOrder[i] + 'a'));
            System.out.println("");
        }
    }
    static class Node{
        public boolean valid;
        HashSet<Integer> in;
        HashSet<Integer> out;
        Node(){
            valid=false;
            in=new HashSet<>();
            out=new HashSet<>();
        }
    }
}