#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 1000000
int c;
char a[11111];
int len;
int d[11111];

int min2(int a, int b){
    return (a<b ? a : b);
}
int difficult(int start, int end){
    int diff;
    bool score1=true;
    for(int i=start+1; i<=end; i++){
        if(a[start]!=a[i]){
            score1=false;
            break;
        }
    }
    if(score1) return 1;

    bool score2=true;
    diff=a[start+1]-a[start];
    if(abs(diff)!=1) score2=false;
    if(score2){
        for(int i=start+2; i<=end; i++){
           if(a[i]-a[i-1]!=diff){
               score2=false;
               break;
           }
        }
    }
    if(score2) return 2;

    bool score4=true;
    diff=a[start+1]-a[start];
    for(int i=start+2; i<=end; i++){
        if(a[i]-a[i-1]!=diff*(-1)){
            score4=false;
            break;
        }
        else diff=a[i]-a[i-1];
    }
    if(score4) return 4;

    bool score5=true;
    diff=a[start+1]-a[start];
    for(int i=start+2; i<=end; i++){
        if(a[i]-a[i-1]!=diff){
            score5=false;
            break;
        }
    }
    if(score5) return 5;

    return 10;
}

int score(int idx){

    if(d[idx]>=0) return d[idx];

    if(idx+2>=len){
        if(idx==len) return (d[idx]=0);
        else return (d[idx]=INF);
    }

    int ret=difficult(idx,idx+2)+score(idx+3);
    if(idx+3<len) ret=min2(ret, difficult(idx,idx+3)+score(idx+4));
    if(idx+4<len) ret=min2(ret, difficult(idx,idx+4)+score(idx+5));

    return (d[idx]=ret);
}

int main(void){

    scanf("%d",&c);
    while(c--){
        scanf("%s",a);
        len=strlen(a);
        for(int i=0; i<11111; i++) d[i]=-1;
        printf("%d\n",score(0));
    }
    return 0;
}