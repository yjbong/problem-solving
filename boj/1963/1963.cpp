#include <cstdio>
#include <cmath>
#include <queue>
#define INF 1000000000
using namespace std;
bool vld[10000];
int min_step[10000];

int chng(int n, int ch, int a){ // change the (10^ch) digit of n to a. (a is one digit number)

    if(ch==0) return (n/10*10+a);
    else if(ch==1) return (n/100*100+a*10+n%10);
    else if(ch==2) return (n/1000*1000+a*100+n%100);
    else if(ch==3) return (a*1000+n%1000);
}

int main(void){

    for(int i=0; i<=9999; i++){
        if(i<1000) vld[i]=false;
        else{
            vld[i]=true;
            int sqrt_i=(int)sqrt(i);
            for(int j=2; j<=sqrt_i; j++){
                if(i%j==0){
                    vld[i]=false;
                    break;
                }
            }
        }
    }

    int t;
    scanf("%d",&t);
    int sol=INF;
    while(t--){

        queue<int> q;
        for(int i=0; i<=9999; i++) min_step[i]=INF;

        int src,dst;
        scanf("%d %d",&src,&dst);
        q.push(src);
        min_step[src]=0;

        while(!q.empty()){

            int fnum=q.front();
            q.pop();

            for(int i=0; i<=3; i++){
                for(int j=0; j<=9; j++){
                    int cnum=chng(fnum,i,j);
                    if(cnum!=fnum && vld[cnum]){
                        if(min_step[cnum]>min_step[fnum]+1){
                            min_step[cnum]=min_step[fnum]+1;
                            q.push(cnum);
                        }
                    }
                }
            }
        }

        if(min_step[dst]>=INF) printf("Impossible\n");
        else printf("%d\n",min_step[dst]);
    }

    return 0;
}