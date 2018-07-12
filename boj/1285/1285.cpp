#include <cstdio>
#define INF 1000000000
int a[20][20];
int b[20][20];
int main(void){

    int n;
    char s[21];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",s);
        for(int j=0; j<n; j++){
            if(s[j]=='H') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    int sol=INF;
    for(int i=0; i<(1<<n); i++){

        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++) b[j][k]=a[j][k];

        int t=i;
        for(int j=0; j<n; j++,t/=2)
            if(t%2) for(int k=0; k<n; k++) b[k][j]=1-b[k][j];

        int csol=0;
        for(int j=0; j<n; j++){
            int sum=0;
            for(int k=0; k<n; k++) sum+=b[j][k];
            if(sum>n/2) sum=n-sum;
            csol+=sum;
        }

        if(sol>csol) sol=csol;
    }
    printf("%d\n",sol);
    return 0;
}