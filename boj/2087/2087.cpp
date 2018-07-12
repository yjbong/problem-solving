#include <cstdio>
#include <algorithm>
using namespace std;

int a1[20];
int a2[20];
typedef struct _a{
    int id;
    int sum;
}ii;

ii s1[1<<20];
ii s2[1<<20];

bool cmp1(ii i, ii j){
    return (i.sum<j.sum);
}
bool cmp2(ii i, ii j){
    return (i.sum>j.sum);
}
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        if(i<(n+1)/2) scanf("%d",&a1[i]);
        else scanf("%d",&a2[i-(n+1)/2]);
    }
    int k;
    scanf("%d",&k);
    int a1s=(n+1)/2;
    int a2s=n-a1s;

    int s1s=1<<a1s;
    int s2s=1<<a2s;

    for(int i=0; i<s1s; i++){
        s1[i].id=i;
        s1[i].sum=0;

        int t=i;
        int c=0;
        while(t>0){
            if(t%2) s1[i].sum+=a1[c];
            t/=2;
            c++;
        }
    }

    for(int i=0; i<s2s; i++){
        s2[i].id=i;
        s2[i].sum=0;

        int t=i;
        int c=0;
        while(t>0){
            if(t%2) s2[i].sum+=a2[c];
            t/=2;
            c++;
        }
    }

    sort(s1,s1+s1s,cmp1);
    sort(s2,s2+s2s,cmp2);

    int idx1,idx2;
    idx1=idx2=0;
    while(idx1<s1s && idx2<s2s){
        int csum=s1[idx1].sum+s2[idx2].sum;
        if(csum<k) idx1++;
        else if(csum>k) idx2++;
        else{
            int t1=s1[idx1].id;
            for(int i=0; i<a1s; i++,t1/=2){
                if(t1%2) printf("1");
                else printf("0");
            }
            int t2=s2[idx2].id;
            for(int i=0; i<a2s; i++,t2/=2){
                if(t2%2) printf("1");
                else printf("0");
            }
            printf("\n");
            break;
        }
    }
    return 0;
}