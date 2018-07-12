#include <cstdio>
typedef long long ll;

ll pw[60];
ll dx[4]={1,0,0,1};
ll dy[4]={1,1,0,0};
char s[55];

void calc_xy(ll *x, ll *y, char *s, int len){
    (*x)=(*y)=0;
    for(int i=0; i<len; i++){
        (*x) += dx[s[i]-'0'-1]*pw[len-1-i];
        (*y) += dy[s[i]-'0'-1]*pw[len-1-i];
    }
}
void get_str(ll x, ll y, char *s, int len){
    for(int i=0; i<len; i++){
        ll curx = x/pw[len-1-i];
        ll cury = y/pw[len-1-i];
        if(curx && cury) s[i]='1';
        else if(!curx && cury) s[i]='2';
        else if(!curx && !cury) s[i]='3';
        else s[i]='4';
        x %= pw[len-1-i]; y %= pw[len-1-i];
    }
    s[len]='\0';
}
int main(void){

    int d;
    ll x,y,mx,my;
    pw[0]=1;
    for(int i=1; i<60; i++) pw[i]=pw[i-1]*2;

    scanf("%d %s",&d,s);
    scanf("%lld %lld",&mx,&my);

    calc_xy(&x,&y,s,d);
    x+=mx; y+=my;

    if(x<0 || x>=pw[d] || y<0 || y>=pw[d])
        printf("-1\n");
    else{
        get_str(x,y,s,d);
        printf("%s\n",s);
    }
    return 0;
}