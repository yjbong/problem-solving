#include <stdio.h>
#define SPACE 0
#define BLACK 1
#define WHITE 2

int b[21][21];

int check(int x, int y, int col){

        int i;
        int seqx, seqy, seq1, seq2;

        seqx=0;
        for(i=0; i<=4; i++){
                if(b[x+i][y]!=col){
                        break;
                }
        }
        seqx+=i;
        for(i=0; i<=4; i++){
                if(b[x-i][y]!=col){
                        break;
                }
        }
        seqx+=i;
        seqx--;
        if(seqx==5) return 1;

        seqy=0;
        for(i=0; i<=4; i++){
                if(b[x][y+i]!=col){
                        break;
                }
        }
        seqy+=i;
        for(i=0; i<=4; i++){
                if(b[x][y-i]!=col){
                        break;
                }
        }
        seqy+=i;
        seqy--;
        if(seqy==5) return 1;

        seq1=0;
        for(i=0; i<=4; i++){
                if(b[x+i][y+i]!=col){
                        break;
                }
        }
        seq1+=i;
        for(i=0; i<=4; i++){
                if(b[x-i][y-i]!=col){
                        break;
                }
        }
        seq1+=i;
        seq1--;
        if(seq1==5) return 1;

        seq2=0;
        for(i=0; i<=4; i++){
                if(b[x+i][y-i]!=col){
                        break;
                }
        }
        seq2+=i;
        for(i=0; i<=4; i++){
                if(b[x-i][y+i]!=col){
                        break;
                }
        }
        seq2+=i;
        seq2--;
        if(seq2==5) return 1;

        return 0;
}

int main(void){

        int i,j;
        int n;
        int x,y,sol;
        scanf("%d", &n);
        for(i=0; i<=20; i++){
                for(j=0; j<=20; j++){
                        b[i][j]=SPACE;
                }
        }

        sol=-1;
        for(i=0; i<n; i++){
                scanf("%d %d", &x, &y);
                if(i%2==0){
                        b[x][y]=BLACK;
                        if(check(x,y,BLACK)==1){
                                sol=i+1;
                                break;
                        }
                }

                else{
                        b[x][y]=WHITE;
                        if(check(x,y,WHITE)==1){
                                sol=i+1;
                                break;
                        }
                }
        }
        if(sol<0) printf("-1\n");
        else printf("%d\n", sol);
        return 0;
}