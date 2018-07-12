#include <cstdio>
#include <stack>
#define MAX_N 500000
using namespace std;
typedef long long ll;
typedef pair<int,ll> ii; // first: idx, second: s[idx] 값

int n; // 수열의 길이
ll x; // 목표 수
ll a[MAX_N+1]; // 수열 (idx=1부터 시작)
ll s[MAX_N+1]; // s[i]=a[1]+a[2]+...+a[i]

stack <ii> stk;

ii searchList[MAX_N+1]; // searchList=의미있는 (idx,s[idx]) 쌍의 집합
int searchSize; // searchList의 크기

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld",&n,&x);
		for(int i=1; i<=n; i++) scanf("%lld",&a[i]);

		// s계산
		s[0]=0;
		for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];

		for(int i=1; i<=n; i++){
			// idx가 작으면서 s[idx]값이 작지 않은 쌍은 이진 탐색 시 불필요한 데이터
			while(!stk.empty() && stk.top().first<i && stk.top().second>=s[i]) stk.pop();
			stk.push(make_pair(i,s[i]));
		}
		/*
		for(int i=1; i<=n; i++) printf("s[%d]=%lld, ",i,s[i]);
		printf("\n");
		*/
		int searchSize=stk.size();
		int tmp=searchSize-1;
		while(!stk.empty()){
			searchList[tmp--]=stk.top();
			stk.pop();
		}
		/*
		for(int i=0; i<searchSize; i++){
			printf("s[%d]=%lld\n",searchList[i].first,searchList[i].second);
		}
		*/
		int ans=-1;
		for(int i=1; i<=n; i++){
			// 구간의 끝 인덱스를 i로 고정
			// 구간의 시작 인덱스가 1인 경우
			if(s[i]>=x){ // 구간 a[1~i]의 합이 x이상인 경우
				if(ans<0 || ans>i){
					ans=i;
					//printf("ans = a[%d~%d]\n", 1, i);
				}
			}
			
			// 이외의 경우 구간의 (시작 인덱스-1)을 이진 탐색
			int left=0, right=searchSize-1;
			while(left<=right){
				int mid=(left+right)/2;
				if(searchList[mid].first>=i){ // 빈 구간(시작 인덱스가 끝 인덱스를 역전)인 경우
					right=mid-1; // 시작 인덱스를 감소시킨다 (구간 크기 증가)
				}
				// 구간 a[searchList[mid].first+1~i]의 합이 x이상인 경우
				else if(s[i]-s[searchList[mid].first]>=x){
					if(ans<0 || ans>i-searchList[mid].first){
						ans=i-searchList[mid].first;
						//printf("ans = a[%d~%d]\n", searchList[mid].first+1, i);
					}
					left=mid+1; // 시작 인덱스를 증가시킨다 (구간 크기 감소)
				}
				// 구간 a[searchList[mid].first+1~i]의 합이 x미만인 경우
				else{
					right=mid-1; // 시작 인덱스를 감소시킨다 (구간 크기 증가)
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}