#include <stdio.h>
#define MAX_SONGS 100
#define MAX_M 1000
int vol_possible[MAX_SONGS+1][MAX_M+1];
int vol_diff_list[MAX_SONGS];
int main(void){

        int i, j;
        int songs, start_vol, m;
        int cur_possible_vol, max_possible_vol;
        scanf("%d %d %d", &songs, &start_vol, &m);
        for(i=0; i<songs; i++) scanf("%d", &vol_diff_list[i]);

        for(i=0; i<=songs; i++)
                for(j=0; j<=m; j++)
                        vol_possible[i][j]=0;

        vol_possible[0][start_vol]=1;
        max_possible_vol=-1;
        for(i=1; i<=songs; i++){
                for(j=0; j<=m; j++){
                        if(vol_possible[i-1][j]==1){
                                if(j+vol_diff_list[i-1]<=m){
                                        vol_possible[i][j+vol_diff_list[i-1]]=1;
                                        if(i==songs && max_possible_vol<j+vol_diff_list[i-1]) max_possible_vol=j+vol_diff_list[i-1];
                                }

                                if(j-vol_diff_list[i-1]>=0){
                                        vol_possible[i][j-vol_diff_list[i-1]]=1;
                                        if(i==songs && max_possible_vol<j-vol_diff_list[i-1]) max_possible_vol=j-vol_diff_list[i-1];
                                }
                        }
                }
        }

        printf("%d\n", max_possible_vol);
        return 0;
}