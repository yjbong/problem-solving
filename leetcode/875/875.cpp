class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1, r=1000000000;
        int ans=r;
        while(l<=r){
            long long m=(l+r)/2;
            long long c=0;
            for(int i=0; i<piles.size(); i++){
                c+=piles[i]/m;
                if(piles[i]%m) c++;
            }
            if(c<=h){
                if(ans>m) ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};