#include <stdio.h>
int bb[1000];
int n;
int min;
int max_bb_idx;

int binsearch(int key){

    int left, mid, right;

    left=0, right=max_bb_idx;
    while(left<=right){
        mid=(left+right)/2;
        if(bb[mid]<key) left=mid+1;
        else if(bb[mid]>key) right=mid-1;
        else return mid;
    }
    return -1;
}

void go(int cur_n, int used, int used_max){

    int i;

    if(binsearch(cur_n)>=0){
        if(min>used) min=used;
        return;
    }
    else if(used==used_max) return;
    for(i=0; i<=max_bb_idx; i++)
        go(cur_n-bb[i], used+1, used_max);
}

int main(void){

    int i;

    for(i=0; i<750; i++)
        bb[i]=2*i*i+3*i+1;

    scanf("%d", &n);

    i=0;
    while(bb[i]<=n) i++;
    max_bb_idx=i-1;

    if(n>146858){ /* check 1, 2 */
        min=3;
        go(n, 1, 2);
    }
    else if(n>130){ /* check 1, 2, 3 */
        min=4;
        go(n, 1, 3);
    }
    else if(n>26){ /* check 1, 2, 3, 4 */
        min=5;
        go(n, 1, 4);
    }
    else{
        min=6;
        go(n, 1, 5);
    }
    printf("%d\n", min);
    return 0;
}