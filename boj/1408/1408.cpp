#include <stdio.h>
int main(void){

    char line[10];
    int h,m,s,start,now,remain;
    scanf("%s", line);
    h=(line[0]-'0')*10+line[1]-'0';
    m=(line[3]-'0')*10+line[4]-'0';
    s=(line[6]-'0')*10+line[7]-'0';
    start=h*3600+m*60+s;

    scanf("%s", line);
    h=(line[0]-'0')*10+line[1]-'0';
    m=(line[3]-'0')*10+line[4]-'0';
    s=(line[6]-'0')*10+line[7]-'0';
    now=h*3600+m*60+s;

    if(now>=start) remain=now-start;
    else remain=86400+now-start;
    h=remain/3600;
    m=(remain%3600)/60;
    s=remain%60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}