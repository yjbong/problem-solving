#include <cstdio>
#define MAX_M 1000
typedef long long ll;
int T; // �׽�Ʈ ���̽� ��
ll N, M;
ll check[MAX_M][MAX_M]; // check[x][y] = ���� �� ��(Si-1, Si-2)�� M���� ���� �������� ���� x, y�� �� ���� i��
  
int main() {
    scanf("%d",&T);
    for(int z=1; z<=T; z++){
        scanf("%lld %lld",&N,&M);
        printf("#%d ", z);
        if(M==1) { printf("0\n"); continue; }
        else if(N<=1){ printf("%lld\n", N); continue; }
 
        // check �ʱ�ȭ
        for(int i=0; i<M; i++)
            for(int j=0; j<M; j++) check[i][j]=-1;
  
        ll bfr2; // Si-2�� M���� ���� ������
        ll bfr1; // Si-1�� M���� ���� ������
  
        // �ֱ� Ȯ��
        ll start; // �ֱⰡ �����ϴ� i
        ll length; // �ֱ��� ����
        bfr2=0;
        bfr1=1;
        for(ll i=2; ; i++){
            if(check[bfr1][bfr2]>=0) {
                //printf("S%lld and S%lld are same!\n", check[bfr1][bfr2], i);
                start=check[bfr1][bfr2];
                length=i-start;
                break;
            }
            check[bfr1][bfr2]=i;
            ll now=(bfr1*bfr1*bfr1+bfr2*bfr2*bfr2)%M;
            bfr2=bfr1;
            bfr1=now;
        }
  
        // �ֱ⼺�� �̿��ؼ� N���� ���
        if(N>=start){
            N%=length;
            while(N<start) N+=length;
        }
  
        // ������ N��° �� ���
        bfr2=0;
        bfr1=1;
        for(ll i=2; i<=N; i++){
            ll now=(bfr1*bfr1*bfr1+bfr2*bfr2*bfr2)%M;
            if(i==N) printf("%lld\n", now);
            bfr2=bfr1;
            bfr1=now;
        }
    }
  
    return 0;
}