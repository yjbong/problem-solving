#include <cstdio>
#include <cstring>
char s[7];
int n[6];
int nlen;
int a[6];
int c[6];
int clen;
int cdgt;

int start;
int seq_num;
int sol;

void make_c(int t){

    clen=0;
    while(t>0){
        c[clen]=t%10;
        t/=10;
        clen++;
    }
    for(int i=0; i<=(clen-1)/2; i++){
        int tmp;
        tmp=c[i];
        c[i]=c[clen-1-i];
        c[clen-1-i]=tmp;
    }
}

int main(void){

    scanf("%s",s);
    nlen=strlen(s);
    for(int i=0; i<nlen; i++) n[i]=s[i]-'0';

    for(int i=0; i<6; i++) a[i]=i+1;

    start=0;
    seq_num=7;
    make_c(seq_num);
    cdgt=0;

    sol=1;
    while(1){
        int i,j;
        bool ok=true;
        for(i=0,j=start; i<nlen; i++, j=(j+1)%6){
            if(n[i]!=a[j]){
                ok=false;
                break;
            }
        }

        if(ok){
            printf("%d\n",sol);
            break;
        }
        sol++;

        a[start]=c[cdgt];
        start=(start+1)%6;
        cdgt++;
        if(cdgt==clen){
            seq_num++;
            make_c(seq_num);
            cdgt=0;
        }
    }
    return 0;
}