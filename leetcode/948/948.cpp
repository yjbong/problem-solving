class Solution {
public:
    int sum[1000]; // sum[i]=power[1]+power[2]+...+power[i]
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        if(tokens.size()==0) return 0;
        sort(tokens.begin(),tokens.end());
        if(tokens[0]>power) return 0;
        
        //최소 power 코인은 무조건 up으로 해야 한다.
        power-=tokens[0];
        int score=1;
        
        int n=tokens.size();
        if(n==1) return 1;
        
        sum[1]=tokens[1];
        for(int i=2; i<n; i++)
            sum[i]=sum[i-1]+tokens[i];
        
        for(int i=n; i>=1; i--){
            // n-1번부터 i번 코인을 down으로 했을 때 사용할 수 있는 power
            int powerSum=power+sum[n-1]-sum[i-1];
            
            int left=1, right=i-1;
            while(left<=right){
                int mid=(left+right)/2;
                // 1번부터 mid번 코인을 up 하기 위해 필요한 power
                int powerNeed=sum[mid];
                
                if(powerNeed<=powerSum){
                    if(score<1+mid-(n-i)) score=1+mid-(n-i);
                    left=mid+1;
                }
                else right=mid-1;
            }
        }
        return score;
    }
};