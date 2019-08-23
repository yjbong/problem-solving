#include <cstdio>
int N; // 원판의 개수
// move(n, from, to) : 크기가 1~n인 원판을 from번에서 to번 장대로 이동
void move(int n, int from, int to){
    if(from==to) return;
    if(n==1) {
        printf("%d %d\n", from, to);
        return;
    }
 
    int other=6-from-to; // 3개의 장대 중 from도 to도 아닌 장대
    move(n-1, from, other);
    printf("%d %d\n", from, to);
    move(n-1, other, to);
}
 
int main() {
    scanf("%d",&N);
    printf("%d\n",(1<<N)-1);
    move(N, 1, 3);
    return 0;
}