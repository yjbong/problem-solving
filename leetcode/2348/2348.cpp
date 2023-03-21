class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int len=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0) len=0;
            else ans+=(++len);
        }
        return ans;
    }
};