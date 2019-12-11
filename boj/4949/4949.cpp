#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s;
stack <char> st;
int main() {
    while(1){
        getline(cin, s);
        if(s.compare(".")==0) break;
        //cout << s << endl;
        int slen=s.length();
        bool ok=true;
        while(!st.empty()) st.pop();
        for(int i=0; i<slen && ok; i++){
            if(s[i]=='(' || s[i]=='[') st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty() || st.top()!='(') ok=false;
                else st.pop();
            }
            else if(s[i]==']'){
                if(st.empty() || st.top()!='[') ok=false;
                else st.pop();
            }
        }
        if(!st.empty()) ok=false;
 
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}