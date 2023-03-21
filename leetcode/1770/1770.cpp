class Solution {
public:
    
    int cache[1001][1001];
    const int nan=-2000000000;
    int solve(vector<int>& nums, vector<int>& multipliers, int lstep, int rstep){
        if(lstep+rstep==multipliers.size()) return 0;
        if(cache[lstep][rstep]>nan) return cache[lstep][rstep];
        
        int lidx=lstep;
        int ridx=nums.size()-1-rstep;
        return cache[lstep][rstep]=max(
            nums[lidx]*multipliers[lstep+rstep]+
            solve(nums,multipliers,lstep+1,rstep),
            nums[ridx]*multipliers[lstep+rstep]+
            solve(nums,multipliers,lstep,rstep+1)
        );
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i=0; i<=1000; i++)
            for(int j=0; j<=1000; j++)
                cache[i][j]=nan;
        return solve(nums,multipliers,0,0);
    }
};