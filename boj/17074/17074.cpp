#include <cstdio>
#define MAX_N 100000
#define INF 2000000000
using namespace std;
int N;
int a[MAX_N];
 
int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&a[i]);
 
    int inv=-1; // 정렬되지 않은 위치
    for(int i=0; i<N-1; i++)
        if(a[i]>a[i+1]){ inv=i; break; }
 
    int ans=0;
    if(inv<0) ans=N;
    else{
        bool ok; int c;
        // a[inv] 제외하고 정렬되어 있는지 확인
        ok=true;
        c=INF;
        for(int i=0; i<N; i++){
            if(i==inv) continue;
            if(c<INF && c>a[i]){ ok=false; break; }
            c=a[i];
        }
        if(ok) ans++;
 
        // a[inv+1] 제외하고 정렬되어 있는지 확인
        ok=true;
        c=INF;
        for(int i=0; i<N; i++){
            if(i==inv+1) continue;
            if(c<INF && c>a[i]){ ok=false; break; }
            c=a[i];
        }
        if(ok) ans++;
    }
    printf("%d\n",ans);
	return 0;
}