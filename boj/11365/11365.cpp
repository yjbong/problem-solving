#include <iostream>
#include <cstring>
using namespace std;
char s[501];
int main() {
    while(1){
        cin.getline(s,500);
        if(!strcmp(s,"END")) break;
        int l=strlen(s);
        for(int i=l-1; i>=0; i--) cout<<s[i];
        cout<<endl;
    }
	return 0;
}