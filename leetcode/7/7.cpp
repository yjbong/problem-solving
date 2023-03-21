class Solution {
public:
    int dgts[10]={0,};
    const int mini[10]=
        {2,1,4,7,4,8,3,6,4,8};
    const int maxi[10]=
        {2,1,4,7,4,8,3,6,4,7};
    bool minus=false;
    int reverse(int x) {
        if(x==0) return 0;
        if(x==-2147483648) return 0;
        if(x<0){
            minus=true;
            x=-x;
        }
        vector<int> tmp;
        while(x>0){
            tmp.push_back(x%10);
            x/=10;
        }
        for(int i=tmp.size()-1,j=9; i>=0; i--,j--){
            dgts[j]=tmp[i];
        }
        
        // 뒤집은 수가 int 표현 가능한지 확인
        if(minus){
            for(int i=0; i<10; i++){
                if(dgts[i]>mini[i]) return 0;
                else if(dgts[i]<mini[i]) break;
            }
        }
        else{
            for(int i=0; i<10; i++){
                if(dgts[i]>maxi[i]) return 0;
                else if(dgts[i]<maxi[i]) break;
            }
        }
        
        // 뒤집은 수가 int 표현 가능한 경우, 그대로 리턴
        int ans=0;
        for(int i=0; i<10; i++){
            ans*=10;
            if(minus) ans-=dgts[i];
            else ans+=dgts[i];
        }
        return ans;
    }
};