#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int N; // 재료의 개수

typedef struct{
	ll bunja;
	ll bunmo;	
}BUNSU;

typedef struct{
	ll p;
	ll q;
}RATIO;

BUNSU d[10]; // d[i] : 전체에서 재료 i가 차지하는 크기
RATIO r[10][10]; // r[i][j] = 재료 i와 j의 비율

// 각 재료의 비율 관계는 tree의 형태이다
vector <int> adj[10]; // adj[i] = 재료 i와 직접적인 비율 관계가 있는 재료 리스트
int lv[10]; // lv[i] = i번 재료의 트리 루트로부터의 거리
queue <int> q;
int order[10]; int orders;

ll gcd(ll p, ll q)
{
	if (q==0) return p;
	return gcd(q, p%q);
}

ll lcm(ll p, ll q){
	ll gcdVal=gcd(p,q);
	if(gcdVal==0) return 0;
	return (p*q)/gcdVal;
}

BUNSU mul2(BUNSU a, BUNSU b){ // c = a*b

	ll agcd=gcd(a.bunja,a.bunmo);
	a.bunja/=agcd;
	a.bunmo/=agcd;

	ll bgcd=gcd(b.bunja,b.bunmo);
	b.bunja/=bgcd;
	b.bunmo/=bgcd;

	BUNSU c;
	c.bunja=a.bunja*b.bunja;
	c.bunmo=a.bunmo*b.bunmo;

	ll cgcd=gcd(c.bunja,c.bunmo);
	c.bunja/=cgcd;
	c.bunmo/=cgcd;

	return c;
}

int main(void){
    
    // 입력
	scanf("%d",&N);
	for(int i=0; i<N; i++){ d[i].bunja=0; d[i].bunmo=1; }
	
	for(int i=0; i<N-1; i++){
		int a,b,p,q;
		scanf("%d %d %d %d",&a,&b,&p,&q);
		r[a][b].p=p; r[b][a].p=q;
		r[a][b].q=q; r[b][a].q=p;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0; i<N; i++) lv[i]=10000;
	lv[0]=0; // 0번 재료를 루트로 가정
	q.push(0);

	// 각 재료의 lv 구하기	
	orders=0;
	while(!q.empty()){
		int f=q.front(); q.pop();
		order[orders++]=f;
		for(int i=0; i<adj[f].size(); i++){
			int cv=adj[f][i];
			if(lv[cv]>lv[f]+1){
				lv[cv]=lv[f]+1;
				q.push(cv);
			}
		}
	}
	
	// 0번 재료와의 비율 계산
	for(int i=0; i<orders; i++){
		int ov=order[i];
		if(lv[ov]==0){ d[ov].bunja=1; d[ov].bunmo=1; } // 0번 재료의 질량 = 1
		for(int j=0; j<adj[ov].size(); j++){
			int cv=adj[ov][j];
			BUNSU b;
			b.bunja=r[ov][cv].q;
			b.bunmo=r[ov][cv].p;
			d[cv]=mul2(d[ov],b);
		}
	}

	ll totalLcm=1; // 분모들의 lcm 계산
	for(int i=0; i<N; i++)
		totalLcm=lcm(totalLcm,d[i].bunmo);
	
	// 분자에 분모들의 lcm을 곱하여 자연수로 만듬
	for(int i=0; i<N; i++){
		BUNSU b;
		b.bunja=totalLcm;
		b.bunmo=1;
		d[i]=mul2(d[i],b);
	}

	// 답 출력
	for(int i=0; i<N; i++)
		printf("%lld ", d[i].bunja);
	printf("\n");

	return 0;
}