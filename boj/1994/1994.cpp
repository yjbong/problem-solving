#include <stdio.h>
#include <stdlib.h>

int a[2000];
int d[2000][2000];

int cmp(const void *a, const void *b){
    if(*((int*)a)>*((int*)b)) return 1;
    else return 0;
}

int binsearch(int left, int right, int key){

    int mid,ret=-1;
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]<key) left=mid+1;
        else if(a[mid]>key) right=mid-1;
        else{
            ret=mid;
            left=mid+1;
        }
    }
    return ret;
}

int main(void){

    int i,j,k,n,maxlen;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);

    for(j=0; j<n; j++){
        if(j==0) d[0][j]=1;
        else d[0][j]=2;
    }
    for(i=1; i<n; i++){
        for(j=i; j<n; j++){
            k=binsearch(0,i-1,a[i]-(a[j]-a[i]));
            if(k<0){
                if(i==j) d[i][j]=1;
                else d[i][j]=2;
            }
            else{
                if(i==j) d[i][j]=d[k][i];
                else d[i][j]=d[k][i]+1;
            }
        }
    }

    maxlen=0;
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
            if(maxlen<d[i][j]) maxlen=d[i][j];

    printf("%d\n",maxlen);
    return 0;
}