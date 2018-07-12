#include <stdio.h>
int d[11][501];
int max2(int a,int b){
    if(a>b) return a;
    else return b;
}

int main(void){

   int i,j,k,n,m;
   int cur,curlow,curhigh;

   scanf("%d %d", &n,&m);
   if(m>10) m=10;

   for(i=1; i<=n; i++) d[1][i]=i;
   for(i=1; i<=10; i++) d[i][1]=1;

   for(i=2; i<=10; i++){
       for(j=2; j<=n; j++){
           d[i][j]=1000000000;
           for(k=1; k<=n; k++){
               if(k-1>0) curlow=d[i-1][k-1];
               else curlow=1000000000;
               if(j-k>0) curhigh=d[i][j-k];
               else curhigh=1000000000;

               cur=max2(curlow,curhigh)+1;
               if(d[i][j]>cur) d[i][j]=cur;
               if(d[i][j]>d[i-1][j]) d[i][j]=d[i-1][j];
           }
       }
   }
   printf("%d\n",d[m][n]);
   return 0;
}