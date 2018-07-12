#include <cstdio>
int main(void){

    int n,k=0;
    scanf("%d",&n);
    for(int i=0; ;){
        int c=i;
        int cseq=0,mseq=0;
        bool ok=false;
        while(c>0){
            if(c%10==6){
                cseq++;
                if(mseq<cseq) mseq=cseq;
            }
            else cseq=0;
            if(cseq==3){
                ok=true;
                break;
            }
            c/=10;
        }
        if(ok) k++;
        if(k==n){
            printf("%d\n",i);
            break;
        }

        if(mseq==0) i+=60;
        else if(mseq==1) i+=10;
        else i++;
    }
    return 0;
}