#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int diff[36][100];
int num[50][100],nums;
int sol[100];

int k;
char tmp[100];

int cmp(const void *a, const void *b){

    int i,b_is_big;

    b_is_big=0;
    for(i=99; i>=0; i--){
        if(*(((int*)a)+i)<*(((int*)b)+i) ){
            b_is_big=1;
            break;
        }

        else if(*(((int*)a)+i)>*(((int*)b)+i) ) break;
    }

    if(b_is_big==1) return 1;
    else return 0;
}

void add(int a[100], int b[100]){

    int i;
    for(i=0; i<99; i++){
        a[i]=a[i]+b[i];
        a[i+1]+=a[i]/36;
        a[i]%=36;
    }
}

int main(void){

    int i,j,len,zerovalid;
    int print;

    scanf("%d", &nums);

    for(i=0; i<nums; i++)
        for(j=0; j<100; j++) num[i][j]=0;

    for(i=0; i<36; i++)
        for(j=0; j<100; j++) diff[i][j]=0;

    for(i=0; i<nums; i++){
        scanf("%s", tmp);
        len=strlen(tmp);
        for(j=len-1; j>=0; j--){
            if(tmp[j]>='0' && tmp[j]<='9') num[i][len-1-j]=tmp[j]-'0';
            else if(tmp[j]>='A' && tmp[j]<='Z') num[i][len-1-j]=tmp[j]-'A'+10;
            else if(tmp[j]>='a' && tmp[j]<='z') num[i][len-1-j]=tmp[j]-'a'+10;
        }
    }

    for(i=0; i<nums; i++){
        zerovalid=0;
        for(j=99; j>=0; j--){
            if(num[i][j]!=0 || zerovalid==1){
                diff[num[i][j]][j]+=(35-num[i][j]);
                zerovalid=1;
            }
        }
    }

    for(i=0; i<36; i++){
        for(j=0; j<99; j++){
            diff[i][j+1]+=(diff[i][j]/36);
            diff[i][j]%=36;
        }
    }

    qsort(diff, 36, sizeof(int)*100, cmp);

    for(i=0; i<100; i++) sol[i]=0;
    for(i=0; i<nums; i++) add(sol, num[i]);
    scanf("%d", &k);
    for(i=0; i<k; i++) add(sol, diff[i]);

    print=0;
    for(i=99; i>=0; i--){
        if(sol[i]!=0 || print==1){
            if(sol[i]>=10) printf("%c", sol[i]-10+'A');
            else printf("%c", sol[i]+'0');
            print=1;
        }
    }
    if(print==0) printf("0");
    printf("\n");

    return 0;
}