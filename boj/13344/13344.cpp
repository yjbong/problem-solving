#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#define MAX_N 50000
#define MAX_M 250000
using namespace std;
int N; // 플레이어의 수
int M; // 전체 대국 수
typedef struct{
    int p1; // 대국자1 번호
    int p2; // 대국자2 번호
    char result; // > < = 중 하나
} GAME;
typedef struct{
    set <int> member;
    int indegree; // 현재 그룹을 이긴 그룹의 수
    set <int> outedges; //현재 그룹이 이긴 그룹의 리스트
    bool visited;
} GROUP; // 그룹은 서로 비긴 선수들의 집합이다.

GROUP group[MAX_N]; int groups;
int groupNum[MAX_N+1]; // groupNum[i]=i번 플레이어가 속한 그룹의 번호

GAME game[MAX_M];

queue <int> q;

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<M; i++) scanf("%d %c %d",&game[i].p1, &game[i].result, &game[i].p2);

    // group 구성
    set<int>::iterator it;
    groups=0;
    for(int i=0; i<N; i++) groupNum[i]=-1;
    for(int i=0; i<M; i++){
        int curP1=game[i].p1;
        int curP2=game[i].p2;
        char curResult=game[i].result;
        if(curResult=='='){
            if(groupNum[curP1]<0 && groupNum[curP2]<0){
                group[groups].member.insert(curP1);
                group[groups].member.insert(curP2);
                group[groups].indegree=0;
                group[groups].outedges.clear();
                group[groups].visited=false;
                groupNum[curP1]=groups;
                groupNum[curP2]=groups++;
            }
            else if(groupNum[curP1]<0){
                group[groupNum[curP2]].member.insert(curP1);
                groupNum[curP1]=groupNum[curP2];
            }
            else if(groupNum[curP2]<0){
                group[groupNum[curP1]].member.insert(curP2);
                groupNum[curP2]=groupNum[curP1];
            }
        }
    }
    for(int i=0; i<M; i++){
        int curP1=game[i].p1;
        int curP2=game[i].p2;
        char curResult=game[i].result;
        if(curResult!='='){
            if(groupNum[curP1]<0){
                group[groups].member.insert(curP1);
                group[groups].indegree=0;
                group[groups].outedges.clear();
                group[groups].visited=false;
                groupNum[curP1]=groups++;
            }
            if(groupNum[curP2]<0){
                group[groups].member.insert(curP2);
                group[groups].indegree=0;
                group[groups].outedges.clear();
                group[groups].visited=false;
                groupNum[curP2]=groups++;
            }
        }
    }

    // edge 구성
    bool isValid=true;
    for(int i=0; i<M; i++){
        int curG1=groupNum[game[i].p1];
        int curG2=groupNum[game[i].p2];
        char curResult=game[i].result;
        if(curResult=='>'){
            if(curG1!=curG2){ 
                if(group[curG1].outedges.find(curG2)==group[curG1].outedges.end()){
                    group[curG1].outedges.insert(curG2);
                    group[curG2].indegree++;
                }
            }
            else isValid=false;
        }
        else if(curResult=='<'){
            if(curG1!=curG2){
                if(group[curG2].outedges.find(curG1)==group[curG2].outedges.end()){
                    group[curG2].outedges.insert(curG1);
                    group[curG1].indegree++;
                }
            }
            else isValid=false;
        }
    }
    if(!isValid){
        printf("inconsistent\n");
        return 0;
    }

    // Topological sort
    int sorted=0;
    for(int i=0; i<groups; i++){
        if(group[i].indegree==0 && group[i].visited==false){
            q.push(i);
            group[i].visited=true;
            sorted++;
        }
    }
    while(!q.empty()){
        int f=q.front(); q.pop();
        for(set<int>::iterator it=group[f].outedges.begin(); it!=group[f].outedges.end(); it++){
            int c=*it;
            group[c].indegree--;
            if(group[c].indegree==0 && group[c].visited==false){
                q.push(c);
                group[c].visited=true;
                sorted++;
            }
        }
    }
    if(sorted!=groups) isValid=false;

    if(isValid) printf("consistent\n");
    else printf("inconsistent\n");
    return 0;
}