#include <cstdio>
#define NODATA -1000000000

int c,n;
int a[55];
int cache[55][55][2];

int max2(int a, int b){
        return a>b?a:b;
}
int min2(int a, int b){
        return a<b?a:b;
}
// return maximum (player0 score-player1 score)
// turn=0 if player0's turn, 1 if player1's turn
// item[left~right] is valid
int go(int left, int right, int turn){
        if(cache[left][right][turn]>NODATA) return cache[left][right][turn];

        if(left>right) return 0;
        else if(left==right){
                if(turn==0) return a[left];
                else return (-a[left]);
        }
        else{
                if(turn==0){
                        int ret=NODATA;
                        ret=max2(ret,go(left+1,right,1)+a[left]);
                        ret=max2(ret,go(left,right-1,1)+a[right]);
                        ret=max2(ret,go(left+2,right,1));
                        ret=max2(ret,go(left,right-2,1));
                        return (cache[left][right][turn]=ret);
                }
                else{
                        int ret=-NODATA;
                        ret=min2(ret,go(left+1,right,0)-a[left]);
                        ret=min2(ret,go(left,right-1,0)-a[right]);
                        ret=min2(ret,go(left+2,right,0));
                        ret=min2(ret,go(left,right-2,0));
                        return (cache[left][right][turn]=ret);
                }
        }
}
int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++) scanf("%d",&a[i]);
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                for(int k=0; k<2; k++) cache[i][j][k]=NODATA;
                printf("%d\n",go(0,n-1,0));
        }
        return 0;
}