#include <cstdio>
#include <vector>
using namespace std;
int N; // 멀티탭 구멍 개수
int refSize; // 전기 용품 총 사용 횟수

int ref[111]; // 전기 용품 사용 순서

vector <int> tap; // 멀티탭 상태

int main(void){

	scanf("%d %d",&N,&refSize);
	for(int i=0; i<refSize; i++) scanf("%d",&ref[i]);

	int ans=0;
	for(int i=0; i<refSize; i++){

		// 현재 사용할 물건(ref[i])이 이미 꽂혀 있는지 확인
		bool exist=false;
		for(int j=0; j<tap.size(); j++)
			if(tap[j]==ref[i]){ exist=true; break; }
		if(exist) continue; // 이미 꽂혀 있으면 무시함

		// 빈 자리가 있는 경우 그냥 꽂음
		if(tap.size()<N) tap.push_back(ref[i]);

		else{
			int del=-1; // 제거할 멀티탭 위치
			int delUse=-1; // 제거할 멀티탭에 꽂힌 물건이 이후에 쓰일 시점

			 // 제거 대상 선정 (OPT 알고리즘)
			for(int j=0; j<tap.size(); j++){
				int curUse=-1; // 현재 고려 중인 물건이 이후에 쓰일 시점
				for(int k=i; k<refSize; k++)
					if(tap[j]==ref[k]){ curUse=k; break; }

				if(curUse<0) curUse=refSize; // 이 물건이 앞으로 안 쓰이는 경우
				
				if(del<0 || delUse<curUse){ // 현재 고려한 물건이 뽑기로 한 물건보다 더 뒤에 쓰일 경우
					del=j;
					delUse=curUse;
				}
			}

			if(del>=0){
				tap.erase(tap.begin()+del); // 교체 대상 제거
				tap.push_back(ref[i]); // ref[i]를 꽂음
				ans++; // 뽑는 횟수 증가
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}