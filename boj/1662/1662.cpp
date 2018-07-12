#include <cstdio>
#include <cstring>
int d[50][50];
char a[51];
int n;
int main(void){

    scanf("%s",a);
    n=strlen(a);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) d[i][j]=-1;

    for(int i=0; i<n; i++)
        if('0'<=a[i] && a[i]<='9')
            if(!(i<n-1 && a[i+1]=='(')) d[i][i]=1;

    for(int i=1; i<n; i++){
        for(int j=0; j+i<n; j++){
            for(int k=j; k+1<=j+i; k++){
                if(d[j][k]>=0 && d[k+1][j+i]>=0){
                    d[j][j+i]=d[j][k]+d[k+1][j+i];
                    break;
                }
            }

            if(a[j]=='(' && a[j+i]==')'){
                if(i==1) d[j][j+i]=0;
                else if(d[j+1][j+i-1]>=0) d[j][j+i]=d[j+1][j+i-1];
            }
            else if('0'<=a[j] && a[j]<='9' && a[j+1]=='(' && a[j+i]==')'){
                if(j+2>j+i-1) d[j][j+i]=0;
                else if(d[j+2][j+i-1]>=0) d[j][j+i]=(a[j]-'0')*d[j+2][j+i-1];
            }
        }
    }
    printf("%d\n",d[0][n-1]);
    return 0;
}