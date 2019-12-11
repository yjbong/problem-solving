#include <cstdio>
int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 
bool leapYear(int y){
    if(y%400==0) return true;
    else if(y%100==0) return false;
    else if(y%4==0) return true;
    else return false;
}
int main() {
    int d,m,y;
    while(1){
        scanf("%d %d %d",&d,&m,&y);
        if(d==0 && m==0 && y==0) break;
        int ans=d;
        for(int i=0; i<m-1; i++){
            ans+=daysInMonth[i];
            if(i==1 && leapYear(y)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}