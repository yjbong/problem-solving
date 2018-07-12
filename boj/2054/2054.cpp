#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len;
char oper_tmp[10];

int factor[50];
int factors;

char input[10];

char sol[100000][20];
int sols;

int cmp(const void *a, const void *b){
    if(strcmp((char *)a, (char *)b)>0) return 1;
    else return 0;
}
void go(int cur_opers, char cur_oper){

    int i, j, tmp, tmp2;
    int muls;
    int pluss, minuss;
    int result;
    char tmpstr[20];
    int tmpstrs;

    if(cur_opers>0) oper_tmp[cur_opers-1]=cur_oper;
    if(cur_opers==len-1){

        factors=0;
        tmp=input[0]-'0';
        muls=pluss=minuss=0;

        tmpstrs=0;
        tmpstr[tmpstrs]=input[0];
        tmpstrs++;

        for(i=1; i<=cur_opers; i++){
            if(oper_tmp[i-1]==' '){
                tmp*=10;
                tmp+=input[i]-'0';

                tmpstr[tmpstrs]=input[i];
                tmpstrs++;
            }

            else{
                factor[factors]=tmp;
                factors++;
                if(oper_tmp[i-1]=='*'){
                    factor[factors]=-1;
                    muls++;
                }
                else if(oper_tmp[i-1]=='+'){
                    factor[factors]=-2;
                    pluss++;
                }
                else if(oper_tmp[i-1]=='-'){
                    factor[factors]=-3;
                    minuss++;
                }

                tmpstr[tmpstrs]=oper_tmp[i-1];
                tmpstrs++;

                factors++;
                tmp=input[i]-'0';

                tmpstr[tmpstrs]=input[i];
                tmpstrs++;
            }
        }

        factor[factors]=tmp;
        factors++;

        tmpstr[tmpstrs]=input[i];
        tmpstrs++;
        tmpstr[tmpstrs]='\0';

        tmp=0;
        for(i=0; i<factors; i++){
            if(factor[i]>=0){
                tmp2=factor[i];
                do{
                    tmp2/=10;
                    tmp++;
                }while(tmp2>0);
            }
        }

        if(tmp==len && factors>1){

            while(muls>0){
                for(i=1; i<factors; i+=2){
                    if(factor[i]==-1){
                        factor[i-1]=factor[i-1]*factor[i+1];
                        for(j=i; j<factors-2; j++) factor[j]=factor[j+2];
                        factors-=2;
                        muls--;
                        break;
                    }
                }
            }

            while(pluss+minuss>0){
                for(i=1; i<factors; i+=2){
                    if(factor[i]==-2){
                        factor[i-1]=factor[i-1]+factor[i+1];
                        for(j=i; j<factors-2; j++) factor[j]=factor[j+2];
                        factors-=2;
                        pluss--;
                        break;
                    }
                    else if(factor[i]==-3){
                        factor[i-1]=factor[i-1]-factor[i+1];
                        for(j=i; j<factors-2; j++) factor[j]=factor[j+2];
                        factors-=2;
                        minuss--;
                        break;
                    }
                }
            }

            result=factor[0];
            if(result==2000){
                strcpy(sol[sols], tmpstr);
                sols++;
            }
        }
    }

    else{
        go(cur_opers+1, ' ');
        go(cur_opers+1, '+');
        go(cur_opers+1, '-');
        go(cur_opers+1, '*');
    }
}

int main(void){

    int i;
    scanf("%s", &input);
    len=strlen(input);
    sols=0;
    go(0, ' ');
    qsort(sol, sols, sizeof(char)*20, cmp);

    for(i=0; i<sols; i++) printf("%s\n", sol[i]);
    return 0;
}