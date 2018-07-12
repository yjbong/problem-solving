#include <cstdio>
#include <set>
using namespace std;
int na; // n(A) : size of set A
int nb; // n(B) : size of set B

set <int> A;

int main(void){

	scanf("%d %d",&na,&nb);
	// make set A
	for(int i=0; i<na; i++){
		int num;
		scanf("%d",&num);
		A.insert(num);
	}
	// delete elements from A which is included in set B
	for(int i=0; i<nb; i++){
		int num;
		scanf("%d",&num);
		if(A.size()>0){
			set<int>::iterator it=A.find(num);
			if(it!=A.end()) A.erase(it);
		}
	}

	// print answer
	if(A.size()>0){
		printf("%d\n",A.size());
		set<int>::iterator it;
		for(it=A.begin(); it!=A.end(); it++)
			printf("%d ",*it);
		printf("\n");
	}
	else printf("0\n");

	return 0;
}