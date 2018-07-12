#include <cstdio>

typedef struct node{
    int idx1,lc,rc,pa,lv;
}NODE;
NODE v[4444];
char sq[4444];

int main(void){

    int n,x,y,vx,vy;
    scanf("%d",&n);
    scanf("%s",sq);
    scanf("%d %d",&x,&y);

    for(int i=0; i<=2*n; i++){
        v[i].idx1=-1;
        v[i].lc=-1;
        v[i].rc=-1;
        v[i].pa=-1;
        v[i].lv=-1;
    }

    int cpa=0;
    v[0].lv=0;

    for(int i=1; i<=n*2; i++){
        if(sq[i-1]=='0'){
            if(v[cpa].rc<0){
                v[cpa].rc=i;
                v[i].pa=cpa; v[i].lv=v[cpa].lv+1;
                cpa=i;
            }
            else{
                v[cpa].lc=i;
                v[i].pa=cpa; v[i].lv=v[cpa].lv+1;
                cpa=i;
            }
        }
        else{
            v[cpa].idx1=i;
            cpa=v[cpa].pa;
        }
    }

    if(sq[x-1]=='1'){
        for(int i=0; i<=n*2; i++){
            if((v[i].idx1)==x){
                vx=i;
                break;
            }
        }
    }
    else vx=x;

    if(sq[y-1]=='1'){
        for(int i=0; i<=n*2; i++){
            if((v[i].idx1)==y){
                vy=i;
                break;
            }
        }
    }
    else vy=y;

    int itr;
    if(v[vx].lv>v[vy].lv){
        itr=v[vx].lv-v[vy].lv;
        for(int i=0; i<itr; i++) vx=v[vx].pa;
    }
    else if(v[vy].lv>v[vx].lv){
        itr=v[vy].lv-v[vx].lv;
        for(int i=0; i<itr; i++) vy=v[vy].pa;
    }

    int sol_i,sol_j;
    while(1){
        if(vx==vy){
            sol_i=vx;
            sol_j=v[vx].idx1;
            break;
        }
        vx=v[vx].pa, vy=v[vy].pa;
    }
    printf("%d %d\n",sol_i,sol_j);
    return 0;
}