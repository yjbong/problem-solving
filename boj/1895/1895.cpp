#include <cstdio>
#include <algorithm>
using namespace std;
int a[50][50];
int b[10];
int main(void){

    int r,c,t;
    scanf("%d %d",&r,&c);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) scanf("%d",&a[i][j]);

    scanf("%d",&t);
    int sol=0;
    for(int i=0; i<r-2; i++){
        for(int j=0; j<c-2; j++){
            int bs=0;
            for(int k=i; k<i+3; k++)
                for(int l=j; l<j+3; l++) b[bs++]=a[k][l];
            sort(b,b+bs);
            if(t<=b[4]) sol++;
        }
    }
    printf("%d\n",sol);
    return 0;
}