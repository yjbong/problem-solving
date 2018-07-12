#include <cstdio>
typedef struct{
	double x;
	double y;
}COORD;
COORD one[3];
COORD two[3];

int score(COORD a){
	double dist=a.x*a.x+a.y*a.y; // 거리의 제곱
	if(dist<=9.0) return 100;
	else if(dist<=36.0) return 80;
	else if(dist<=81.0) return 60;
	else if(dist<=144.0) return 40;
	else if(dist<=225.0) return 20;
	else return 0;
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0; i<3; i++) scanf("%lf %lf",&one[i].x,&one[i].y);
		for(int i=0; i<3; i++) scanf("%lf %lf",&two[i].x,&two[i].y);

		int onescore=0, twoscore=0;
		for(int i=0; i<3; i++) onescore+=score(one[i]);
		for(int i=0; i<3; i++) twoscore+=score(two[i]);

		printf("SCORE: %d to %d, ",onescore,twoscore);
		if(onescore>twoscore) printf("PLAYER 1 WINS.\n");
		else if(onescore<twoscore) printf("PLAYER 2 WINS.\n");
		else printf("TIE.\n");
	}
	return 0;
}