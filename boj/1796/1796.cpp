#include <cstdio>
#include <cstring>

bool c[26];
int al[26];
int als;

char a[1001];

int d[26][2];
int f[26];
int sp[26];
int ep[26];

int min2(int a, int b){

    if(a<b) return a;
    else return b;
}
int abs2(int a){

    if(a<0) return (-a);
    else return a;
}
int main(void){

    scanf("%s",a);
    int len=strlen(a);
    for(int i=0; i<len; i++) c[a[i]-'a']=true;
    for(int i=0; i<26; i++) if(c[i]) al[als++]=i;

    for(int i=0; i<len; i++){
        for(int j=0; j<als; j++){
            if(a[i]-'a'==al[j]){
                a[i]=j+'a';
                break;
            }
        }
    }

    for(int i=0; i<als; i++){
        for(int j=0; j<len; j++){
            if(a[j]-'a'==i){
                ep[i]=j;
                f[i]++;
            }
        }
        for(int j=len-1; j>=0; j--) if(a[j]-'a'==i) sp[i]=j;
    }
/*
    printf("%s\n",a);
    for(int i=0; i<als; i++){
        printf("%c: sp %d ep %d f %d\n",i+'a',sp[i],ep[i],f[i]);
    }
*/
    d[0][0]=ep[0]+abs2(ep[0]-sp[0])+f[0], d[0][1]=ep[0]+f[0];
    for(int i=1; i<als; i++){
        d[i][0]=min2(d[i-1][0]+abs2(sp[i-1]-ep[i])+abs2(ep[i]-sp[i]), d[i-1][1]+abs2(ep[i-1]-ep[i])+abs2(ep[i]-sp[i]))+f[i];
        d[i][1]=min2(d[i-1][0]+abs2(sp[i-1]-sp[i])+abs2(sp[i]-ep[i]), d[i-1][1]+abs2(ep[i-1]-sp[i])+abs2(sp[i]-ep[i]))+f[i];
    }
    int sol=min2(d[als-1][0],d[als-1][1]);
    printf("%d\n",sol);
    return 0;
}