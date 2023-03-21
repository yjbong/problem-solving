class Solution {
public:
    int mySqrt(int x) {
        long long ans=0;
        long long left=0, right=2147483647;
        while(left<=right){
            long long mid=(left+right)>>1;
            if(mid*mid>x) right=mid-1;
            else{
                if(ans<mid) ans=mid;
                left=mid+1;
            }
        }
        return (int)ans;
    }
};