#include <cstdio>
using namespace std;
typedef long long ll;
int N; // 0~N-1까지의 숫자
ll P[10]; // P[i]=숫자 i 한 개의 가격
ll M; // 가진 돈
ll D[10]; // D[i]=만들 수 있는 가장 큰 수에서 숫자 i의 개수
 
int main() {
    while(scanf("%d",&N)==1){
        for(int i=0; i<N; i++) scanf("%lld",&P[i]);
        scanf("%lld",&M);
        for(int i=0; i<10; i++) D[i]=0;
 
        int cheap=0;
        int nonzeroCheap=1;
        for(int i=0; i<N; i++){
            if(P[cheap]>P[i]) cheap=i;
            if(i>0 && P[nonzeroCheap]>P[i]) nonzeroCheap=i;
        }
 
        if(N==1){
            if(M<P[0]){
                // 답 출력
                printf("0\n");
                printf("\n");
                printf("\n");
            }
            else{
                // 답 출력
                printf("1\n");
                printf("0\n");
                printf("0\n");
            }
        }
        else if(M<P[cheap]){ // 수를 만들 수 없음
            // 답 출력
            printf("0\n");
            printf("\n");
            printf("\n");
        }
        else if(M<P[nonzeroCheap]){ // 0밖에 못만듬
            // 답 출력
            printf("1\n");
            printf("0\n");
            printf("0\n");
        }
        else{
            ll digits;
            if(cheap==0) digits=(M-P[nonzeroCheap])/P[cheap]+1;
            else digits=M/P[cheap];
            ll curDigits=digits, curM=M;
            for(int i=N-1; i>=0; i--){
                // 자릿수를 유지하면서 최대한 큰 숫자를 앞쪽에 많이 배치
                ll left=0, right=curM/P[i];
                while(left<=right){
                    ll mid=(left+right)/2;
                    if(P[i]*mid+P[cheap]*(curDigits-mid)<=curM){
                        if(D[i]<mid) D[i]=mid;
                        left=mid+1;
                    }
                    else right=mid-1;
                }
                curDigits-=D[i];
                curM-=D[i]*P[i];
            }
            /*
            for(int i=N-1; i>=0; i--){
                printf("D[%d] = %lld\n",i,D[i]);
            }
            */
            // 답 출력
            printf("%lld\n",digits);
            if(digits>50){
                // 앞 50 자리 출력
                int ans1[50], ans1Len=0;
                for(int i=N-1; i>=0; i--)
                    for(int j=0; j<D[i] && ans1Len<50; j++)
                        ans1[ans1Len++]=i;
                for(int i=0; i<50; i++) printf("%d",ans1[i]); printf("\n");
 
                // 뒤 15 자리 출력
                int ans2[50], ans2Len=0;
                for(int i=0; i<N; i++)
                    for(int j=0; j<D[i] && ans2Len<50; j++)
                        ans2[ans2Len++]=i;
                for(int i=49; i>=0; i--) printf("%d",ans2[i]); printf("\n");
            }
            else{
                for(int i=N-1; i>=0; i--)
                    for(int j=0; j<D[i]; j++) printf("%d",i);
                printf("\n");
                for(int i=N-1; i>=0; i--)
                    for(int j=0; j<D[i]; j++) printf("%d",i);
                printf("\n");
            }
        }
    }
    return 0;
}