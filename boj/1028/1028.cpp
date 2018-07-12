#include <stdio.h>
int b[750+2][750+2];
int d[750+2][750+2][2];
int main(void){

    int r,c,i,j,k;
    int max,lim;
    scanf("%d %d",&r,&c);
    for(i=0; i<=r+1; i++){
        b[i][0]=0;
        b[i][c+1]=0;
        d[i][0][0]=0;
        d[i][0][1]=0;
        d[i][c+1][0]=0;
        d[i][c+1][1]=0;
    }
    for(i=0; i<=c+1; i++){
        b[0][i]=0;
        b[r+1][i]=0;
        d[0][i][0]=0;
        d[0][i][1]=0;
        d[r+1][i][0]=0;
        d[r+1][i][1]=0;
    }
    for(i=1; i<=r; i++){
        for(j=1; j<=c; j++){
            scanf("%1d",&b[i][j]);
        }
    }

    for(i=r; i>=1; i--){
        for(j=c; j>=1; j--){

            if(b[i][j]==1){

                if(b[i+1][j-1]==1) d[i][j][0]=d[i+1][j-1][0]+1;
                else d[i][j][0]=1;

                if(b[i+1][j+1]==1) d[i][j][1]=d[i+1][j+1][1]+1;
                else d[i][j][1]=1;
            }
            else{
                d[i][j][0]=0;
                d[i][j][1]=0;
            }
        }
    }

    max=0;
    for(i=1; i<=r; i++){
        for(j=1; j<=c; j++){

            if(d[i][j][0]<d[i][j][1]) lim=d[i][j][0];
            else lim=d[i][j][1];

            for(k=max+1; k<=lim; k++){
                if(i+(k-1)>r || j-(k-1)<1 || j+(k-1)>c) break;
                if(d[i+(k-1)][j-(k-1)][1]>=k && d[i+(k-1)][j+(k-1)][0]>=k) max=k;
            }
        }
    }

    printf("%d\n",max);
    return 0;
}