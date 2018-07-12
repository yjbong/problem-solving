#include <cstdio>
#include <cstring>
char k[3],s[3];
int ky, kx;
int sy, sx;
int n;
int main(void){

    scanf("%s %s %d",k, s, &n);

    ky=k[1]-'0'; kx=k[0]-'A'+1;
    sy=s[1]-'0'; sx=s[0]-'A'+1;

    for(int i=0; i<n; i++){
        int my,mx;
        char t[3];
        scanf("%s",t);
        if(!strcmp(t, "R")) my=0, mx=1;
        if(!strcmp(t, "L")) my=0, mx=-1;
        if(!strcmp(t, "B")) my=-1, mx=0;
        if(!strcmp(t, "T")) my=1, mx=0;
        if(!strcmp(t, "RT")) my=1, mx=1;
        if(!strcmp(t, "LT")) my=1, mx=-1;
        if(!strcmp(t, "RB")) my=-1, mx=1;
        if(!strcmp(t, "LB")) my=-1, mx=-1;

        if(ky+my==sy && kx+mx==sx){
            if(ky+my>=1 && ky+my<=8 && kx+mx>=1 && kx+mx<=8
                && sy+my>=1 && sy+my<=8 && sx+mx>=1 && sx+mx<=8)
                ky+=my, kx+=mx, sy+=my, sx+=mx;
        }
        else{
            if(ky+my>=1 && ky+my<=8 && kx+mx>=1 && kx+mx<=8)
                ky+=my, kx+=mx;
        }
    }

    printf("%c",kx+'A'-1);
    printf("%d\n",ky);
    printf("%c",sx+'A'-1);
    printf("%d\n",sy);
    return 0;
}