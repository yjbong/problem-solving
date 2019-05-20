#include <cstdio>
#include <utility>
#define SIZE 100
using namespace std;
typedef pair<int,int> ii;

ii q[SIZE+1];
int front, rear;
void init(void){ front=rear=0; }
bool empty(void){ return front==rear?true:false; }
bool full(void){ return (rear+1)%(SIZE+1) == front?true:false; }
template<typename T>
void push(T data){ if(!full()){ rear=(rear+1)%(SIZE+1); q[rear]=data; }}
template<typename T>
T getFront(void){
	T tmp;
	return empty()?tmp:q[front];
}
template<typename T>
void pop(void){ if(!empty()){ front=(front+1)%(SIZE+1); } }

int TC; // 테스트 케이스의 수
int N; // 문서의 수
int Q; // 출력 순서를 알고 싶은 문서
int cnt[10]; // cnt[i] = 남아있는 문서들 중에서 중요도가 i인 것의 개수

int main() {
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d",&N,&Q);
		for(int i=0; i<N; i++){
			ii data;
			data.first=i; // 문서 id
			scanf("%d",&data.second); // 문서 중요도
			push<ii>(data);
			cnt[data.second]++;
		}

		int printOrder=1;
		while(!empty()){
			ii f=getFront<ii>(); pop<ii>();
			int fprio=f.second;
			bool printNow=true;
			for(int i=fprio+1; i<10; i++)
				if(cnt[i]>0){ printNow=false; break; }

			if(printNow){
				if(f.first==Q) printf("%d\n",printOrder);
				printOrder++;
				cnt[f.second]--;
			}
			else push<ii>(f);
		}
	}
	return 0;
}