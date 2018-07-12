#include <cstdio>
#include <algorithm>
int main(void){
	int a[3];
	for(int i=0; i<3; i++) scanf("%d",&a[i]);
	std::sort(a,a+3);

	int maxSames=1;
	int maxSameNum=a[0];

	int curSames=1;
	int curSameNum=a[0];
	for(int i=1; i<3; i++){
		if(a[i]==a[i-1]) curSames++;
		else{
			if(maxSames<=curSames){
				maxSames=curSames;
				maxSameNum=curSameNum;
			}
			curSames=1;
			curSameNum=a[i];
		}
	}
	if(maxSames<=curSames){
		maxSames=curSames;
		maxSameNum=curSameNum;
	}

	int ans;
	if(maxSames==3) ans=10000+maxSameNum*1000;
	else if(maxSames==2) ans=1000+maxSameNum*100;
	else if(maxSames==1) ans=maxSameNum*100;
	printf("%d\n",ans);
	return 0;
}