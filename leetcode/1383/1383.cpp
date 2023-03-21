class Solution {
public:

    priority_queue <int, vector<int>, greater<int> > pq;
    typedef struct{
        int spd;
        int efy;
    }DATA;
    vector<DATA> data;
    static bool cmp(DATA a, DATA b){
        return a.efy>b.efy;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        for(int i=0; i<n; i++){
            DATA d{speed[i],efficiency[i]};
            data.push_back(d);
        }
        sort(data.begin(),data.end(),cmp);
        long long ans=0;
        long long spdSum=0;
        for(int i=0; i<n; i++){
            int minSpd=pq.size()>0?pq.top():0;
            int curSpd=data[i].spd;
            int curEfy=data[i].efy;
            if(pq.size()<k){
                pq.push(curSpd);
                spdSum+=curSpd;
            }
            else if(minSpd<curSpd){
                pq.pop();
                spdSum-=minSpd;
                pq.push(curSpd);
                spdSum+=curSpd;
            }
            long long curAns=spdSum*curEfy;
            if(ans<spdSum*curEfy)
                ans=spdSum*curEfy;
        }
        return ans%1000000007;
    }
};