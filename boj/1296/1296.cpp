#include <stdio.h>
#include <string.h>
char name[21][21];
int main(void){

    int i,j,n;
    long long L1,O1,V1,E1,L2,O2,V2,E2;
    long long maxmatch,curmatch,maxidx;
    scanf("%s\n", name[0]);

    L1=O1=V1=E1=0;
    for(i=0; i<strlen(name[0]); i++){
        if(name[0][i]=='L') L1++;
        else if(name[0][i]=='O') O1++;
        else if(name[0][i]=='V') V1++;
        else if(name[0][i]=='E') E1++;
    }

    scanf("%d\n",&n);
    for(i=1; i<=n; i++) scanf("%s\n",name[i]);

    maxmatch=-1;
    maxidx=-1;
    for(i=1; i<=n; i++){
        L2=O2=V2=E2=0;
        for(j=0; j<strlen(name[i]); j++){
            if(name[i][j]=='L') L2++;
            else if(name[i][j]=='O') O2++;
            else if(name[i][j]=='V') V2++;
            else if(name[i][j]=='E') E2++;
        }
        curmatch=((L1+L2+O1+O2)*(L1+L2+V1+V2)*(L1+L2+E1+E2)*(O1+O2+V1+V2)*(O1+O2                                                                             +E1+E2)*(V1+V2+E1+E2))%100;
        if(maxmatch<curmatch){
            maxmatch=curmatch;
            maxidx=i;
        }
        else if(maxmatch==curmatch){
            if(strcmp(name[maxidx],name[i])>0) maxidx=i;
        }
    }
    printf("%s\n",name[maxidx]);
    return 0;
}