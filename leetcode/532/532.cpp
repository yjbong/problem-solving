class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int left=i+1, right=n-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(nums[mid]<nums[i]+k) left=mid+1;
                else if(nums[mid]>nums[i]+k) right=mid-1;
                else{ ans++; break; }
            }
        }
        return ans;
    }
};