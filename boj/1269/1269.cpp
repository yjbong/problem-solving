#include <stdio.h>
#include <stdlib.h>

int a[200000], b[200000];
int as,bs;
int cmp(const void *a, const void *b){
    if(*((int*)a)>*((int*)b)) return 1;
    else return 0;
}

int binsearch(int key){
    int left, right, mid;
    left=0, right=bs-1;
    while(left<=right){
        mid=(left+right)/2;
        if(b[mid]<key) left=mid+1;
        else if(b[mid]>key) right=mid-1;
        else return mid;
    }
    return -1;
}

int main(void){

    int i,sol;
    scanf("%d %d", &as, &bs);
    for(i=0; i<as; i++) scanf("%d", &a[i]);
    for(i=0; i<bs; i++) scanf("%d", &b[i]);
    qsort(b, bs, sizeof(int), cmp);
    sol=as+bs;
    for(i=0; i<as; i++)
        if(binsearch(a[i])>=0) sol-=2;

    printf("%d\n", sol);

    return 0;
}