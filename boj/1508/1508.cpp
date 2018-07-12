#include <cstdio>
#include <vector>
using namespace std;
int p[10000];
int s[10000];
int sol[10000];
int main(void){

    int n,m,k;
    int left,mid,right,curp,curm;

    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<k; i++) scanf("%d",&p[i]);

    if(m==0){
        for(int i=0; i<k; i++) printf("0");
        printf("\n");
    }
    else if(m==1){
        printf("1");
        for(int i=0; i<k-1; i++) printf("0");
        printf("\n");
    }
    else{
        int left,mid,right;
        left=1,right=n;

        vector<int> v;
        while(left<=right){

            mid=(left+right)/2;
            int curp=p[0];

            v.clear();
            v.push_back(0);

            for(int i=1; i<k; i++){
                if(v.size()==m) break;
                else if(p[i]-curp>=mid){
                    v.push_back(i);
                    curp=p[i];
                }
            }
            if(v.size()==m){
                for(int i=0; i<v.size(); i++) s[i]=v[i];
                left=mid+1;
            }
            else right=mid-1;
        }

        for(int i=0; i<m; i++) sol[s[i]]=1;
        for(int i=0; i<k; i++) printf("%d",sol[i]);
        printf("\n");
    }

    return 0;
}