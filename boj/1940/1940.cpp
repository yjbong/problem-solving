#include <cstdio>
#include <algorithm>
using namespace std;
int a[15000];

int bsearch(int left, int right, int key){

    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(key>a[mid]) left=mid+1;
        else if(key<a[mid]) right=mid-1;
        else return mid;
    }
    return -1;
}
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int sol=0;
    for(int i=0; i<n-1; i++)
        if(bsearch(i+1,n-1,m-a[i])>=0) sol++;

    printf("%d\n",sol);
    return 0;
}