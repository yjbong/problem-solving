#include <cstdio>
int cases;
int towns,days,prison;
int t;
int a[55][55];
int e[55];
double d[111][55];
int main(void){

        scanf("%d",&cases);
        while(cases--){
                scanf("%d %d %d",&towns,&days,&prison);
                for(int i=0; i<towns; i++)
                        for(int j=0; j<towns; j++) scanf("%d",&a[i][j]);

                for(int i=0; i<towns; i++){
                        e[i]=0;
                        for(int j=0; j<towns; j++) if(a[i][j]) e[i]++;
                }
                for(int i=0; i<=days; i++)
                        for(int j=0; j<towns; j++) d[i][j]=0;
                d[0][prison]=1.0;

                for(int i=1; i<=days; i++){
                        for(int j=0; j<towns; j++){
                                for(int k=0; k<towns; k++){
                                        if(a[k][j]) d[i][j]+=d[i-1][k]/e[k];
                                }
                        }
                }

                scanf("%d",&t);
                while(t--){
                        int curtown;
                        scanf("%d",&curtown);
                        printf("%.15lf ",d[days][curtown]);
                }
                printf("\n");
        }
        return 0;
}