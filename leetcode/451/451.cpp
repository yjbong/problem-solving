class Solution {
public:
    int frq[128];
    string frequencySort(string s) {
        for(int i=0; i<128; i++) frq[i]=0;
        for(int i=0; i<s.length(); i++) frq[s[i]]++;
        sort(s.begin(),s.end(),
            [this](char first, char second) -> bool
        {
            if(frq[first]>frq[second]) return true;
            else if(frq[first]<frq[second]) return false;
            else return first<second;
        });
        return s;
    }
};