#include <cstdio>

int cases,tasks,edges;
int indeg[26];
int outdeg[26];
int outtask[26][26];
bool check[26];

int main(void){

    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&tasks,&edges);
        for(int i=0; i<tasks; i++){
            indeg[i]=outdeg[i]=0;
            check[i]=false;
        }
        for(int i=0; i<edges; i++){
            char tmp[5];
            scanf("%s",tmp);
            int from=tmp[0]-'A',to=tmp[1]-'A';
            outtask[from][outdeg[from]++]=to;
            indeg[to]++;
        }

        bool go;
        do{
            go=false;
            for(int i=0; i<tasks; i++){
                if(!check[i] && indeg[i]==0){
                    printf("%c",i+'A');
                    go=true;
                    check[i]=true;
                    for(int j=0; j<outdeg[i]; j++)
                        indeg[outtask[i][j]]--;
                    break;
                }
            }
        }while(go);
        printf("\n");
    }
    return 0;
}