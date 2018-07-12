#include <cstdio>
#include <cstdlib>
int N; // 줄의 개수
int now[1000];
int goal[1000];
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&now[i]);
	for(int i=0; i<N; i++) scanf("%d",&goal[i]);

	int ans=0;
	bool go;
	do{
		go=false;
		for(int i=0; i<N; i++){
			int diff=goal[i]-now[i];
			if(diff>0){
				go=true;
				int j;
				for(j=i; j<N; j++){
					int curDiff=goal[j]-now[j];
					if(curDiff>0){
						if(diff>curDiff) diff=curDiff;
					}
					else break;
				}
				for(int k=i; k<j; k++) now[k]+=diff;
				ans+=abs(diff);
				break;
			}
			else if(diff<0){
				go=true;
				int j;
				for(j=i; j<N; j++){
					int curDiff=goal[j]-now[j];
					if(curDiff<0){
						if(diff<curDiff) diff=curDiff;
					}
					else break;
				}
				for(int k=i; k<j; k++) now[k]+=diff;
				ans+=abs(diff);
				break;
			}
		}
	}while(go);

	printf("%d\n",ans);
	return 0;
}