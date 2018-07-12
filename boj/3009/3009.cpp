#include <cstdio>
#include <utility>
using namespace std;
pair<int,int> p[3];
int smallX,bigX;
int smallY,bigY;

int main(void){
	for(int i=0; i<3; i++) scanf("%d %d",&p[i].first,&p[i].second);

	smallX=1001, bigX=0;
	smallY=1001, bigY=0;
	for(int i=0; i<3; i++){
		if(smallX>p[i].first) smallX=p[i].first;
		if(bigX<p[i].first) bigX=p[i].first;
		if(smallY>p[i].second) smallY=p[i].second;
		if(bigY<p[i].second) bigY=p[i].second;
	}
	int smallXcnt=0, bigXcnt=0, smallYcnt=0, bigYcnt=0;
	for(int i=0; i<3; i++){
		if(p[i].first==smallX) smallXcnt++;
		if(p[i].first==bigX) bigXcnt++;
		if(p[i].second==smallY) smallYcnt++;
		if(p[i].second==bigY) bigYcnt++;
	}
	if(smallXcnt==1) printf("%d ",smallX);
	else printf("%d ",bigX);
	if(smallYcnt==1) printf("%d ",smallY);
	else printf("%d ",bigY);
	printf("\n");
	return 0;
}