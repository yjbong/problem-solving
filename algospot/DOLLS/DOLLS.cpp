#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

int t;

//int doll[111111];
vector<pair<int,int> >doll; // doll[i].first : quantity of i-th doll, doll[i].second : original index
ll original_doll_quantity[111111]; // original doll array before sorting
ll total_doll_quantity;
int dolls;

ll use[111111];

ll m;

ll stages;
ll gone[111111]; // gone[i] : num of doll kinds that would be zero quantity after finishing i-th stage
ll min_quantity[111111]; // a minimum quantity of dolls from every kinds that remains at i-th stage

ll max_stage[111111]; // max_stage[i] : maximum possible stages with initial quantity of i-th doll

ll min2(ll a, ll b){
        return a<b?a:b;
}
int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&dolls,&m);
                total_doll_quantity=0;
                doll.clear();
                for(int i=0; i<dolls; i++){
                        ll tmp;
                        scanf("%lld",&tmp);
                        doll.push_back(make_pair(tmp,i));

                        original_doll_quantity[i]=tmp;
                        total_doll_quantity+=tmp;
                        use[i]=0;
                }
                m=min2(m,total_doll_quantity);

                sort(doll.begin(), doll.end());
                /*
                for(int i=0; i<dolls; i++)
                        printf("idx=%d, quantity=%d\n",doll[i].second, doll[i].first);
                printf("\n");
                */

                ll recent_quantity=0;

                min_quantity[0]=0;
                ll stages=1;
                for(int i=0; i<dolls; i++){
                        if(recent_quantity!=doll[i].first){
                                gone[stages]=1;
                                min_quantity[stages]=doll[i].first;
                                stages++;
                                recent_quantity=doll[i].first;

                                max_stage[doll[i].second]=stages-1;
                        }
                        else{
                                gone[stages-1]++;
                                max_stage[doll[i].second]=stages-1;
                        }
                }
                /*
                for(int i=0; i<dolls; i++){
                        printf("max stage of %d-th doll = %d\n", doll[i].second, max_stage[doll[i].second]);
                }

                for(int i=1; i<stages; i++){
                        printf("gone[%d]=%d, min_quantity[%d]=%d\n", i,gone[i],i,min_quantity[i]);
                }
                */

                ll curdolls=dolls;

                // for output //
                ll done_stages=0; // # of done stages for current input m
                ll partial_rounds=0; // # of partially possible rounds of first undone stage
                ll remain_m=m; // # of remained m after doing all of possible rounds (it's for doing naive method)
                ////////////////

                for(int i=1; i<stages; i++){
                        //printf("cur m=%d\n",remain_m);
                        if(remain_m>=(min_quantity[i]-min_quantity[i-1])*curdolls){
                                done_stages++;
                                remain_m-=(min_quantity[i]-min_quantity[i-1])*curdolls;
                        }
                        else{
                                partial_rounds=remain_m/curdolls;
                                remain_m-=(partial_rounds*curdolls);
                                break;
                        }
                        curdolls-=gone[i];
                }
                /*
                printf("done_stages=%d\n",done_stages);
                printf("partial_rounds=%d\n",partial_rounds);
                printf("remain_m=%d\n",remain_m);
                */
                for(int i=0; i<dolls; i++){
                        use[i]+=min_quantity[min2(max_stage[i],done_stages)];
                        if(max_stage[i]>done_stages) use[i]+=partial_rounds;
                }

                // naive method for # of remained m
                for(int i=0; remain_m>0 && i<dolls; i++){
                        if(original_doll_quantity[i] > min_quantity[done_stages]+partial_rounds){
                                remain_m--;
                                use[i]++;
                        }
                }
                //printf("use\n");
                for(int i=0; i<dolls; i++){
                        printf("%lld ",use[i]);
                }
                printf("\n");
        }
        return 0;
}