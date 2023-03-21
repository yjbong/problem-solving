class Solution {
public:
    
    int firstUniqChar(string s) {
        const int INF=1000000000;
        int idx[26];
        bool valid[26];
        for(int i=0; i<26; i++){
            idx[i]=INF;
            valid[i]=true;
        }
        for(int i=0; i<s.length(); i++){
            int c=s[i]-'a';
            if(valid[c]){
                if(idx[c]>=INF) idx[c]=i;
                else valid[c]=false;
            }
        }
        
        int ans=INF;
        for(int i=0; i<26; i++)
            if(valid[i] && ans>idx[i]) ans=idx[i];
        if(ans>=INF) ans=-1;
        return ans;
    }
};