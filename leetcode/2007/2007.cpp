class Solution {
public:
    int cnt[100001]={0,};
    vector<int> findOriginalArray(vector<int>& changed) {
        int maxNum=0;
        for(int i=0; i<changed.size(); i++){
            if(maxNum<changed[i])
                maxNum=changed[i];
            cnt[changed[i]]++;
        }
        
        vector<int> ans;
        if(cnt[0]%2) return ans;
        for(int i=0; i<cnt[0]/2; i++)
            ans.push_back(0);
        
        for(int i=maxNum; i>=1; i--){
            if(cnt[i]==0) continue;
            if(i%2==0 && cnt[i/2]>=cnt[i]){
                for(int j=0; j<cnt[i]; j++)
                    ans.push_back(i/2);
                cnt[i/2]-=cnt[i];
                cnt[i]=0;
            }
            else return vector<int>();
        }
        
        return ans;
    }
};