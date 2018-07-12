#include <cstdio>
#include <cstring>

char a[111];
int d[111][111];
int main(void){

    scanf("%s",a);
    int n=strlen(a);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) d[i][j]=-1;

    for(int i=0; i<n; i++){
        if(a[i]=='H') d[i][i]=1;
        else if(a[i]=='C') d[i][i]=12;
        else if(a[i]=='O') d[i][i]=16;
    }

    for(int i=0; i<n-1; i++){
        if(a[i]=='(' && a[i+1]==')') d[i][i+1]=0;
        else if(a[i+1]>='0' && a[i+1]<='9'){
            if(a[i]=='H') d[i][i+1]=1*(a[i+1]-'0');
            else if(a[i]=='C') d[i][i+1]=12*(a[i+1]-'0');
            else if(a[i]=='O') d[i][i+1]=16*(a[i+1]-'0');
        }
        else if(a[i]>='A' && a[i]<='Z' && a[i+1]>='A' && a[i+1]<='Z') d[i][i+1]=d[i][i]+d[i+1][i+1];
    }

    for(int i=2; i<n; i++){
        for(int j=0; j+i<n; j++){
            for(int k=j; k+1<=j+i; k++){
                if(d[j][k]>=0 && d[k+1][j+i]>=0){
                    d[j][j+i]=d[j][k]+d[k+1][j+i];
                    break;
                }
            }

            if(a[j]=='(' && a[j+i]==')'){
                if(d[j+1][j+i-1]>=0) d[j][j+i]=d[j+1][j+i-1];
            }
            else if(a[j+i]>='0' && a[j+i]<='9'){
                if(a[j+i-1]==')'){
                    if(i==2) d[j][j+1]=0;
                    else if(d[j+1][j+i-2]>=0) d[j][j+i]=d[j+1][j+i-2]*(a[j+i]-'0');
                }
            }
        }
    }
    printf("%d\n",d[0][n-1]);
    return 0;
}