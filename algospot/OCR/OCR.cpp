#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>

int m,q,n;
char word[555][11];
double B[555];
double T[555][555];
double M[555][555];
int R[111]; char tmp[11];

double cache[111][555];
int choice[111][555];
double go(int donewords, int lastword){

    if(cache[donewords][lastword]<1.0) return cache[donewords][lastword]; // memoization

    if(donewords>=n) return (cache[donewords][lastword]=0);
    double ans=-1e200;
    for(int i=0; i<m; i++){
        double cur_ans=go(donewords+1,i)+log(M[i][R[donewords]]);

        if(donewords>=1) cur_ans+=log(T[lastword][i]);
        else cur_ans+=log(B[i]);

        if(ans<cur_ans){
            ans=cur_ans;
            choice[donewords][lastword]=i;
        }
    }

    return (cache[donewords][lastword]=ans);
}

int main(void){

    scanf("%d %d",&m,&q);
    for(int i=0; i<m; i++) scanf("%s",word[i]);
    for(int i=0; i<m; i++) scanf("%lf",&B[i]);
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++) scanf("%lf",&T[i][j]);
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++) scanf("%lf",&M[i][j]);

    while(q--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%s",tmp);
            for(int j=0; j<m; j++){
                if(!strcmp(tmp,word[j])){
                    R[i]=j;
                    break;
                }
            }
        }

        for(int i=0; i<=n; i++)
            for(int j=0; j<m; j++) cache[i][j]=1;
        go(0,0);

        int cur_donewords=0; int cur_lastword=0;
        while(cur_donewords<n){
            int cur_choice=choice[cur_donewords][cur_lastword];
            printf("%s ",word[cur_choice]);
            cur_donewords++;
            cur_lastword=cur_choice;
        }
        printf("\n");
    }
    return 0;
}