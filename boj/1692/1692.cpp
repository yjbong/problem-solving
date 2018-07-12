#include <cstdio>
#define INF 1000000000
int r;
int a[50][16];
int d[2][1<<16][2];

int push_lsb(int stat, int statlen, int val){ // push val(0 or 1) to lsb of stat
        stat <<= 1;
        stat |= val;
        stat &= ((1<<statlen)-1);
        return stat;
}

int main(void){

        scanf("%d",&r);
        for(int i=0; i<r; i++)
                for(int j=0; j<16; j++)
                        scanf("%1d",&a[i][j]);

        for(int j=0; j<(1<<16); j++)
                for(int k=0; k<2; k++) d[0][j][k]=0;

        int cur=1;
        for(int i=r*16-1; i>=0; i--){

                for(int j=0; j<(1<<16); j++)
                        for(int k=0; k<2; k++) d[cur][j][k]=INF;

                for(int j=0; j<(1<<16); j++){
                        for(int k=0; k<2; k++){

                                int cy=i/16, cx=i%16; int cval;
                                if(a[cy][cx]==0){ // 현재 칸을 뒤집지 않음
                                        cval = d[1-cur][push_lsb(j, 16, 0)][0];
                                        if(d[cur][j][k]>cval) d[cur][j][k]=cval;
                                }

                                if(a[cy][cx]==1){ // 현재 칸을 1번 뒤집음

                                        // 현재 칸을 가로 방향으로만 뒤집는 경우
                                        if(cx==15){
                                                cval = d[1-cur][push_lsb(j, 16, 0)][0];
                                                if(k==0) cval++;
                                                if(d[cur][j][k]>cval) d[cur][j][k]=cval;
                                        }
                                        else{
                                                cval = d[1-cur][push_lsb(j, 16, 0)][1];
                                                if(k==0) cval++;
                                                if(d[cur][j][k]>cval) d[cur][j][k]=cval;
                                        }

                                        // 현재 칸을 세로 방향으로만 뒤집는 경우
                                        cval = d[1-cur][push_lsb(j, 16, 1)][0];
                                        if((j & (1<<15)) == 0) cval++;
                                        if(d[cur][j][k]>cval) d[cur][j][k]=cval;
                                }

                                if(a[cy][cx]==0){ // 현재 칸을 2번 뒤집음

                                        // 현재 칸을 가로 및 세로 방향으로 뒤집음
                                        if(cx==15){
                                                cval = d[1-cur][push_lsb(j, 16, 1)][0];
                                                if(k==0) cval++;
                                        }
                                        else{
                                                cval = d[1-cur][push_lsb(j, 16, 1)][1];
                                                if(k==0) cval++;
                                        }
                                        if((j & (1<<15)) == 0) cval++;

                                        if(d[cur][j][k]>cval) d[cur][j][k]=cval;
                                }
                        }
                }
                cur=1-cur;
        }

        printf("%d\n",d[1-cur][0][0]);
        return 0;
}