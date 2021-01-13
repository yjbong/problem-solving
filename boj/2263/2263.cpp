#include <cstdio>
#define MAXN 100000
 
int N; // 이진트리의 정점 개수
int inorder[MAXN];
int postorder[MAXN];
int pos[MAXN+1]; // pos[i]=수 i가 inorder에 있는 위치
 
void preorder(int left, int right){
    if(left>right) return;
    int root=postorder[right];
    printf("%d ", root); // 루트
 
    if(left<right){
        int l=left, r=right-1;
        int rightmostL=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(pos[postorder[m]]<pos[root]){
                if(rightmostL<m) rightmostL=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }  
        preorder(left,rightmostL);
        preorder(rightmostL+1, right-1);
   }
}
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&inorder[i]);
        pos[inorder[i]]=i;
    }
    for(int i=0; i<N; i++) scanf("%d",&postorder[i]);
    preorder(0,N-1);
    return 0;
}