#include <stdio.h>
int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int main(void){

    int i,n,m,sol;
    int min_pack,min_one;
    int cur_pack,cur_one;
    int cost[7];
    scanf("%d %d", &n, &m);

    min_pack=min_one=-1;
    for(i=0; i<m; i++){
        scanf("%d %d", &cur_pack, &cur_one);
        if(min_pack<0 || min_pack>cur_pack) min_pack=cur_pack;
        if(min_one<0 || min_one>cur_one) min_one=cur_one;
    }

    cost[0]=0;
    for(i=1; i<=6; i++)
        cost[i]=min(min_one*i, min_pack);

    sol=cost[6]*(n/6)+cost[n%6];
    printf("%d\n", sol);
    return 0;
}