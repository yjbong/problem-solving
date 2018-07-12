#include <cstdio>
int N;
int seq[80];

bool found;

bool isValid(int idx, int seq[]){
	bool ok=true;	
	for(int i=1; i<=(idx+1)/2; i++){
		bool curOk=false;	
		for(int j=0; j<i; j++)
			if(seq[idx-j]!=seq[idx-j-i]){ curOk=true; break; }

		if(!curOk){ ok=false; break; }
	}	
	return ok;
}
void go(int idx, int dgt, int len){
	if(found) return;
	if(idx==N){
		for(int i=0; i<len; i++) printf("%d",seq[i]);
		printf("\n");
		found=true;
		return;
	}
	
	seq[idx]=dgt;
	if(isValid(idx, seq)){
		for(int i=1; i<=3; i++) go(idx+1, i, len);
	}
}
int main(void){
	scanf("%d",&N);

	found=false;
	go(0, 1, N);
	go(0, 2, N);
	go(0, 3, N);
	return 0;
}