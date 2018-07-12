#include <cstdio>
int N; // 바구니 수
int M; // 회전 수
int order[101]; // order[i] = 왼쪽에서부터 i번째에 있는 바구니의 번호
int tmp[100];
int tmps;

void rotate(int begin, int end, int mid){
	tmps=0;
	for(int i=mid; i<=end; i++) tmp[tmps++]=order[i];

	for(int i=mid-1; i>=begin; i--) order[i+end-mid+1]=order[i];
	for(int i=begin; i<begin+tmps; i++) order[i]=tmp[i-begin];
}

int main(void){
	scanf("%d %d",&N,&M);
	for(int t=1; t<=N; t++) order[t]=t;
	for(int t=0; t<M; t++){
		int i,j,k;
		scanf("%d %d %d",&i,&j,&k);
		rotate(i,j,k);	
	}
	for(int i=1; i<=N; i++) printf("%d ",order[i]);
	printf("\n");
	return 0;
}