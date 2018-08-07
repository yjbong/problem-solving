#include <cstdio>
#include <algorithm>
using namespace std;
int c,n;
int rus[100];
int kor[100];
int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++) scanf("%d",&rus[i]);
                for(int i=0; i<n; i++) scanf("%d",&kor[i]);
                sort(rus,rus+n);
                sort(kor,kor+n);

                int ans=0;
                int cur_kor=n-1;
                for(int i=n-1; i>=0; i--){
                        if(kor[cur_kor]>=rus[i]){
                                ans++;
                                cur_kor--;
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}