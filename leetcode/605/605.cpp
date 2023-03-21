class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans=0;
        int curSize;
        if(flowerbed[0]) curSize=-1;
        else curSize=1;
        
        for(int i=1; i<flowerbed.size(); i++){
            if(flowerbed[i]){
                if(curSize>0)
                    ans+=(curSize-1)/2+(curSize-1)%2;
                curSize=-1;
            }
            else curSize++;
        }
        if(curSize>0)
            ans+=curSize/2+curSize%2;
        
        return ans>=n;
    }
};