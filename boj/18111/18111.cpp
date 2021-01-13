#include <cstdio>
#define MAXH 256 // 최대 높이
#define INF 1000000000
int N,M; // 집터는 N*M 크기
int B; // 처음에 인벤토리에 있는 블럭
int hCnt[MAXH+1]; // hCnt[i] = 높이가 i인 셀의 수
int totBlks; // 전체 블럭 수
int main() {
    scanf("%d %d %d",&N,&M,&B);
    totBlks=B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int curH;
            scanf("%d",&curH);
            hCnt[curH]++;
            totBlks+=curH;
        }
    }

    int time=INF, height;
    for(int tgtH=256; tgtH>=0; tgtH--){ // tgtH = 목표 높이
        if(totBlks<tgtH*N*M) continue;
        int curTime=0;
        for(int i=0; i<=MAXH; i++){
            if(i>tgtH) curTime+=(i-tgtH)*hCnt[i]*2;
            else if(i<tgtH) curTime+=(tgtH-i)*hCnt[i];
        }
        if(time>curTime){
            time=curTime;
            height=tgtH;
        }
    }
    printf("%d %d\n",time,height);
    return 0;
}