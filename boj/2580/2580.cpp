#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int board[9][9];
vector<ii> zero;
bool found;
int rowCheck[9][10]; // 각 row의 숫자 사용 상태
int colCheck[9][10]; // 각 col의 숫자 사용 상태
int boxCheck[9][10]; // 각 box의 숫자 사용 상태
 
void dfs(int idx){
	if(found) return;
	if(idx==zero.size()){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++)
				printf("%d ",board[i][j]);
			printf("\n");
		}
		found=true;
	}
	int cy=zero[idx].first, cx=zero[idx].second;
	int curBox=cy/3*3+cx/3;
 
	for(int num=1; num<=9; num++){
 
		bool promising=true;
 
		if(rowCheck[cy][num]>0) promising=false;
		if(colCheck[cx][num]>0) promising=false;
		if(boxCheck[curBox][num]>0) promising=false;
 
		if(promising){
			board[cy][cx]=num;
			rowCheck[cy][num]++;
			colCheck[cx][num]++;
			boxCheck[curBox][num]++;
			dfs(idx+1);
            board[cy][cx]=0;
		    rowCheck[cy][num]--;
		    colCheck[cx][num]--;
		    boxCheck[curBox][num]--;
		}
	}
}
 
int main() {
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d",&board[i][j]);
			if(board[i][j]==0) zero.push_back(make_pair(i,j));
			else{
				int curBox=i/3*3+j/3;
				rowCheck[i][board[i][j]]++;
				colCheck[j][board[i][j]]++;
				boxCheck[curBox][board[i][j]]++;
			}
		}
	}
 
	if(zero.size()>0){
		found=false;
		dfs(0);
	}
	else{
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++)
				printf("%d ",board[i][j]);
			printf("\n");
		}
	}
	return 0;
}