#include <cstdio>

int main(void){
	int a[10];
	int b[10];

	for(int i=0; i<10; i++) scanf("%d",&a[i]);
	for(int i=0; i<10; i++) scanf("%d",&b[i]);

	char lastWinner='D';
	int ascore=0;
	int bscore=0;
	for(int i=0; i<10; i++){
		if(a[i]>b[i]){ // i번 라운드를 A가 이김
			ascore+=3;
			lastWinner='A';
		}
		else if(a[i]<b[i]){ // i번 라운드를 B가 이김
			bscore+=3;
			lastWinner='B';
		}
		else{ // i번 라운드를 비김
			ascore++;
			bscore++;
		}
	}

	printf("%d %d\n",ascore,bscore);
	if(ascore>bscore) printf("A\n");
	else if(ascore<bscore) printf("B\n");
	else printf("%c\n",lastWinner); // 동점인 경우 마지막에 이긴 사람을 출력

	return 0;
}