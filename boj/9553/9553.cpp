#include <cstdio>
#include <cmath>
int cases;
int targets;

double angle(double x, double y){ // return radian angle between [0,2*PI)

	if(x==0 && y==0) return 0;
	else if(x==0 && y>0) return M_PI*0.5;
	else if(x==0 && y<0) return M_PI*1.5;

	else if(x>0 && y>=0) return atan(y/x);
	else if(x<0 && y>=0) return (M_PI+atan(y/x));
	else if(x<0 && y<=0) return (M_PI+atan(y/x));
	else if(x>0 && y<=0) return (2*M_PI+atan(y/x));
}

int main(void){

	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&targets);
		double ans=0.0;
		for(int i=0; i<targets; i++){

			double x1,y1,x2,y2;
			double range;
			scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
			if((x1==0 && y1==0) || (x2==0 && y2==0)){
				range=2*M_PI;
			}
			else{
				double start_angle = angle(x1,y1);
				double end_angle = angle(x2,y2);

				range = fabs(end_angle-start_angle);
				if(range>M_PI) range=2*M_PI-range;
			}

			ans+=range;
		}
		ans/=(2*M_PI);
		printf("%.5lf\n",ans);
	}
	
	return 0;
}