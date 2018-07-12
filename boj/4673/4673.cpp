#include <cstdio>
bool isNotSelfNumber[10001];
int main(void){
	for(int i=1; i<=10000; i++){
		if(!isNotSelfNumber[i]){
			int num=i;
			do{
				int dgtSum=0;
				int tmp=num;
				while(tmp>0){ dgtSum+=tmp%10; tmp/=10; }
				num+=dgtSum;
				if(num<=10000) isNotSelfNumber[num]=true;
			}while(num<=10000);
		}
	}
	for(int i=1; i<=10000; i++)
		if(!isNotSelfNumber[i]) printf("%d\n",i);
	return 0;
}