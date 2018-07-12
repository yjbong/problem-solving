#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;
int shom[1111];
int shoms;
int n;
queue <int> q;
int d[1000001];
void go(int cnum, int cdigit, int clen, int lim_len){

    if(clen==lim_len){
        if(shom[shoms-1]!=cnum) shom[shoms++] = cnum;
        return;
    }
    go(cnum*10+cdigit, 4, clen+1,lim_len);
    go(cnum*10+cdigit, 7, clen+1,lim_len);
}

int main(void){

    shoms=0;
    for(int i=1; i<7; i++){
        go(0,4,0,i);
        go(0,7,0,i);
    }
    sort(shom,shom+shoms);

    scanf("%d",&n);
    d[0]=0;
    for(int i=1; i<=n; i++) d[i]=INF;

    for(int i=0; shom[i]<=n && i<shoms; i++){
        q.push(shom[i]);
        d[shom[i]]=1;
    }


    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int i=0; f+shom[i]<=n && i<shoms; i++){
            if(d[f+shom[i]]>d[f]+1){
                d[f+shom[i]]=d[f]+1;
                q.push(f+shom[i]);
            }
        }
    }

    if(n>0 && d[n]<INF){
        int cur=n;
        while(cur>0){
            int idx=0;
            for(int i=1; cur-shom[i]>=0 && i<shoms; i++){
                if(d[cur-shom[i]]<d[cur-shom[idx]]){
                    idx=i;
                }
            }
            printf("%d ",shom[idx]);
            cur-=shom[idx];
        }
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}