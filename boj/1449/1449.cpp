#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000];
int main(void){

    int n,l;
    scanf("%d %d",&n,&l);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int st_pos=a[0];
    int sol=1;
    for(int i=1; i<n; i++){
        if(st_pos+l-1 < a[i]){
            st_pos=a[i];
            sol++;
        }
    }
    printf("%d\n",sol);
    return 0;
}