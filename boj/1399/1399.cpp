#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll dig(ll x){
	while(x>=10){
		ll newX=0;
		while(x>0){ newX+=x%10; x/=10; }
		x=newX;
	}
	return x;
}

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}

int min2(int a, int b){
	return a<b?a:b;
}

const ll dirX[4]={0,1,0,-1}; // 이동 방향 순서 : 북->동->남->서
const ll dirY[4]={1,0,-1,0};

int main(void){

	int t;
	scanf("%d",&t);
	while(t--){
		ll k; // 반복 횟수
		ll m; // 골드 넘버에 곱하는 수
		scanf("%lld %lld",&k,&m);

		ll ansX=0, ansY=0; // 목적지 좌표

		// dig(골드 넘버)의 반복 주기 확인
		vector <ll> digCycle;
		digCycle.push_back(1); // 최초에는 골드 넘버=1이므로 dig(1)=1 push

		bool go;
		do{
			go=true;
			ll curDig=dig(digCycle[digCycle.size()-1]*dig(m));
			for(int i=0; i<digCycle.size(); i++)
				if(curDig==digCycle[i]){ go=false; break; }
			if(go) digCycle.push_back(curDig);
		}while(go);

		if(digCycle[digCycle.size()-1]!=9){		
			// 이동의 반복 주기를 digCycle의 크기와 4의 최소공배수로 맞춤
			int curDir, digCycleIdx;

			ll moveCycle=lcm(digCycle.size(), 4);
			ll cycleX=0, cycleY=0; // 이동 반복 주기 1번이 지났을 때의 X, Y 좌표 변화량

			curDir=0;
			digCycleIdx=0;
			for(int i=0; i<moveCycle; i++){
				cycleX+=dirX[curDir]*digCycle[digCycleIdx];
				cycleY+=dirY[curDir]*digCycle[digCycleIdx];
				curDir=(curDir+1)%4;
				digCycleIdx=(digCycleIdx+1)%(digCycle.size());
			}

			// 반복 횟수 k에 대한 목적지 좌표 계산 (반복 주기로 나누어 떨어지는 부분)
			ansX+=cycleX*(k/moveCycle);
			ansY+=cycleY*(k/moveCycle);
			// 나머지 부분에 대한 시뮬레이션
			curDir=0;
			digCycleIdx=0;
			for(int i=0; i<k%moveCycle; i++){
				ansX+=dirX[curDir]*digCycle[digCycleIdx];
				ansY+=dirY[curDir]*digCycle[digCycleIdx];
				curDir=(curDir+1)%4;
				digCycleIdx=(digCycleIdx+1)%(digCycle.size());
			}
		}
		else{
			int curDir, digCycleIdx;

			curDir=0;
			digCycleIdx=0;
			for(int i=0; i<min2(k,digCycle.size()-1); i++){
				ansX+=dirX[curDir]*digCycle[digCycleIdx];
				ansY+=dirY[curDir]*digCycle[digCycleIdx];
				curDir=(curDir+1)%4;
				digCycleIdx=(digCycleIdx+1)%(digCycle.size());
			}

			k-=min2(k,digCycle.size()-1);

			for(int i=0; i<k%4; i++){
				ansX+=dirX[curDir]*9;
				ansY+=dirY[curDir]*9;
				curDir=(curDir+1)%4;
				digCycleIdx=(digCycleIdx+1)%(digCycle.size());
			}
		}
		printf("%lld %lld\n", ansX, ansY);
	}
	return 0;
}