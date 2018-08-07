#include <cstdio>
#define MAX_N 50
#define MAX_P 1000000049
int c,n,p,l;
int x[51]; int y[51];

int main(void){

        x[0]=y[0]=1;
        for(int i=1; i<=MAX_N; i++){
                x[i]=x[i-1]+1+y[i-1]+1;
                if(x[i]>MAX_P) x[i]=MAX_P+1;
                y[i]=1+x[i-1]+1+y[i-1];
                if(y[i]>MAX_P) y[i]=MAX_P+1;
        }
        scanf("%d",&c);
        while(c--){
                scanf("%d %d %d",&n,&p,&l);
                for(int i=p; i<p+l; i++){
                        int idx=i;
                        int state=0;
                        for(int j=n; j>=0; j--){
                                switch(state){
                                case 0: // at first

                                        // F
                                        if(idx<=1){
                                                printf("F");
                                                goto out;
                                        }
                                        else idx-=1;

                                        // X
                                        if(idx<=x[j]){
                                                if(j==0) printf("X");
                                                else state=1;
                                                break;
                                        }
                                        else idx-=x[j];

                                        break;

                                case 1: // from 'X'

                                        // X
                                        if(idx<=x[j]){
                                                if(j==0) printf("X");
                                                else state=1;
                                                break;
                                        }
                                        else idx-=x[j];

                                        // +
                                        if(idx<=1){
                                                printf("+");
                                                goto out;
                                        }
                                        else idx-=1;

                                        // Y
                                        if(idx<=y[j]){
                                                if(j==0) printf("Y");
                                                else state=2;
                                                break;
                                        }
                                        else idx-=y[j];

                                        // F
                                        if(idx<=1){
                                                printf("F");
                                                goto out;
                                        }
                                        else idx-=1;

                                        break;

                                case 2: // from 'Y'

                                        // F
                                        if(idx<=1){
                                                printf("F");
                                                goto out;
                                        }
                                        else idx-=1;

                                        // X
                                        if(idx<=x[j]){
                                                if(j==0) printf("X");
                                                else state=1;
                                                break;
                                        }
                                        else idx-=x[j];

                                        // -
                                        if(idx<=1){
                                                printf("-");
                                                goto out;
                                        }
                                        else idx-=1;

                                        // Y
                                        if(idx<=y[j]){
                                                if(j==0) printf("Y");
                                                else state=2;
                                                break;
                                        }
                                        else idx-=y[j];

                                        break;
                                }
                        }
                        out: ;
                }
                printf("\n");
        }
        return 0;
}