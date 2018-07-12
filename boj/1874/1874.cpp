#include <stdio.h>
#define PUSH 0
#define POP 1
int seq[100000];
int stck[100000];
int top;
int pp[200000];
int pps;

int main(void){

    int i,j,n,curnum;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &seq[i]);

    top=pps=-1;
    for(i=1; i<=seq[0]; i++){
        stck[++top]=i;
        pp[++pps]=PUSH;
        if(pps==2*n-1) goto exit;
    }
    top--;
    pp[++pps]=POP;
    if(pps==2*n-1) goto exit;

    curnum=seq[0]+1;
    for(i=1; ;i++){
        if(stck[top]==seq[i]){
            top--;
            pp[++pps]=POP;
            if(pps==2*n-1) goto exit;
        }
        else{
            for(j=curnum; j<=seq[i]; j++){
                stck[++top]=j;
                pp[++pps]=PUSH;
                if(pps==2*n-1) goto exit;
            }
            top--;
            pp[++pps]=POP;
            curnum=seq[i]+1;
            if(pps==2*n-1) goto exit;
        }
    }

exit:

    if(top<0){
        for(i=0; i<=pps; i++){
            if(pp[i]==PUSH) printf("+\n");
            else printf("-\n");
        }
    }
    else printf("NO\n");
    return 0;
}