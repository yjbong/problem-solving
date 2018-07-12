#include <cstdio>
#include <queue>
using namespace std;

int n; // 카드 묶음 수
priority_queue <int> pq;
int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int size;
		scanf("%d",&size);
		pq.push(-size);
	}

	int ans=0;
	while(pq.size()>=2){
		int min1=-pq.top(); // 가장 작은 카드 묶음
		pq.pop();
		int min2=-pq.top(); // 두번째로 작은 카드 묶음
		pq.pop();
		ans+=min1+min2;
		pq.push(-(min1+min2));
	}
	printf("%d\n",ans);
	return 0;
}