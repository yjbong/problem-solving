#include <cstdio>
int org_clock[16];
int new_clock[16];
bool sw[10][16];
int main(void){

        for(int i=0; i<10; i++)
                for(int j=0; j<16; j++) sw[i][j]=false;

        sw[0][0]=sw[0][1]=sw[0][2]=true;
        sw[1][3]=sw[1][7]=sw[1][9]=sw[1][11]=true;
        sw[2][4]=sw[2][10]=sw[2][14]=sw[2][15]=true;
        sw[3][0]=sw[3][4]=sw[3][5]=sw[3][6]=sw[3][7]=true;
        sw[4][6]=sw[4][7]=sw[4][8]=sw[4][10]=sw[4][12]=true;
        sw[5][0]=sw[5][2]=sw[5][14]=sw[5][15]=true;
        sw[6][3]=sw[6][14]=sw[6][15]=true;
        sw[7][4]=sw[7][5]=sw[7][7]=sw[7][14]=sw[7][15]=true;
        sw[8][1]=sw[8][2]=sw[8][3]=sw[8][4]=sw[8][5]=true;
        sw[9][3]=sw[9][4]=sw[9][5]=sw[9][9]=sw[9][13]=true;


        int cases;
        scanf("%d",&cases);
        while(cases--){

                for(int i=0; i<16; i++){
                        scanf("%d",&org_clock[i]);
                        org_clock[i]/=3;
                        if(org_clock[i]==4) org_clock[i]=0;
                }

                int ans=-1;
                for(int i=0; i<(1<<20); i++){
                        int t=i;
                        int push=0;

                        for(int j=0; j<16; j++) new_clock[j]=org_clock[j];
                        for(int j=0; j<10; j++){
                                int cur_push = (t>>(j*2)) % 4;
                                push+=cur_push;
                                for(int k=0; k<16; k++){
                                        if(sw[j][k]) new_clock[k]=(new_clock[k]+cur_push)%4;
                                }
                        }

                        bool ok=true;
                        for(int j=0; j<16; j++){
                                if(new_clock[j]!=0){
                                        ok=false;
                                        break;
                                }
                        }

                        if(ok){
                                if(ans<0 || ans>push) ans=push;
                        }
                }
                printf("%d\n", ans);
        }
        return 0;
}