#include<cstdio>
int p[101][101];
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int j=y1; j<=y2; j++)
            for(int k=x1; k<=x2; k++) p[j][k]++;
    }
    int sol=0;
    for(int j=1; j<=100; j++)
        for(int k=1; k<=100; k++) if(p[j][k]>m) sol++;
    printf("%d\n",sol);
    return 0;
}