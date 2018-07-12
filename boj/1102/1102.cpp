#include <cstdio>
#include <vector>
#define INF 2000000000
using namespace std;
int c[16][16];
char s[20];

vector <int> a;
vector <int> b;

int minp[1<<16];

int main(void){

    int n;
    scanf("%d",&n);

    for(int i=0; i<(1<<n); i++)  minp[i]=INF;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&c[i][j]);

    scanf("%s",s);
    int on=0,st=0;
    for(int i=0; i<n; i++){
        if(s[i]=='Y'){
            on++;
            st+=(1<<i);
        }
    }

    int p;
    scanf("%d",&p);

    if(p<=on) printf("0\n");
    else if(!on) printf("-1\n");
    else{

        int sol=INF;
        a.clear();
        a.push_back(st);
        minp[st]=0;
        for(int i=on; i<p; i++){
            for(int j=0; j<a.size(); j++){
                for(int k=0; k<n; k++){
                    if(a[j]&(1<<k)){
                        for(int l=0; l<n; l++){
                            if(!(a[j]&(1<<l)) && minp[a[j]+(1<<l)]>minp[a[j]]+c[k][l]){
                                if(minp[a[j]+(1<<l)]>=INF) b.push_back(a[j]+(1<<l));
                                minp[a[j]+(1<<l)]=minp[a[j]]+c[k][l];
                            }
                        }
                    }
                }
            }

            if(i==p-1){
                for(int j=0; j<b.size(); j++){
                    if(sol>minp[b[j]]) sol=minp[b[j]];
                }
                printf("%d\n",sol);
            }
            else{
                a.clear();
                for(int j=0; j<b.size(); j++) a.push_back(b[j]);
                b.clear();
            }
        }
    }

    return 0;
}