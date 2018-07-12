#include <cstdio>
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int hp,mp,atk,def;
		int hp2,mp2,atk2,def2;
		scanf("%d %d %d %d %d %d %d %d",&hp,&mp,&atk,&def,&hp2,&mp2,&atk2,&def2);
		hp+=hp2; if(hp<1) hp=1;
		mp+=mp2; if(mp<1) mp=1;
		atk+=atk2; if(atk<0) atk=0;
		def+=def2;
		int ans=1*hp+5*mp+2*atk+2*def;
		printf("%d\n",ans);
	}
	return 0;
}