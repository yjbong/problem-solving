#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#define MAXN 300
#define MAXSUM 100000
using namespace std;
typedef pair<int, int> ii;
int N; // 당의 수
int total; // 전체 의석 수
int overHalf; // 과반 의석 수
ii A[MAXN]; // A[i].first=의석 수, A[i].second=당 번호
bool D[MAXN][MAXSUM+1]; // D[i][j]=0~i번 당이 있을 때, 선택한 당의 의석 수의 합이 정확히 j가 될 수 있으면 true (단, 이미 깔끔한 연합이거나 깔끔한 연합이 될 가능성이 있어야 함
bool T[MAXN][MAXSUM+1]; // T[i][j]=D[i][j]가 true인 경우, i번 당을 선택한 것이라면 true
vector<int> ans;
bool cmp(ii a, ii b){ return a.first>b.first; }
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&A[i].first); A[i].second=i+1;
        total+=A[i].first;   
    }
    overHalf=total/2+1;
 
    // 의석 수의 내림차순으로 정렬
    sort(A,A+N,cmp);
    //for(int i=0; i<N; i++) printf("%d ",A[i].first);
 
    // DP
    D[0][0]=true;
    D[0][A[0].first]=true; T[0][A[0].first]=true; 
    for(int i=1; i<N; i++){
        for(int j=0; j<=total; j++){
            // case 1: i번 당을 선택하지 않음
            if(D[i-1][j]){
                D[i][j]=true;
            }
            // case 2: i번 당을 선택
            if(j-A[i].first>=overHalf) continue; // i번 당 없이도 이미 과반인 경우에는 무시
            if(j>=A[i].first && D[i-1][j-A[i].first]){
                D[i][j]=true;
                T[i][j]=true;
            }
        }
    }
 
    // max=깔끔한 연합의 최대 의석 수
    int max=0;
    for(int j=total; j>=overHalf; j--)
        if(D[N-1][j]){ max=j; break; }
    //printf("%d\n",max);
 
    // Trace 정보(T 배열)를 이용하여 최대의 깔끔한 연합에 속하는 당을 구함
    int cur=max;
    for(int i=N-1; i>=0; i--){
        if(T[i][cur]){
            ans.push_back(A[i].second);
            cur-=A[i].first;
        }
    }
 
    // 최대의 깔끔한 연합을 출력
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}