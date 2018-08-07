#include <cstdio>
int c,n,k;
int base;
int BIT[1<<12];

void kill(int idx){
        idx+=base;
        if(BIT[idx]){
                BIT[idx]=0; idx/=2;
                while(idx>0){
                        BIT[idx]=BIT[idx*2]+BIT[idx*2+1];
                        idx/=2;
                }
        }
}

int find(int num){ // get (num-th) living person's idx

        if(BIT[1]<1) return -1;
        if(num>BIT[1]) num%=BIT[1];
        int idx=1;
        while(idx<base){
                if(BIT[idx*2]>=num) idx*=2;
                else{
                        num-=BIT[idx*2];
                        idx=idx*2+1;
                }
        }
        return (idx-base);
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&k);
                base=1;
                while(base<n) base*=2;
                for(int i=base; i<base*2; i++) BIT[i]=(i<base+n?1:0);
                for(int i=base-1; i>=1; i--) BIT[i]=BIT[i*2]+BIT[i*2+1];

                kill(find(1));
                int before=0;
                for(int i=n-1; i>2; i--){
                        //kill(find(before+k));
                        int cur=before+k;
                        if(cur>BIT[1]){
                                cur%=BIT[1];
                                if(cur==0) cur=BIT[1];
                        }

                        kill(find(cur));

                        before=cur-1;
                }
                for(int i=base; i<base*2; i++)
                        if(BIT[i]) printf("%d ",i-base+1);
                printf("\n");
        }
        return 0;
}