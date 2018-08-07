#include <cstdio>
int t,n;
int L[111]; // L[i] = left child of node i
int R[111]; // R[i] = right child of node i
int K[111]; // K[i] = key of node i
bool isK[1111]; // isK[i] = true if Key value i exists
bool isRoot[111]; // isRoot[i] = true if node i is root of bst

bool isValid(int root, int lower_bound, int upper_bound){
	if(root==0) return true; // empty tree is always valid
	else if(K[root]<lower_bound || K[root]>upper_bound) return false; // key value should be between lower & upper bound
	else return isValid(L[root], lower_bound, K[root]-1) && isValid(R[root], K[root]+1, upper_bound);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d %d %d",&L[i],&R[i],&K[i]);

		// check if key values are unique
		bool isUniqueVal=true;
		for(int i=0; i<=1000; i++) isK[i]=false;
		for(int i=1; i<=n; i++){
			if(isK[K[i]]){isUniqueVal=false; break;}
			else isK[K[i]]=true;
		}
		if(!isUniqueVal){ printf("NO\n"); continue; }

		// find root of bst
		for(int i=1; i<=n; i++) isRoot[i]=true;
		for(int i=1; i<=n; i++)
			isRoot[L[i]]=isRoot[R[i]]=false;

		bool isUniqueRoot=true;
		int root=0;
		for(int i=1; i<=n; i++){
			if(isRoot[i]){
				if(root>0){ isUniqueRoot=false; break; }
				else root=i;
			}
		}
		if(!isUniqueRoot){ printf("NO\n"); continue; }

		// check if given bst is valid
		bool isValidBST = isValid(root, 0, 1000);
		if(isValidBST) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}