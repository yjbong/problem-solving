#include <cstdio>
#include <cstring>
int len;
char str[111];
int d[111][111];
int max2(int a,int b){return a>b?a:b;}
int main(void){
    while(1){
        scanf("%s",str);
        if(!strcmp(str, "end")) break;
        len=strlen(str);
        for(int i=0; i<len; i++){
            for(int j=0; j+i<len; j++){
                d[j][j+i]=0;
                if((str[j]=='(' && str[j+i]==')') || (str[j]=='[' && str[j+i]==']'))
                    d[j][j+i]=max2(d[j][j+i],d[j+1][j+i-1]+2);
                for(int k=j; k<j+i; k++)
                    d[j][j+i]=max2(d[j][j+i],d[j][k]+d[k+1][j+i]);
            }
        }
        int ans=0;
        for(int i=0; i<len; i++)
            for(int j=0; j<len; j++)
                ans=max2(ans,d[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}