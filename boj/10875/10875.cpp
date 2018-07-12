#include <cstdio>
#include <vector>
#define INF 1000000000000000000ll
#define HORIZONTAL 0
#define VERTICAL 1

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;
typedef long long ll;

ll L; // 격자판 크기 = (2L+1)*(2L+1)
int N; // 머리 방향 회전 횟수

typedef struct{
	ll x;
	ll y;
}POINT;
typedef struct{
	POINT start; // 선분의 시작점
	POINT end; // 선분의 끝점
}LINE;

vector <LINE> lineList;

ll min2(ll a, ll b){ return a<b?a:b; }

// NORTH, EAST, SOUTH, WEST
const int dx[4]={0, 1, 0,-1};
const int dy[4]={1, 0,-1, 0};

// curLine이 oldLine과 몇 초 후에 충돌하는지 구함
ll getCrashTime(LINE curLine, LINE oldLine){
	ll ret=INF;

	int curLineType;
	if(curLine.start.y==curLine.end.y) curLineType=HORIZONTAL; // x축에 평행
	else curLineType=VERTICAL; // y축에 평행

	int oldLineType;
	if(oldLine.start.y==oldLine.end.y) oldLineType=HORIZONTAL; // x축에 평행
	else oldLineType=VERTICAL; // y축에 평행

	if(curLineType==HORIZONTAL && oldLineType==HORIZONTAL){
		// 두 선분이 만나기 위해서는 같은 행에 있어야 함
		if(oldLine.start.y==curLine.start.y){
			// 현재 선분이 오른쪽 방향으로 진행되는 경우
			if(curLine.start.x<curLine.end.x){
				if(curLine.start.x<=oldLine.start.x && oldLine.start.x<=curLine.end.x) ret=min2(ret,oldLine.start.x-curLine.start.x);
				if(curLine.start.x<=oldLine.end.x && oldLine.end.x<=curLine.end.x) ret=min2(ret,oldLine.end.x-curLine.start.x);
			}
		
			else{ // 현재 선분이 왼쪽 방향으로 진행되는 경우
				if(curLine.end.x<=oldLine.start.x && oldLine.start.x<=curLine.start.x) ret=min2(ret,curLine.start.x-oldLine.start.x);
				if(curLine.end.x<=oldLine.end.x && oldLine.end.x<=curLine.start.x) ret=min2(ret,curLine.start.x-oldLine.end.x);
			}
		}
	}
	else if(curLineType==VERTICAL && oldLineType==VERTICAL){
		// 두 선분이 만나기 위해서는 같은 열에 있어야 함
		if(oldLine.start.x==curLine.start.x){	
			// 현재 선분이 위쪽 방향으로 진행되는 경우
			if(curLine.start.y<curLine.end.y){
				if(curLine.start.y<=oldLine.start.y && oldLine.start.y<=curLine.end.y) ret=min2(ret,oldLine.start.y-curLine.start.y);
				if(curLine.start.y<=oldLine.end.y && oldLine.end.y<=curLine.end.y) ret=min2(ret,oldLine.end.y-curLine.start.y);
			}
		
			else{ // 현재 선분이 아래쪽 방향으로 진행되는 경우
				if(curLine.end.y<=oldLine.start.y && oldLine.start.y<=curLine.start.y) ret=min2(ret,curLine.start.y-oldLine.start.y);
				if(curLine.end.y<=oldLine.end.y && oldLine.end.y<=curLine.start.y) ret=min2(ret,curLine.start.y-oldLine.end.y);
			}
		}
	}
	else if(curLineType==HORIZONTAL && oldLineType==VERTICAL){
		// 현재 선분이 오른쪽 방향으로 진행되는 경우
		if(curLine.start.x<curLine.end.x && (curLine.start.x<=oldLine.start.x && oldLine.start.x<=curLine.end.x)){
			if(oldLine.start.y<oldLine.end.y && (oldLine.start.y<=curLine.start.y && curLine.start.y<=oldLine.end.y)) ret=min2(ret,oldLine.start.x-curLine.start.x);	
			if(oldLine.start.y>oldLine.end.y && (oldLine.end.y<=curLine.start.y && curLine.start.y<=oldLine.start.y)) ret=min2(ret,oldLine.start.x-curLine.start.x);
		}
		// 현재 선분이 왼쪽 방향으로 진행되는 경우
		else if(curLine.start.x>curLine.end.x && (curLine.end.x<=oldLine.start.x && oldLine.start.x<=curLine.start.x)){
			if(oldLine.start.y<oldLine.end.y && (oldLine.start.y<=curLine.start.y && curLine.start.y<=oldLine.end.y)) ret=min2(ret,curLine.start.x-oldLine.start.x);
			if(oldLine.start.y>oldLine.end.y && (oldLine.end.y<=curLine.start.y && curLine.start.y<=oldLine.start.y)) ret=min2(ret,curLine.start.x-oldLine.start.x);
		}
	}
	else if(curLineType==VERTICAL && oldLineType==HORIZONTAL){
		// 현재 선분이 위쪽 방향으로 진행되는 경우
		if(curLine.start.y<curLine.end.y && (curLine.start.y<=oldLine.start.y && oldLine.start.y<=curLine.end.y)){
			if(oldLine.start.x<oldLine.end.x && (oldLine.start.x<=curLine.start.x && curLine.start.x<=oldLine.end.x)) ret=min2(ret,oldLine.start.y-curLine.start.y);
			if(oldLine.start.x>oldLine.end.x && (oldLine.end.x<=curLine.start.x && curLine.start.x<=oldLine.start.x)) ret=min2(ret,oldLine.start.y-curLine.start.y);
		}
		// 현재 선분이 아래쪽 방향으로 진행되는 경우
		else if(curLine.start.y>curLine.end.y && (curLine.end.y<=oldLine.start.y && oldLine.start.y<=curLine.start.y)){
			if(oldLine.start.x<oldLine.end.x && (oldLine.start.x<=curLine.start.x && curLine.start.x<=oldLine.end.x)) ret=min2(ret,curLine.start.y-oldLine.start.y);
			if(oldLine.start.x>oldLine.end.x && (oldLine.end.x<=curLine.start.x && curLine.start.x<=oldLine.start.x)) ret=min2(ret,curLine.start.y-oldLine.start.y);
		}
	}

	return ret;
}

