#include <cstdio>
#include <vector>
#define UNKNOWN 0
#define LOSE -1
#define WIN 1

using namespace std;

int c;
char board[5][6];
char cache[1<<25]; // if cell (i,j) is occupied, (i*5+j)th bit is set.

const int block2_y[2][2] = {{0,0},{0,1}};
const int block2_x[2][2] = {{0,1},{0,0}};
const int block3_y[4][3] = {{0,0,1},{0,0,1},{0,1,1},{0,1,1}};
const int block3_x[4][3] = {{0,1,0},{0,1,1},{0,0,1},{0,0,-1}};

vector <int> add_state;

void build_add_state(void){

        for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){

                        int cur_bitmask;
                        for(int k=0; k<2; k++){ // block size 2
                                cur_bitmask=0;
                                for(int l=0; l<2; l++){
                                        int cy=i+block2_y[k][l];
                                        int cx=j+block2_x[k][l];
                                        if(cy<0 || cy>=5 || cx<0 || cx>=5){ cur_bitmask=-1; break; }
                                        else cur_bitmask |= (1<<(cy*5+cx));
                                }
                                if(cur_bitmask>=0) add_state.push_back(cur_bitmask);
                        }

                        for(int k=0; k<4; k++){ // block size 3
                                cur_bitmask=0;
                                for(int l=0; l<3; l++){
                                        int cy=i+block3_y[k][l];
                                        int cx=j+block3_x[k][l];
                                        if(cy<0 || cy>=5 || cx<0 || cx>=5){ cur_bitmask=-1; break; }
                                        else cur_bitmask |= (1<<(cy*5+cx));
                                }
                                if(cur_bitmask>=0) add_state.push_back(cur_bitmask);
                        }
                }
        }
}

char go(int state){
        if(cache[state]!=UNKNOWN) return cache[state];

        char ret=LOSE;
        for(int i=0; i<add_state.size(); i++){
                if((state & add_state[i])==0){ // possible to add this block
                        if(go(state|add_state[i])==LOSE){ // if there's a way to make opponent lose
                                ret=WIN;
                                break;
                        }
                }
        }

        return (cache[state]=ret);
}

int main(void){

        build_add_state();
        scanf("%d",&c);
        while(c--){
                for(int i=0; i<5; i++) scanf("%s",board[i]);

                int init_state=0;
                for(int i=0; i<5; i++)
                        for(int j=0; j<5; j++)
                                if(board[i][j]=='#') init_state|=(1<<(i*5+j));

                //for(int i=0; i<(1<<25); i++) cache[i]=UNKNOWN;
                char ans=go(init_state);

                if(ans==WIN) printf("WINNING\n");
                else printf("LOSING\n");
        }
        return 0;
}