#include <stdio.h>

int vs, es, src;
int e[1001][1001];
int vst[1001];
int vsts;
int q[1001];
int q_frt, q_end;

void dfs(int idx){
    int i;
    vst[idx]=1;
    vsts++;
    printf("%d", idx);
    if(vsts<vs) printf(" ");
    else printf("\n");
    for(i=1; i<=vs; i++){
        if(e[idx][i]==1 && vst[i]==0) dfs(i);
    }
}

int main(void){

    int i,j;
    int a,b;
    scanf("%d %d %d", &vs, &es, &src);

    for(i=0; i<=vs; i++)
        for(j=0; j<=vs; j++) e[i][j]=0;
    for(i=0; i<=vs; i++) vst[i]=0;

    for(i=0; i<es; i++){
        scanf("%d %d", &a, &b);
        if(a!=b){
            e[a][b]=1;
            e[b][a]=1;
        }
    }

    vsts=0;
    dfs(src);

    vsts=0;
    for(i=0; i<=vs; i++) vst[i]=0;
    vst[src]=1;
    vsts++;
    printf("%d ", src);
    q_frt=0, q_end=1;
    q[0]=src;

    while(q_frt<q_end){
        for(i=1; i<=vs; i++){
            if(e[q[q_frt]][i]==1 && vst[i]==0){
                vst[i]=1;
                vsts++;
                printf("%d", i);
                if(vsts<vs) printf(" ");
                q[q_end]=i;
                q_end++;
            }
        }
        q_frt++;
    }
    printf("\n");

    return 0;
}