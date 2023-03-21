class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int s=0,e=n-1;
        int ans=0;
        while(s<e){
            int w=e-s;
            int h=min(height[s],height[e]);
            ans=max(ans,w*h);
            
            // 작은 쪽이 s인 경우
            if(h==height[s]) s++;
            // 작은 쪽이 e인 경우
            else e--;
        }
        return ans;
    }
};