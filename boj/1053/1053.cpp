#include <cstdio>
#include <cstring>
#define INF 1000000000
char s[55*55][55];
int d[55][55];
int main(void){

    scanf("%s",s[0]);
    int n=strlen(s[0]);

    int ss=1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            strcpy(s[ss], s[0]);
            char t;
            t=s[ss][i]; s[ss][i]=s[ss][j]; s[ss][j]=t;
            ss++;
        }
    }

    int sol=INF;
    for(int z=0; z<ss; z++){
        for(int i=0; i<n; i++)
           for(int j=0; j<n; j++) d[i][j]=INF;

        for(int i=0; i<n; i++) z==0 ? d[i][i]=0 : d[i][i]=1;
        for(int i=0; i<n-1; i++){
            if(s[z][i]==s[z][i+1]) z==0 ? d[i][i+1]=0 : d[i][i+1]=1;
            else z==0 ? d[i][i+1]=1 : d[i][i+1]=2;
        }

        for(int k=2; k<n; k++){
            for(int i=0; i+k<n; i++){

                if(d[i][i+k]>d[i][i+k-1]+1) d[i][i+k]=d[i][i+k-1]+1;
                if(d[i][i+k]>d[i+1][i+k]+1) d[i][i+k]=d[i+1][i+k]+1;

                if(s[z][i]==s[z][i+k]){
                    if(d[i][i+k] > d[i+1][i+k-1]) d[i][i+k] = d[i+1][i+k-1];
                }
                else{
                    if(d[i][i+k] > d[i+1][i+k-1]+1) d[i][i+k] = d[i+1][i+k-1]+1;
                }
            }
        }

        if(sol>d[0][n-1]) sol=d[0][n-1];
    }

    printf("%d\n",sol);

    return 0;
}