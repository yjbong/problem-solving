#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#define INF 1000000000
using namespace std;
int c,n;
vector <int> seq;
int order[8];
int facto[9]; // facto[i] = i!
queue <int> q;
int step[40320]; // 8! = 40320
vector <int> neighbor[9][40320]; // neighbor[i][j] = when input size is i, neighbor seq index list of a seq whose index is j

int get_idx(vector <int> seq, int seq_len){ // return index of current permutation

        int ret=0;
        bool used[8];
        for(int i=0; i<seq_len; i++) used[i]=false;

        for(int i=0; i<seq_len; i++){
                int cur_order=0;
                for(int j=0; j<seq_len; j++){
                        if(j==seq[i]) break;
                        else if(!used[j]) cur_order++;
                }
                used[seq[i]]=true;
                ret+=cur_order*facto[seq_len-1-i];
        }
        return ret;
}

void rev_seq(vector <int> &seq, int start, int end){ // reverse [start~end] of current permutation
        int tmp;
        while(start<end){
                tmp=seq[start];
                seq[start]=seq[end];
                seq[end]=tmp;
                start++;
                end--;
        }
}

void precalc_neighbor(){
        vector <int> tmp;
        for(int i=1; i<=8; i++){
                tmp.clear();
                for(int j=0; j<i; j++) tmp.push_back(j);
                int cnt=0;
                do{
                        for(int j=0; j<i; j++){
                                for(int k=j+1; k<i; k++){
                                        rev_seq(tmp,j,k);
                                        int cur_idx=get_idx(tmp,i);
                                        neighbor[i][cnt].push_back(cur_idx);
                                        rev_seq(tmp,j,k);
                                }
                        }
                        cnt++;
                }while(next_permutation(tmp.begin(),tmp.end()));
        }
}

int main(void){

        //freopen("input", "r", stdin);

        scanf("%d",&c);
        facto[0]=1;
        for(int i=1; i<=8; i++) facto[i]=facto[i-1]*i;
        precalc_neighbor();

        while(c--){
                // init input
                seq.clear();
                scanf("%d",&n);
                for(int i=0; i<n; i++){
                        int a;
                        scanf("%d",&a);
                        seq.push_back(a);
                }
                for(int i=0; i<n; i++){
                        order[i]=0;
                        for(int j=0; j<n; j++) if(seq[i]>seq[j]) order[i]++;
                }
                seq.clear();
                for(int i=0; i<n; i++) seq.push_back(order[i]);

                // init queue and cache
                while(!q.empty()) q.pop();
                for(int i=0; i<facto[n]; i++) step[i]=INF;

                int seq_idx=get_idx(seq,n);
                q.push(seq_idx);
                step[seq_idx]=0;
                while(!q.empty()){
                        int front=q.front(); q.pop();
                        for(int i=0; i<neighbor[n][front].size(); i++){
                                int cur_idx=neighbor[n][front][i];
                                if(step[cur_idx]>step[front]+1){
                                        step[cur_idx]=step[front]+1;
                                        q.push(cur_idx);
                                }
                        }
                }

                // print answer
                printf("%d\n",step[0]);
        }
        return 0;
}