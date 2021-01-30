#include <cstdio>
#include <cstring>
#define MAXN 2000000
int N;
int q[MAXN+1];
int f; // front index
int r; // rear index

// 원형 큐는 [f, r) 구간에 데이터가 있는 것으로 본다.
int size(){
	int ret=r-f;
	if(ret<0) ret+=N+1;
	return ret;
}
int empty(){
	if(f==r) return 1;
	else return 0;
}
void push(int X){
	q[r]=X;
	r=(r+1)%(N+1);
}
int pop(){
	if(empty()) return -1;
	int ret=q[f];
	f=(f+1)%(N+1);
	return ret;
}
int front(){
	if(empty()) return -1;
	return q[f];
}
int back(){
	if(empty()) return -1;
	return q[(r+N)%(N+1)];
}

int main() {
	scanf("%d\n", &N);
	f=r=0;
	char cmd[10];
	int X;
	for(int i=0; i<N; i++){
		scanf("%s", cmd);
		if(!strcmp(cmd, "push")){
			scanf("%d",&X);
			push(X);
		}
		else if(!strcmp(cmd, "pop")) printf("%d\n", pop());
		else if(!strcmp(cmd, "size")) printf("%d\n", size());
		else if(!strcmp(cmd, "empty")) printf("%d\n", empty());
		else if(!strcmp(cmd, "front")) printf("%d\n", front());
		else if(!strcmp(cmd, "back")) printf("%d\n", back());
	}
	return 0;
}