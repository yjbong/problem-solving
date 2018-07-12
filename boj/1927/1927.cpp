#include <stdio.h>
#define SWAP(a,b,tmp){tmp=a;a=b;b=tmp;}
#define MAXSIZE 262144
int minheap[MAXSIZE+1];
int datas;

void add_data(int cur_data){

        int i, tmp;
        datas++;
        minheap[datas]=cur_data;
        i=datas;

        while(i/2>0 && minheap[i]<minheap[i/2]){
                SWAP(minheap[i],minheap[i/2],tmp);
                i=i/2;
        }
}

void pop_min(){

        int i, tmp, cur_min_idx;

        if(datas==0){
                printf("0\n");
        }
        else{
                printf("%d\n", minheap[1]);
                minheap[1]=minheap[datas];
                minheap[datas]=0;
                datas--;
                i=1;
                while(1){
                        cur_min_idx=i;
                        if(minheap[i*2]>0 && minheap[cur_min_idx]>minheap[i*2]) cur_min_idx=i*2;
                        if(minheap[i*2+1]>0 && minheap[cur_min_idx]>minheap[i*2+1]) cur_min_idx=i*2+1;

                        if(cur_min_idx==i) break;
                        SWAP(minheap[i], minheap[cur_min_idx], tmp);
                        i=cur_min_idx;
                }
        }
}

int main(void){

        int i, n, near_pow2;
        int cur_data;
        scanf("%d", &n);
        near_pow2=1;
        while(near_pow2<n) near_pow2*=2;
        for(i=1; i<=near_pow2*2; i++) minheap[i]=0;

        datas=0;
        while(n--){
                scanf("%d", &cur_data);
                if(cur_data==0) pop_min();
                else add_data(cur_data);
        }
        return 0;
}