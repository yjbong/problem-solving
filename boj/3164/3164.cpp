#include <cstdio>
typedef long long ll;
ll max2(ll a, ll b){ return a>b?a:b; }
int main(void){

        // input
        ll x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);

        // boundary
        ll lowX=x1, lowY=y1, highX=x2-1, highY=y2-1;

        // k = max2(x coord, y coord)
        // possible range of K from given rectangle --> [lowK, highK]
        ll lowK=max2(lowX,lowY), highK=max2(highX,highY);

        ll ans=0; // # of black grid from given rectangle
        for(ll curK=lowK; curK<=highK; curK++){
                if(curK%2==1){ // a grid(x,y) is black if k=max2(x,y) is odd

                        if(curK<=highX && curK<=highY){
                                ans += (curK-lowX+1)*(curK-lowY+1) - ((curK-1)-lowX+1)*((curK-1)-lowY+1);
                        }
                        else if(curK>highX && curK<=highY){
                                ans += (highX-lowX+1)*(curK-lowY+1) - (highX-lowX+1)*((curK-1)-lowY+1);
                        }
                        else if(curK<=highX && curK>highY){
                                ans += (curK-lowX+1)*(highY-lowY+1) - ((curK-1)-lowX+1)*(highY-lowY+1);            
                        }
                }
        }
        printf("%lld\n",ans);
        return 0;
}