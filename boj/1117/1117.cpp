#include <cstdio>
typedef long long ll;
ll min(ll a, ll b){
	if(a<b) return a;
	else return b;
}

int main(void){
	ll w,h,f,c,x1,y1,x2,y2,sol;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&w,&h,&f,&c,&x1,&y1,&x2,&y2);
	
	ll double_x=min(f,w-f);
	ll double_s,double_e;
	if(double_x<x1){
		sol=w*h-(x2-x1)*(y2-y1)*(c+1);
	}
	else if(double_x>=x1 && double_x<=x2){
		double_s=x1, double_e=double_x;
		sol=w*h-(x2-x1)*(y2-y1)*(c+1)-(double_e-double_s)*(y2-y1)*(c+1);
	}
	else if(double_x>x2){
		double_s=x1, double_e=x2;
		sol=w*h-(x2-x1)*(y2-y1)*(c+1)-(double_e-double_s)*(y2-y1)*(c+1);
	}
	printf("%lld\n",sol);
	return 0;
}