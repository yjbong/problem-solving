#include <cstdio>
#include <map>
using namespace std;
map <int,int> idx;
int N;
int A[1000000];
int main() {
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	for(int i=0; i<N; i++) idx[A[i]]=0;
	map<int,int>::iterator it;
    int c=0;
	for(it=idx.begin(); it!=idx.end(); it++, c++) it->second=c;
	for(int i=0; i<N; i++) printf("%d ",idx[A[i]]);
	printf("\n");
	return 0;
}