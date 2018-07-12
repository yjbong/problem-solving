#include <cstdio>
#include <cstring>
#define SWAP(a,b,t) {t=a;a=b;b=t;}
char a[3][111];
int t[3][111];
int s[8][8][8];

int d[111][111][111][8];

const int vld[8][8]={{0,1,2,3,4,5,6},{0,2,4,6},{0,1,4,5},{0,4},{0,1,2,3},{0,2},{                                                            0,1},{}};
const int vlds[8]={7,4,4,2,4,2,2,0};

int score(int a, int b, int c){

    int t;
    if(c>b) SWAP(c,b,t);
    if(b>a) SWAP(b,a,t);
    if(c>b) SWAP(c,b,t);

    if(a==b && b==c) return 3;
    else if(a==b && c==0) return 1;
    else return 0;
}

int main(void){

    int len[3];

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            for(int k=0; k<8; k++) s[i][j][k]=score(i,j,k);

    for(int i=0; i<3; i++) scanf("%s",a[i]);
    for(int i=0; i<3; i++) len[i]=strlen(a[i]);

    t[0][0]=t[1][0]=t[2][0]=-1;
    for(int i=0; i<3; i++)
        for(int j=1; j<=len[i]; j++) t[i][j]=a[i][j-1]-'A'+1;

    for(int i=0; i<=len[0]; i++)
        for(int j=0; j<=len[1]; j++)
            for(int k=0; k<=len[2]; k++)
                for(int l=0; l<8; l++) d[i][j][k][l]=-1;

    d[0][0][0][0]=0;
    for(int i=0; i<=len[0]; i++){
        for(int j=0; j<=len[1]; j++){
            for(int k=0; k<=len[2]; k++){
                if(i>0 && j>0 && k>0){
                    int max=d[i-1][j-1][k-1][0];
                    for(int l=1; l<vlds[0]; l++){
                        int cur=d[i-1][j-1][k-1][vld[0][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][0]=-1;
                    else d[i][j][k][0]=max+s[ t[0][i] ][ t[1][j] ][ t[2][k] ];
                }

                if(i>0 && j>0){
                    int max=d[i-1][j-1][k][0];
                    for(int l=1; l<vlds[1]; l++){
                        int cur=d[i-1][j-1][k][vld[1][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][1]=-1;
                    else d[i][j][k][1]=max+s[ t[0][i] ][ t[1][j] ][ 0 ];
                }

                if(i>0 && k>0){
                    int max=d[i-1][j][k-1][0];
                    for(int l=1; l<vlds[2]; l++){
                        int cur=d[i-1][j][k-1][vld[2][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][2]=-1;
                    else d[i][j][k][2]=max+s[ t[0][i] ][ 0 ][ t[2][k] ];
                }

                if(i>0){
                    int max=d[i-1][j][k][0];
                    for(int l=1; l<vlds[3]; l++){
                        int cur=d[i-1][j][k][vld[3][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][3]=-1;
                    else d[i][j][k][3]=max+s[ t[0][i] ][ 0 ][ 0 ];
                }

                if(j>0 && k>0){
                    int max=d[i][j-1][k-1][0];
                    for(int l=1; l<vlds[4]; l++){
                        int cur=d[i][j-1][k-1][vld[4][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][4]=-1;
                    else d[i][j][k][4]=max+s[ 0 ][ t[1][j] ][ t[2][k] ];
                }

                if(j>0){
                    int max=d[i][j-1][k][0];
                    for(int l=1; l<vlds[5]; l++){
                        int cur=d[i][j-1][k][vld[5][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][5]=-1;
                    else d[i][j][k][5]=max+s[ 0 ][ t[1][j] ][ 0 ];
                }

                if(k>0){
                    int max=d[i][j][k-1][0];
                    for(int l=1; l<vlds[6]; l++){
                        int cur=d[i][j][k-1][vld[6][l]];
                        if(max<cur) max=cur;
                    }
                    if(max<0) d[i][j][k][6]=-1;
                    else d[i][j][k][6]=max+s[ 0 ][ 0 ][ t[2][k] ];
                }
            }
        }
    }

    int sol=d[len[0]][len[1]][len[2]][0];
    for(int l=1; l<7; l++){
        int cur=d[len[0]][len[1]][len[2]][l];
        if(sol<cur) sol=cur;
    }
    printf("%d\n",sol);
    return 0;
}