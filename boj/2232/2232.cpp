#include <cstdio>
int p[50005];
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&p[i]);
    int sol=0;
    bool is_up=true;
    p[0]=p[n+1]=0;
    for(int i=1; i<=n; i++){
        if(is_up){
            if(p[i]>p[i+1]){
                printf("%d ",i);
                is_up=false;
            }
            else if(p[i]==p[i+1]) printf("%d ",i);
        }
        else{
            if(p[i]<p[i+1]) is_up=true;
            else if(p[i]==p[i+1]) is_up=true;
        }
    }
    printf("\n");
    return 0;
}