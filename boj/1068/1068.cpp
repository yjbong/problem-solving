#include <stdio.h>
#define MAXNODE 50
typedef struct _node{
        int parent_idx;
        int child_num;
}NODE;

int main(void){

        int i;
        int nodes;
        int del_idx;
        int leaf_idx[MAXNODE], leaf_idxs;
        int cur_idx;
        int leaf_nodes;
        NODE node[MAXNODE];
        scanf("%d", &nodes);
        for(i=0; i<nodes; i++){
                scanf("%d", &(node[i].parent_idx));
                node[i].child_num=0;
        }

        for(i=0; i<nodes; i++)
                if(node[i].parent_idx>=0) node[node[i].parent_idx].child_num++;

        for(i=0, leaf_idxs=0; i<nodes; i++){
                if(node[i].child_num==0){
                        leaf_idx[leaf_idxs]=i;
                        leaf_idxs++;
                }
        }

        leaf_nodes=leaf_idxs;

        scanf("%d", &del_idx);
        if(node[del_idx].parent_idx>=0){
                node[node[del_idx].parent_idx].child_num--;
                if(node[node[del_idx].parent_idx].child_num==0) leaf_nodes++;
        }

        for(i=0; i<leaf_idxs; i++){
                cur_idx=leaf_idx[i];
                while(cur_idx>=0){
                        if(cur_idx==del_idx) leaf_nodes--;
                        cur_idx=node[cur_idx].parent_idx;
                }
        }

        printf("%d\n", leaf_nodes);
        return 0;
}