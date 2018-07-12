#include <cstdio>
#include <vector>
using namespace std;
int h[16];
long long d[1<<16][16];
bool c[1<<16];
vector <int> a,b;

int abs2(int a){
    if(a<0) return (-a);
    else return a;
}

int main(void){

    int n,dif;
    scanf("%d %d",&n,&dif);
    for(int i=0; i<n; i++) scanf("%d",&h[i]);

    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++) d[i][j]=0;

    for(int i=0; i<n; i++){
        d[1<<i][i]=1;
        c[1<<i]=true;
        a.push_back(1<<i);
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<a.size(); j++){
            int st=a[j];
            for(int k=0; k<n; k++){
                if(!(st&(1<<k))){
                    int nst=st+(1<<k);
                    if(!c[nst]){
                        b.push_back(nst);
                        c[nst]=true;
                    }

                    for(int l=0; l<n; l++){
                        if((st&(1<<l)) && (abs2(h[k]-h[l])>dif)){
                            d[nst][k]+=d[st][l];
                        }
                    }
                }
            }
        }
        a.clear();
        for(int j=0; j<b.size(); j++) a.push_back(b[j]);
        b.clear();
    }
    long long sol=0;
    for(int i=0; i<n; i++) sol+=d[(1<<n)-1][i];
    printf("%lld\n",sol);
    return 0;
}