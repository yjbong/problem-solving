#include <cstdio>
int hp[111111];
int main(void){
    int n;
    scanf("%d",&n);
    if(n==1) hp[1]=1;
    else{
        hp[1]=2, hp[2]=1;
        for(int i=3; i<=n; i++){
            int j=i-1;
            while(j>0){
                hp[j]=hp[j/2];
                j/=2;
            }
            hp[i]=1;
            hp[1]=i;
        }
    }
    for(int i=1; i<=n; i++) printf("%d ",hp[i]);
    printf("\n");
    return 0;
}