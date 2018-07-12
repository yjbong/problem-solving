#include <stdio.h>
int candies[2097152];
int nearpow;

int get_pos(int n){

    int cur_idx, tmp_idx;

    cur_idx=n;
    tmp_idx=1;
    while(tmp_idx<nearpow){
        if(cur_idx<=candies[tmp_idx*2]) tmp_idx=tmp_idx*2;
        else{
            cur_idx-=candies[tmp_idx*2];
            tmp_idx=tmp_idx*2+1;
        }
    }
    return tmp_idx-nearpow+1;
}

void update(int chng_idx){

    int tmp_idx;
    tmp_idx=chng_idx/2;
    while(tmp_idx>=1){
        candies[tmp_idx]=candies[tmp_idx*2]+candies[tmp_idx*2+1];
        tmp_idx/=2;
    }
}

int main(void){

    int i;
    int chngs;
    int op;
    int cur_candy, cur_rank;
    int chng_idx;
    int chng_qty;

    nearpow=1048576;
    for(i=nearpow; i<nearpow*2; i++) candies[i]=0;
    for(i=nearpow-1; i>=1; i--) candies[i]=candies[i*2]+candies[i*2+1];

    scanf("%d", &chngs);
    while(chngs--){
        scanf("%d", &op);
        if(op==1){
            scanf("%d", &cur_rank);
            cur_candy=get_pos(cur_rank);
            printf("%d\n", cur_candy);
            chng_idx=cur_candy-1+nearpow;
            candies[chng_idx]--;
            update(chng_idx);
        }
        else if(op==2){
            scanf("%d %d", &cur_candy, &chng_qty);
            chng_idx=cur_candy-1+nearpow;
            candies[chng_idx]+=chng_qty;
            update(chng_idx);
        }
    }
    return 0;
}