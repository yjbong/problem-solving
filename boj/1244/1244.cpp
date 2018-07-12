#include <cstdio>
int n; // # of switches
int s[111]; // switch status
int m; // # of students
int main(void){

	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&s[i]);
	scanf("%d",&m);
	for(int i=1; i<=m; i++){
		int type, num;
		scanf("%d %d",&type,&num);
		if(type==1){
			for(int j=num; j<=n; j+=num) s[j]=1-s[j];
		}
		else if(type==2){
			s[num]=1-s[num];
			for(int j=1; num-j>=1 && num+j<=n; j++){
				if(s[num-j]==s[num+j]){
					s[num-j]=1-s[num-j];
					s[num+j]=1-s[num+j];
				}
				else break;
			}
		}
	}

	for(int i=1; i<=n; i++){
		printf("%d ",s[i]);
		if(i%20==0 && i<n) printf("\n");
	}
	printf("\n");
	return 0;
}