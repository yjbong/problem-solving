#include <cstdio>
#define INF 1000000000
int n,w;
int d[11111][5];
// d[i][0] = i열까지 모두 채웠을 때 최소 특수 소대 개수
// d[i][1] = i열까지 모두 채우고, (i+1,0)을 채웠을 때
// d[i][2] = i열까지 모두 채우고, (i+1,1)을 채웠을 때
// d[i][3] = i열까지 모두 채우고, (i+1,0), (i+2,0)을 채웠을 때
// d[i][4] = i열까지 모두 채우고, (i+1,1), (i+2,1)을 채웠을 때

int e[11111][2]; // e[i][j] = (i,j)에 있는 적의 수. 가장 처음 셀은 (1,0)

void init_table(){
        for(int i=0; i<=n; i++)
                for(int j=0; j<5; j++) d[i][j]=INF;
}

void make_table(){

        for(int i=1; i<=n; i++){
                int tmp;

                // update d[i][0]
                tmp = d[i-1][0] + (e[i][0]+e[i][1]<=w ? 1 : 2);
                if(d[i][0] > tmp) d[i][0] = tmp;
                tmp = d[i-1][1] + 1;
                if(d[i][0] > tmp) d[i][0] = tmp;
                tmp = d[i-1][2] + 1;
                if(d[i][0] > tmp) d[i][0] = tmp;
                if(i-2>=0){
                        tmp = d[i-2][3] + (e[i-1][1]+e[i][1]<=w ? 1 : 2);
                        if(d[i][0] > tmp) d[i][0] = tmp;
                        tmp = d[i-2][4] + (e[i-1][0]+e[i][0]<=w ? 1 : 2);
                        if(d[i][0] > tmp) d[i][0] = tmp;
                }

                // update d[i][1]
                if(i+1<=n){
                        tmp = d[i][0] + 1;
                        if(d[i][1] > tmp) d[i][1] = tmp;
                        tmp = d[i-1][2] + (e[i][0]+e[i+1][0]<=w ? 1 : 2);
                        if(d[i][1] > tmp) d[i][1] = tmp;
                }

                // update d[i][2]
                if(i+1<=n){
                        tmp = d[i][0] + 1;
                        if(d[i][2] > tmp) d[i][2] = tmp;
                        tmp = d[i-1][1] + (e[i][1]+e[i+1][1]<=w ? 1 : 2);
                        if(d[i][2] > tmp) d[i][2] = tmp;
                }

                // update d[i][3]
                if(i+2<=n){
                        tmp = d[i][0] + (e[i+1][0]+e[i+2][0]<=w ? 1 : 2);
                        if(d[i][3] > tmp) d[i][3] = tmp;
                        tmp = d[i][1] + 1;
                        if(d[i][3] > tmp) d[i][3] = tmp;
                }

                // update d[i][4]
                if(i+2<=n){
                        tmp = d[i][0] + (e[i+1][1]+e[i+2][1]<=w ? 1 : 2);
                        if(d[i][4] > tmp) d[i][4] = tmp;
                        tmp = d[i][2] + 1;
                        if(d[i][4] > tmp) d[i][4] = tmp;
                }
        }
}

int main(void){

        int t;
        scanf("%d",&t);
        while(t--){

                int sol;

                scanf("%d %d",&n,&w);

                for(int j=0; j<2; j++)
                        for(int i=1; i<=n; i++) scanf("%d",&e[i][j]);

                if(n==1){
                        e[1][0]+e[1][1]<=w ? sol=1 : sol=2;
                        printf("%d\n",sol);
                        continue;
                }

                sol=INF;

                // case 1: 링의 경계를 넘지 않는 경우
                init_table();
                d[0][0]=0; d[0][1]=1; d[0][2]=1; (e[1][0]+e[2][0]<=w) ? d[0][3]=1 : d[0][3]=2; (e[1][1]+e[2][1]<=w) ? d[0][4]=1 : d[0][4]=2;
                make_table();
                if(sol>d[n][0]) sol=d[n][0];

                // case 2: 0행의 경계를 넘는 경우
                if(e[1][0]+e[n][0]<=w){
                        init_table();
                        d[0][0]=INF; d[0][1]=0; d[0][2]=INF; d[0][3]=1; d[0][4]=INF;
                        make_table();
                        if(sol>d[n-1][2]+1) sol=d[n-1][2]+1;
                }

                // case 3: 1행의 경계를 넘는 경우
                if(e[1][1]+e[n][1]<=w){
                        init_table();
                        d[0][0]=INF; d[0][1]=INF; d[0][2]=0; d[0][3]=INF; d[0][4]=1;
                        make_table();
                        if(sol>d[n-1][1]+1) sol=d[n-1][1]+1;
                }

                // case 4: 1, 2행의 경계를 넘는 경우
                if(e[1][0]+e[n][0]<=w && e[1][1]+e[n][1]<=w){
                        init_table();
                        d[0][0]=INF; d[0][1]=INF; d[0][2]=INF; d[0][3]=INF; d[0][4]=INF;
                        d[1][0]=0;
                        make_table();
                        if(sol>d[n-1][0]+2) sol=d[n-1][0]+2;
                }

                printf("%d\n",sol);
        }

        return 0;
}