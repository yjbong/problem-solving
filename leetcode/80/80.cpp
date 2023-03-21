class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int curNum=nums[0];
        int cnt=1;
        int k=1;
        for(int i=1; i<n; i++){
            if(nums[i]==curNum){
                if(cnt<2){
                    cnt++;
                    nums[k++]=nums[i];
                }
                else
                    ; // skip
            }
            else{
                curNum=nums[i];
                cnt=1;
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};