#include <stdio.h>
#include <string.h>

double stack[111111];
char line[111111];
long long val[26];
int main(void){

    int i,n,len,top;
    scanf("%d\n",&n);
    gets(line);
    len=strlen(line);
    for(i=0; i<n; i++) scanf("%lld",&val[i]);

    top=-1;
    for(i=0; i<len; i++){
        if(line[i]>='A' && line[i]<='Z'){
            top++;
            stack[top]=val[line[i]-'A'];
        }
        else if(line[i]=='+'){
            stack[top-1]+=stack[top];
            top--;
        }
        else if(line[i]=='-'){
            stack[top-1]-=stack[top];
            top--;
        }
        else if(line[i]=='*'){
            stack[top-1]*=stack[top];
            top--;
        }
        else if(line[i]=='/'){
            stack[top-1]/=stack[top];
            top--;
        }
    }
    printf("%.2lf\n",stack[top]);
    return 0;
}