#include <cstdio>
int abs(int a){
    if(a<0) return (-a);
    else return a;
}
char s[10];
bool c[6][6];
int main(void){

    int i;
    int srow,scol;
    int orow,ocol;
    int crow,ccol;
    for(i=0; i<36; i++){
        scanf("%s",s);
        ccol=s[0]-'A';
        crow=s[1]-'0'-1;
        if(i==0){
            scol=ccol;
            srow=crow;
        }
        if(c[crow][ccol]) break;
        if(i>0){
            if(abs(orow-crow)==1 && abs(ocol-ccol)==2);
            else if(abs(orow-crow)==2 && abs(ocol-ccol)==1);
            else break;
        }
        c[crow][ccol]=true;
        orow=crow;
        ocol=ccol;
    }
    if(i==36){
        if(abs(orow-srow)==1 && abs(ocol-scol)==2) printf("Valid\n");
        else if(abs(orow-srow)==2 && abs(ocol-scol)==1) printf("Valid\n");
        else printf("Invalid\n");
    }
    else printf("Invalid\n");
    return 0;
}