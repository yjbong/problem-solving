#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUMS 100000
#define MAXLEN 20
int num[MAXNUMS];
int int_cmp(const void *a, const void* b){
        if(*((int*)a)>*((int*)b)) return 1;
        else return 0;
}

int main(void){

        int i, left, right, mid;
        int nums;
        int queries, cur_query, is_found;
        scanf("%d", &nums);
        for(i=0; i<nums; i++) scanf("%d", &num[i]);

        qsort(num, nums, sizeof(int), int_cmp);

        scanf("%d", &queries);

        while(queries--){
                scanf("%d", &cur_query);
                is_found=0;
                left=0, right=nums-1;
                while(left<=right){
                        mid=(left+right)/2;
                        if(num[mid]<cur_query) left=mid+1;
                        else if(num[mid]>cur_query) right=mid-1;
                        else{
                                is_found=1;
                                break;
                        }
                }
                printf("%d\n", is_found);
        }
        return 0;
}