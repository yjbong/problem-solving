#include <cstdio>
#define PERIODS 90/5

// d[i][j][k] = probability Team A gains i goals and Team B gains j goals within i*5 mins
double d[PERIODS+1][PERIODS+1][PERIODS+1];

double pa; //  probability Team A gains 1 goal within 5 mins
double pb; //  probability Team B gains 1 goal within 5 mins
bool p[PERIODS+1]; // p[i]=false if i is prime

int main(void){

	// check prime number
	p[0]=p[1]=true;
	for(int i=2; i<=PERIODS; i++)
		if(!p[i]) for(int j=i*2; j<=PERIODS; j+=i) p[j]=true;
	
	// input
	scanf("%lf %lf",&pa,&pb);
	pa *= 0.01;
	pb *= 0.01;

	// DP
	d[0][0][0]=1;
	for(int i=1; i<=PERIODS; i++){
		for(int j=0; j<=i; j++){
			for(int k=0; k<=i; k++){
				d[i][j][k]=0;
				if(j>=1 && k>=1) d[i][j][k] += d[i-1][j-1][k-1]*pa*pb;
				if(j>=1) d[i][j][k] += d[i-1][j-1][k]*pa*(1-pb);
				if(k>=1) d[i][j][k] += d[i-1][j][k-1]*(1-pa)*pb;
				d[i][j][k] += d[i-1][j][k]*(1-pa)*(1-pb);
			}
		}
	}

	// answer
	double ans=0;
	for(int j=0; j<=PERIODS; j++)
		for(int k=0; k<=PERIODS; k++)
			if(!p[j] || !p[k]) ans += d[PERIODS][j][k];
	printf("%.16lf\n",ans);
	return 0;
}