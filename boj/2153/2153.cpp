#include <stdio.h>
#include <string.h>
#include <math.h>
char line[21];

int main(void){

    int i,sosu,sum,sqrt_sum;
    scanf("%s",line);
    sum=0;
    for(i=0; i<strlen(line); i++){
        if(line[i]>='a' && line[i]<='z') sum+=line[i]-'a'+1;
        else if(line[i]>='A' && line[i]<='Z') sum+=line[i]-'A'+27;
    }
    if(sum<1) sosu=0;
    else if(sum==1) sosu=1;
    else{
        sosu=1;
        sqrt_sum=(int)sqrt(sum);
        for(i=2; i<=sqrt_sum; i++){
            if(sum%i==0){
                sosu=0;
                break;
            }
        }
    }
    if(sosu) printf("It is a prime word.\n");
    else printf("It is not a prime word.\n");
    return 0;
}