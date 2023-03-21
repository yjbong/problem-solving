class Solution {
public:
    int minP[100000];
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        minP[0]=prices[0];
        for(int i=1; i<n; i++)
            minP[i]=min(prices[i],minP[i-1]);
        for(int i=1; i<n; i++){
            int curAns=prices[i]-minP[i-1];
            if(ans<curAns) ans=curAns;
        }
        return ans;
    }
};