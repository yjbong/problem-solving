class Solution {
public:
    int D[46];
    int climbStairs(int n) {
        D[0]=1,D[1]=1;
        for(int i=2; i<=n; i++)
            D[i]=D[i-1]+D[i-2];
        return D[n];
    }
};