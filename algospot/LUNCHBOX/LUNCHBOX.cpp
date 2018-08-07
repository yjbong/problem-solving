#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
int c,n;
pair <int,int> person[10000]; // person[i].first: Ei, person[i].second: Mi

int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++) scanf("%d",&(person[i].second));
                for(int i=0; i<n; i++) scanf("%d",&(person[i].first));

                sort(person,person+n);
                int cur_m=0, cur_e;
                int ans=-1;
                for(int i=n-1; i>=0; i--){
                        cur_m+=person[i].second;
                        cur_e=cur_m+person[i].first;
                        if(ans<cur_e) ans=cur_e;
                }
                printf("%d\n",ans);
        }
        return 0;
}