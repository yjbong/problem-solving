#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char c[25]={"bdefghjklmopqrsuvwxyz"};
bool d[26];
char w[50][20];
int a[21]={0,};
int main(void){

    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++) scanf("%s",w[i]);

    if(k<5) printf("0\n");
    else{
        k-=5;
        int sol=0;
        for(int i=21-1; i>=21-k; i--) a[i]=1;
        do{
            for(int i=0; i<26; i++){
                if(i=='a'-'a'||i=='n'-'a'||i=='t'-'a'||i=='i'-'a'||i=='c'-'a') d[i]=true;
                else d[i]=false;
            }
            for(int i=0; i<21; i++) if(a[i]) d[c[i]-'a']=true;

            int csol=0;
            for(int i=0; i<n; i++){
                bool cok=true;
                for(int j=4; j<strlen(w[i])-4; j++){
                    if(d[w[i][j]-'a']==false){
                        cok=false;
                        break;
                    }
                }
                if(cok) csol++;
            }
            if(sol<csol) sol=csol;

        }while(next_permutation(a,a+21));
        printf("%d\n",sol);
    }
    return 0;
}