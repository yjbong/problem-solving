#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
bool ch[201][201];
int s[201*201];
int main(void){

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    queue<ii> q;
    q.push(ii(0,0));
    while(!q.empty()){
        ii f=q.front();
        q.pop();
        int fa=f.first;
        int fb=f.second;
        int fc=c-fa-fb;
        ch[fa][fb]=true;

        int na,nb,nc;

        //a->b
        if(fa+fb>b) nb=b, na=fa-(b-fb);
        else na=0, nb=fa+fb;
        if(!ch[na][nb]) q.push(ii(na,nb));

        //b->a
        if(fa+fb>a) na=a, nb=fb-(a-fa);
        else nb=0, na=fa+fb;
        if(!ch[na][nb]) q.push(ii(na,nb));

        //b->c
        na=fa;
        if(fb+fc>c) nc=c, nb=fb-(c-fc);
        else nb=0, nc=fb+fc;
        if(!ch[na][nb]) q.push(ii(na,nb));

        //c->b
        na=fa;
        if(fb+fc>b) nb=b, nc=fc-(b-fb);
        else nc=0, nb=fb+fc;
        if(!ch[na][nb]) q.push(ii(na,nb));

        //a->c
        nb=fb;
        if(fa+fc>c) nc=c, na=fa-(c-fc);
        else na=0, nc=fa+fc;
        if(!ch[na][nb]) q.push(ii(na,nb));

        //c->a
        nb=fb;
        if(fa+fc>a) na=a, nc=fc-(a-fa);
        else nc=0, na=fa+fc;
        if(!ch[na][nb]) q.push(ii(na,nb));
    }

    int ss=0;
    for(int i=0; i<=b; i++) if(ch[0][i]) s[ss++]=c-i;

    sort(s,s+ss);
    int old=-1;
    for(int i=0; i<ss; i++){
        if(s[i]!=old){
            printf("%d ",s[i]);
            old=s[i];
        }
    }
    printf("\n");
    return 0;
}