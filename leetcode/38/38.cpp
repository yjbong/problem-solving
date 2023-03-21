class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        string ns;
        char cnum='?';
        int ccnt=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=cnum){
                if(ccnt>0){
                    ns=ns+to_string(ccnt)+cnum;
                }
                cnum=s[i];
                ccnt=1;
            }
            else ccnt++;
        }
        ns=ns+to_string(ccnt)+cnum;

        return ns;
    }
};