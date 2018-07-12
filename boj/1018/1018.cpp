#include <stdio.h>
#define W 0
#define B 1
int b[50][50];
char line[51];
int main(void){

    int i,j,k,l,n,m,min,cur;

    scanf("%d %d", &n, &m);

    for(i=0; i<n; i++){
        scanf("%s", line);
        for(j=0; j<m; j++){
            if(line[j]=='W') b[i][j]=W;
            else if(line[j]=='B') b[i][j]=B;
        }
    }

    min=100000000;
    for(i=0; i<n-7; i++){
        for(j=0; j<m-7; j++){

            /* upleft=WHITE */
            cur=0;
            for(k=i; k<=i+7; k++){
                for(l=j; l<=j+7; l++){
                    if((k-i+l-j)%2==0){
                        if(b[k][l]==B) cur++;
                    }
                    else{
                        if(b[k][l]==W) cur++;
                    }
                }
            }
            if(min>cur) min=cur;

            /* upleft=BLACK */
            cur=0;
            for(k=i; k<=i+7; k++){
                for(l=j; l<=j+7; l++){
                    if((k-i+l-j)%2==0){
                        if(b[k][l]==W) cur++;
                    }
                    else{
                        if(b[k][l]==B) cur++;
                    }
                }
            }
            if(min>cur) min=cur;
        }
    }
    printf("%d\n", min);
    return 0;
}