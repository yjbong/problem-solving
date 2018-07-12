#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct{
	long long y;
	long long x;
}POINT;
int main(void){

	int T;
	scanf("%d",&T);
	while(T--){
		POINT point[4];
		for(int i=0; i<4; i++) scanf("%lld %lld",&point[i].y,&point[i].x);
		int perm[4];
		for(int i=0; i<4; i++) perm[i]=i;

		bool ok=false;
		do{
			bool curOk=true;

			// 각 변의 길이가 같은지 확인
			long long side=(point[perm[0]].y-point[perm[1]].y)*(point[perm[0]].y-point[perm[1]].y)+(point[perm[0]].x-point[perm[1]].x)*(point[perm[0]].x-point[perm[1]].x);
			for(int i=1; i<4; i++){
				long long curSide=(point[perm[i]].y-point[perm[(i+1)%4]].y)*(point[perm[i]].y-point[perm[(i+1)%4]].y)+(point[perm[i]].x-point[perm[(i+1)%4]].x)*(point[perm[i]].x-point[perm[(i+1)%4]].x);
				if(curSide!=side){ curOk=false; break; }
			}
			// 대각선 길이가 같은지 확인
			long long diag0=(point[perm[0]].y-point[perm[2]].y)*(point[perm[0]].y-point[perm[2]].y)+(point[perm[0]].x-point[perm[2]].x)*(point[perm[0]].x-point[perm[2]].x);
			long long diag1=(point[perm[1]].y-point[perm[3]].y)*(point[perm[1]].y-point[perm[3]].y)+(point[perm[1]].x-point[perm[3]].x)*(point[perm[1]].x-point[perm[3]].x);
			if(diag0!=diag1) curOk=false;

			if(curOk){ ok=true; break; }

		}while(next_permutation(perm,perm+4));

		if(ok) printf("1\n");
		else printf("0\n");
	}
	return 0;
}