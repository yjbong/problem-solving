#include <stdio.h>
int pos[50];
int main(void){

    int i,j,n,m,left,right,sol;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++){
        scanf("%d", &pos[i]);
        pos[i]--;
    }

    sol=0;
    for(i=0; i<m; i++){
        left=pos[i];
        right=n-i-pos[i];
        while(right<0) right+=(n-i);
        if(left<right) sol+=left;
        else sol+=right;
        for(j=i+1; j<m; j++){
            pos[j]-=(left+1);
            while(pos[j]<0) pos[j]+=(n-i);
        }
    }
    printf("%d\n", sol);
    return 0;
}