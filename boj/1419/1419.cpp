#include <stdio.h>
int main(void){

    int l,r,k,s;
    scanf("%d %d %d",&l,&r,&k);
    if(k==2){
        if(r<3) s=0;
        else{
            s=r-l+1;
            if(l==1) s-=2;
            else if(l==2) s-=1;
        }
    }
    else if(k==3){
        if(r<6) s=0;
        else{
            s=r/3-(l-1)/3;
            if(l<=3) s-=1;
        }
    }
    else if(k==4){
        if(r<10) s=0;
        else{
            s=r/2-(l-1)/2;
            if(l<=2) s-=4;
            else if(l<=4) s-=3;
            else if(l<=6) s-=2;
            else if(l<=8) s-=1;
            if(l<=12 && r>=12) s-=1;
        }
    }
    else if(k==5){
        if(r<15) s=0;
        else{
            s=r/5-(l-1)/5;
            if(l<=5) s-=2;
            else if(l<=10) s-=1;
        }
    }
    printf("%d\n",s);
    return 0;
}