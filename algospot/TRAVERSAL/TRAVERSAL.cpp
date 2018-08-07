#include <cstdio>
int c,n;
int pre[111]; int preidx[1111];
int in[111]; int inidx[1111];
int findnum;

int find(int i){
    return inidx[pre[i]];
}
void go(int i, int j){
    int cur_root=find(findnum++);
    if(i==j){
        printf("%d ",in[i]);
        return;
    }
    if(cur_root>i) go(i,cur_root-1);
    if(cur_root<j) go(cur_root+1,j);
    printf("%d ",in[cur_root]);
}
int main(void){

    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&pre[i]);
            preidx[pre[i]]=i;
        }
        for(int i=0; i<n; i++){
            scanf("%d",&in[i]);
            inidx[in[i]]=i;
        }
        findnum=0;
        go(0,n-1);
        printf("\n");
    }
    return 0;
}