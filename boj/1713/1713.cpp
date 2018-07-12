#include <stdio.h>
#define SWAP(a,b,t){t=a;a=b;b=t;}
typedef struct _photo{
    int who;
    int recs;
    int times;
    int valid;
}PHOTO;

PHOTO p[20];
int ps;
int r[1000],rs;
int sol[20],sols;

int main(void){

    int i,j,t,n,alrdy,victim;
    scanf("%d",&n);
    scanf("%d",&rs);
    for(i=0; i<rs; i++) scanf("%d",&r[i]);
    for(i=0; i<n; i++) p[i].valid=0;

    ps=0;
    for(i=0; i<rs; i++){

        alrdy=0;
        for(j=0; j<n; j++){
            if(p[j].valid && r[i]==p[j].who){
                p[j].recs++;
                alrdy=1;
                break;
            }
        }
        if(!alrdy){
            if(ps==n){
                victim=0;
                for(j=1; j<n; j++){
                    if(p[victim].recs>p[j].recs) victim=j;
                    else if(p[victim].recs==p[j].recs && p[victim].times<p[j].times) victim=j;
                }

                p[victim].who=r[i];
                p[victim].recs=1;
                p[victim].times=0;
            }
            else{
                for(j=0; j<n; j++){
                    if(!p[j].valid){
                        p[j].who=r[i];
                        p[j].recs=1;
                        p[j].times=0;
                        p[j].valid=1;
                        ps++;
                        break;
                    }
                }
            }
        }
        for(j=0; j<n; j++)
            if(p[j].valid) p[j].times++;
    }

    sols=0;
    for(i=0; i<n; i++) if(p[i].valid) sol[sols++]=p[i].who;
    for(i=0; i<sols; i++)
        for(j=i+1; j<sols; j++)
            if(sol[i]>sol[j]) SWAP(sol[i],sol[j],t);

    for(i=0; i<sols; i++) printf("%d ",sol[i]);
    printf("\n");

    return 0;
}