#include <stdio.h>
int pw[11];
int d[11];
char sol[101];
int main(void){

    int i,j,n,als,minlen;
    pw[0]=1;
    for(i=1; i<=10; i++) pw[i]=pw[i-1]*2;
    scanf("%d",&n);
    for(i=10; i>=0; i--){
        if(n>pw[i]-1){
            als=i+1;
            break;
        }
    }
    minlen=als*(als+1)/2;
    if(n<1 || n<minlen) printf("-1\n");
    else{
        for(i=minlen; i<=n; i++){
            if(i==minlen) for(j=0; j<als; j++) d[j]=j+1;
            else{
                for(j=0; j<als; j++){
                    if(j<als-1){
                        if(d[j]+1<=pw[j] && d[j]+1<d[j+1]){
                            d[j]++;
                            break;
                        }
                    }
                    else{
                        d[j]++;
                        break;
                    }
                }
            }
        }
        for(i=0; i<n; i++) sol[i]='?';
        sol[n]='\0';

        for(i=0; i<als; i++) sol[d[i]-1]='A'+i;
        for(i=0; i<als; i++) d[i]--;

        for(i=0; i<n; i++){
            if(sol[i]=='?'){
                for(j=0; j<als; j++){
                    if(d[j]>0){
                        sol[i]='A'+j;
                        d[j]--;
                        break;
                    }
                }
            }
        }
        printf("%s\n",sol);
    }
    return 0;
}