#include <cstdio>
int n;
int q1,q2,q3,q4,axis;
int main(void){
	q1=q2=q3=q4=axis=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x>0 && y>0) q1++;
		else if(x<0 && y>0) q2++;
		else if(x<0 && y<0) q3++;
		else if(x>0 && y<0) q4++;
		else axis++;
	}
	printf("Q1: %d\n",q1);
	printf("Q2: %d\n",q2);
	printf("Q3: %d\n",q3);
	printf("Q4: %d\n",q4);
	printf("AXIS: %d\n",axis);
	return 0;
}