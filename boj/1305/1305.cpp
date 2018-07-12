#include <stdio.h>
int fail[1000001];
char line[1000001];
int main(void){
    int i,len,cur;
    scanf("%d", &len);
    scanf("%s", line);
    fail[0]=-1;
    for(i=1; i<len; i++){
        cur=fail[i-1]+1;
        while(line[i]!=line[cur] && cur>0)
            cur=fail[cur-1]+1;
        if(line[i]==line[cur]) fail[i]=cur;
        else fail[i]=-1;
    }
    printf("%d\n", len-(fail[len-1]+1));
    return 0;
}