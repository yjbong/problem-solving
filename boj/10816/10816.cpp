#include <cstdio>
#include <map>
using namespace std;

int N; // 숫자 카드의 개수
int M; // 질문의 개수
map<int,int> card; // first=카드 숫자, second=동일한 숫자의 개수

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int num;
		scanf("%d",&num);
		map<int,int>::iterator it=card.find(num);
		// map에 num에 해당하는 데이터가 없는 경우
		if(it==card.end()) card.insert(make_pair(num,1));
		// 해당하는 데이터가 있는 경우 숫자 개수만 1 증가
		else it->second++;
	}

	scanf("%d",&M);
	for(int i=0; i<M; i++){
		int num;
		scanf("%d",&num);
		map<int,int>::iterator it=card.find(num);
		// map에 num에 해당하는 데이터가 없는 경우
		if(it==card.end()) printf("0 ");
		// 해당하는 데이터가 있는 경우 그 개수를 출력
		else printf("%d ",it->second);
	}
	printf("\n");
	return 0;
}