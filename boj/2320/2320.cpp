#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char a[16][101];
int d[1<<16][5];
bool c[1<<16];
int len[16];
int m[26];

vector <int> v1,v2;

int main(void){

    m['A'-'A']=0;m['E'-'A']=1;m['I'-'A']=2;m['O'-'A']=3;m['U'-'A']=4;

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",a[i]);
        len[i]=strlen(a[i]);
    }
    v1.push_back(0);
    c[0]=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<v1.size(); j++){
            int st=v1[j];
            for(int k=0; k<n; k++){
                if(!(st&(1<<k))){
                    int cst=st+(1<<k);
                    if(!c[cst]){
                        c[cst]=true;
                        v2.push_back(cst);
                    }

                    int t1=m[a[k][len[k]-1]-'A'];
                    int t2=m[a[k][0]-'A'];
                    if(d[cst][t1]<d[st][t2]+len[k]) d[cst][t1]=d[st][t2]+len[k];
                }
            }
        }

        v1.clear();
        for(int j=0; j<v2.size(); j++) v1.push_back(v2[j]);
        v2.clear();
    }
    int sol=0;
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<5; j++) if(sol<d[i][j]) sol=d[i][j];
    printf("%d\n",sol);
    return 0;
}