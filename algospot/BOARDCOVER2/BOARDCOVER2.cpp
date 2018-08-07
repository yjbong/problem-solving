#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t,h,w,r,c;
char board[10][10+1];
char block[10][10+1];
int best; // answer
int whites; // # of remained white cells
bool blockvalid[4];
int blocksize;
vector <pair<int,int> > block_pos[4]; // relative (y,x) coord of block
void go(int idx, int cur_ans){
        if(best>=cur_ans+whites/blocksize) return; // pruning
        else if(best<cur_ans) best=cur_ans; // update answer

        int y=idx/w;
        int x=idx%w;
        int k;
        if(idx>=h*w) return;
        else if(board[y][x]=='#'){
                k=idx+1;
                while(k<h*w && board[k/w][k%w]=='#') k++;
                go(k,cur_ans);
        }
        else{
                // try putting block[0~3] at (y,x)
                for(int i=0; i<4; i++){
                        if(blockvalid[i]){ // ignore duplicated block
                                bool possible=true;
                                for(int j=0; j<blocksize; j++){
                                        int dy=block_pos[i][j].first, dx=block_pos[i][j].second;
                                        if(y+dy>=0 && y+dy<h && x+dx>=0 && x+dx<w && board[y+dy][x+dx]!='#');
                                        else{ possible=false; break; }
                                }
                                // if possible to put block, put it and go to next index
                                if(possible){
                                        for(int j=0; j<blocksize; j++){
                                                int dy=block_pos[i][j].first, dx=block_pos[i][j].second;
                                                board[y+dy][x+dx]='#';
                                        }
                                        whites-=blocksize;

                                        k=idx+1;
                                        while(k<h*w && board[k/w][k%w]=='#') k++;
                                        go(k,cur_ans+1);

                                        whites+=blocksize;
                                        for(int j=0; j<blocksize; j++){
                                                int dy=block_pos[i][j].first, dx=block_pos[i][j].second;
                                                board[y+dy][x+dx]='.';
                                        }
                                }
                        }
                }
                // skip putting block and go to next index
                board[y][x]='#';
                whites--;

                k=idx+1;
                while(k<h*w && board[k/w][k%w]=='#') k++;
                go(k,cur_ans);

                board[y][x]='.';
                whites++;
        }
}

int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%d %d %d %d",&h,&w,&r,&c);
                for(int i=0; i<h; i++) scanf("%s",board[i]);
                for(int i=0; i<r; i++) scanf("%s",block[i]);
                whites=0;
                for(int i=0; i<h; i++)
                        for(int j=0; j<w; j++)
                                if(board[i][j]!='#') whites++;

                // build block_pos[0]
                block_pos[0].clear();
                int upleft_y=-1, upleft_x=-1;
                for(int i=0; i<r; i++){
                        for(int j=0; j<c; j++){
                                if(block[i][j]=='#'){
                                        if(upleft_y<0) upleft_y=i, upleft_x=j;
                                        block_pos[0].push_back(make_pair(i-upleft_y,j-upleft_x));
                                }
                        }
                }
                blocksize=block_pos[0].size();

                // build block_pos[1~3]. block_pos[i+1] = 90 degree clockwise rotation of block_pos[i]
                // 90 degree clocksize rotation matrix = | 0 1 |
                //                                       |-1 0 |
                for(int i=1; i<4; i++){
                        block_pos[i].clear();
                        for(int j=0; j<blocksize; j++){
                                int cur_y=block_pos[i-1][j].first, cur_x=block_pos[i-1][j].second;
                                int new_y= 0*cur_y+1*cur_x, new_x=-1*cur_y+0*cur_x;
                                block_pos[i].push_back(make_pair(new_y,new_x));
                        }
                }

                // make (0,0) as upleft coord
                for(int i=1; i<4; i++){
                        upleft_y=0, upleft_x=0;
                        for(int j=0; j<blocksize; j++){
                                int cur_y=block_pos[i][j].first, cur_x=block_pos[i][j].second;
                                if(cur_y<upleft_y || (cur_y==upleft_y && cur_x<upleft_x)) upleft_y=cur_y, upleft_x=cur_x;
                        }
                        for(int j=0; j<blocksize; j++)
                                block_pos[i][j].first-=upleft_y, block_pos[i][j].second-=upleft_x;
                }

                // remove duplicated block
                for(int i=0; i<4; i++){
                        sort(block_pos[i].begin(), block_pos[i].end());
                        blockvalid[i]=true;
                }
                for(int i=0; i<4; i++){
                        for(int j=0; j<i; j++){
                                bool same=true;
                                for(int k=0; k<blocksize; k++){
                                        if(block_pos[i][k].first!=block_pos[j][k].first || block_pos[i][k].second!=block_pos[j][k].second){
                                                same=false;
                                                break;
                                        }
                                }
                                if(same){
                                        blockvalid[i]=false;
                                        break;
                                }
                        }
                }

                // searching best answer
                best=0;
                go(0,0);
                printf("%d\n",best);
        }
        return 0;
}