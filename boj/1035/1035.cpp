#include <cstdio>
#include <utility>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

ii p[5];
int ps;
int ord[5];

ii m[50000][5];
int ms;
bool c[7][7];
ii pos[5];

char s[10];

int abs(int a){
    if(a<0) return (-a);
    else return a;
}

void go(int size, ii pos[5]){

    if(size==ps){
        for(int i=0; i<size; i++){
            m[ms][i].first=pos[i].first;
            m[ms][i].second=pos[i].second;
        }
        ms++;
        return;
    }

    for(int i=0; i<size; i++){
        int cy=pos[i].first;
        int cx=pos[i].second;

        for(int j=0; j<4; j++){
            if(!c[cy+dy[j]][cx+dx[j]]){
                pos[size].first=cy+dy[j]; pos[size].second=cx+dx[j];

                c[cy+dy[j]][cx+dx[j]]=true;
                go(size+1,pos);
                c[cy+dy[j]][cx+dx[j]]=false;
            }
        }
    }
}


int main(void){

    ps=0;
    for(int i=0; i<5; i++){
        gets(s);
        for(int j=0; j<5; j++){
            if(s[j]=='*'){
                p[ps].first=i+1;
                p[ps].second=j+1;
                ps++;
            }
        }
    }

    for(int i=0; i<7; i++){
        c[i][0]=true;
        c[i][6]=true;
    }
    for(int j=0; j<7; j++){
        c[0][j]=true;
        c[6][j]=true;
    }
    ms=0;

    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){

            pos[0].first=i; pos[0].second=j;

            c[i][j]=true;
            go(1,pos);
            c[i][j]=false;
        }
    }

    for(int i=0; i<ps; i++) ord[i]=i;

    int sol=INF;
    do{
        for(int i=0; i<ms; i++){
            int cur=0;
            for(int j=0; j<ps; j++){
                cur=cur+abs(m[i][j].first-p[ord[j]].first)+abs(m[i][j].second-p[ord[j]].second);
            }
            if(sol>cur) sol=cur;
        }

    }while(next_permutation(ord,ord+ps));

    printf("%d\n",sol);
    return 0;
}