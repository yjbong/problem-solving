#include <cstdio>
#include <cstdlib>
#include <cstring>
int r,c;
int zr,zc;

char news[50+1][50+1];
char zoomnews[50*5+1][50*5+1];
int main(void){

	// 입력
	scanf("%d %d %d %d\n",&r,&c,&zr,&zc);
	for(int i=0; i<r; i++) gets(news[i]);
	// zr*zc배 확대
	for(int i=0; i<r*zr; i++){
		for(int j=0; j<c*zc; j++)
			zoomnews[i][j]=news[i/zr][j/zc];
		zoomnews[i][c*zc]='\0';
	}
	// 출력
	for(int i=0; i<r*zr; i++) printf("%s\n",zoomnews[i]);
	
	return 0;
}