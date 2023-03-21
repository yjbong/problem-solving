int D[30000]; // D[i] = 지형 height[0~i]에 담을 수 있는 물의 양
int lMax[30000]; // lMax[i] = max(height[0], height[1], ... , height[i])
int rMax[30000]; // rMax[i] = max(height[n-1], height[n-2], ... , height[i])

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;

        lMax[0]=height[0];
        for(int i=1; i<n; i++)
            lMax[i]=max(lMax[i-1],height[i]);
        rMax[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--)
            rMax[i]=max(rMax[i+1],height[i]);
        
        D[0]=0;
        for(int i=1; i<n; i++){
            // D[i]를 구할 때, 인덱스 (i-1) 에 얼마만큼의 물을 채울 수 있는지 확인한다.
            D[i]=D[i-1]+max(0,min(lMax[i-1],rMax[i-1])-height[i-1]);
        }
        return D[n-1];
    }
};