#include <cstdio>
#define MAX_N 100
int N; // 문제의 수
int avg[MAX_N]; // avg[i] = i번 문제의 평균 점수 * 1000

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int a,b;
		scanf("%d.%d",&a,&b);
		avg[i]=a*1000+b;
	}

	// 평균 점수는 소수 셋째 자리까지이므로, 사람의 수가 1000명을 넘는 경우는 생각하지 않아도 됨
	int ans=1001;
	for(int i=1; i<=1000; i++){

		bool ok=true;

		for(int j=0; j<N; j++){

			bool curOk=false;
			// i명의 응답자가 있을 때, j번 문제의 평균 점수가 avg[j]가 될 수 있는지 확인
			// binary search

			// 각 응답자는 0~10의 점수를 줄 수 있는데, avg[j]는 실제 평균 점수에 1000을 곱한 것이므로,
			// 응답자들도 0, 1*1000, 2*1000, ... , 10*1000 점 중에 1가지를 줄 수 있다고 생각한다

			int left=0, right=i*10*1000; // avg[j]를 맞추기 위해서 응답자들이 줘야 하는 점수의 총합을 구함 
			while(left<=right){
				int mid=(left+right)/2;
				mid=mid/1000*1000; // 응답자들이 줄 수 있는 점수의 총합 역시 1000의 배수일 수 밖에 없음

				if(mid/i==avg[j]){ curOk=true; break; } // 평균이 avg[j]가 되게 점수를 주는 방법이 있음
				else if(mid/i<avg[j]) left=mid+1000;
				else right=mid-1000;
			}
			if(!curOk){ ok=false; break; }
		}

		if(ok){ ans=i; break; }
	}
	printf("%d\n",ans);
	return 0;
}