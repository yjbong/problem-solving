class Solution {
public:
    int getNumberOfBytes(vector<int>& data, int idx){
        int n=data.size();
        if(idx>=n) return -1;
        int header=data[idx]&0xff;
        int first1 = header>>7;
        int first3 = header>>5;
        int first4 = header>>4;
        int first5 = header>>3;
        
        if((first1 ^ 0x0) == 0) return 1;
        else if((first3 ^ 0x6) == 0)
        {
            for(int i=idx+1; i<=idx+1; i++)
            {
                if(i>=n) return -1;
                int cdata=data[i]&0xff;
                int first2=cdata>>6;
                if((first2 ^ 0x2) != 0) return -1;
            }
            return 2;
        }
        else if((first4 ^ 0xe) == 0)
        {
            for(int i=idx+1; i<=idx+2; i++)
            {
                if(i>=n) return -1;
                int cdata=data[i]&0xff;
                int first2=cdata>>6;
                if((first2 ^ 0x2) != 0) return -1;
            }
            return 3;
        }
        else if((first5 ^ 0x1e) == 0)
        {
            for(int i=idx+1; i<=idx+3; i++)
            {
                if(i>=n) return -1;
                int cdata=data[i]&0xff;
                int first2=cdata>>6;
                if((first2 ^ 0x2) != 0) return -1;
            }
            return 4;
        }
        else return -1;
    }
    bool validUtf8(vector<int>& data) {
        int idx=0;
        while(idx<data.size()){
            int step=getNumberOfBytes(data, idx);
            if(step<0) return false;
            idx+=step;
        }
        return true;
    }
};