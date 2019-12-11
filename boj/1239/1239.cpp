#include <cstdio>
#include <algorithm>
int a[8];
int p[8];
 
int main(void){
    int n,ans;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<n; i++) p[i]=i;
 
    ans=0;
    do{
        int curAns=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int curSum=0;
                for(int k=i; ;k=(k+1)%n){
                    curSum+=a[p[k]];
                    if(k==j) break;
                }
                if(curSum==50) curAns++;
            }
        }
        curAns/=2;
        if(ans<curAns) ans=curAns;
    }while(std::next_permutation(p,p+n));
    printf("%d\n",ans);
    return 0;
}