#include <cstdio>
#include <cstring>
#include <algorithm>
char num[81];

int main(void){
	int t;
	scanf("%d\n",&t);
	while(t--){
		gets(num);

		int n=strlen(num);
		bool biggest=true;

		for(int i=n-1; i>=0; i--){
			bool swap=false;
			int swapIdx=-1;
			for(int j=i+1; j<n; j++){
				if(num[i]<num[j]){
					if(swapIdx<0 || num[swapIdx]>num[j]){
						swap=true;
						swapIdx=j;
					}
				}
			}
			if(swap){
				biggest=false;
				char tmp=num[i];
				num[i]=num[swapIdx];
				num[swapIdx]=tmp;
				std::sort(num+i+1,num+n);
				break;
			}
		}
		if(biggest) printf("BIGGEST\n");
		else printf("%s\n",num);
	}
	return 0;
}