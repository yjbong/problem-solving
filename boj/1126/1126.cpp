#include <cstdio>
#include <vector>

int abs(int a){
    if(a<0) return (-a);
    else return a;
}
int max(int a, int b){
    if(a<b) return b;
    else return a;
}
using namespace std;
int n;
int a[51];
int d[51][500001]; // d[i][j] : 현재 [1~i]번째 탑이 존재, 만들어진 두 탑의 높이차가 j일 때, 두 탑 중 높은 탑의 높이
bool c[500001];
vector <int> v[2];
int main(void){

    scanf("%d",&n);
    int tot=0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    for(int i=0; i<=n; i++)
        for(int j=0; j<=tot; j++) d[i][j]=-1;

    d[0][0]=0;
    v[0].push_back(0);

    for(int i=1; i<=n; i++){
        for(int j=0; j<=tot; j++) c[j]=false;

        int newv=i%2;
        int oldv=1-newv;
        for(int j=0; j<v[oldv].size(); j++){

            int cur=v[oldv][j];

            // 둘 중 높은 쪽에 현재 블록을 쌓음.
            if(!c[cur+a[i]]){
                c[cur+a[i]]=true;
                v[newv].push_back(cur+a[i]);
            }
            if(d[i][cur+a[i]]<d[i-1][cur]+a[i]) d[i][cur+a[i]]=d[i-1][cur]+a[i];

            // 둘 중 낮은 쪽에 현재 블록을 쌓음.
            if(!c[abs(cur-a[i])]){
                c[abs(cur-a[i])]=true;
                v[newv].push_back(abs(cur-a[i]));
            }
            if(d[i][abs(cur-a[i])]<max(d[i-1][cur],d[i-1][cur]-cur+a[i]))
                d[i][abs(cur-a[i])]=max(d[i-1][cur],d[i-1][cur]-cur+a[i]);

            // 현재 블록을 쌓지 않음.
            if(!c[cur]){
                c[cur]=true;
                v[newv].push_back(cur);
            }
            if(d[i][cur]<d[i-1][cur]) d[i][cur]=d[i-1][cur];
        }
        v[oldv].clear();
    }

    int sol=-1;
    for(int i=0; i<=n; i++) if(d[i][0]>0 && sol<d[i][0]) sol=d[i][0];
    printf("%d\n",sol);

    return 0;
}