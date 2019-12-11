#include <cstdio>
#include <queue>
#define MAX_N 50000000
#define MAX_M 100
#define INF 1000000000
using namespace std;
typedef long long ll;
ll N; // 건물의 층수
int M; // 엘리베이터의 수
ll X[MAX_M+1];
ll Y[MAX_M+1];
ll A; // 출발층
ll B; // 도착층
 
int step[MAX_M+1]; // dist[i] = 출발층에서 i번 엘리베이터를 타기 위해 최소한 타야되는 엘리베이터의 수 (i번 엘리베이터를 타는 것도 포함)
int pre[MAX_M];
int order[MAX_M];
 
queue <int> q;
 
ll max2(ll a, ll b){ return a>b?a:b; }
ll getgcd(ll a, ll b){
    if(b==0) return a;
    else return getgcd(b,a%b);
}
 
// 부정방정식 ax+by=c 가 주어졌을 때, 이를 만족하는 특수해 x_sp, y_sp를 찾는다.
bool diophantineSpecial(ll a, ll b, ll c, ll &x_sp, ll &y_sp){
    ll orgA=a, orgB=b;
    if(orgA==0 && orgB==0){ // 0=c
        if(c==0){ x_sp=0; y_sp=0; return true; }
        else return false;
    }
    else if(orgA==0){ // by=c
        if(c%b==0){ x_sp=0; y_sp=c/b; return true; }
        else return false;
    }
    else if(orgB==0){ // ax=c
        if(c%a==0){ x_sp=c/a; y_sp=0; return true; }
        else return false;
    }
    else{
        pair<ll, pair<ll,ll> > old2, old1;
        old2.first=a, old2.second=make_pair(1,0);
        old1.first=b, old1.second=make_pair(0,1);
        while(a!=0 && b!=0){
            ll t=b;
            b=a%b;
            a=t;
 
            pair<ll,ll> newPair=make_pair(old2.second.first+old1.second.first*(-(old2.first/old1.first)),old2.second.second+old1.second.second*(-(old2.first/old1.first)));
            old2=old1;
            old1.first=b, old1.second=newPair;
            
        }
        ll gcd=old2.first;
        if(c%gcd==0){
            x_sp=(c/gcd)*old2.second.first;
            y_sp=(c/gcd)*old2.second.second;
            return true;
        }
        else return false;
    }
}
 
typedef struct{
    ll a;
    ll b;
}LINEAR; // a*k+b를 표현 (k는 임의의 정수)
 
// 부정방정식 ax+by=c가 주어졌을 때, 이를 만족하는 일반해 x_gn, y_gn를 찾는다.
bool diophantineGeneral(ll a, ll b, ll c, LINEAR &x_gn, LINEAR &y_gn){
    if(a==0 && b==0){ // 0=c
        if(c==0){
            x_gn={0,0}; y_gn={0,0};
            return true;
        }
        else return false;
    }
    else if(a==0){ // by=c
        if(c%b==0){ x_gn={0,0}; y_gn={0,c/b}; return true; }
        else return false;
    }
    else if(b==0){ // ax=c
        if(c%a==0){ x_gn={0,c/a}; y_gn={0,0}; return true; }
        else return false;
    }
    else{
        ll x_sp, y_sp;
        if(diophantineSpecial(a, b, c, x_sp, y_sp)){
            ll d=getgcd(a,b);
            x_gn={b/d,x_sp};
            y_gn={-a/d,y_sp};
            return true;
        }
        else return false;
    }
}
 
// i번 엘리베이터에서 j번 엘리베이터로 갈아탈 수 있으면 true, 아니면 false
bool isTransferable(int i, int j){
    LINEAR Ci, Cj;
    if(diophantineGeneral(Y[i], -Y[j], X[j]-X[i], Ci, Cj)){
        ll T=max2(X[i],X[j]);
        if(Ci.a>0){
            ll K=(T-X[i]-Ci.b*Y[i])/(Ci.a*Y[i]);
            ll curFloor=X[i]+Y[i]*(Ci.a*K+Ci.b);
            if(T<=curFloor && curFloor<=N) return true;
            K++;
            curFloor=X[i]+Y[i]*(Ci.a*K+Ci.b);
            if(T<=curFloor && curFloor<=N) return true;
            return false;
        }
        else if(Ci.a<0){
            ll K=(N-X[i]-Ci.b*Y[i])/(Ci.a*Y[i]);
            ll curFloor=X[i]+Y[i]*(Ci.a*K+Ci.b);
            if(T<=curFloor && curFloor<=N) return true;
            K++;
            curFloor=X[i]+Y[i]*(Ci.a*K+Ci.b);
            if(T<=curFloor && curFloor<=N) return true;
            return false;
        }
        else{ // Ci.a==0
            ll curFloor=X[i]+Y[i]*Ci.b;
            if(T<=curFloor && curFloor<=N) return true;
            return false;
        }
    }
    else return false;
}
 
// i번 엘리베이터가 n층에 멈추면 true, 아니면 false
bool isStop(int i, ll n){
    if(n<1 || n>N) return false;
 
    if(n<X[i]) return false;
    else if(n==X[i]) return true;
    else if((n-X[i])%Y[i]==0) return true;
    else return false;
}
 
int main() {
    scanf("%lld %d",&N,&M);
    for(int i=1; i<=M; i++)
        scanf("%lld %lld",&X[i],&Y[i]);
    scanf("%lld %lld",&A,&B);
 
    // step 초기화
    for(int i=1; i<=M; i++) step[i]=INF;
    // 출발층에서 바로 탈 수 있는 엘리베이터 확인
    for(int i=1; i<=M; i++)
        if(isStop(i,A)){ step[i]=1; q.push(i); pre[i]=0; }
 
    while(!q.empty()){
        int f=q.front(); q.pop();
        for(int i=1; i<=M; i++){
            if(isTransferable(f,i) && step[i]>step[f]+1){
                step[i]=step[f]+1; q.push(i); pre[i]=f;
            }
        }
    }
 
    int minStep=INF;
    int ctrace;
    for(int i=1; i<=M; i++){
        if(isStop(i,B) && minStep>step[i]){
            minStep=step[i]; ctrace=i;
        }
    }
 
    // 출력
    if(minStep<INF){
        printf("%d\n",minStep); // 최소로 엘리베이터를 타는 횟수
        int orders=0;
        while(ctrace){
            order[orders++]=ctrace;
            ctrace=pre[ctrace];
        }
        for(int i=orders-1; i>=0; i--) printf("%d\n",order[i]); // 엘리베이터 타는 순서 출력
    }
    else printf("-1\n");
    return 0;
}