#include <cstdio>

int c;
int n;
int move[50000];
int ans[50000];

int BIT[1<<18];
int base;

int find(int x){ // get index of x-th 1
        if(BIT[1]>0 && x>0){
                x%=BIT[1];
                if(x==0) x=BIT[1];
        }

        int i=1;
        while(i<base){
                if(BIT[i*2]<x){
                        x-=BIT[i*2]; i=i*2+1;
                }
                else i=i*2;
        }
        return (i-base);
}

void update(int idx){
        idx+=base; BIT[idx]=0;
        idx/=2;
        while(idx>=1){
                BIT[idx]=BIT[idx*2]+BIT[idx*2+1];
                idx/=2;
        }
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++) scanf("%d",&move[i]);

                base=1;
                while(base<n) base*=2;

                for(int i=base; i<base+n; i++) BIT[i]=1;
                for(int i=base+n; i<base*2; i++) BIT[i]=0;
                for(int i=base-1; i>=1; i--) BIT[i]=BIT[i*2]+BIT[i*2+1];

                for(int i=n-1; i>=0; i--){
                        int cur_ans=find(i+1-move[i]);
                        update(cur_ans);
                        ans[i]=cur_ans+1;
                }
                for(int i=0; i<n; i++) printf("%d ",ans[i]);
                printf("\n");
        }
        return 0;
}