class Solution {
public:
    // radix sort용
    queue<int> q[10];
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        
        // radix sort
        for(int i=0; i<=10; i++){
            for(int j=0; j<n; j++){
                int tmp=nums[j];
                for(int k=0; k<i; k++) tmp/=10;
                int bucket=tmp%10;
                q[bucket].push(nums[j]);
            }
            
            nums.clear();
            for(int j=0; j<10; j++){
                while(!q[j].empty()){
                    nums.push_back(q[j].front());
                    q[j].pop();
                }
            }
        }
        
        // max gap
        int ans=0;
        for(int i=1; i<n; i++){
            if(ans<nums[i]-nums[i-1])
                ans=nums[i]-nums[i-1];
        }
        return ans;
    }
};