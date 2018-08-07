#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int t,n,m;
char name[50][11];
char curname[11];

vector <int> edible[50]; // edible[i] : list of dish that friend i can eat
vector <int> eater[50]; // eater[i] : list of friend who eat dish i
int dish[50]; // dish[i] : # of currently served dish that friend i can eat

int best;
void go(int selects){

    if(best<=selects) return; // pruning

    int cur_friend=-1; // first friend who can't eat any dish now
    for(int i=0; i<n; i++){
        if(dish[i]==0){
            cur_friend=i;
            break;
        }
    }
    if(cur_friend<0){ // every friend can eat some dish
        if(best>selects) best=selects;
        return;
    }

    for(int i=0; i<edible[cur_friend].size(); i++){ // serve a dish that current friend can eat
        int cur_dish=edible[cur_friend][i];
        for(int j=0; j<eater[cur_dish].size(); j++) dish[eater[cur_dish][j]]++;
        go(selects+1);
        for(int j=0; j<eater[cur_dish].size(); j++) dish[eater[cur_dish][j]]--;
    }
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%s",name[i]);

        for(int i=0; i<n; i++) edible[i].clear();
        for(int i=0; i<m; i++) eater[i].clear();

        for(int i=0; i<m; i++){
            int tmp;
            scanf("%d",&tmp);
            for(int j=0; j<tmp; j++){
                scanf("%s",curname);
                for(int k=0; k<n; k++){
                    if(!strcmp(curname,name[k])){ // friend k can eat dish i
                        edible[k].push_back(i);
                        eater[i].push_back(k);
                    }
                }
            }
        }

        for(int i=0; i<n; i++) dish[i]=0;
        best=m;
        go(0);
        printf("%d\n",best);
    }
    return 0;
}