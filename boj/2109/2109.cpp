#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct _sc{

    int pay;
    int due;
}SC;
SC sc[10000];

priority_queue<int> pq;
int cmp(const void *a, const void *b){

    if(((SC*)a)->due > ((SC*)b)->due) return 1;
    else return 0;
}

int main(void){

    int i,j,n;
    int day,start;
    int income;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d %d", &(sc[i].pay), &(sc[i].due));
    qsort(sc,n,sizeof(SC),cmp);

    income=0;
    day=sc[n-1].due;

    for(i=n-1; i>=0; i--){
        if(sc[i].due<day){
            if(!pq.empty()){
                income+=pq.top();
                pq.pop();
                day--;
            }
            else day=sc[i].due;
            i++;
        }
        else{
            pq.push(sc[i].pay);
        }
    }

    while(day>0 && !pq.empty()){
        income+=pq.top();
        pq.pop();
        day--;
    }

    printf("%d\n", income);
    return 0;
}