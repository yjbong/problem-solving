#include <cstdio>
#include <algorithm>
using namespace std;

int L; // 통나무 길이
int K; // 컷 위치 갯수
int C; // 최대 컷 횟수
int cut[11111]; // 컷 위치

 // 최대 조각 길이가 주어졌을 때, 이를 만족하면서 자를 때 가장 왼쪽 컷의 위치 리턴
int leftMostCut(int limitLen){

	// 가장 왼쪽 위치를 구하기 위해 오른쪽 끝에서부터 시도
	int curPos=L;
	int remainCuts=C;

	int leftIdx, rightIdx=K-1;

	while(remainCuts>0 && curPos>limitLen){
		leftIdx=0;
		// 현재 컷 위치로부터 limitLen을 만족하면서 가장 왼쪽에 있는 컷 위치를 찾음
		int ansIdx=K;
		while(leftIdx<=rightIdx){
			int midIdx=(leftIdx+rightIdx)/2;
			if(curPos-cut[midIdx]<=limitLen){
				if(ansIdx>midIdx) ansIdx=midIdx;
				rightIdx=midIdx-1;
			}
			else leftIdx=midIdx+1;
		}

		if(ansIdx<K){
			curPos=cut[ansIdx];
			rightIdx=ansIdx-1;
			remainCuts--;
		}
		else break;
	}

	if(curPos<=limitLen){
		if(remainCuts>0) return cut[0]; // 컷 횟수가 남아있는 경우 가장 왼쪽 위치에서 한번 더 컷
		else return curPos; // 아닌 경우 현재 위치 리턴
	}
	else return -1;
}

int main(void){

	scanf("%d %d %d",&L,&K,&C);
	for(int i=0; i<K; i++) scanf("%d",&cut[i]);
	sort(cut,cut+K);

	// 답의 하한(left) 구하기
	int left=cut[0];
	for(int i=1; i<K; i++)
		if(left<cut[i]-cut[i-1]) left=cut[i]-cut[i-1];
	
	// 답의 상한(right)
	int right=L;

	// 통나무의 최대 조각 길이에 대한 이진 탐색
	int ans=L;
	int leftmostCutPos;

	while(left<=right){
		int mid=(left+right)/2;
		int curCutPos;
		if((curCutPos = leftMostCut(mid))>=0){ // 현재 최대 조각 길이가 가능한 경우
			if(ans>mid){
				ans=mid;
				leftmostCutPos=curCutPos;
			}
			right=mid-1;
		}
		else left=mid+1; // 가능하지 않은 경우
	}
	// 답 출력
	printf("%d %d\n",ans,leftmostCutPos);

	return 0;
}