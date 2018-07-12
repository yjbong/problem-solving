#include <cstdio>
#define UNKNOWN 0
#define ALICE 1
#define BOB 2
int d[100][100][100]; // d[i][j][k] = Alice의 차례에 숫자 1의 왼쪽에 연속으로 i개, 오른쪽에 연속으로 j개의 숫자가 있고, 1과 연결되지 않은 숫자들이 k개 있을 때의 승자

int t; // 테스트 케이스 수
int n; // 정사각형의 수 (1~n까지의 숫자)
int a[100]; // a[i] = i번째 정사각형에 쓰인 숫자
int pos1; // 숫자 1의 위치(index)

int win(int leftNumbers, int rightNumbers, int otherNumbers){

	if(d[leftNumbers][rightNumbers][otherNumbers]!=UNKNOWN) return d[leftNumbers][rightNumbers][otherNumbers];

	// Alice의 차례에 1의 양 옆에 숫자가 없다면 Alice가 1을 지울 수 있음
	if(leftNumbers==0 && rightNumbers==0){
		d[leftNumbers][rightNumbers][otherNumbers]=ALICE;
		return d[leftNumbers][rightNumbers][otherNumbers];
	}

	// case 1: 1의 왼쪽 연속구간에서 숫자를 지움
	for(int i=pos1-leftNumbers; i<pos1; i++){

		// a[i]를 지울 수 있는지 확인 (a[i-1]과 a[i+1] 위치에 a[i]보다큰 수가 없어야만 가능)
		bool removable = true;
		if(i==pos1-leftNumbers){
			if(a[i]<a[i+1]) removable=false;
		}
		else if(a[i]<a[i+1] || a[i]<a[i-1]) removable=false;

		// a[i]를 지울 수 있는 경우
		if(removable){
			if(win(pos1-(i+1), rightNumbers, otherNumbers + i-(pos1-leftNumbers)) == BOB){
				return (d[leftNumbers][rightNumbers][otherNumbers]=ALICE);
			}
		}
	}

	// case 2: 1의 오른쪽 연속구간에서 숫자를 지움
	for(int i=pos1+rightNumbers; i>pos1; i--){
		bool removable = true;
		if(i==pos1+rightNumbers){
			if(a[i]<a[i-1]) removable=false;
		}
		else if(a[i]<a[i+1] || a[i]<a[i-1]) removable=false;

		if(removable){
			if(win(leftNumbers, (i-1)-pos1, otherNumbers + (pos1+rightNumbers)-i) == BOB){
				return (d[leftNumbers][rightNumbers][otherNumbers]=ALICE);
			}
		}
	}

	// case 3: 1과 연결되어 있지 않은 숫자를 지움
	if(otherNumbers>0){
		if(win(leftNumbers, rightNumbers, otherNumbers-1) == BOB){
			return (d[leftNumbers][rightNumbers][otherNumbers]=ALICE);
		}
	}

	return (d[leftNumbers][rightNumbers][otherNumbers]=BOB);
}

int main(void){

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&a[i]);
		for(int i=0; i<n; i++)
			if(a[i]==1){ pos1=i; break; }

		int initialLeftNumbers = pos1;
		int initialRightNumbers = n-initialLeftNumbers-1;

		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		for(int k=0; k<n; k++)
			d[i][j][k]=UNKNOWN;

		int winner = win(initialLeftNumbers, initialRightNumbers, 0);
		if(winner == ALICE) printf("Alice\n");
		else if(winner == BOB) printf("Bob\n");
	}
	return 0;
}