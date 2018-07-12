#include <stdio.h>
#include <string.h>
char line[100];
char mon[20];
long long day_in_mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(void){

    long long i,monnum,daynum,yearnum,hournum,minnum;
    long long totmin,curmin;
    scanf("%[^\n]", line);
    for(i=0; ; i++){
        mon[i]=line[i];
        if(line[i]==' '){
            mon[i]='\0';
            break;
        }
    }
    if(strcmp(mon,"January")==0) monnum=1;
    else if(strcmp(mon,"February")==0) monnum=2;
    else if(strcmp(mon,"March")==0) monnum=3;
    else if(strcmp(mon,"April")==0) monnum=4;
    else if(strcmp(mon,"May")==0) monnum=5;
    else if(strcmp(mon,"June")==0) monnum=6;
    else if(strcmp(mon,"July")==0) monnum=7;
    else if(strcmp(mon,"August")==0) monnum=8;
    else if(strcmp(mon,"September")==0) monnum=9;
    else if(strcmp(mon,"October")==0) monnum=10;
    else if(strcmp(mon,"November")==0) monnum=11;
    else if(strcmp(mon,"December")==0) monnum=12;

    daynum=0;
    for(i++; ;i++){
        if(line[i]==',') break;
        daynum*=10;
        daynum+=line[i]-'0';
    }
    i++;
    yearnum=0;
    for(i++; ; i++){
        if(line[i]==' ') break;
        yearnum*=10;
        yearnum+=line[i]-'0';
    }
    hournum=0;
    for(i++; ; i++){
        if(line[i]==':') break;
        hournum*=10;
        hournum+=line[i]-'0';
    }
    minnum=0;
    for(i++; i<strlen(line); i++){
        minnum*=10;
        minnum+=line[i]-'0';
    }

    if(yearnum%400==0 || (yearnum%4==0 && yearnum%100!=0)){
        totmin=366*24*60;
        day_in_mon[2]=29;
    }
    else totmin=365*24*60;

    curmin=0;
    for(i=0; i<monnum; i++) curmin+=day_in_mon[i];
    curmin+=(daynum-1);
    curmin*=(24*60);
    curmin+=(hournum*60+minnum);
    printf("%.10lf\n",100.0*(double)curmin/(double)totmin);
    return 0;
}