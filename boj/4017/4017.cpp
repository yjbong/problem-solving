#include <cstdio>
#include <vector>
using namespace std;
int N; // # of animal cages
int C; // # of children

typedef struct{
	vector <int> fearList; // fear cage idx list
	vector <int> likeList; // like cage idx list
}CHILD;

vector <CHILD> children[10000]; // children[i] = list of children in front i-th cage

int h[10000][1<<5]; // h[i][j] = # of happy children in front of i-th cage when cage state [i+4 ~ i] is j.
int d[10000][1<<5]; // d[i][j] = maximum # of children in front of [0~i]th cage when cage state [i+4 ~ i] is j.

int max2(int a, int b){
	return a>b?a:b;
}

bool visibleIdx(int E, int pos){

	for(int i=E; i<=E+4; i++)
		if(pos==i%N) return true;
	return false;
}

int getH(int cageIdx, int cageStatus){
	int ret=0;
	for(int i=0; i<children[cageIdx].size(); i++){
		bool isHappy=false;
		for(int j=0; j<children[cageIdx][i].fearList.size(); j++){
			int curFearCage=children[cageIdx][i].fearList[j];
			int curFearCageBit=curFearCage-cageIdx;
			if(curFearCageBit<0) curFearCageBit+=N;
			if(!(cageStatus & (1<<curFearCageBit))){ isHappy=true; break; } // a fear cage is removed.
		}

		if(!isHappy)
		for(int j=0; j<children[cageIdx][i].likeList.size(); j++){
			int curLikeCage=children[cageIdx][i].likeList[j];
			int curLikeCageBit=curLikeCage-cageIdx;
			if(curLikeCageBit<0) curLikeCageBit+=N;
			if(cageStatus & (1<<curLikeCageBit)){ isHappy=true; break; } // a like cage is not removed.
		}

		if(isHappy) ret++;
	}
	return ret;
}

int main(void){

	// process input
	scanf("%d %d",&N,&C);
	for(int i=0; i<C; i++){
		int E,F,L;
		scanf("%d %d %d",&E,&F,&L);

		E--; // make cage idx starting from 0 and ending at N-1

		CHILD curChild;
		for(int i=0; i<F; i++){
			int fearIdx;
			scanf("%d",&fearIdx);
			fearIdx--; // make cage idx starting from 0 and ending at N-1
			if(visibleIdx(E,fearIdx)) curChild.fearList.push_back(fearIdx);
		}
		for(int i=0; i<L; i++){
			int likeIdx;
			scanf("%d",&likeIdx);
			likeIdx--; // make cage idx starting from 0 and ending at N-1
			if(visibleIdx(E,likeIdx)) curChild.likeList.push_back(likeIdx);
		}
		children[E].push_back(curChild);
	}

	// calc h array
	for(int i=0; i<N; i++)
		for(int j=0; j<(1<<5); j++)
			h[i][j]=getH(i,j);

	int ans=0;
	// Dynamic Programming
	for(int _3to0_state=0; _3to0_state<(1<<4); _3to0_state++){ // fix state of cage[3~0] and consider every cage[3~0] states

		// init d array
		for(int i=0; i<N; i++)
			for(int j=0; j<(1<<5); j++) d[i][j]=0;

		// base case
		d[0][(0<<4)|_3to0_state]=h[0][(0<<4)|_3to0_state]; // 4th cage is removed.
		d[0][(1<<4)|_3to0_state]=h[0][(1<<4)|_3to0_state]; // 4th cage is not removed.

		for(int i=1; i<N; i++){
			for(int j=0; j<(1<<5); j++){

				// check if fixed state[3~0] is not changed (check from i=n-4 to i=n-1)
				bool isValid=true;
				for(int k=4; k>=N-i; k--){
					if( ((j&(1<<k))>>k) != ((_3to0_state&(1<<(k-N+i)))>>(k-N+i)) ){
						isValid=false; break;
					}
				}

				// consider two cases for i-th cage (remove i-th cage or Not)
				if(isValid) d[i][j]=max2(d[i-1][((j<<1)&0x1F)|0], d[i-1][((j<<1)&0x1F)|1])+h[i][j];
				else d[i][j]=0;
			}
		}

		// update answer
		int curAns=0;
		for(int j=0; j<(1<<5); j++) curAns=max2(curAns,d[N-1][j]);
		
		ans=max2(ans,curAns);
	}
	printf("%d\n",ans);

	return 0;
}