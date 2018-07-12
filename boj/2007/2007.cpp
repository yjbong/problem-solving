#include <cstdio>
#include <algorithm>
#define MAX_NUM 111

using namespace std;
int s[MAX_NUM*(MAX_NUM-1)/2];
int ss;

int c[1<<15]; //s[i]가 이미 쓰였는지 나타냄. BIT구조
int cbase;

int a[MAX_NUM]; // 정답 배열
int n; // 정답 배열의 크기

int get_pos(int p){ // 아직 사용되지 않은 sum중 p번째의 idx를 return

    int cur_idx, tmp_idx;
    cur_idx=p;
    tmp_idx=1;
    while(tmp_idx<cbase){
        if(cur_idx<=c[tmp_idx*2]) tmp_idx*=2;
        else{
            cur_idx -= c[tmp_idx*2];
            tmp_idx=tmp_idx*2+1;
        }
    }
    return tmp_idx-cbase;
}

void update_BIT(int p){ // cbase+p번째 idx의 값이 바뀌었을때 나머지 BIT를 update

    p=cbase+p;
    int tmp_idx;
    tmp_idx=p/2;
    while(tmp_idx>=1){
        c[tmp_idx]=c[tmp_idx*2]+c[tmp_idx*2+1];
        tmp_idx/=2;
    }
}

int bsearch(int key){

    int l,m,r;

    int st=-1;
    int ed=-1;

    l=0; r=ss-1;
    while(l<=r){
        m=(l+r)/2;
        if(s[m]<key) l=m+1;
        else if(s[m]>key) r=m-1;
        else{
            st=m;
            r=m-1;
        }
    }

    l=0; r=ss-1;
    while(l<=r){
        m=(l+r)/2;
        if(s[m]<key) l=m+1;
        else if(s[m]>key) r=m-1;
        else{
            ed=m;
            l=m+1;
        }
    }

    if(st>=0 && ed>=0){
        for(int i=st; i<=ed; i++){
            if(c[cbase+i]>0) return i;
        }
    }

    return -1;
}

int main(void){

    scanf("%d",&n);
    ss=n*(n-1)/2; // ss는 sum의 가짓수

    // cbase = BIT에서 실제 데이터가 어느 idx부터 시작하는지 나타냄
    cbase=1;
    while(cbase<ss) cbase*=2;

    // sum들을 입력받아서 오름차순 정렬
    for(int i=0; i<ss; i++) scanf("%d",&s[i]);
    sort(s,s+ss);

    if(n==1){
        printf("0\n");
    }
    else if(n==2){
        if(s[0]<0) printf("%d %d\n",s[0],0);
        else printf("%d %d\n",0,s[0]);
    }
    else if(n>=3){

        bool ok=false;
        for(int i=2; i<ss; i++){

            // BIT 초기화
            for(int j=cbase; j<cbase*2; j++){
                if(j<cbase+ss) c[j]=1;
                else c[j]=0;
            }
            for(int j=cbase-1; j>=1; j--) c[j]=c[j*2]+c[j*2+1];

            if((s[0]+s[1]+s[i])%2) continue;
            int t=(s[0]+s[1]+s[i])/2;

            a[0]=t-s[i]; a[1]=t-s[1]; a[2]=t-s[0];

            c[cbase+0]=0; update_BIT(0);
            c[cbase+1]=0; update_BIT(1);
            c[cbase+i]=0; update_BIT(i);

            int j;
            for(j=3; j<n; j++){
                int min_idx=get_pos(1);

                a[j]=s[min_idx]-a[0];

                c[cbase+min_idx]=0; update_BIT(min_idx);

                for(int k=1; k<j; k++){
                    int cur_idx=bsearch(a[k]+a[j]);
                    if(cur_idx<0){
                        goto cont;
                    }
                    c[cbase+cur_idx]=0; update_BIT(cur_idx);
                }
            }

cont:
            if(j==n){
                ok=true;
                for(int i=0; i<n; i++) printf("%d ",a[i]);
                printf("\n");
                break;
            }
        }
        if(!ok) printf("Impossible\n");
    }
    return 0;
}