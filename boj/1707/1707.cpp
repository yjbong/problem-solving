#include <cstdio>
#include <vector>
#define YET -1
#define RED 0
#define BLUE 1
#define NO 0
#define YES 1

using namespace std;
vector<int> v[22222];
int vs;
int valid_vs;
int es;

int c[22222];
int cs;

int q[44444];
int f,e;

int main(void){

    int i,a,b,cases,yes;
    scanf("%d", &cases);

    while(cases--){
        scanf("%d %d", &vs, &es);
        for(i=0; i<=vs; i++) c[i]=YET;
        for(i=0; i<=vs; i++) v[i].clear();

        for(i=0; i<es; i++){
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        valid_vs=0;
        for(i=1; i<=vs; i++){
            if(v[i].size()>0) valid_vs++;
        }

        cs=0;
        yes=YES;
        while(yes==YES && cs<valid_vs){

            f=0, e=1;
            for(i=1; i<=vs; i++){
                if(c[i]==YET && v[i].size()>0){
                    q[f]=i;
                    c[i]=RED;
                    cs++;
                    break;
                }
            }

            while(f<e){

                for(i=0; i<(int)(v[q[f]].size()); i++){
                    if(c[q[f]]==RED){
                        if(c[v[q[f]][i]]==YET){
                            c[v[q[f]][i]]=BLUE;
                            cs++;

                            q[e]=v[q[f]][i];
                            e++;
                        }
                        else if(c[v[q[f]][i]]==RED){
                            yes=NO;
                            break;
                        }
                        else continue;
                    }
                    else{
                        if(c[v[q[f]][i]]==YET){
                            c[v[q[f]][i]]=RED;
                            cs++;

                            q[e]=v[q[f]][i];
                            e++;
                        }
                        else if(c[v[q[f]][i]]==BLUE){
                            yes=NO;
                            break;
                        }
                        else continue;
                    }
                }
                f++;
                if(yes==NO) break;
            }
        }

        if(yes==YES) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}