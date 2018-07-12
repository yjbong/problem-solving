#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char s[55];
stack <char> stk;
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		while(!stk.empty()) stk.pop();
		bool ok=true;
		for(int i=0; i<strlen(s); i++){
			if(s[i]=='(') stk.push(s[i]);
			else{
				if(!stk.empty()) stk.pop();
				else{ ok=false; break; }
			}
		}
		if(!stk.empty()) ok=false;

		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}