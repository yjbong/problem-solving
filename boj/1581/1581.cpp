#include <stdio.h>
int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int main(void){

    int sol,ff,fs,sf,ss;
    scanf("%d %d %d %d", &ff, &fs, &sf, &ss);
    if(ff==0 && fs==0){
        sol=ss;
        if(sf>0) sol++;
    }
    else{
        if(fs==0) sol=ff;
        else if(sf==0) sol=ff+1+ss;
        else{
            if(fs>sf) sol=ff+ss+min(fs,sf)*2+1;
            else sol=ff+ss+min(fs,sf)*2;
        }
    }

    printf("%d\n", sol);
    return 0;
}