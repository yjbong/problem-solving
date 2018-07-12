#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

int n; // # of employees
int m; // # of queries

// segment tree
int base;
ll tree[1<<20];


// input data
ll salary[500001];
int parent[500001];
vector <int> child[500001];
char query[100];

// mapping data
int curNewNum;
int oldToNew[500001]; // oldToNew[i] = j when original number i is mapped to new number j
int newToOld[500001]; // newToOld[i] = j when new number i mapped to original number j
int range[500001][2]; // range[a][0], [a][1] = update range for "p a x" (a is old number, but range uses new number)


int min2(int a, int b) { return a<b?a:b; }

// postorder
void settingNewNumber(int idx){

	for(int i=0; i<child[idx].size(); i++)
		settingNewNumber(child[idx][i]);

	oldToNew[idx]=curNewNum;
	newToOld[curNewNum]=idx;
	curNewNum++;
}

// dfs
int findLeftRange(int idx){
	if(range[idx][0]!=0) return range[idx][0];

	int ret=oldToNew[idx];
	for(int i=0; i<child[idx].size(); i++)
		ret=min2(ret,findLeftRange(child[idx][i]));
	
	return (range[idx][0]=ret);
}


void updateSalary(int a, ll x){
	int left=range[a][0]-1+base;
	int right=range[a][1]-1+base;
	while(left<right){
		if(left%2==0) left/=2;
		else{
			tree[left]+=x;
			left=(left+1)/2;
		}

		if(right%2==1) right/=2;
		else{
			tree[right]+=x;
			right=(right-1)/2;
		}
	}

	if(left==right) tree[left]+=x;
}

ll printSalary(int a){
	
	ll ret=0;
	int curIdx=oldToNew[a]-1+base;
	while(curIdx>0){
		ret+=tree[curIdx];
		curIdx/=2;
	}
	return ret;
}


int main(void){

	// process input
	scanf("%d %d",&n,&m);
	scanf("%lld",&salary[1]); parent[1]=0; // no parent for 1
	for(int i=2; i<=n; i++){
		scanf("%lld %d",&salary[i],&parent[i]);
		child[parent[i]].push_back(i);
	}

	// setting new number by postorder traversal
	curNewNum=1;
	settingNewNumber(1);

	// setting update range for update query "p a x"
	findLeftRange(1);
	for(int i=1; i<=n; i++){
		range[i][1]=oldToNew[i]-1;
		//printf("oldNum %d --> newNum %d --> new range (%d to %d)\n",i,oldToNew[i], range[i][0], range[i][1]);
	}

	// init segment tree
	base=1;
	while(base<n) base*=2;

	for(int i=1; i<=n; i++)
		tree[oldToNew[i]-1+base]=salary[i];
	
	// process queries
	scanf("\n");
	for(int i=0; i<m; i++){
		char type;
		int a; ll x;
		scanf("%c",&type);
		if(type=='p'){
			scanf("%d %lld\n",&a,&x);
			updateSalary(a,x);
		}
		else if(type=='u'){
			scanf("%d\n",&a);
			printf("%lld\n",printSalary(a));
		}
	}
	return 0;
}