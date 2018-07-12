#include <cstdio>
#include <queue>
#define MAX_RODS 16
#define MAX_LEN 10
int rods; // # of rods
int rod[MAX_RODS]; // rod[i] = length of i-th rod
int dp[1<<MAX_RODS][MAX_RODS*MAX_LEN+1]; // dp[i][j] = 1 if length sum of some subsets of rods is j from the subset with state i
int sum[1<<MAX_RODS]; // sum[i] = length sum of subset of rods with state i

using namespace std;
queue <pair<int,int> > q; // for calculating dp table by BFS
int ans; // area of largest rectangle


int max2(int a, int b){
        return a>b?a:b;
}


void go(int next_rod, int vstate, int hstate){

        if(next_rod == rods){
                if(sum[vstate]%2==0 && dp[vstate][sum[vstate]/2] &&
                   sum[hstate]%2==0 && dp[hstate][sum[hstate]/2]){ // possible to make rectangular

                        ans = max2(ans, (sum[vstate]/2)*(sum[hstate]/2));
                }
                return;
        }

        go(next_rod+1, vstate | (1<<next_rod), hstate);
        go(next_rod+1, vstate, hstate | (1<<next_rod));
        go(next_rod+1, vstate, hstate);
}


int main(void){

        scanf("%d",&rods);
        for(int i=0; i<rods; i++) scanf("%d",&rod[i]);

        // calc sum table
        for(int i=0; i<(1<<rods); i++){
                sum[i]=0;
                for(int j=0; j<rods; j++) if(i&(1<<j)) sum[i]+=rod[j];
        }

        // init dp table
        for(int i=0; i<(1<<rods); i++)
                for(int j=0; j<sum[(1<<rods)-1]; j++) dp[i][j]=0;

        // init queue
        while(!q.empty()) q.pop();

        // run BFS to calc dp table
        q.push(make_pair(0,0));
        dp[0][0]=1;

        while(!q.empty()){
                int fstate = q.front().first;
                int fsum = q.front().second;
                q.pop();

                for(int i=0; i<rods; i++){
                        if( !(fstate & (1<<i) ) ){ // select a rod which hasn't selected yet
                                int cstate = fstate | (1<<i);
                                int csum = fsum;
                                if(!dp[cstate][csum]){ q.push(make_pair(cstate, csum)); dp[cstate][csum]=1; }

                                csum += rod[i];
                                if(!dp[cstate][csum]){ q.push(make_pair(cstate, csum)); dp[cstate][csum]=1; }
                        }
                }
        }

        // run DFS to calc answer (area of largest rectangle)
        ans=0;
        go(0,0,0);
        if(ans==0) ans=-1;
        printf("%d\n",ans);

        return 0;
}