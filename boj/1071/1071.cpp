#include <cstdio>
#include <algorithm>
int n;
int a[50];

// a[from]에 있는 값을 a[to]로 이동 (from>to)
void moveAndShift(int a[], int n, int from, int to){
	int fromVal=a[from];
	for(int i=from-1; i>=to; i--) a[i+1]=a[i]; // shift
	a[to]=fromVal; // move
}

int main(void){
	while(scanf("%d",&n) == 1){
		for(int i=0; i<n; i++) scanf("%d",&a[i]);
		std::sort(a,a+n);

		//for(int i=0; i<n; i++) printf("%d ",a[i]);
		//printf("\n");

		bool go;
		do{
			go=false;
			for(int i=0; i<n-1; i++){
				// 문제의 정렬 조건에 위배되는 경우 발생
				if(a[i+1]==a[i]+1){
					go=true;

					bool biggerNumExist=false;
					for(int j=i+2; j<n; j++){
						// a[i]와 a[i+1] 사이에 넣을 수 있는 숫자가 존재함
						if(a[j]>a[i+1]){
							biggerNumExist=true;
							moveAndShift(a,n,j,i+1);
							break;
						}
					}

					// a[i+1]보다 큰 숫자가 존재하지 않는 경우
					if(!biggerNumExist){
						go=false;

						// TODO: a[i+1]과 같은 숫자들이 a[i]와 같은 숫자들보다 먼저 나오게 순서를 바꿈
						int preNum=a[i];
						int curNum=a[i+1];

						int putIdx=n-1;
						for(int j=i; j>=0; j--){
							if(a[j]==preNum) putIdx=j;
							else break;
						}

						int curNums=0; // 끝에서부터 연속된 curNum의 개수
						for(int j=n-1; j>=0; j--){
							if(a[j]==curNum) curNums++;
							else break;
						}

						for(int j=0; j<curNums; j++){
							moveAndShift(a,n,n-1,putIdx+j);
						}
					}
					break;
				}
			}

			//printf("current sequence: ");
			//for(int j=0; j<n; j++) printf("%d ",a[j]);
			//printf("\n");
		}while(go);

		for(int j=0; j<n; j++) printf("%d ",a[j]);
		printf("\n");
	}

	return 0;
}