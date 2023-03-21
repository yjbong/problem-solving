class Solution {
public:
    int D[100]; // D[i]=i번 집을 마지막으로 털었을 때의 최대 이익
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        D[0]=nums[0];
        D[1]=nums[1];
        if(n>2) D[2]=D[0]+nums[2];
        for(int i=3; i<n; i++)
            D[i]=max(D[i-2],D[i-3])+nums[i];
        return max(D[n-1],D[n-2]);
    }
};