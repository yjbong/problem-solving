#include <cstdio>
int d[100000/2+1]; // d[i]=1 if there's a subset of coins with sum of value = i
int cs; // # of kinds of coin
int c[100][2]; // c[i][0] = i-th coin's value, c[i][1] = i-th coin's quantity
int new_cs; // # of new coins
int new_c[1000]; // new_c[i] = i-th new coin's value

int main(void){

        while(scanf("%d",&cs)==1){

                int total_sum=0, ans=0;

                for(int i=0; i<cs; i++){
                        scanf("%d %d",&c[i][0],&c[i][1]);
                        total_sum += c[i][0]*c[i][1];
                }

                if(total_sum%2==0){ // total_sum should be even num
                        // make array new_c
                        new_cs=0;
                        for(int i=0; i<cs; i++){
                                int j=0;
                                while(c[i][1]>=(1<<j)){
                                        new_c[new_cs++]=c[i][0]*(1<<j);
                                        c[i][1]-=(1<<j);
                                        j++;
                                }
                                if(c[i][1]>0) new_c[new_cs++]=c[i][0]*c[i][1];
                        }

                        // init array d
                        d[0]=1;
                        for(int i=1; i<=total_sum/2; i++) d[i]=0;

                        // run DP
                        for(int i=1; i<=total_sum/2; i++){
                                for(int j=0; j<new_cs; j++){
                                        if(i-new_c[j]>=0 && d[i-new_c[j]]){
                                                d[i]=1;
                                                break;
                                        }
                                }
                        }
                        if(d[total_sum/2]) ans=1;
                }
                printf("%d\n",ans);
        }
        return 0;
}