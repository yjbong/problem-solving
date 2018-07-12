#include <cstdio>
int n; // 한 변의 길이 (2^n 꼴)
int paper[128][128];
int whites;
int blues;

void go(int topleftY, int topleftX, int size){

	bool allWhite=true;
	for(int i=topleftY; i<topleftY+size; i++){
		for(int j=topleftX; j<topleftX+size; j++){
			if(paper[i][j]!=0){
				allWhite=false;
				break;
			}
		}
	}
	if(allWhite){ whites++; return; }

	bool allBlue=true;
	for(int i=topleftY; i<topleftY+size; i++){
		for(int j=topleftX; j<topleftX+size; j++){
			if(paper[i][j]!=1){
				allBlue=false;
				break;
			}
		}
	}
	if(allBlue){ blues++; return; }

	go(topleftY, topleftX, size/2);
	go(topleftY+size/2, topleftX, size/2);
	go(topleftY, topleftX+size/2, size/2);
	go(topleftY+size/2, topleftX+size/2, size/2);
}
int main(void){
	// 입력
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&paper[i][j]);
	// D&C
	go(0,0,n);
	// 출력
	printf("%d\n%d\n",whites,blues);
	
	return 0;
}