int main(void){
	scanf("%lld",&L);

	// 격자판 가장자리에 해당하는 선분 4개를 추가
	LINE l;

	l.start.x=-(L+1), l.start.y=L+1;
	l.end.x=L+1, l.end.y=L+1;
	lineList.push_back(l);

	l.start.x=-(L+1), l.start.y=-(L+1);
	l.end.x=L+1, l.end.y=-(L+1);
	lineList.push_back(l);

	l.start.x=-(L+1), l.start.y=L+1;
	l.end.x=-(L+1), l.end.y=-(L+1);
	lineList.push_back(l);

	l.start.x=L+1, l.start.y=L+1;
	l.end.x=L+1, l.end.y=-(L+1);
	lineList.push_back(l);


	scanf("%d\n",&N);

	int curDir=EAST; // 초기에는 머리가 동쪽을 보고 있음
	POINT curStart, curEnd;
	curStart.x=0, curStart.y=0; // 초기 출발점은 (0,0)

	ll ans=0;
	// 회전이 없는 경우의 예외 처리
	if(N==0){
		ans=L+1;
		goto ansPrint;
	}
	for(int i=0; i<N; i++){
		ll t;
		char dir;
		scanf("%lld %c\n",&t,&dir);

		curEnd.x=curStart.x+dx[curDir]*t;
		curEnd.y=curStart.y+dy[curDir]*t;

		LINE curLine;
		curLine.start=curStart;
		curLine.end=curEnd;

		ll curMinCrashTime=INF;

		for(int j=0; j<lineList.size(); j++){
			if(!(lineList[j].end.x==curLine.start.x && lineList[j].end.y==curLine.start.y)){ // 어떤 선분의 끝점과 현재 선분의 시작점이 같다면, 이 선분은 직전에 추가된 선분이므로 당연히 겹치는 것이다
				ll curCrashTime = getCrashTime(curLine, lineList[j]);
				/*
				if(curCrashTime<INF)
					printf("curLine = (%lld,%lld ~ %lld,%lld), oldLine = (%lld,%lld ~ %lld,%lld) --> crash at %lld\n", curLine.start.x, curLine.start.y, curLine.end.x, curLine.end.y, lineList[j].start.x, lineList[j].start.y, lineList[j].end.x, lineList[j].end.y, curCrashTime);
				else
					printf("curLine = (%lld,%lld ~ %lld,%lld), oldLine = (%lld,%lld ~ %lld,%lld) --> no crash\n", curLine.start.x, curLine.start.y, curLine.end.x, curLine.end.y, lineList[j].start.x, lineList[j].start.y, lineList[j].end.x, lineList[j].end.y);
				*/
				if(curMinCrashTime>curCrashTime) curMinCrashTime=curCrashTime;
			}
		}

		// 이미 있는 선분에 부딪힌 경우
		if(curMinCrashTime<INF){
			ans+=curMinCrashTime;
			break;
		}
		// 부딪히지 않은 경우
		else{
			lineList.push_back(curLine);

			curStart.x=curEnd.x;
			curStart.y=curEnd.y;

			if(dir=='L') curDir=(curDir-1+4)%4; // 반시계 방향 회전
			else curDir=(curDir+1)%4; // 시계 방향 회전

			ans+=t;
		}
		//printf("\n");

		// 주어진 회전을 모두 수행하는 동안 부딪히지 않은 경우
		if(i==N-1){
			// 추가해야 하는 선분은 무한한 시간동안 현재 방향으로 진행함
			curEnd.x=curStart.x+dx[curDir]*INF;
			curEnd.y=curStart.y+dy[curDir]*INF;

			curLine.start=curStart;
			curLine.end=curEnd;

			curMinCrashTime=INF;
			for(int j=0; j<lineList.size(); j++){
				if(!(lineList[j].end.x==curLine.start.x && lineList[j].end.y==curLine.start.y)){ // 어떤 선분의 끝점과 현재 선분의 시작점이 같다면, 이 선분은 직전에 추가된 선분이므로 당연히 겹치는 것이다
					ll curCrashTime = getCrashTime(curLine, lineList[j]);
					/*
					if(curCrashTime<INF)
						printf("curLine = (%lld,%lld ~ %lld,%lld), oldLine = (%lld,%lld ~ %lld,%lld) --> crash at %lld\n", curLine.start.x, curLine.start.y, curLine.end.x, curLine.end.y, lineList[j].start.x, lineList[j].start.y, lineList[j].end.x, lineList[j].end.y, curCrashTime);
					else
						printf("curLine = (%lld,%lld ~ %lld,%lld), oldLine = (%lld,%lld ~ %lld,%lld) --> no crash\n", curLine.start.x, curLine.start.y, curLine.end.x, curLine.end.y, lineList[j].start.x, lineList[j].start.y, lineList[j].end.x, lineList[j].end.y);
					*/
					if(curMinCrashTime>curCrashTime) curMinCrashTime=curCrashTime;
				}
			}
			ans+=curMinCrashTime;
		}
	}

ansPrint:
	printf("%lld\n",ans);
	return 0;
}