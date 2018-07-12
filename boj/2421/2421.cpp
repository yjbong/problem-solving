#include <cstdio>
bool p[1000000];
int d[1000][1000];

int max2(int a, int b){
    if(a>b) return a;
    else return b;
}

int is_p(int a, int b){

    if(a==1 && b==1) return 0;

    int b_dgts=0;
    int t=b;
    while(t>0){
         t/=10;
         b_dgts++;
    }

    for(int i=0; i<b_dgts; i++) a*=10;

    if(p[a+b]==false) return 1;
    else return 0;
}

int main(void){

    p[0]=p[1]=true;
    for(int i=2; i<1000000; i++)
        if(!p[i]) for(int j=i*2; j<1000000; j+=i) p[j]=true;

    int n;
    scanf("%d",&n);

    int sol=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j]=max2(d[i-1][j],d[i][j-1])+is_p(i,j);
            if(sol<d[i][j]) sol=d[i][j];
        }
    }

    printf("%d\n",sol);
    return 0;
}