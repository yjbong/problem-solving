#include <cstdio>
#define MAX_N 1000
int N,K;
bool del[MAX_N+1];
int main() {
    del[0]=del[1]=true;
    scanf("%d %d",&N,&K);
    int idx=1;
    int ans=-1;
    for(int i=2; i<=N; i++){
        if(!del[i]){
            for(int j=i; j<=N; j+=i){
                if(!del[j]){
                    if(idx==K){ ans=j; goto out; }
                    else idx++;
                    del[j]=true;
                }
            }
        }
    }
out:
    printf("%d\n",ans);
    return 0;
}