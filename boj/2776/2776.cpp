#include <cstdio>
#include <algorithm>

int t;
int n,m;

int book1[1000000]; // 수첩1
int book2[1000000]; // 수첩2

int main(void){

	scanf("%d",&t);
	while(t--){
		// 입력
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&book1[i]);
		scanf("%d",&m);
		for(int i=0; i<m; i++) scanf("%d",&book2[i]);

		// 수첩1 소팅
		std::sort(book1,book1+n);

		// 수첩2 질문
		for(int i=0; i<m; i++){

			// 이분 탐색
			bool found=false;
			int left=0, right=n-1;
			while(left<=right){
				int mid=(left+right)/2;
				if(book1[mid]<book2[i]) left=mid+1;
				else if(book1[mid]>book2[i]) right=mid-1;
				else{ found=true; break; }
			}

			if(found) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}