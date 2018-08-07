#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack <char> s;
int c;
char str[11111];
int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%s",str);
                int len=strlen(str);
                while(!s.empty()) s.pop();
                for(int i=0; i<len; i++){
                        if(s.empty()) s.push(str[i]);
                        else if(s.top()=='[' && str[i]==']') s.pop();
                        else if(s.top()=='(' && str[i]==')') s.pop();
                        else if(s.top()=='{' && str[i]=='}') s.pop();
                        else s.push(str[i]);
                }
                if(s.empty()) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}