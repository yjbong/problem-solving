#include <stdio.h>
#include <math.h>
int sum[262144];
int main(void){

        int i,j, N, M;
        int nearest_pow;
        int result_sum;
        int cur_idx, result_idx, tmp_idx, tmp, remains;
        scanf("%d %d", &N, &M);

        i=1;
        while(i<N) i*=2;
        nearest_pow=i;

        for(i=nearest_pow; i<nearest_pow*2; i++){
                if(i-nearest_pow+1<=N) sum[i]=1;
                else sum[i]=0;
        }

        for(i=nearest_pow-1; i>=1; i--) sum[i]=sum[i*2]+sum[i*2+1];

        remains=N;
        cur_idx=M;
        while(remains>0){

                if(cur_idx>sum[1]){
                        cur_idx%=sum[1];
                        if(cur_idx==0) cur_idx=sum[1];
                }

                tmp_idx=1;
                tmp=cur_idx;
                while(tmp_idx<nearest_pow){
                        if(tmp<=sum[tmp_idx*2]) tmp_idx=tmp_idx*2;
                        else{
                                tmp-=sum[tmp_idx*2];
                                tmp_idx=tmp_idx*2+1;
                        }
                }

                result_idx=tmp_idx;

                if(remains==N) printf("<");
                printf("%d", result_idx-nearest_pow+1);
                if(remains==1) printf(">\n");
                else printf(", ");

                sum[result_idx]=0;
                while(1){

                        result_idx/=2;
                        if(result_idx<1) break;
                        sum[result_idx]=sum[result_idx*2]+sum[result_idx*2+1];
                }

                cur_idx=cur_idx+M-1;
                remains--;
        }

        return 0;
}