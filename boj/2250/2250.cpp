#include <cstdio>
#define MAX_N 10000
typedef struct{
    int parent;
    int lChild;
    int rChild;
    int level;
    int nodes; // 해당 노드를 루트로 하는 트리에 속한 노드의 수(자신 포함)
    int pos;
} NODE;
int N; // 노드의 수
NODE node[MAX_N+1];
int root; // 루트 노드 번호
int maxLv;
int leftestPos[MAX_N+1]; // leftestPos[i] = 레벨 i에서 가장 왼쪽에 있는 노드의 위치
int rightestPos[MAX_N+1]; // leftestPos[i] = 레벨 i에서 가장 오른쪽에 있는 노드의 위치
 
void setLv(int idx, int curLv){
    node[idx].level=curLv;
    if(maxLv<curLv) maxLv=curLv;
    if(node[idx].lChild>=0) setLv(node[idx].lChild, curLv+1);
    if(node[idx].rChild>=0) setLv(node[idx].rChild, curLv+1);
}
 
int getNodes(int idx){
    int nodes=1;
    if(node[idx].lChild>=0) nodes+=getNodes(node[idx].lChild);
    if(node[idx].rChild>=0) nodes+=getNodes(node[idx].rChild);
    return node[idx].nodes=nodes;
}
 
void getPos(int idx, int addPos){
 
    int pos=1;
    if(node[idx].lChild>=0)
        pos+=node[node[idx].lChild].nodes;
 
    node[idx].pos=addPos+pos;
 
    if(node[idx].lChild>=0) getPos(node[idx].lChild, addPos);
    if(node[idx].rChild>=0) getPos(node[idx].rChild, node[idx].pos);
}

int main() {
    // 입력
    scanf("%d",&N);
    for(int i=1; i<=N; i++) node[i].parent=-1;
    for(int i=1; i<=N; i++){
        int n,l,r;
        scanf("%d %d %d",&n,&l,&r);
        node[n].lChild=l; node[n].rChild=r;
        if(l>=0) node[l].parent=n;
        if(r>=0) node[r].parent=n;
    }
 
    // 루트 노드 찾기
    for(int i=1; i<=N; i++)
        if(node[i].parent<0){ root=i; break; }
 
    // 각 노드의 레벨 및 위치 찾기
    maxLv=0;
    setLv(root, 1);
    getNodes(root);
    getPos(root, 0);
 
    /*
    for(int i=1; i<=N; i++){
        printf("node %d: p=%d, l=%d, r=%d, lv=%d, pos=%d\n",
                    i, node[i].parent, node[i].lChild, node[i].rChild, node[i].level, node[i].pos);
    }
    */
 
    // 너비 구하기
    for(int i=1; i<=N; i++){
        leftestPos[i]=N+1;
        rightestPos[i]=0;
    }
    for(int i=1; i<=N; i++){
        int curLv=node[i].level;
        int curPos=node[i].pos;
        if(leftestPos[curLv]>curPos) leftestPos[curLv]=curPos;
        if(rightestPos[curLv]<curPos) rightestPos[curLv]=curPos;
    }
 
    // 답 출력
    int ansLv=1, ansWidth=rightestPos[1]-leftestPos[1]+1;
    for(int i=2; i<=maxLv; i++){
        int curWidth=rightestPos[i]-leftestPos[i]+1;
        if(ansWidth<curWidth){ ansLv=i; ansWidth=curWidth; }
    }
    printf("%d %d\n", ansLv, ansWidth);
    return 0;
}