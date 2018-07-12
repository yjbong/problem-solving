#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[2000];

int binsearch(int l, int r, int key){

        int m;
        while(l<=r){
                m=(l+r)/2;
                if(a[m]<key) l=m+1;
                else if(key<a[m]) r=m-1;
                else return m;
        }
        return -1;
}

int main(void){

        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int sol=0;
        for(int i=0; i<n; i++){
                bool ok=false;
                for(int j=0; j<n; j++){
                        if(i<j){
                                if(binsearch(0, i-1, a[i]-a[j])>=0 || binsearch(i+1, j-1, a[i]-a[j])>=0 || binsearch(j+1, n-1, a[i]-a[j])>=0){
                                        ok=true;
                                        break;
                                }
                        }
                        else if(i>j){
                                if(binsearch(0, j-1, a[i]-a[j])>=0 || binsearch(j+1, i-1, a[i]-a[j])>=0 || binsearch(i+1, n-1, a[i]-a[j])>=0){
                                        ok=true;
                                        break;
                                }
                        }
                }
                if(ok) sol++;
        }
        printf("%d\n",sol);
        return 0;
}