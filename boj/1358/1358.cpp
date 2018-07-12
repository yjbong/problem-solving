#include <stdio.h>
int main(void){

    int w,h,x,y,p,curx,cury;
    int cx1,cy1,cx2,cy2,d1,d2;
    int ok1,ok2,ok3;
    int sol=0;
    scanf("%d %d %d %d %d",&w,&h,&x,&y,&p);
    cx1=x,cy1=y+h/2;
    cx2=x+w,cy2=y+h/2;
    while(p--){
        scanf("%d %d",&curx,&cury);
        if(curx>=x && curx<=x+w && cury>=y && cury<=y+h) ok1=1;
        else ok1=0;

        d1=(curx-cx1)*(curx-cx1)+(cury-cy1)*(cury-cy1);
        if(d1<=(h/2)*(h/2)) ok2=1;
        else ok2=0;

        d2=(curx-cx2)*(curx-cx2)+(cury-cy2)*(cury-cy2);
        if(d2<=(h/2)*(h/2)) ok3=1;
        else ok3=0;

        if(ok1||ok2||ok3) sol++;
    }
    printf("%d\n",sol);
    return 0;
}