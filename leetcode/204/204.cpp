class Solution {
public:
    bool isNotP[5000000];
    int countPrimes(int n) {
        isNotP[0]=isNotP[1]=true;
        for(int i=2; i<n; i++)
            if(!isNotP[i])
                for(int j=i*2; j<n; j+=i)
                    isNotP[j]=true;
        
        vector<int> p;
        for(int i=0; i<n; i++)
            if(!isNotP[i]) p.push_back(i);

        int ans=0;
        for(int i=0; i<p.size(); i++){
            if(p[i]<n) ans++;
            else break;
        }
        
        return ans;
    }
};