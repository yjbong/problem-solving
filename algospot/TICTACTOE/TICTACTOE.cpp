#include <cstdio>
#include <cassert>
#define X 1
#define O 2
#define TIE 3

// # of state = 3^9 = 19683
// i-th bit of state = 0 if empty, 1 if x, 2 if o
int win[20000]; // win[state] = 0 if unknown, 1 if x's win state, 2 if o's win state, 3 if tie state
int cases;

int pow3[10];

int calc_win(int state){

	if(win[state]!=0) return win[state]; // memoization
	
	int bit[9], tmp=state;
	for(int i=0; i<9; i++){
		bit[i]=tmp%3;
		tmp/=3;
	}

	int xs, os;
	xs=os=0;
	for(int i=0; i<9; i++){
		if(bit[i]==X) xs++;
		else if(bit[i]==O) os++;
	}
	assert(xs-os<=1);


	// calc win[state] directly
	if(bit[0]==X && bit[1]==X && bit[2]==X) return (win[state]=X);
	else if(bit[3]==X && bit[4]==X && bit[5]==X) return (win[state]=X);
	else if(bit[6]==X && bit[7]==X && bit[8]==X) return (win[state]=X);
	else if(bit[0]==X && bit[3]==X && bit[6]==X) return (win[state]=X);
	else if(bit[1]==X && bit[4]==X && bit[7]==X) return (win[state]=X);
	else if(bit[2]==X && bit[5]==X && bit[8]==X) return (win[state]=X);
	else if(bit[0]==X && bit[4]==X && bit[8]==X) return (win[state]=X);
	else if(bit[2]==X && bit[4]==X && bit[6]==X) return (win[state]=X);

	else if(bit[0]==O && bit[1]==O && bit[2]==O) return (win[state]=O);
	else if(bit[3]==O && bit[4]==O && bit[5]==O) return (win[state]=O);
	else if(bit[6]==O && bit[7]==O && bit[8]==O) return (win[state]=O);
	else if(bit[0]==O && bit[3]==O && bit[6]==O) return (win[state]=O);
	else if(bit[1]==O && bit[4]==O && bit[7]==O) return (win[state]=O);
	else if(bit[2]==O && bit[5]==O && bit[8]==O) return (win[state]=O);
	else if(bit[0]==O && bit[4]==O && bit[8]==O) return (win[state]=O);
	else if(bit[2]==O && bit[4]==O && bit[6]==O) return (win[state]=O);

	else if(xs+os==9) return (win[state]=TIE);


	// calc win[state] from next possible states
	if(xs-os==0){ // x's turn
		bool can_win, can_tie;
		can_win=can_tie=false;
		for(int i=0; i<9; i++){
			if(bit[i]==0){ // i-th cell is empty
				int next;
				next=state+X*pow3[i];
				if(calc_win(next)==X) { can_win=true; break; }
				if(calc_win(next)==TIE) { can_tie=true; }
			}
		}
		if(can_win) return (win[state]=X);
		else if(can_tie) return (win[state]=TIE);
		else return (win[state]=O);
	}

	else if(xs-os==1){ // o's turn
		bool can_win, can_tie;
		can_win=can_tie=false;
		for(int i=0; i<9; i++){
			if(bit[i]==0){ // i-th cell is empty
				int next;
				next=state+O*pow3[i];
				if(calc_win(next)==O) { can_win=true; break; }
				if(calc_win(next)==TIE) { can_tie=true; }
			}
		}
		if(can_win) return (win[state]=O);
		else if(can_tie) return (win[state]=TIE);
		else return (win[state]=X);
	}
}

int main(void){

	pow3[0]=1;
	for(int i=1; i<10; i++) pow3[i]=pow3[i-1]*3;

	scanf("%d",&cases);
	while(cases--){
		char str[5];
		int curstate=0;
		for(int i=0; i<3; i++){
			scanf("%s",str);
			for(int j=0; j<3; j++){
				if(str[j]=='x') curstate += X*pow3[i*3+j];
				else if(str[j]=='o') curstate += O*pow3[i*3+j];
			}
		}

		int ans=calc_win(curstate);
		if(ans==X) printf("x\n");
		else if(ans==O) printf("o\n");
		else if(ans==TIE) printf("TIE\n");
	}
	return 0;
}