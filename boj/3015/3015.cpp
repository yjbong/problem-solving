#include <cstdio>
#include <stack>
#include <utility>
using namespace std;
typedef pair<int,int> ii;

int n; // # of people
int h[500000]; // h[i] : height of i-th person

stack <ii> st; // each entry's first : height, second : count

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&h[i]);

	long long ans=0;
	for(int i=0; i<n; i++){
		if(st.empty()) st.push(make_pair(h[i],1));
		else{
			if(h[i]>st.top().first){
				while(!st.empty() && h[i]>st.top().first){
					ans+=st.top().second;
					st.pop();
				}
			}

			if(!st.empty()){
				if(h[i]==st.top().first){
					ans+=st.top().second;
					st.top().second++;
					if(st.size()>1) ans++;
				}
				else if(h[i]<st.top().first){
					st.push(make_pair(h[i],1));
					ans++;
				}
			}
			else st.push(make_pair(h[i],1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}