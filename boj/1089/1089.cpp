#include <stdio.h>
const char digit[10][5][4]=
{
    {
        "###",
        "#.#",
        "#.#",
        "#.#",
        "###"
    }
    ,
    {
        "..#",
        "..#",
        "..#",
        "..#",
        "..#"
    }
    ,
    {
        "###",
        "..#",
        "###",
        "#..",
        "###"
    }
    ,
    {
        "###",
        "..#",
        "###",
        "..#",
        "###"
    }
    ,
    {
        "#.#",
        "#.#",
        "###",
        "..#",
        "..#"
    }
    ,
    {
        "###",
        "#..",
        "###",
        "..#",
        "###"
    }
    ,
    {
        "###",
        "#..",
        "###",
        "#.#",
        "###"
    }
    ,
    {
        "###",
        "..#",
        "..#",
        "..#",
        "..#"
    }
    ,
    {
        "###",
        "#.#",
        "###",
        "#.#",
        "###"
    }
    ,
    {
        "###",
        "#.#",
        "###",
        "..#",
        "###"
    }
};
char indigit[10][5][4];
char line[50];

long long possible_digit[10][10];
long long possible_digits[10];
long long possible_nums;
int main(void){

    int i,j,k,l,n,ok;
    long long sol,cur;
    scanf("%d",&n);
    for(i=0; i<5; i++){
        scanf("%s",line);
        for(j=0; j<4*n-1; j++){
            if(j%4!=3) indigit[j/4][i][j%4]=line[j];
            else indigit[j/4][i][j%4]='\0';
        }
    }

    for(i=0; i<10; i++) possible_digits[i]=0;
    for(i=0; i<n; i++){
        for(j=0; j<10; j++){
            ok=1;
            for(k=0; k<5; k++){
                for(l=0; l<3; l++){
                    if(indigit[i][k][l]=='#' && digit[j][k][l]=='.') ok=0;
                }
            }
            if(ok){
                possible_digit[i][possible_digits[i]]=j;
                possible_digits[i]++;
            }
        }
    }

    possible_nums=1;
    for(i=0; i<n; i++) possible_nums*=possible_digits[i];
    if(possible_nums==0) printf("-1\n");
    else{
        sol=0;
        for(i=0; i<n; i++){
            cur=0;
            for(j=0; j<possible_digits[i]; j++) cur+=possible_digit[i][j];
            for(j=0; j<n-1-i; j++) cur*=10;
            cur*=(possible_nums/possible_digits[i]);
            sol+=cur;
        }
        printf("%.10lf\n",(double)sol/(double)possible_nums);
    }
    return 0;
}