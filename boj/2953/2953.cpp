#include <cstdio>
int score[5];
int main(void){

	for(int i=0; i<5; i++){
		score[i]=0;
		for(int j=0; j<4; j++){
			int num;
			scanf("%d",&num);
			score[i]+=num;
		}
	}

	int win=0;
	for(int i=1; i<5; i++)
		if(score[i]>score[win]) win=i;
	printf("%d %d\n",win+1,score[win]);
	return 0;
}