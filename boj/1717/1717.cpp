#include <stdio.h>
#define MAX_N 1000000
#define MAX_M 100000

int parent[MAX_N+1];
int childs[MAX_N+1];
int top_parent(int a){

        while(1){
                if(a!=parent[a]) a=parent[a];
                else break;
        }

        return a;
}

int main(void){

        int i, j, tmp;
        int n, m;
        int option, a, b;
        int a_top_parent, b_top_parent;
        scanf("%d %d", &n, &m);
        for(i=1; i<=n; i++){
                parent[i]=i;
                childs[i]=0;
        }

        for(i=1; i<=m; i++){
                scanf("%d %d %d", &option, &a, &b);
                if(option==0){
                        a_top_parent=top_parent(a);
                        b_top_parent=top_parent(b);
                        if(a_top_parent!=b_top_parent){
                                if(childs[a_top_parent]>=childs[b_top_parent]){
                                        parent[b_top_parent]=a_top_parent;
                                        childs[a_top_parent]++;
                                }
                                else{
                                        parent[a_top_parent]=b_top_parent;
                                        childs[b_top_parent]++;
                                }
                        }
                }

                else if(option==1){
                        if(top_parent(a)==top_parent(b)) printf("YES\n");
                        else printf("NO\n");
                }
        }

        return 0;
}