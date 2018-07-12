#include <stdio.h>
#define LEFT_CHILD 0
#define RIGHT_CHILD 1
int node[26][2];
int nodes;
void preorder(int node_idx){

        if(node_idx>=0){
                printf("%c", node_idx+'A');
                preorder(node[node_idx][LEFT_CHILD]);
                preorder(node[node_idx][RIGHT_CHILD]);
        }
}

void inorder(int node_idx){

        if(node_idx>=0){
                inorder(node[node_idx][LEFT_CHILD]);
                printf("%c", node_idx+'A');
                inorder(node[node_idx][RIGHT_CHILD]);
        }
}

void postorder(int node_idx){

        if(node_idx>=0){
                postorder(node[node_idx][LEFT_CHILD]);
                postorder(node[node_idx][RIGHT_CHILD]);
                printf("%c", node_idx+'A');
        }
}

int main(void){
        int i;
        char a,b,c;
        char line[10];
        scanf("%d\n", &nodes);

        for(i=0; i<nodes; i++){
                scanf("%c %c %c\n", &a, &b, &c);
                if(b=='.') node[a-'A'][LEFT_CHILD]=-1;
                else node[a-'A'][LEFT_CHILD]=b-'A';

                if(c=='.') node[a-'A'][RIGHT_CHILD]=-1;
                else node[a-'A'][RIGHT_CHILD]=c-'A';
        }

        preorder(0);
        printf("\n");
        inorder(0);
        printf("\n");
        postorder(0);
        printf("\n");

        return 0;
}