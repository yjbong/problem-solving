#include <stdio.h>
#define MAXNUMS 50
int main(void){

        int i,j,nums,result;
        int a[MAXNUMS], a_rank[MAXNUMS];
        int b[MAXNUMS], b_rank[MAXNUMS];

        scanf("%d", &nums);
        for(i=0; i<nums; i++) scanf("%d", &a[i]);
        for(i=0; i<nums; i++) scanf("%d", &b[i]);

        for(i=0; i<nums; i++) a_rank[i]=0;
        for(i=0; i<nums; i++){
                for(j=0; j<=i; j++){
                        if(a[i]>=a[j]) a_rank[i]++;
                        else a_rank[j]++;
                }
        }

        for(i=0; i<nums; i++) b_rank[i]=0;
        for(i=0; i<nums; i++){
                for(j=0; j<=i; j++){
                        if(b[i]<=b[j]) b_rank[i]++;
                        else b_rank[j]++;
                }
        }

        result=0;
        for(i=0; i<nums; i++){
                for(j=0; j<nums; j++){
                        if(a_rank[i]==b_rank[j]){
                                result += a[i]*b[j];
                                break;
                        }
                }
        }
        printf("%d\n", result);
        return 0;
}