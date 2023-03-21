class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int s,e;
        s=e=0;
        int sum=nums[0];
        int ans=sum;
        while(true){
            if(sum<0){
                e++; s=e;
                if(s==n) break;
                sum=nums[s];
                if(ans<sum) ans=sum;
            }
            else{
                if(e<n-1){
                    e++;
                    sum+=nums[e];
                    if(ans<sum) ans=sum;
                }
                else break;
            }
        }
        return ans;
    }
};