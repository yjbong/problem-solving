#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define INF 1000000000
#define MAX_PLAYERS 12
#define MAX_MATCHES 100
#define MAX_V (2+MAX_MATCHES+MAX_PLAYERS)

using namespace std;

// Input
int cases; // # of test cases
int players; // # of players
int matches; // # of total remained match
int curWin[MAX_PLAYERS]; // curWin[i] = current # of wins of player i
pair<int,int> match[MAX_MATCHES]; // match info list

int p0_matches; // # of total remained match for player 0

// For networkFlow
int V; // # of vertices in network flow
int capacity[MAX_V][MAX_V]; // capacity[i][j] = capacity from vertex i to j
int flow[MAX_V][MAX_V]; // flow = flow from vertex i to j

int min2(int a, int b){
    return a<b?a:b;
}

int max2(int a, int b){
    return a>b?a:b;
}

// return possible maximum flow amount from source to sink
int networkFlow(int source, int sink){

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            flow[i][j]=0;

    int totflow=0;

    while(1){
        // finding an augmenting path
        vector <int> pre(V,-1);
        queue <int> q;
        pre[source]=source; // pre[i]=if vertex i is on currently found path, pre[i] is index of previous vertex.
                            //        if vertex i is NOT on the path, pre[i]=-1.
        q.push(source);
        while(!q.empty()){
            int from=q.front(); q.pop();
            for(int to=0; to<V; to++){
                if(capacity[from][to]-flow[from][to]>0 && pre[to]==-1){
                    q.push(to);
                    pre[to]=from;
                }
            }
        }
        // if there's no more augmenting path, terminate.
        if(pre[sink] == -1) break;

        // decide maximum possible flow amount for the augmenting path found now
        int amount=INF;
        for(int p=sink; p!=source; p=pre[p])
            amount=min2(amount,capacity[pre[p]][p]-flow[pre[p]][p]);

        // send flow through the augmenting path
        for(int p=sink; p!=source; p=pre[p]){
            flow[pre[p]][p]+=amount;
            flow[p][pre[p]]-=amount;
        }

        // update return value
        totflow+=amount;
    }
    return totflow;
}

// return true if player 0 can be unique winner with W wins.
bool uniqueWinner(int W){
    // If player 0 cannot make W wins even though he wins every remained matches, return false
    if(curWin[0]+p0_matches<W) return false;

    //// modeling network flow ////

    if(matches>0){
        // initialize
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++) capacity[i][j]=flow[i][j]=0;

        // vertex 0 : source
        // vertex 1 : sink
        // vertex (2~2+matches-1) : match
        // vertex (2+matches~2+matches+players-1) : player

        // capacity from source to each match is 1
        for(int i=2; i<2+matches; i++)
            capacity[0][i]=1;

        // capacity from a match to 2 players who participate in the match is 1
        for(int i=2; i<2+matches; i++)
            capacity[i][2+matches+match[i-2].first]=capacity[i][2+matches+match[i-2].second]=1;

        // capacity from a player to sink is below
        // for player 0, W-curWin[0]
        capacity[2+matches][1]=W-curWin[0];
        // for any other player i, (W-1)-curWin[i]
        for(int i=2+matches+1; i<2+matches+players; i++)
            capacity[i][1]=(W-1)-curWin[i-(2+matches)];

        //// running network flow ////
        int doneMatches=networkFlow(0,1);
        if(doneMatches==matches) return true; // if every match can be done, meeting constraints modeled by network flow
        else return false;
    }
    else return true;
}

int main(void){
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&players,&matches);

        V=2+matches+players;

        for(int i=0; i<players; i++) scanf("%d",&curWin[i]);

        // calc maximum wins except player 0
        int maxWin=curWin[1]; // maxWin = # of maximum win from all players except player 0
        for(int i=1; i<players; i++) maxWin=max2(maxWin,curWin[i]);

        // calc # of player 0's remained matches
        p0_matches=0;
        for(int i=0; i<matches; i++){
            scanf("%d %d",&(match[i].first),&(match[i].second));
            if(match[i].first==0 || match[i].second==0) p0_matches++;
        }

        // get answer
        int ans=-1;
        for(int i=max2(curWin[0],maxWin+1); i<=curWin[0]+matches; i++){
            if(uniqueWinner(i)){
                ans=i; break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}