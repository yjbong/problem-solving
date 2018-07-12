#include <stdio.h>
#include <stdlib.h>
int ho[200000];
int cmp(const void *a, const void *b){

        if(*((int*)a)>*((int*)b)) return 1;
        else return 0;
}

int main(void){

        int i,n,c;
        int left,right,mid,cur,cur_c,ok,sol;
        scanf("%d %d",&n,&c);
        for(i=0; i<n; i++) scanf("%d",&ho[i]);
        qsort(ho,n,sizeof(int),cmp);

        left=1,right=ho[n-1];
        while(left<=right){
                mid=(left+right)/2;
                cur_c=c;
                cur=ho[0], cur_c--;
                for(i=1; i<n; i++){
                        if(ho[i]-cur>=mid) cur=ho[i], cur_c--;
                        if(cur_c==0) break;
                }

                if(cur_c==0) left=mid+1, sol=mid;
                else right=mid-1;
        }
        printf("%d\n",sol);
        return 0;
}