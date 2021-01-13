#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int T;
ll side[3], eat;
int main() {
    scanf("%d",&T);
    while(T--){
        for(int i=0; i<3; i++) scanf("%lld",&side[i]);
        scanf("%lld",&eat);
        // 변의 길이는 side[0]<=side[1]<=side[2]
        sort(side, side+3); 
 
        // side[2]와 side[1]을 최대한 같게 만든다.
        if(eat<=side[2]-side[1]){
            side[2]-=eat; eat=0;
        } else {
            eat-=side[2]-side[1];
            side[2]=side[1];
        }
 
        // 남은 eat가 0보다 크다면 side[1]과 side[2]는 같아져 있다.
        // 이제 side[1,2]와 side[0]을 최대한 같게 만든다. 
        if(eat<=(side[1]-side[0])*2){
            side[2]-=eat/2, side[1]-=eat/2;
            side[1]-=eat%2; eat=0;
        } else {
            eat-=(side[1]-side[0])*2;
            side[2]=side[1]=side[0]; 
        }
 
        // 남은 eat가 0보다 크다면 side[0], side[1], side[2]는 같아져 있다.
        // 남은 eat를 3개의 변에 최대한 비슷하게 분배하여 뺀다.
        for(int i=0; i<3; i++) side[i]-=eat/3;
        for(int i=0; i<eat%3; i++) side[i]--;
 
        // 신혜가 먹고 남은 케이크의 부피
        ll ans=side[0]*side[1]*side[2];
        printf("%lld\n",ans);
    }
    return 0;
}