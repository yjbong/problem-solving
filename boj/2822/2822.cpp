#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int,int> ii;
ii score[8];
int ansList[5];
int main(void){
	for(int i=0; i<8; i++){
		scanf("%d",&score[i].first);
		score[i].second=i+1;
	}
	sort(score,score+8,greater<ii>());
	int ans=0;
	for(int i=0; i<5; i++){
		ans+=score[i].first;
		ansList[i]=score[i].second;
	}
	sort(ansList,ansList+5);
	printf("%d\n",ans);
	for(int i=0; i<5; i++) printf("%d ",ansList[i]);
	printf("\n");
	return 0;
}