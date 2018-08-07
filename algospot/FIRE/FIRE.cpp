#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
using namespace std;
int t,n,p;
int c[100001]; // c[i] = cost for building beacon at position i
// possible built position = 1~n (pos 0 = capital, pos n+1 = boundary)

int d[100001]; // d[i] = minimum total cost that last built position is i
int min2(int a, int b){
        return a<b?a:b;
}
int max2(int a, int b){
        return a>b?a:b;
}

priority_queue<pair<int,int> > pq; // first = d[i], second = i

int main(void){

        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&n,&p);
                for(int i=1; i<=n; i++) scanf("%d",&c[i]);

                for(int i=0; i<=n; i++) d[i]=INF;
                d[0]=0;
                /*
                for(int i=1; i<=n; i++){
                        for(int j=max2(i-p,0); j<i; j++) d[i]=min2(d[i],d[j]+c[i]);
                }
                */

                while(!pq.empty()) pq.pop();
                pq.push(make_pair(-d[0],0));

                for(int i=1; i<=n; i++){
                        while(!pq.empty() && pq.top().second < i-p) pq.pop();
                        d[i]=min2(d[i],-(pq.top().first)+c[i]);
                        pq.push(make_pair(-d[i],i));
                }

                int ans=INF;
                for(int i=max2(n-p+1,1); i<=n; i++) ans=min2(ans,d[i]);
                printf("%d\n",ans);
        }
        return 0;
}